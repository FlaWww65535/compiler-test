#include "Ast.h"
#include "SymbolTable.h"
#include "Unit.h"
#include "Instruction.h"
#include "IRBuilder.h"
#include <string.h>
#include "Type.h"
#include <assert.h>
extern FILE *yyout;
int Node::counter = 0;
IRBuilder* Node::builder = nullptr;

Node::Node()
{
    seq = counter++;
}
void Node::backPatch(std::vector<Instruction*> &list, BasicBlock*bb)
{
    for(auto &inst:list)
    {
        if(inst->isCond())
            dynamic_cast<CondBrInstruction*>(inst)->setTrueBranch(bb);
        else if(inst->isUncond())
            dynamic_cast<UncondBrInstruction*>(inst)->setBranch(bb);
    }
}

std::vector<Instruction*> Node::merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2)
{
    std::vector<Instruction*> res(list1);
    res.insert(res.end(), list2.begin(), list2.end());
    return res;
}

void Ast::genCode(Unit *unit)
{
    //printf("gen Ast");
    IRBuilder *builder = new IRBuilder(unit);
    Node::setIRBuilder(builder);
    root->genCode();
}

void FunctionDef::genCode()
{
    //printf("gen FuncDef");
    Unit *unit = builder->getUnit();
    Function *func = new Function(unit,se);
    //printf("FunctionDef::genCode()");
    func->setParamList(paramList);
    BasicBlock *entry = func->getEntry();
    // set the insert point to the entry basicblock of this function.

    for(auto &param_se:seList){

        Type* type=param_se->getType();
        SymbolEntry* addr_se = new TemporarySymbolEntry(new PointerType(type), SymbolTable::getLabel());
        Operand* addr=new Operand(addr_se);

        AllocaInstruction* alloca=new AllocaInstruction(addr, new TemporarySymbolEntry(type,0));
        entry->insertFront(alloca);
        param_se->setAddr(addr);
        Operand* param=new Operand(param_se);
        //new StoreInstruction(addr,param,entry);
        //BUG FIX
       // SymbolEntry* param_se=identifiers->lookup(i.second);
       /*
        printf("param_se:%s\n",i.second.c_str());
        Type *type;
        type = new PointerType(i.first);
        printf("%s",i.second.c_str());
        SymbolEntry* param_se = new IdentifierSymbolEntry(i.first,i.second,0);
        Operand* param=new Operand(param_se);
        addr_se = new TemporarySymbolEntry(type, SymbolTable::getLabel());
        addr=new Operand(addr_se);
        AllocaInstruction* alloca=new AllocaInstruction(addr, addr_se);
        entry->insertFront(alloca);
        new StoreInstruction(addr, param, entry);
        assert(param_se);*/
     /*   dynamic_cast<IdentifierSymbolEntry*>(param_se)->setAddr(addr);
        Type * type = new PointerType(param_se->getType());
        addr_se = new TemporarySymbolEntry(type, SymbolTable::getLabel());
        addr = new Operand(addr_se);
        AllocaInstruction* alloca = new AllocaInstruction(addr, param_se);                   // allocate space for local id in function stack.
        entry->insertFront(alloca);                                 // allocate instructions should be inserted into the begin of the entry block.
        //printf("funcdef addr %d\n",(void*)addr);
        //Operand *addr = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getAddr();
        //new LoadInstruction(dst, addr, entry);
        Operand* src=new Operand(param_se);
        new StoreInstruction(addr, src, entry);*/
    }
    
    builder->setInsertBB(entry);
    
    
    if (stmt)stmt->genCode();

    /*
     * Construct control flow graph. You need do set successors and predecessors for each basic block.
     * Todo
    */
    for(auto i=func->begin();i!=func->end();i++){
        BasicBlock* bb = (*i);
        Instruction* inst = bb->rbegin();
        if(inst->isCond()){
            BasicBlock* trueBB;
            BasicBlock* falseBB;
            trueBB = dynamic_cast<CondBrInstruction*>(inst)->getTrueBranch();
            falseBB = dynamic_cast<CondBrInstruction*>(inst)->getFalseBranch();
            bb->addSucc(trueBB);
            bb->addSucc(falseBB);
            trueBB->addPred(bb);
            falseBB->addPred(bb);
        }else if(inst->isUncond()){
            //Todo:Uncond
            BasicBlock* thenBB;
            thenBB = dynamic_cast<UncondBrInstruction*>(inst)->getBranch();
            bb->addSucc(thenBB);
            thenBB->addPred(bb);
        }else if(!inst->isRet()){
            Operand *op = new Operand(new ConstantSymbolEntry(new IntType(32),0));
            new RetInstruction(op,bb);
        }
    }
}

