#ifndef COMPANYTYPES_H
#define COMPANYTYPES_H
#include "Company.h"


class Governmental : public Company
{
public:
    Governmental(QString &Name, QList<QString> &Owners, double Income, double Area, int EmpNumber);
    type getCompType();
    double getCompTax();
};

class International : public Company
{
public:
    International(QString &Name, QList<QString> &Owners, double Income, double Area, int EmpNumber);
    type getCompType();
    double getCompTax();
};

class General : public Company
{
public:
    General(QString &Name, QList<QString> &Owners, double Income, double Area, int EmpNumber);
    type getCompType();
    double getCompTax();
};
#endif
