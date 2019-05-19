#ifndef XMLPARSER_H
#define XMLPARSER_H
#include"calculator.h"
#include<QFile>
#include<QXmlStreamReader>
#include<QXmlStreamWriter>
#include<exception>

class xmlparser : public calculator
{
public:

    xmlparser();
   ~xmlparser();

    QVector<int>parse(const QString &path)override;
    void write(const QString &path, QVector<int>result)override;
};

#endif // XMLPARSER_H
