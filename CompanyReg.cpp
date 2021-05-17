#include "CompanyReg.h"

CompReg::CompReg()
{}

CompReg::~CompReg()
{
    while(!CompList.empty())
    {
        delete CompList.takeFirst();
    }
}

void CompReg::AddCompany(Company& Company)
{
    CompList.append(&Company);
}

void CompReg::DelCompany(int index)
{
    if(!CompList.empty())
    {
       delete CompList.at(index);
       CompList.takeAt(index);
    }
}

Company* CompReg::getCompanyIndex(int index)
{
    return CompList.at(index);
}

int CompReg::getRegSize()
{
    return CompList.size();
}

CompReg& CompReg::getReg()
{
    static CompReg Reg;
    return Reg;
}