void BinaryExpr::genCode()
{
    BasicBlock *bb = builder->getInsertBB();
    Function *func = bb->getParent();
    dst=new Operand(new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel()));
    if (op == AND)
    {
        BasicBlock *trueBB = new BasicBlock(func);  // if the result of lhs is true, jump to the trueBB.
        expr1->genCode();
        backPatch(expr1->trueList(), trueBB);
        builder->setInsertBB(trueBB);               // set the insert point to the trueBB so that intructions generated by expr2 will be inserted into it.
        expr2->genCode();
        true_list = expr2->trueList();
        false_list = merge(expr1->falseList(), expr2->falseList());
    }
    else if(op == OR)
    {
        // Todo:Done
        BasicBlock *falseBB = new BasicBlock(func);  // if the result of lhs is false, jump to the falseBB.
        expr1->genCode();
        backPatch(expr1->falseList(), falseBB);
        builder->setInsertBB(falseBB);               // set the insert point to the falseBB so that intructions generated by expr2 will be inserted into it.
        expr2->genCode();
        true_list = merge(expr1->trueList(), expr2->trueList());
        false_list = expr2->falseList();
    }
    else if(op >= LESS && op <= EQUAL)
    {
        // Todo:Done
        //if_in_cond=false;
        expr1->genCode();
        expr2->genCode();
        Operand *src1 = expr1->getOperand();
        Operand *src2 = expr2->getOperand();
        int opcode;
        switch (op)
        {
        case LESS:
            opcode = CmpInstruction::L;
            break;
        case GREATER:
            opcode = CmpInstruction::G;
            break;
        case LESSEQ:
            opcode = CmpInstruction::LE;
            break;
        case GREATEREQ:
            opcode = CmpInstruction::GE;
            break;
        case NOTEQ:
            opcode = CmpInstruction::NE;
            break;
        case EQUAL:
            opcode = CmpInstruction::E;
            break;
        }
        new CmpInstruction(opcode, dst, src1, src2, bb);
        BasicBlock *trueBB, *falseBB, *endBB;
        trueBB = new BasicBlock(func);
        falseBB = new BasicBlock(func);
        endBB = new BasicBlock(func);

        true_list.push_back(new CondBrInstruction(trueBB, endBB, dst, bb));
        false_list.push_back(new UncondBrInstruction(falseBB, endBB));


    }
    else if(op >= ADD && op <= MOD)
    {
        expr1->genCode();
        expr2->genCode();
        Operand *src1 = expr1->getOperand();
        Operand *src2 = expr2->getOperand();
        int opcode;
        switch (op)
        {
        case ADD:
            opcode = BinaryInstruction::ADD;
            break;
        case SUB:
            opcode = BinaryInstruction::SUB;
            break;
        case MUL:
            opcode = BinaryInstruction::MUL;
            break;
        case DIV:
            opcode = BinaryInstruction::DIV;
            break;
        case MOD:
            opcode = BinaryInstruction::MOD;
            break;
        }
        new BinaryInstruction(opcode, dst, src1, src2, bb);
     /*   if(if_in_cond==true){
            BasicBlock *trueBB, *falseBB, *endBB;
            trueBB = new BasicBlock(func);
            falseBB = new BasicBlock(func);
            endBB = new BasicBlock(func);
            true_list.push_back(new CondBrInstruction(trueBB, endBB, dst, bb));
            false_list.push_back(new UncondBrInstruction(falseBB, endBB));
        }*/
    }
}


