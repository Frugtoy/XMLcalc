#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"calculator.h"
#include<QString>
#include<QVector>

class calculator
{
public:
    calculator();
    virtual void write (const QString& path , QVector<double>result)=0;
    virtual QVector<double> parse (const QString& path )=0;
   ~calculator();
protected:
    virtual float div( int first_digit , int second_digit);
    virtual int sum(int first_digit , int second_digit);
    virtual int mult(int first_digit , int second_digit);
    virtual int diff(int first_digit , int second_digit);
};

#endif // CALCULATOR_H
