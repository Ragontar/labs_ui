#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget_Graphic->setCurrentIndex(0);
    this->ui->stackedWidget_Input->setCurrentIndex(0);
    this->ui->stackedWidget_Output->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    this->ui->stackedWidget_Graphic->setCurrentIndex(0);
    this->ui->stackedWidget_Input->setCurrentIndex(0);
    this->ui->stackedWidget_Output->setCurrentIndex(0);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    this->ui->stackedWidget_Graphic->setCurrentIndex(1);
    this->ui->stackedWidget_Input->setCurrentIndex(1);
    this->ui->stackedWidget_Output->setCurrentIndex(1);
}

void MainWindow::on_radioButton_3_toggled(bool checked)
{

    this->ui->stackedWidget_Graphic->setCurrentIndex(2);
    this->ui->stackedWidget_Input->setCurrentIndex(2);
    this->ui->stackedWidget_Output->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked() //p1 rand
{
    LEx1* lab = nullptr;
    if(this->ui->entries_LineEdit->text().isEmpty()){
        lab = new LEx1();
    }
    else{
        lab = new LEx1(this->ui->entries_LineEdit->text().toInt());
    }


    QGraphicsScene* scene = new QGraphicsScene;
    QImage image("lab1_hist.png"); //в конструктор - путь
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    this->ui->graphicsView->setScene(scene);

    QString cov, corr, T;
    cov = QString::number(lab->getCov());
    corr = QString::number(lab->getCorr());
    T = QString::number(lab->getT());

    this->ui->cov_lineEdit->setText(cov);
    this->ui->corr_lineEdit->setText(corr);
    this->ui->T_lineEdit->setText(T);

    QString cov_m, corr_m, T_m;
    cov_m = QString::number(lab->getCov_manual());
    corr_m = QString::number(lab->getCorr_manual());
    T_m = QString::number(lab->getT_manual());

    this->ui->cov_manual_lineEdit->setText(cov_m);
    this->ui->corr_manual_lineEdit->setText(corr_m);
    this->ui->T_manual_lineEdit->setText(T_m);

    QMessageBox log;
    double k = lab->getK();
    double b = lab->getB();
    QString results = "k = " + QString::number(k) + "\nb = " +  QString::number(b);
    log.information(0, "Regression line parameters: ", results);
    log.setFixedSize(500,200);

}

void MainWindow::on_pushButton_p2_rand_clicked()
{

    LEx1_p2* lab = nullptr;
    if(this->ui->entries_LineEdit->text().isEmpty()){
        lab = new LEx1_p2();
    }
    else{
        lab = new LEx1_p2(this->ui->entries_LineEdit->text().toInt());
    }

    QGraphicsScene* scene = new QGraphicsScene;
    QImage image("lab2_hist.png"); //в конструктор - путь
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    this->ui->graphicsView_2->setScene(scene);

    QString cov, corr, T;
    cov = QString::number(lab->getCov());
    corr = QString::number(lab->getCorr());
    T = QString::number(lab->getT());

    this->ui->cov_lineEdit_2->setText(cov);
    this->ui->corr_lineEdit_2->setText(corr);
    this->ui->T_lineEdit_2->setText(T);

    QString cov_m, corr_m, T_m;
    cov_m = QString::number(lab->getCov_manual());
    corr_m = QString::number(lab->getCorr_manual());
    T_m = QString::number(lab->getT_manual());

    this->ui->cov_manual_lineEdit->setText(cov_m);
    this->ui->corr_manual_lineEdit->setText(corr_m);
    this->ui->T_manual_lineEdit->setText(T_m);

    QMessageBox log;
    double k = lab->getK();
    double b = lab->getB();
    QString results = "k = " + QString::number(k) + "\nb = " +  QString::number(b);
    log.information(0, "Regression line parameters: ", results);
    log.setFixedSize(500,200);
}

void MainWindow::on_pushButton_p3_rand_clicked()
{
    LEx1_p3* lab = nullptr;
    if(this->ui->entries_LineEdit->text().isEmpty()){
        lab = new LEx1_p3();
    }
    else{
        lab = new LEx1_p3(this->ui->entries_LineEdit->text().toInt());
    }

    QGraphicsScene* scene = new QGraphicsScene;
    QImage image("lab3_hist.png"); //в конструктор - путь
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    this->ui->graphicsView_3->setScene(scene);

    QString cov, corr, T;
    cov = QString::number(lab->getCov());
    corr = QString::number(lab->getCorr());
    T = QString::number(lab->getT());

    this->ui->cov_lineEdit_3->setText(cov);
    this->ui->corr_lineEdit_3->setText(corr);
    this->ui->T_lineEdit_3->setText(T);

    QString cov_m, corr_m, T_m;
    cov_m = QString::number(lab->getCov_manual());
    corr_m = QString::number(lab->getCorr_manual());
    T_m = QString::number(lab->getT_manual());

    this->ui->cov_manual_lineEdit->setText(cov_m);
    this->ui->corr_manual_lineEdit->setText(corr_m);
    this->ui->T_manual_lineEdit->setText(T_m);

    QMessageBox log;
    double k = lab->getK();
    double b = lab->getB();
    QString results = "k = " + QString::number(k) + "\nb = " +  QString::number(b);
    log.information(0, "Regression line parameters: ", results);
    log.setFixedSize(500,200);
}

void MainWindow::on_pushButton_clicked()
{
    QString str_x, str_y;
    QList<double> xData, yData;

    str_x = this->ui->lineEdit_p1_x->text();
    str_y = this->ui->lineEdit_p1_y->text();
    xData = qStrToQList(str_x);
    yData = qStrToQList(str_y);

    if(xData.size() == yData.size()){
        LEx1* lab = new LEx1(xData, yData, "lab1_hist");

        QGraphicsScene* scene = new QGraphicsScene;
        QImage image("lab1_hist.png"); //в конструктор - путь
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        this->ui->graphicsView->setScene(scene);

        QString cov, corr, T;
        cov = QString::number(lab->getCov());
        corr = QString::number(lab->getCorr());
        T = QString::number(lab->getT());

        this->ui->cov_lineEdit->setText(cov);
        this->ui->corr_lineEdit->setText(corr);
        this->ui->T_lineEdit->setText(T);
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is incorrect!");
        messageBox.setFixedSize(500,200);
        return;
    }

}

void MainWindow::on_pushButton_p2_input_clicked()
{
    QString str_x, str_y;
    QList<double> xData;

    str_x = this->ui->lineEdit_p2_x->text();
    xData = qStrToQList(str_x);

    LEx1_p2* lab = new LEx1_p2(xData, "lab2_hist");

    QGraphicsScene* scene = new QGraphicsScene;
    QImage image("lab2_hist.png"); //в конструктор - путь
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    this->ui->graphicsView_2->setScene(scene);

    QString cov, corr, T;
    cov = QString::number(lab->getCov());
    corr = QString::number(lab->getCorr());
    T = QString::number(lab->getT());

    this->ui->cov_lineEdit_2->setText(cov);
    this->ui->corr_lineEdit_2->setText(corr);
    this->ui->T_lineEdit_2->setText(T);

    for(int i=0; i<xData.size(); i++){
        str_y+=QString::number(-5*xData[i]+0.6);

        if(i!=xData.size()-1){
            str_y+=", ";
        }
    }

    this->ui->lineEdit_p2_y->setText(str_y);
}

void MainWindow::on_pushButton_p3_input_clicked()
{
    QString str_x, str_z;
    QList<double> xData, zData;

    str_x = this->ui->lineEdit_p3_x->text();
    str_z = this->ui->lineEdit_p3_z->text();
    xData = qStrToQList(str_x);
    zData = qStrToQList(str_z);

    if(xData.size() == zData.size()){
        LEx1_p3* lab = new LEx1_p3(xData, zData, "lab3_hist");

        QGraphicsScene* scene = new QGraphicsScene;
        QImage image("lab3_hist.png"); //в конструктор - путь
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        this->ui->graphicsView_3->setScene(scene);

        QString cov, corr, T;
        cov = QString::number(lab->getCov());
        corr = QString::number(lab->getCorr());
        T = QString::number(lab->getT());

        this->ui->cov_lineEdit_3->setText(cov);
        this->ui->corr_lineEdit_3->setText(corr);
        this->ui->T_lineEdit_3->setText(T);
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Data set is incorrect!");
        messageBox.setFixedSize(500,200);
        return;
    }
}
