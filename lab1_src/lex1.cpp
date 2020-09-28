#include "lex1.h"

LEx1::LEx1()
{
    //const int N = 10;
    this->generateX(N);
    this->generateY(N);
    this->hist_name = "lab1_hist";
    this->initHistCreator();
    this->getCov();
    this->getCorr();
    this->getT();
    this->MNK();
    this->printRegLine();
    this->printHist();

}

LEx1::LEx1(int n)
{
    this->setN(n);
    this->generateX(N);
    this->generateY(N);
    this->hist_name = "lab1_hist";
    this->initHistCreator();
    this->getCov();
    this->getCorr();
    this->getT();
    this->MNK();
    this->printRegLine();
    this->printHist();
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

void LEx1::setN(int n)
{
    this->N = n;
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

double LEx1::getCov_manual()
{
    this->cov_m = 0;
    double x_avg, y_avg;
    x_avg = this->avg(x);
    y_avg = this->avg(y);

    for(int i = 0; i < x.size(); i++) this->cov_m += (y[i] - y_avg)*(x[i] - x_avg);
    return cov_m/x.size();
}

double LEx1::getCorr_manual()
{
    corr_m = 0;
    double sigma_x = this->sigma(x);
    double sigma_y = this->sigma(y);
    corr_m = cov_m/(sigma_x*sigma_y);
    return corr_m;
}

double LEx1::getT_manual()
{
    this->T_m = this->corr_m*sqrt(this->x.size()-2)/sqrt(1-this->corr_m*this->corr_m);
    return this->T_m;
}

double LEx1::getK()
{
    return k;
}

double LEx1::getB()
{
    return b;
}

double LEx1::avg(QList<double> x)
{
    double avg = 0;
    for(int i = 0; i < x.size(); i++) avg += x[i];
    return avg/x.size();
}

double LEx1::sigma(QList<double> x)
{
    double x_avg = this->avg(x);
    double sigma = 0;
    for(int i = 0; i < x.size(); i++) sigma += (x[i] - x_avg)*(x[i] - x_avg);
    return sqrt(sigma);
}

void LEx1::generateX(int n)
{
    this->x.clear();
    sleep(1);
    srand(time(0));
    for(int i=0; i<n; i++){
        this->x.append(((double)rand()/(double)RAND_MAX)*10);
        //this->x[i] = ((double)rand()/(double)RAND_MAX)*10;
    }
}

void LEx1::generateY(int n)
{
    this->y.clear();
    sleep(1);
    srand(time(0));
    for(int i=0; i<n; i++){
        this->y.append(((double)rand()/(double)RAND_MAX)*10);
        //this->y[i] = ((double)rand()/(double)RAND_MAX)*10;
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

