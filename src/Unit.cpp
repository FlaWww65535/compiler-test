#include "Unit.h"
#include "Type.h"
extern FILE* yyout;

void Unit::insertFunc(Function *f)
{
    func_list.push_back(f);
}

void Unit::removeFunc(Function *func)
{
    func_list.erase(std::find(func_list.begin(), func_list.end(), func));
}

void Unit::insertGlobal(IdentifierSymbolEntry *se)
{
    global_list.push_back(se);
}

void Unit::removeGlobal(IdentifierSymbolEntry *se)
{
    global_list.erase(std::find(global_list.begin(), global_list.end(), se));
}


void Unit::output() const
{

    
    for (auto &v : global_list)
    {
        fprintf(yyout,"@%s = dso_local global %s %d, align 4\n",v->getName().c_str(),v->getType()->toStr().c_str(),v->getValue());
    }
    for (auto &func : func_list)
        func->output();
    
    fprintf(yyout,"declare i32 @getint(...) #1\n");
    fprintf(yyout,"declare i32 @putint(...) #1\n");
    fprintf(yyout,"declare i32 @getch(...) #1\n");
    fprintf(yyout,"declare i32 @putch(...) #1\n");
}

void Unit::genMachineCode(MachineUnit* munit) 
{
    munit->SetUnit(this);
    for (auto v : global_list)
    {
        munit->insertGlobal(v);
    }
    AsmBuilder* builder = new AsmBuilder();
    builder->setUnit(munit);
    for (auto &func : func_list)
        func->genMachineCode(builder);
}

Unit::~Unit()
{
    for(auto &func:func_list)
        delete func;

}
