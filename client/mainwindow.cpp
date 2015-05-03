#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "shift_.h"
#include "buttons_.h"
#include "schede_1.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readSettings();
    ui->templ_label->setText(temp_);

    ui->progressBar->hide();
    ui->progressBar_tot->hide();
    ui->templateButton->hide();
    ui->templ_label->hide();
    ui->line->hide();
    ui->reset->hide();

    xclient = new Client("127.0.0.1", 69);
    sh1=0;

    xclient->connect_();

    ui->tableWidget->setRowCount(ROWS_);
    ui->tableWidget->setColumnCount(COLUMS_);
    for (int i=0; i< ROWS_; i++)
        for (int j=0; j<COLUMS_; j++){
            lblr[i][j]  = new QLineEdit();
            ui->tableWidget->setCellWidget(i, j, lblr[i][j]);
        }
}

MainWindow::~MainWindow()
{
    writeSettings();
    delete xclient;
    delete ui;
}

void MainWindow::sss(){

    int caso = 0;
    if (lblr[0][0]->text() == "SH1") caso = 1;
    else if (lblr[0][0]->text() == "END") caso = -1;

    switch (caso){
    case -1:
        ui->progressBar_tot->hide();
        break;
    case 1:
       sh1_start();
       break;
    default:
        shift_matrix(*lblr);
        for (int i=0; i<COLUMS_;i++) lblr[ROWS_-1][i]->setText(memoria[0][i]);
        shift_memory(memoria);
        ui->progressBar_tot->setValue((righ_bar+= 100/sum_bar));
        QTimer::singleShot(1, this, SLOT(sss()));
        break;
    }
}
