#include "Company.h"

Company::Company(QString &Name, QList<QString> &Owners, double Income, double Area, int EmpNumber)
{
    CompanyName = Name;
    CompanyOwners = Owners;
    CompanyIncome = Income;
    CompanyArea = Area;
    EmployeesNumber = EmpNumber;
}

Company::~Company() {}

QString Company::getCompName()
{
    return CompanyName;
}

QList<QString> Company::getCompOwners()
{
    return CompanyOwners;
}

double Company::getCompIncome()
{
    return CompanyIncome;
}

double Company::getCompArea()
{
    return CompanyArea;
}

int Company::getEmployeesNumber()
{
    return EmployeesNumber;
}
void Company::setName(QString Name_)
{
    CompanyName = Name_;
}

void Company::setOwners(QList<QString> Owners_)
{
    CompanyOwners = Owners_;
}
void Company::setRevenue(double Income_)
{
    CompanyIncome = Income_;
}
void Company::setArea(double Area_)
{
    CompanyArea = Area_;
}

void Company::setEmployeesNumber(int EmpNumber_)
{
    EmployeesNumber = EmpNumber_;
}
