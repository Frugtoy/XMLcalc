#include "xmlparser.h"

xmlparser::xmlparser(){}
xmlparser::~xmlparser(){}
QVector<int>xmlparser::parse(const Qstring &path){
    QVector<int>result;
    QFile*file = new Qfile(path);
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::logic_error("pleace check a path of file");
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
                switch (tag.name()) {
                    case "sum": {
                        result.push_back(0);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(sum(attributes.value("arg1").toInt(),attributes.value("arg2").toInt());
                        break;
                    }
                     case "diff": {
                        result.push_back(1);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(sum(attributes.value("arg1").toInt(),attributes.value("arg2").toInt());
                        break;
                     }
                     case "div": {
                        result.push_back(2);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(sum(attributes.value("arg1").toInt(),attributes.value("arg2").toInt());
                        break;
                     }

                     case "mult": {
                        result.push_back(3);
                        result.push_back(attributes.value("arg1").toInt());
                        result.push_back(attributes.value("arg2").toInt());
                        result.push_back(sum(attributes.value("arg1").toInt(),attributes.value("arg2").toInt());
                     break;
                     }
                }
           }
       }


    file->close();
    return result;
}
}

void xmlparser::write(const QString& path, QVector<int> result) {

    QFile* file =new QFile(path);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
            throw std::logic_error("cannot find a path of file");

    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("respnse");

    for(int i =0;i<result.size();i+=4) {
        switch(result[i]) {
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
