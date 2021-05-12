#ifndef COMPANYREG_H
#define COMPANYREG_H
#include "Company.h"
#include <QList>

class CompReg
{
private:
    QList<Company*> CompList;
    CompReg();
public:
    ~CompReg();
    CompReg(const CompReg&) = delete;
    void AddCompany(Company& comp);
    void DelCompany(int index);
    Company* getCompanyIndex(int index);
    int getRegSize();
    static CompReg& getReg();
};

#endif
