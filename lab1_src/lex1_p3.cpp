#include "lex1_p3.h"

LEx1_p3::LEx1_p3()
{

}

LEx1_p3::LEx1_p3(QList<double> xData, QList<double> zData, TString name)
{
    /*
     * Задает датасет, имя гистограммы, считает Y, и инициализирует ее LHistCreator2D*.
     * Считает ковариацию, коэфф. корреляции, t-критерий.
     * Считает коэффициенты через МНК.
     * Сохраняет гистограмму как .png в корневую директорию
     */
    this->x = xData;

    this->z = zData; //вернуть, нижнюю - удалить
    //this->generateZ(xData.size());

    this->hist_name = name;
    this->generateY();
    this->initHistCreator();
    this->getCov();
    this->getCorr();
    this->getT();
    this->MNK();
    this->printRegLine();
    this->printHist();
}

void LEx1_p3::generateZ(int n)
{
    this->z.clear();
    srand(time(0));
    for(int i=0; i<n; i++){
        this->z.append(((double)rand()/(double)RAND_MAX)*10);
    }
}

void LEx1_p3::generateY()
{
    //Y=Z*X
    this->y.clear();
    for(int i=0; i<this->x.size(); i++){
        this->y.append(this->z[i]*this->x[i]);
    }
}
