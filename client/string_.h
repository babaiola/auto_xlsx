#ifndef STRING__H
#define STRING__H

#include <QString>

class String_
{
public:
    String_();


    QString shs(const char* point, const char* dimension, const char* rotation, QString text, const char *justify);
    QString shs(const char* point, const char* dimension, const char* rotation, QString text);
};

#endif // STRING__H
