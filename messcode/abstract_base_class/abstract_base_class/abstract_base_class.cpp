//
//  abstract_base_class.cpp
//  abstract_base_class
//
//  Created by matthew on 2017/8/12.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <stdio.h>
#include "ACCTABC.h"
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ios_base;
AcctABC::AcctABC(const string &s,long an,double bal)
{
    fullName=s;
    acctNum=an;
    balance=bal;
}
void AcctABC::Deposit(double amt)
{
    if(amt<0)
        cout<<"something must be wrong"<<endl;
    else
        balance+=amt;
}
void AcctABC::withdraw(double amt)
{
    balance-=amt;
}
AcctABC::Formatting AcctABC::SetFormat()const
{
    Formatting f;
    f.flag=cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr=cout.precision(2);
    return f;
}
void AcctABC::Restore(Formatting &f)const
{
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}
void Brass::withdraw(double amt)
{
    if(amt<0)
        cout<<"something must be wrong"<<endl;
    else if(amt<=Balance())
        AcctABC::withdraw(amt);
    else
        cout<<"cancelled"<<endl;
}
void Brass::ViewAcct()const
{
    Formatting f=SetFormat();
    cout<<"Brass client: "<<FullName()<<endl;
    cout<<"Account Number: "<<AcctNum()<<endl;
    cout<<"Balacne: "<<Balance()<<endl;
    Restore(f);
}
BrassPlus::BrassPlus(const string &s,long an,double bal,double ml,double r) : AcctABC(s,an,bal)
{
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}
BrassPlus::BrassPlus(const Brass &ba,double ml,double r) : AcctABC(ba)
{
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}
void BrassPlus::ViewAcct() const
{
    Formatting
}