void UnaryExpr::genCode()
{
    expr1->genCode();
    BasicBlock* bb =builder->getInsertBB();
    Function* func = bb->getParent();
    Operand* src = expr1->getOperand();
    //Todo
    if(op == UnaryExpr::UMINUS){
        //printf("size is %s",src->getType()->toStr().c_str());
        if(src->getType()->toStr()=="i32")
        {
            Operand* src2 = new Operand(new ConstantSymbolEntry(new IntType(32),0));
            new BinaryInstruction(BinaryInstruction::SUB,dst,src2,src,bb);
        }else{
            Operand* zero = new Operand(new ConstantSymbolEntry(TypeSystem::boolType,0));
            new CmpInstruction(CmpInstruction::NE, dst, src,zero,bb);
            BasicBlock *trueBB, *falseBB, *endBB;
            trueBB = new BasicBlock(func);
            falseBB = new BasicBlock(func);
            endBB = new BasicBlock(func);

            true_list.push_back(new CondBrInstruction(trueBB, endBB, dst, bb));
            false_list.push_back(new UncondBrInstruction(falseBB, endBB));
        }
    }else if(op == UnaryExpr::NOT){
        Operand* res = new Operand(new TemporarySymbolEntry(TypeSystem::boolType,SymbolTable::getLabel()));
        Operand* zero = new Operand(new ConstantSymbolEntry(TypeSystem::boolType,0));
        new CmpInstruction(CmpInstruction::E, res, src,zero,bb);
        dst = res;
        //new BinaryInstruction(BinaryInstruction::ADD,dst,zero,src,bb);
    }else {dst=src;}
}

void PrimaryExp::genCode(){
    //Todo
    //printf("Gen PrimaryExp");
    expr1->genCode();
}

void FuncUseExpr::genCode(){
    //Todo

    BasicBlock* bb = builder->getInsertBB();
    std::vector<Operand*> paramList={};
    ExprNode* param = funcRParams;
    if(param!=nullptr){
        while (param->isRParam()) {

            FuncRParams* tmp = dynamic_cast<FuncRParams*>(param);
            tmp->getFirst()->genCode();
            paramList.push_back(tmp->getFirst()->getOperand());
            //printf("push\n");
            param = tmp->getNext();
        }
        param->genCode();
        paramList.push_back(param->getOperand());
        reverse(paramList.begin(),paramList.end());
        //printf("push\n");
    }

    new CallInstruction(dst, funcName->getSymPtr(), paramList, bb);
}

void FuncRParams::genCode(){
    //Do Nothing
}

void Constant::genCode()
{
    // we don't need to generate code.
}

void Id::genCode()
{
    BasicBlock *bb = builder->getInsertBB();
    Operand *addr = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getAddr();
    //if(addr==nullptr) addr=new Operand(new TemporarySymbolEntry(TypeSystem::boolType,SymbolTable::getLabel()));
    //printf("ID gencode addr %d\n",(void *)addr);
    new LoadInstruction(dst, addr, bb);
}

void IfStmt::genCode()
{
    //if_in_cond=true;
    Function *func;
    BasicBlock *then_bb, *end_bb;

    func = builder->getInsertBB()->getParent();
    then_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);

    cond->genCode();
    backPatch(cond->trueList(), then_bb);
    backPatch(cond->falseList(), end_bb);

    builder->setInsertBB(then_bb);
    //if_in_cond=false;
    thenStmt->genCode();
    then_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb, then_bb);

    builder->setInsertBB(end_bb);

}

void IfElseStmt::genCode()
{
    // Todo
    //if_in_cond=true;
    Function* func;
    BasicBlock *then_bb, *else_bb , *end_bb;
    func = builder->getInsertBB()->getParent();
    then_bb = new BasicBlock(func);
    else_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);

    cond->genCode();
    backPatch(cond->trueList(),then_bb);
    backPatch(cond->falseList(),else_bb);
    //if_in_cond=false;
    builder->setInsertBB(then_bb);
    thenStmt->genCode();
    then_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb,then_bb);

    builder->setInsertBB(else_bb);
    elseStmt->genCode();
    else_bb = builder->getInsertBB();
    new UncondBrInstruction(end_bb,else_bb);

    builder->setInsertBB(end_bb);

}

void WhileStmt::genCode()
{
    //Todo
    //if_in_cond=true;
    Function *func;
    BasicBlock *cond_bb, *loop_bb, *end_bb,*bb;

    func = builder->getInsertBB()->getParent();
    cond_bb = new BasicBlock(func);
    loop_bb = new BasicBlock(func);
    end_bb = new BasicBlock(func);
    bb = builder->getInsertBB();

    new UncondBrInstruction(cond_bb,bb);

    builder->setInsertBB(cond_bb);
    cond->genCode();
    backPatch(cond->trueList(), loop_bb);
    backPatch(cond->falseList(), end_bb);
    //if_in_cond=false;
    builder->setInsertBB(loop_bb);
    loopStmt->genCode();
    loop_bb=builder->getInsertBB();
    new UncondBrInstruction(cond_bb, loop_bb);

    builder->setInsertBB(end_bb);

}

