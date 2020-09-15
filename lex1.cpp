#include "lex1.h"

LEx1::LEx1()
{

}

LEx1::LEx1(QList<double> x, QList<double> y, TString name)
{
    /*
     * Задает датасет, имя гистограммы и инициализирует ее LHistCreator2D*.
     * Считает ковариацию, коэфф. корреляции, t-критерий.
     * Считает коэффициенты через МНК.
     * Сохраняет гистограмму как .png в корневую директорию
     */
    this->setData(x, y);
    this->hist_name = name;
    this->initHistCreator();
    this->getCov();
    this->getCorr();
    this->getT();
    this->MNK();
    this->printRegLine();
    this->printHist();

}

void LEx1::setData(QList<double> x, QList<double> y)
{
    this->x = x;
    this->y = y;
}

QList<double> LEx1::getX()
{
    return x;
}

QList<double> LEx1::getY()
{
    return y;
}

double LEx1::getCov()
{
    this->cov = this->hist->GetHist()->GetCovariance();
    return cov;
}

double LEx1::getCorr()
{
    double sx = this->hist->GetHist()->GetStdDev(1);
    double sy = this->hist->GetHist()->GetStdDev(2);
    this->corr = this->cov/(sx*sy);
    return this->corr;
}

double LEx1::getT()
{
    this->T = this->corr*sqrt(this->x.size()-2)/sqrt(1-this->corr*this->corr);
    return this->T;
}

void LEx1::generateX(int n)
{
    srand(time(0));
    for(int i=0; i<n; i++){
        this->x[i] = ((double)rand()/(double)RAND_MAX)*10;
    }
}

void LEx1::generateY(int n)
{
    srand(time(0));
    for(int i=0; i<n; i++){
        this->y[i] = ((double)rand()/(double)RAND_MAX)*10;
    }
}

void LEx1::initHistCreator()
{
    //Заполнение и рисование гистограммы на канвасе
    this->hist = new LHistCreator2D(this->x, this->y, hist_name);
}

QList<double> LEx1::MNK()
{
    double xx=0, x=0, xy=0, y=0;
    for(int i=0; i<this->x.size(); i++){
        xx+=this->x[i]*this->x[i];
        x+=this->x[i];
        xy+=this->x[i]*this->y[i];
        y+=this->y[i];
    }
    double n = this->x.size();

    double det;
    const double data[2][2] = {{xx, x}, {x, n}};
    const double bdata[2][1] = {{xy}, {y}};

    TMatrixD* A = new TMatrixD(2,2);
    TMatrixD* B = new TMatrixD(2, 1);
    TMatrixD* res = new TMatrixD(1, 2);

    A->SetMatrixArray(*data, "");
    B->SetMatrixArray(*bdata, "");

    const TMatrixD Ac = A->Invert(&det);

    res->Mult(Ac, *B);

    this->k = res->GetMatrixArray()[0];
    this->b = res->GetMatrixArray()[1];

    QList<double> result = {res->GetMatrixArray()[0],res->GetMatrixArray()[1]};
    return result;
}

void LEx1::printRegLine()
{
    double x[this->x.size()];
    double mnk_y[this->x.size()];
    std::cout << "\n\n";
    for(int i=0; i<this->x.size(); i++){
        mnk_y[i] = this->k*this->x[i] + this->b;
        x[i] = this->x[i];

        std::cout << "(" << x[i] << "; " << mnk_y[i] << ")\n";
    }
    this->regLine = new TGraph(this->x.size(), x, mnk_y);
    this->regLine->SetLineColor(4);
    this->regLine->SetLineWidth(4);
    this->regLine->SetMarkerColor(4);
    this->regLine->SetMarkerSize(1);
    this->regLine->SetMarkerStyle(21);

    TCanvas* canv = hist->GetCanvas();
    this->regLine->Draw("same");

    this->hist->SetCanvas(canv);
}

void LEx1::printHist()
{
    this->hist->SaveHist();
}

