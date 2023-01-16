#ifndef __AST_H__
#define __AST_H__

#include <fstream>
#include <vector>
#include "Operand.h"
#include "Type.h"

class SymbolEntry;
class Unit;
class Function;
class BasicBlock;
class Instruction;
class IRBuilder;
class Type;
//bool if_in_cond=false;
class Node
{
private:
    static int counter;
    int seq;
protected:
    std::vector<Instruction*> true_list;
    std::vector<Instruction*> false_list;
    static IRBuilder *builder;
    void backPatch(std::vector<Instruction*> &list, BasicBlock*bb);
    std::vector<Instruction*> merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2);

public:
    Node();
    int getSeq() const {return seq;};
    static void setIRBuilder(IRBuilder*ib) {builder = ib;};
    virtual void output(int level) = 0;
    virtual void typeCheck() = 0;
    virtual void genCode() = 0;
    std::vector<Instruction*>& trueList() {return true_list;}
    std::vector<Instruction*>& falseList() {return false_list;}
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry;
    Operand *dst;   // The result of the subtree is stored into dst.
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
    Operand* getOperand() {return dst;};
    SymbolEntry* getSymPtr() {return symbolEntry;};
    //for global var
    virtual int getValue() = 0;
    virtual bool isRParam(){return false;}
};

class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {ADD, SUB, MUL,DIV,MOD,AND, OR, LESS,GREATER,LESSEQ,GREATEREQ,NOTEQ,EQUAL};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};
class UnaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1;
public:
    enum {UMINUS,UPLUS,NOT};
    UnaryExpr(SymbolEntry *se, int op, ExprNode*expr1) : ExprNode(se),op(op),expr1(expr1){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};
class PrimaryExp : public ExprNode
{
private :
     ExprNode *expr1;
public :
    PrimaryExp(SymbolEntry *se,ExprNode* expr1):ExprNode(se),expr1(expr1){};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};

class FuncUseExpr : public ExprNode
{
private:
    ExprNode *funcName,*funcRParams;
public:
    FuncUseExpr(SymbolEntry *se, ExprNode*funcName, ExprNode* funcRParams):  ExprNode(se),funcName(funcName), funcRParams(funcRParams){dst = new Operand(se);};
    FuncUseExpr(SymbolEntry *se, ExprNode*funcName): ExprNode(se),funcName(funcName),funcRParams(nullptr){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};

class FuncRParams: public ExprNode
{
private:
    ExprNode *expr1,* funcRParams;
public:
    FuncRParams(SymbolEntry *se,ExprNode *expr1,ExprNode* funcRParams): ExprNode(se),expr1(expr1),funcRParams(funcRParams){};
    void output(int level);
    ExprNode *getFirst() const {return expr1;};
    ExprNode *getNext() const {return funcRParams;};
    void typeCheck();
    void genCode();
    int getValue();
    bool isRParam(){return true;}
};

class Constant : public ExprNode
{
public:
    Constant(SymbolEntry *se) : ExprNode(se){dst = new Operand(se);};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se) : ExprNode(se){SymbolEntry *temp = new TemporarySymbolEntry(se->getType(), SymbolTable::getLabel()); dst = new Operand(temp);};
    void output(int level);
    void typeCheck();
    void genCode();
    int getValue();
};

class StmtNode : public Node
{};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
public:
    CompoundStmt(StmtNode *stmt) : stmt(stmt) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
public:
    SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class DeclStmt : public StmtNode
{
private:
    Id *id;
public:
    DeclStmt(Id *id) : id(id){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    StmtNode *elseStmt;
public:
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class WhileStmt : public StmtNode
{
private:
	ExprNode *cond;
	StmtNode *loopStmt;
public:
	WhileStmt(ExprNode *cond,StmtNode *loopStmt):cond(cond),loopStmt(loopStmt){};
	void output(int level);
    void typeCheck();
    void genCode();
};

class ReturnStmt : public StmtNode
{
private:
    ExprNode *retValue;
public:
    ReturnStmt(ExprNode*retValue) : retValue(retValue) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class ExpStmt : public StmtNode
{

private:
    ExprNode *expr1;
public :
    ExpStmt(ExprNode* expr1): expr1(expr1){};
    void output(int level);
    void typeCheck();
    void genCode();
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
    void typeCheck();
    void genCode();
};

class EmptyStmt : public StmtNode
{
public:
    EmptyStmt(){}
    void output(int level){};
    void typeCheck(){};
    void genCode(){};
};

class IDListElement
{
private:
	std::string name;
	ExprNode* val;
public:
	IDListElement(std::string name,ExprNode* val):name(name),val(val){}
	bool isInit()const {return val!=nullptr;}
	std::string getName()const {return name;}
	ExprNode* getExpr()const {return val;}
	void typeCheck();
    void genCode();
};

class IDList
{
public:
	std::vector<IDListElement *> list;
	void insert(IDListElement *s){list.push_back(s);}
};

class FunctionDef : public StmtNode
{
    typedef std::vector<std::pair<Type*,std::string>> ParamList;
    typedef std::vector<IdentifierSymbolEntry*> SEList;
private:
    SymbolEntry *se;
    StmtNode *stmt;
    ParamList paramList;

public:
    FunctionDef(SymbolEntry *se, StmtNode *stmt,ParamList pl);
    void output(int level);
    void typeCheck();
    void genCode();
    SEList seList;
};

class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
    void typeCheck();
    void genCode(Unit *unit);
};

#endif
