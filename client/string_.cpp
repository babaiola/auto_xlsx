#include "string_.h"

String_::String_()
{
}


QString String_::shs(const char* point, const char* dimension, const char* rotation, QString text){
    QString string1 = "STR(command \"_text\" \"";
    string1.append(point);
    string1.append("\" \"");
    string1.append(dimension);
    string1.append("\" \"");
    string1.append(rotation);
    string1.append("\" \"");
    string1.append(text);
    string1.append("\" ) ");
    return string1;
}

QString String_::shs(const char* point, const char* dimension, const char* rotation, QString text, const char *justify){
    QString string1 = "STR(command \"_text\" \"_justify\" \"";
    string1.append(justify);
    string1.append("\" \"");
    string1.append(point);
    string1.append("\" \"");
    string1.append(dimension);
    string1.append("\" \"");
    string1.append(rotation);
    string1.append("\" \"");
    string1.append(text);
    string1.append("\" ) ");
    return string1;
}
