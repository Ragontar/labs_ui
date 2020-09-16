#include "lex1_p2.h"


LEx1_p2::LEx1_p2()
{

}

LEx1_p2::LEx1_p2(QList<double> xData, TString name)
{
    /*
     * Задает датасет, имя гистограммы, считает Y, и инициализирует ее LHistCreator2D*.
     * Считает ковариацию, коэфф. корреляции, t-критерий.
     * Считает коэффициенты через МНК.
     * Сохраняет гистограмму как .png в корневую директорию
     */
    this->x = xData;
    this->hist_name = name;
    this->generateY(this->x.size());
    this->initHistCreator();
    this->getCov();
    this->getCorr();
    this->getT();
    this->MNK();
    this->printRegLine();
    this->printHist();
}

void LEx1_p2::generateY(int n)
{
    this->y.clear();
    for(int i=0; i<n; i++){
        y.append(-5.0*this->x[i]+0.6);
    }

}
