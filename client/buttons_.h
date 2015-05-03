#ifndef BUTTONS__H
#define BUTTONS__H

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionAbout_Autoxsl_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("About Autoxsl");
    msgBox.setText("About Autoxsl");
    msgBox.exec();
}


void MainWindow::on_open_clicked()
{

    QString tempo = file_string;
    file_string = QFileDialog::getOpenFileName(this, tr("Open File"),file_string, \
                                                       tr("Supported Files (*.xls *.xlsx);;All Files (*.*)"));

    ui->progressBar->setValue(33);
    ui->progressBar->show();
    ui->centralWidget->repaint();

    if (file_string == NULL){
        ui->progressBar->hide();
        file_string = tempo;
        return;
    }

    for (int i=0; i< ROWS_; i++)
        for (int j=0; j<COLUMS_; j++)
            lblr[i][j]->clear();


    QFile *file = new QFile();

        QString stringa = QDir().homePath () + "\\temp.enri";

        stringa.replace(QString("/"), QString("\\"));


        QAxObject* excel = new QAxObject( "Excel.Application", 0 );
        QAxObject *workbooks = excel->querySubObject( "Workbooks" );
        QAxObject *workbook = workbooks->querySubObject( "Open(const QString&)", file_string.toAscii() );
        excel->setProperty("DisplayAlerts", 0);
        workbook->dynamicCall("SaveAs (const QString&, int)", stringa, "-4158");
        workbook->dynamicCall("Close(const QString&)", "False");
        excel->dynamicCall("Quit()");

        ui->progressBar->setValue(51);

        delete workbook;
        delete workbooks;
        delete excel;

        file->setFileName(stringa);

    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QString data;
    QStringList rowdata;
    QStringList row;
    rowdata.clear();
    row.clear();
    data = file->readAll();
    rowdata = data.split("\n");
    file->close();

    QFile::remove(stringa);

        for (int i = 0; i < rowdata.size(); i++){
            row = rowdata.at(i).split(9);
            for (int j = 0; j < row.size(); j++){
                memoria[i][j] = row[j];
            }
        }

        sum_bar = rowdata.size()-1;
        righ_bar = 0;

        ui->progressBar->setValue(69);

        for (int i =0; i<ROWS_;i++)
            for (int j =0; j<COLUMS_;j++)
                lblr[i][j]->setText(memoria[i][j]);

            for(int i=0; i<ROWS_; i++) shift_memory(memoria);

        ui->progressBar->hide();
}

void MainWindow::on_sh1_w_clicked()
{
    QString tempo = dir;
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                         dir,
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    if (dir == NULL){
        dir = tempo;
        return;
    }
    ui->progressBar_tot->setValue(0);
    ui->progressBar_tot->show();

    sss();
}

void MainWindow::writeSettings()
 {
     QSettings settings("HKEY_CURRENT_USER\\Software\\AutoXlsx", QSettings::NativeFormat);
     settings.setValue("Options/dir", dir);
     settings.setValue("Options/temp", temp_);
     settings.setValue("Options/open", file_string);
 }

 void MainWindow::readSettings()
 {
     QSettings settings("HKEY_CURRENT_USER\\Software\\AutoXlsx", QSettings::NativeFormat);
     dir = QString(settings.value("Options/dir", DIR_).toByteArray());
     temp_ = QString(settings.value("Options/temp", TEMP_).toByteArray());
     file_string = QString(settings.value("Options/open", DIR_).toByteArray());
 }


 void MainWindow::on_actionImport_Spreadsheet_activated()
 {
     on_open_clicked();
 }

 void MainWindow::on_actionWrite_activated()
 {
     on_sh1_w_clicked();
 }

 void MainWindow::on_actionQuit_activated()
 {
     close();
 }

 void MainWindow::on_templateButton_clicked()
 {
     QString tempo = temp_;
     temp_ = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                          temp_,
                                                          QFileDialog::ShowDirsOnly
                                               | QFileDialog::DontResolveSymlinks) + "\\";
     if (temp_ == "\\"){
         temp_ = tempo;
         return;
     }
     ui->templ_label->setText(temp_);
 }


 void MainWindow::on_actionSettings_activated()
 {
     if (ui->actionSettings->isChecked()) {
         ui->templateButton->show();
         ui->templ_label->show();
         ui->line->show();
         ui->reset->show();
     } else {
         ui->templateButton->hide();
         ui->templ_label->hide();
         ui->line->hide();
         ui->reset->hide();
     }
 }

 void MainWindow::on_reset_clicked()
 {
     dir = DIR_;
     temp_ = TEMP_;
     file_string = DIR_;
     ui->templ_label->setText(temp_);
 }


#endif // BUTTONS__H
