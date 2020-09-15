#ifndef LEX1_P2_H
#define LEX1_P2_H
#include "lex1.h"

class LEx1_p2 : public LEx1
{
public:
    LEx1_p2();
    LEx1_p2(QList<double>, TString);
    void generateY(int);
};

#endif // LEX1_P2_H
