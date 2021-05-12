#include <QTextStream>
#include <QCoreApplication>
#include "CompanyTypes.h"
#include "CompanyReg.h"

//1.Вывести на консоль информацию о предприятиях определённого типа.
QTextStream cout(stdout);
QTextStream cin(stdin);
CompReg& Reg = CompReg::getReg();

void TypeInfo(Company::type flag)
{
    switch (flag)
    {
    case Company::type::Governmental: cout << "Governmental companies: "; break;
    case Company::type::International: cout << "International companies: "; break;
    case Company::type::General: cout << "General companies: "; break;
    }
    cout << Qt::endl;
    for (int k = 0; k < Reg.getRegSize(); k++)
    {
        if (Reg.getCompanyIndex(k) -> getCompType() == flag)
        {
            cout << Reg.getCompanyIndex(k) -> getCompName() << Qt::endl;
        }
    }
}

//2.Вывести на консоль все предприятия, принадлежащие определённому владельцу.
void OwnersCompanies(QString own)
{
    cout << own << " companies: "<< Qt::endl;
    for (int k = 0; k < Reg.getRegSize(); k++)
    {
        if(Reg.getCompanyIndex(k) -> getCompOwners().contains(own))
        {
            cout << Reg.getCompanyIndex(k) -> getCompName() << Qt::endl;
        }
    }
}
//3.Вывести на консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.
void CompaniesInfo() // Название предприятия по типу
{
    for(int k = Company::Governmental; k <= Company::General; k++)
    {
        int count = 0;
        double AvergeIncome = 0;
        double AverageArea = 0;
        double AverageNumber = 0;

        switch (k)
        {
        case Company::Governmental: cout << "Governmental companies info: "; break;
        case Company::International: cout << "International companies info: "; break;
        case Company::type::General: cout << "General companies info: "; break;
        }
        cout << Qt::endl;
        for (int kk = 0; kk < Reg.getRegSize(); kk++)
        {
            if (k == Reg.getCompanyIndex(kk) -> getCompType())
            {
                AvergeIncome += Reg.getCompanyIndex(kk) -> getCompIncome();
                AverageArea += Reg.getCompanyIndex(kk) -> getCompArea();
                AverageNumber += Reg.getCompanyIndex(kk) -> getEmployeesNumber();
                count++;
            }
        }
        cout << "Average Income = " << AvergeIncome / count << Qt::endl;
        cout << "Average Area = " << AverageArea / count << Qt::endl;
        cout << "Average Employees number = " << AverageNumber / count << Qt::endl;
        cout << Qt::endl;
    }
}

int main(int argc, char *argv[])
{
      QCoreApplication a(argc, argv);
      QList<QString> Ow, Oww, Owww, Aw, Aww;

      QString M = "Gazprom";
      Ow << "Zubkov Viktor";
      Company* gaz = new Governmental(M, Ow, 162000000000, 466000, 30000);

      QString Mm = "Philip Morris International";
      Oww << "Andre Calantzopoulos";
      Company* sig = new International(Mm, Oww, 7728000000, 91000, 2137);

      QString Mmm = "Bentley Motors";
      Owww << "Franz-Josef Paefgen";
      Company* car = new General(Mmm, Owww, 1030000000, 3726, 1660);

      QString N = "Megafon";
      Aw << "Vladimir Streshinsky";
      Company* meg = new Governmental(N, Aw, 337000000, 25000, 9000);

      QString Nn = "Adidas";
      Aww << "Rupert Campbell";
      Company* ad = new International(Nn, Aww, 1702000000, 57016, 12000);

      Reg.AddCompany(*gaz);
      Reg.AddCompany(*sig);
      Reg.AddCompany(*car);
      Reg.AddCompany(*meg);
      Reg.AddCompany(*ad);
      cout << "Choose company type" << Qt::endl;
      int k;
      cin >> k;
      TypeInfo(Company::type(k));
      cout << Qt::endl;
      OwnersCompanies("Andre Calantzopoulos");
      cout << Qt::endl;
      CompaniesInfo();
      return a.exec();
}