void CompoundStmt::genCode()
{
    // Todo
    if(stmt)stmt->genCode();
}

void SeqNode::genCode()
{
    // Todo
    
    stmt1->genCode();
    stmt2->genCode();
}

void DeclStmt::genCode()
{
    IdentifierSymbolEntry *se = dynamic_cast<IdentifierSymbolEntry *>(id->getSymPtr());
    if(se->isGlobal())
    {
        Operand *addr;
        SymbolEntry *addr_se;
        addr_se = new IdentifierSymbolEntry(*se);
        addr_se->setType(new PointerType(se->getType()));
        addr = new Operand(addr_se);

        se->setAddr(addr);
    }
    else if(se->isLocal())
    {
        Function *func = builder->getInsertBB()->getParent();
        BasicBlock *entry = func->getEntry();
        Instruction *alloca;
        Operand *addr;
        SymbolEntry *addr_se;
        Type *type;
        type = new PointerType(se->getType());
        addr_se = new TemporarySymbolEntry(type, SymbolTable::getLabel());
        addr = new Operand(addr_se);
        alloca = new AllocaInstruction(addr, se);                   // allocate space for local id in function stack.
        entry->insertFront(alloca);                                 // allocate instructions should be inserted into the begin of the entry block.
        se->setAddr(addr);                                          // set the addr operand in symbol entry so that we can use it in


        // code generation.
    }
}

void ReturnStmt::genCode()
{
    // Todo
    //printf("Gen ReturnStmt");
    BasicBlock *bb = builder->getInsertBB();
    Operand *op = nullptr;
    if(retValue){
        retValue->genCode();
        op = retValue->getOperand();
    }
    
    new RetInstruction(op,bb);
}

void ExpStmt::genCode()
{
    expr1->genCode();
}

void AssignStmt::genCode()
{
    
    BasicBlock *bb = builder->getInsertBB();
    expr->genCode();
    
    Operand *addr = dynamic_cast<IdentifierSymbolEntry*>(lval->getSymPtr())->getAddr();
    Operand *src = expr->getOperand();
    
    /***
     * We haven't implemented array yet, the lval can only be ID. So we just store the result of the `expr` to the addr of the id.
     * If you want to implement array, you have to caculate the address first and then store the result into it.
     */
    
    new StoreInstruction(addr, src, bb);
}

void Ast::typeCheck()
{
    if(root != nullptr)
        root->typeCheck();
}

void FunctionDef::typeCheck()
{
    blockType=(dynamic_cast<FunctionType*>(se->getType()))->getRetType();
    if(blockType!=TypeSystem::voidType)ifReturn=false;
    else ifReturn=true;
    stmt->typeCheck();
    if(ifReturn==false){
        fprintf(stderr,"no return");
        exit(EXIT_FAILURE);
    }
    blockType=nullptr;
}

void BinaryExpr::typeCheck()
{
    // Todo
    expr1->typeCheck();
    expr2->typeCheck();
    Type *type1 = expr1->getSymPtr()->getType();
    Type *type2 = expr2->getSymPtr()->getType();
    if(type1 != type2)
    {
        fprintf(stderr, "type %s and %s mismatch",
        type1->toStr().c_str(), type2->toStr().c_str());
        exit(EXIT_FAILURE);
    }
    symbolEntry->setType(type1);
}

void UnaryExpr::typeCheck()
{
    expr1->typeCheck();
    Type *type1 = expr1->getSymPtr()->getType();
    symbolEntry->setType(type1);
}

void PrimaryExp::typeCheck()
{
    expr1->typeCheck();
    Type *type1 = expr1->getSymPtr()->getType();
    symbolEntry->setType(type1);
}

