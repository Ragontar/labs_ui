#ifndef LEX1_H
#define LEX1_H
#include "includes.h"
#include "lhistcreator2d.h"

class LEx1
{
protected:
    QList<double> x, y;
    double k, b;
    double corr, cov, T;
    double corr_m, cov_m, T_m;
    LHistCreator2D* hist;
    TString hist_name = "";
    TGraph* regLine;
    int N=10; //Number of entries for rand-gen

public:
    LEx1();
    LEx1(int);
    LEx1(QList<double>, QList<double>, TString); //Constructor with dataset and initial calculations
    void setData(QList<double>, QList<double>);
    void setN(int);
    QList<double> getX();
    QList<double> getY();
    double getCov(); //Calculates and returns covXY
    double getCorr(); //Calculates and returns corrXY
    double getT(); //Calculates and returns T
    double getCov_manual();
    double getCorr_manual();
    double getT_manual();
    double getK();
    double getB();
    double avg(QList<double>);
    double sigma(QList<double>);
    void generateX(int); //Args: number of random elements
    void generateY(int);
    void initHistCreator(); //Initialize LHistCreator2D* member
    QList<double> MNK(); //Calculates and returns (k, b)
    void printRegLine(); //Prints regression line on canvas
    void printHist(); //Print to root dir
    void printHist(TString, TString); //Prints histo. Args: path and filename

};

#endif // LEX1_H
