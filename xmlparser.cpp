#include "xmlparser.h"

xmlparser::xmlparser(){}
xmlparser::~xmlparser(){}
QVector<double>xmlparser::parse(const QString &path){
    QVector<double>result;
    QFile*file = new QFile(path);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::logic_error("please check a path of file");
    }
    QXmlStreamReader tag(file);
    while (!tag.atEnd() && !tag.hasError()) {
        
        QXmlStreamReader::TokenType token = tag.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if(token == QXmlStreamReader::StartElement) {
            if(tag.name()=="request")
             continue;

            QXmlStreamAttributes attributes = tag.attributes();
            if(attributes.hasAttribute("arg1")&&attributes.hasAttribute("arg2")) {

                if (tag.name() == "sum")
                {
                        result.push_back(0);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(sum(attributes.value("arg1").toInt(),attributes.value("arg2").toInt()));

                 }
                if (tag.name() =="diff") {
                        result.push_back(1);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(diff(attributes.value("arg1").toInt(),attributes.value("arg2").toInt()));

                 }
                     if (tag.name() == "div") {
                        result.push_back(2);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(div(attributes.value("arg1").toInt(),attributes.value("arg2").toInt()));

                     }

                     if (tag.name() == "mult") {
                        result.push_back(3);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(mult(attributes.value("arg1").toInt(),attributes.value("arg2").toInt()));

                     }
                }
           }
       }


    file->close();
    return result;
}


void xmlparser::write(const QString& path, QVector<double> result) {

    QFile* file =new QFile(path);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
            throw std::logic_error("cannot find a path of file");

    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("response");

    for(int i =0;i<result.size();i+=4) {
        switch(static_cast<int>(result[i])) {
            case 0: {
                xml.writeStartElement("sum");
                break;
            }
            case 1: {
                xml.writeStartElement("diff");
                break;
            }
            case 2: {
                xml.writeStartElement("div");
                break;
            }
            case 3: {
                xml.writeStartElement("mult");
                break;
            }
        }

        xml.writeAttribute("arg1",QString::number(result[i+1]));
        xml.writeAttribute("arg2",QString::number(result[i+2]));
        xml.writeAttribute("result",QString::number(result[i+3]));
        xml.writeEndElement();
    }
    xml.writeEndElement();
    file->close();
}
