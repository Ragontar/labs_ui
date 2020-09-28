#ifndef LEX1_P3_H
#define LEX1_P3_H
#include "lex1.h"


class LEx1_p3 : public LEx1
{
private:
    QList<double> z;
public:
    LEx1_p3();
    LEx1_p3(int);
    LEx1_p3(QList<double>, QList<double>, TString); //Args: X, Z, hist_name
    void generateZ(int);
    void generateY();

};

#endif // LEX1_P3_H
