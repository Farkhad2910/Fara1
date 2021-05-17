#include "Company.h"
#include "CompanyTypes.h"

Governmental::Governmental(QString Name, QList<QString> Owners, double Income, double Area, int EmpNumber):
    Company(Name, Owners, Income, Area, EmpNumber)
{
}

Company::type Governmental::getCompType()
{
    return type::Governmental;
}

double Governmental::getCompTax()
{
    double GoverIncome = (getCompIncome()*0.05 + getCompIncome()*0.03)/(getCompIncome()*0.02);
    return GoverIncome;
}

International::International(QString Name, QList<QString> Owners, double Income, double Area, int EmpNumber):
    Company(Name, Owners, Income, Area, EmpNumber)
{
}

Company::type International::getCompType()
{
    return type::International;
}

double International::getCompTax()
{
    double IntIncome = getCompIncome()*0.04*getCompIncome()*0.03/getCompIncome()*0.05;
    return IntIncome;
}


General::General(QString Name, QList<QString> Owners, double Income, double Area, int EmpNumber):
    Company(Name, Owners, Income, Area, EmpNumber)
{
}

Company::type General::getCompType()
{
    return type::General;
}

double General::getCompTax()
{
    double GenIncome = (getCompIncome()*0.5+getCompIncome()*0.4)/2;
    return GenIncome;
}