void FuncUseExpr::typeCheck()
{
    if(funcName!= nullptr)funcName->typeCheck();
    if(funcRParams!=nullptr){
        funcRParams->typeCheck();
    }
    FunctionType* type1;
    FunctionType* type2=(dynamic_cast<FunctionType*>(funcName->getSymPtr()->getType()));
    if(funcRParams!=nullptr)type1=dynamic_cast<FunctionType*> (funcRParams->getSymPtr()->getType());
    if(funcRParams!= nullptr&&type1== nullptr){
        type1=new FunctionType(type2->getRetType(),{funcRParams->getSymPtr()->getType()});
    }
    else {
        if (funcRParams != nullptr)type1 = new FunctionType(type2->getRetType(), type1->paramsType);
        else type1 = new FunctionType(type2->getRetType(), {});
    }
    //Type *type1 =funcName->getSymPtr()->getType();
    symbolEntry->setType(type1);
    if(getSymPtr()->getType()->toStr()!=funcName->getSymPtr()->getType()->toStr())
    {
        fprintf(stderr, "type %s and %s mismatch",
        type1->toStr().c_str(), funcName->getSymPtr()->getType()->toStr().c_str());
        exit(EXIT_FAILURE);
    }
    symbolEntry->setType(type1->getRetType());
}
void FuncRParams::typeCheck()
{
    if(expr1!=nullptr)expr1->typeCheck();
    FunctionType *type1;
    Type* type0;
    if(funcRParams!=nullptr) {
        funcRParams->typeCheck();
        type0 = funcRParams->getSymPtr()->getType();
        type1 = dynamic_cast<FunctionType *> (type0);
    }
    if(type1==nullptr) {
        std::vector<Type*> paramsType;
        paramsType.push_back(type0);
        type1=new FunctionType(TypeSystem::voidType,paramsType);
    }
    else type1=new FunctionType(TypeSystem::voidType,type1->paramsType);
    (type1->paramsType).insert((type1->paramsType).begin(),expr1->getSymPtr()->getType());
    symbolEntry->setType(type1);
}
void Constant::typeCheck()
{
    // do nothing
    
}

void Id::typeCheck()
{
    // do nothing

}
void CompoundStmt::typeCheck()
{
    stmt->typeCheck();
}
void SeqNode::typeCheck()
{
    stmt1->typeCheck();
    stmt2->typeCheck();
}
void IfStmt::typeCheck()
{
    if(cond!=nullptr)cond->typeCheck();
    if(thenStmt!=nullptr)thenStmt->typeCheck();
}

void IfElseStmt::typeCheck()
{
    if(cond!=nullptr)cond->typeCheck();
    if(thenStmt!=nullptr)thenStmt->typeCheck();
    if(elseStmt!=nullptr)elseStmt->typeCheck();
}

void WhileStmt::typeCheck()
{

    if(cond!=nullptr)cond->typeCheck();
    if(loopStmt!=nullptr)loopStmt->typeCheck();
}

void ReturnStmt::typeCheck()
{
    ifReturn=true;
    if(retValue!=nullptr)retValue->typeCheck();
    if(retValue==nullptr){
        if(blockType->toStr()!=TypeSystem::voidType->toStr()){
            fprintf(stderr, "type %s and %s mismatch",
            blockType->toStr().c_str(), TypeSystem::voidType->toStr().c_str());
            exit(EXIT_FAILURE);
        }
    }
    else{
        if(blockType->toStr()!=retValue->getSymPtr()->getType()->toStr()){
            fprintf(stderr, "type %s and %s mismatch",
            blockType->toStr().c_str(), retValue->getSymPtr()->getType()->toStr().c_str());
            exit(EXIT_FAILURE);
        }
    }
}
void DeclStmt::typeCheck()
{
    // Todo
    id->typeCheck();
}
void ExpStmt::typeCheck()
{
    // Todo
    expr1->typeCheck();
}
void AssignStmt::typeCheck()
{
    // Todo
    lval->typeCheck();
    expr->typeCheck();
    Type *type1 = lval->getSymPtr()->getType();
    Type *type2 = expr->getSymPtr()->getType();
    if(type1 != type2)
    {
        fprintf(stderr, "type %s and %s mismatch",
        type1->toStr().c_str(), type2->toStr().c_str());
        exit(EXIT_FAILURE);
    }
}
/*
void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4);
}

void Constant::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void CompoundStmt::output(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    stmt->output(level + 4);
}

void SeqNode::output(int level)
{
    stmt1->output(level);
    stmt2->output(level);
}

void DeclStmt::output(int level)
{
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    id->output(level + 4);
}

void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    retValue->output(level + 4);
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}

void FunctionDef::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    stmt->output(level + 4);
}
*/
void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4);
}
void ExpStmt::output(int level)
{


    fprintf(yyout, "%*cExpStmt\n", level, ' ');
    expr1->output(level+4);
}
void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case MUL:
            op_str = "mul";
            break;
        case DIV:
            op_str = "div";
            break;
        case MOD:
            op_str = "MOD";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
        case GREATER:
            op_str = "greater";
            break;
        case LESSEQ:
            op_str = "lesseq";
            break;
        case GREATEREQ:
            op_str = "greatereq";
            break;
        case EQUAL:
            op_str = "equal";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

void UnaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case UPLUS:
            op_str = "uplus";
            break;
        case UMINUS:
            op_str = "uminus";
            break;
        case NOT:
            op_str = "not";
            break;
    }
    fprintf(yyout,"%*cUnaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level+4);
}

void FuncUseExpr::output(int level){
    fprintf(yyout,"%*cFuncUseExpr\n",level,' ');
    funcName->output(level+4);
    if(funcRParams!=nullptr) funcRParams->output(level+4);
}

void FuncRParams::output(int level){
    fprintf(yyout,"%*cFunRExpr\n",level,' ');
    expr1->output(level+4);
    funcRParams->output(level+4);
}

void Constant::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}
void PrimaryExp::output(int level)
{
    fprintf(yyout, "%*cPrimaryExp\n", level, ' ');
    expr1->output(level+4);
}

void CompoundStmt::output(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    stmt->output(level + 4);
}

void SeqNode::output(int level)
{
    fprintf(yyout, "%*cSequence\n", level, ' ');
    stmt1->output(level + 4);
    stmt2->output(level + 4);
}

void DeclStmt::output(int level)
{
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    id->output(level + 4);
}

void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void WhileStmt::output(int level){
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    loopStmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    retValue->output(level + 4);
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}

void FunctionDef::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ',
            name.c_str(), type.c_str());
    stmt->output(level + 4);
}

FunctionDef::FunctionDef(SymbolEntry *se, StmtNode *stmt,ParamList pl): se(se), stmt(stmt){
    for(auto i=pl.begin();i!=pl.end();i++){
        paramList.push_back((*i));
    }
}

int BinaryExpr::getValue()
{
    if (op == AND)
    {
        return expr1->getValue() && expr2->getValue();
    }
    else if(op == OR)
    {
        return expr1->getValue() || expr2->getValue();
    }
    else if(op >= LESS && op <= EQUAL)
    {
        int val;
        switch (op)
        {
        case LESS:
            val=expr1->getValue() < expr2->getValue()?1:0;
            break;
        case GREATER:
            val=expr1->getValue() > expr2->getValue()?1:0;
            break;
        case LESSEQ:
            val=expr1->getValue() <= expr2->getValue()?1:0;
            break;
        case GREATEREQ:
            val=expr1->getValue() >= expr2->getValue()?1:0;
            break;
        case NOTEQ:
            val=expr1->getValue() != expr2->getValue()?1:0;
            break;
        case EQUAL:
            val=expr1->getValue() == expr2->getValue()?1:0;
            break;
        }
        return val;
    }
    else if(op >= ADD && op <= MOD)
    {
        int val;
        switch (op)
        {
        case ADD:
            val=expr1->getValue() + expr2->getValue();
            break;
        case SUB:
            val=expr1->getValue() - expr2->getValue();
            break;
        case MUL:
            val=expr1->getValue() * expr2->getValue();
            break;
        case DIV:
            val=expr1->getValue() / expr2->getValue();
            break;
        case MOD:
            val=expr1->getValue() % expr2->getValue();
            break;
        }
        return val;
    }
    return 0;
}


int UnaryExpr::getValue()
{
    if(op == UnaryExpr::UMINUS){
        return -expr1->getValue();
    }else if(op == UnaryExpr::UPLUS){
        return expr1->getValue();
    }else if(op == UnaryExpr::NOT){
        return !expr1->getValue();
    }
    return 0;
}

int PrimaryExp::getValue(){
    return expr1->getValue();
}

int FuncUseExpr::getValue(){
    return 0;
}

int FuncRParams::getValue(){
    return expr1->getValue();
}

int Constant::getValue()
{
    return dynamic_cast<ConstantSymbolEntry*>(symbolEntry)->getValue();
}

int Id::getValue()
{
    return dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getValue();
}