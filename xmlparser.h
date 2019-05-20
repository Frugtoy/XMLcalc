#ifndef XMLPARSER_H
#define XMLPARSER_H
#include"calculator.h"
#include<QFile>
#include<QXmlStreamReader>
#include<QXmlStreamWriter>
#include<exception>
#include "calculator.h"
class xmlparser : public calculator
{
public:

    xmlparser();
   ~xmlparser();

    QVector<double>parse(const QString &path)override;
    void write(const QString &path, QVector<double>result)override;
};

#endif // XMLPARSER_H
