#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGlobal>
#include <QtWidgets>
#include <lab1_src/lex1.h>
#include <lab1_src/lex1_p2.h>
#include <lab1_src/lex1_p3.h>
#include "lab1_src/etc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_p2_rand_clicked();

    void on_pushButton_p3_rand_clicked();

    void on_pushButton_clicked();

    void on_pushButton_p2_input_clicked();

    void on_pushButton_p3_input_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
