#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QAxObject>
#include <QSettings>

#include "client.h"
#include "string_.h"

#define ROWS_   50
#define COLUMS_ 10
#define MOLTI   200


#define DIR_    QDir().currentPath()
#define TEMP_   QDir().currentPath()+"/SHS/"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_open_clicked();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_Autoxsl_triggered();

    void on_sh1_w_clicked();

private slots:

    //////sh1//////
    void sh1_o();
    void sh1_0();
    void sh1_save();
    void sh1_start();
    void sh1_all();
///////////////////////

    void sss();

    void shift_matrix(QLineEdit* matrix[COLUMS_]);
    void shift_memory(QString matrix[][COLUMS_]);

    void readSettings();
    void writeSettings();

    void on_actionImport_Spreadsheet_activated();

    void on_actionWrite_activated();

    void on_actionQuit_activated();

    void on_templateButton_clicked();

    void on_actionSettings_activated();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;

    Client *xclient;
    String_ string_;
    QLineEdit *lblr[ROWS_][COLUMS_];
    QString memoria[ROWS_*MOLTI][COLUMS_];
    QString dir;
    QString temp_;
    QString file_string;
    int sh1; //scheda 1 contatore
    float righ_bar;
    float sum_bar;

};

#endif // MAINWINDOW_H
