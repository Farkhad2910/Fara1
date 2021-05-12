#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include <QList>

class Company
{
private:
    QString CompanyName;
    QList<QString> CompanyOwners;
    double CompanyIncome;
    double CompanyArea;
    int EmployeesNumber;
public:
    enum type
    {
        Governmental,
        International,
        General
    };
    void setName(QString Name_);
    void setOwners(QList<QString> Owners_);
    void setRevenue(double Income_);
    void setArea(double Area_);
    void setEmployeesNumber(int EmpNumber_);
    Company(QString &Name, QList<QString> &Owners, double Income, double Area, int EmpNumber);
    virtual ~Company();
    virtual type getCompType() = 0;
    virtual double getCompTax() = 0;
    QString getCompName();
    QList<QString> getCompOwners();
    double getCompIncome();
    double getCompArea();
    int getEmployeesNumber();
};

#endif



