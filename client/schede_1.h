#ifndef SCHEDE_1_H
#define SCHEDE_1_H


void MainWindow::sh1_o()
{
    QString strin0 = "STR(command \"_new\" \"y\" \" \") (command \"_open\" \"";
    strin0.append(temp_);
    strin0.append("EXM 4217-V01A-MSH_34.dwg");
    strin0.append("\") ");
    strin0.replace(QString("\\"), QString("\\\\"));
    strin0.replace(QString("/"), QString("\\\\"));

    xclient->write(strin0);
    qDebug() << strin0;
    ui->progressBar->setValue(0);
}

void MainWindow::sh1_0(){
    xclient->write("STR(command \"_style\" \"SIMPLEX\" \"txt\" \"0\" \"1\" \"0\" \"no\" \"no\" \"no\") ");
    xclient->write("(command \"_cecolor\" \"1\") ");
    ui->progressBar->setValue(8);
}

void MainWindow::sh1_save(){
    QString file = "STR(command \"_saveas\" \"2007\" \"";
    file.append(dir);
    file.append("\\EXM 4217-V01A-MSH_34_");
    file.append(QString("%1").arg(sh1));
    file.append(".dwg");
    file.append("\" \"_yes\") ");
    file.replace(QString("\\"), QString("\\\\"));
    sh1++;
    xclient->write(file);
    ui->progressBar->hide();
}

void MainWindow::sh1_start(){

    if (!QFile(temp_+"/EXM 4217-V01A-MSH_34.dwg").exists()){
        ui->progressBar_tot->hide();
        QMessageBox::warning(this, tr("Warning"),
                                        tr("File EXM 4217-V01A-MSH_34.dwg not found."),
                                        QMessageBox::Close);
        return;
    }

    shift_matrix(*lblr);
    for (int i=0; i<COLUMS_;i++) lblr[ROWS_-1][i]->setText(memoria[0][i]);
    shift_memory(memoria);
    ui->progressBar_tot->setValue((righ_bar+= 100/sum_bar));
    ui->progressBar->show();
    sh1_all();
}


void MainWindow::sh1_all(){

    sh1_o();
    xclient->wait_();
    sh1_0();
    xclient->wait_();

    xclient->write(string_.shs(("248.82,349.2"), ("3.51"), ("270"), lblr[0][0]->text(), "_center"));
    ui->progressBar->setValue(10);
    xclient->wait_();
    xclient->write(string_.shs("239.23,349.2", ("3.51"), ("270"), lblr[1][0]->text(), "_center"));
    ui->progressBar->setValue(12);
    xclient->wait_();
    xclient->write(string_.shs(("229.64,349.2"), ("3.51"), ("270"), lblr[2][0]->text(), "_center"));
    ui->progressBar->setValue(14);
    xclient->wait_();
    xclient->write(string_.shs(("220.05,349.2"), ("3.51"), ("270"), lblr[3][0]->text(), "_center"));
    ui->progressBar->setValue(16);
    xclient->wait_();
    xclient->write(string_.shs(("210.44,349.2"), ("3.51"), ("270"), lblr[4][0]->text(), "_center"));
    ui->progressBar->setValue(18);
    xclient->wait_();
    xclient->write(string_.shs(("200.85,349.2"), ("3.51"), ("270"), lblr[5][0]->text(), "_center"));
    ui->progressBar->setValue(20);
    xclient->wait_();
    xclient->write(string_.shs(("191.26,349.2"), ("3.51"), ("270"), lblr[6][0]->text(), "_center"));
    ui->progressBar->setValue(22);
    xclient->wait_();
    xclient->write(string_.shs(("181.67,349.2"), ("3.51"), ("270"), lblr[7][0]->text(), "_center"));
    ui->progressBar->setValue(24);
    xclient->wait_();
    xclient->write(string_.shs(("172.07,349.2"), ("3.51"), ("270"), lblr[8][0]->text(), "_center"));
    ui->progressBar->setValue(26);
    xclient->wait_();
    xclient->write(string_.shs(("162.48,349.2"), ("3.51"), ("270"), lblr[9][0]->text(), "_center"));
    ui->progressBar->setValue(28);
    xclient->wait_();
    xclient->write(string_.shs(("152.89,349.2"), ("3.51"), ("270"), lblr[10][0]->text(), "_center"));
    ui->progressBar->setValue(30);
    xclient->wait_();
    xclient->write(string_.shs(("143.29,349.2"), ("3.51"), ("270"), lblr[11][0]->text(), "_center"));
    ui->progressBar->setValue(32);
    xclient->wait_();
    xclient->write(string_.shs(("133.70,349.2"), ("3.51"), ("270"), lblr[12][0]->text(), "_center"));
    ui->progressBar->setValue(34);
    xclient->wait_();
    xclient->write(string_.shs(("124.11,349.2"), ("3.51"), ("270"), lblr[13][0]->text(), "_center"));
    ui->progressBar->setValue(36);
    xclient->wait_();
    xclient->write(string_.shs(("114.52,349.2"), ("3.51"), ("270"), lblr[14][0]->text(), "_center"));
    ui->progressBar->setValue(38);
    xclient->wait_();
    xclient->write(string_.shs(("104.92,349.2"), ("3.51"), ("270"), lblr[15][0]->text(), "_center"));
    ui->progressBar->setValue(40);
    xclient->wait_();


    xclient->write(string_.shs(("252.58,462.86"), ("2.29"), ("270"), lblr[0][1]->text()));
    ui->progressBar->setValue(42);
    xclient->wait_();
    xclient->write(string_.shs(("248.10,462.86"), ("2.29"), ("270"), lblr[1][1]->text()));
    ui->progressBar->setValue(44);
    xclient->wait_();
    xclient->write(string_.shs(("242.99,462.86"), ("2.29"), ("270"), lblr[2][1]->text()));
    ui->progressBar->setValue(46);
    xclient->wait_();
    xclient->write(string_.shs(("238.50,462.86"), ("2.29"), ("270"), lblr[3][1]->text()));
    ui->progressBar->setValue(48);
    xclient->wait_();
    xclient->write(string_.shs(("233.40,462.86"), ("2.29"), ("270"), lblr[4][1]->text()));
    ui->progressBar->setValue(50);
    xclient->wait_();
    xclient->write(string_.shs(("228.91,462.86"), ("2.29"), ("270"), lblr[5][1]->text()));
    ui->progressBar->setValue(52);
    xclient->wait_();
    xclient->write(string_.shs(("223.80,462.86"), ("2.29"), ("270"), lblr[6][1]->text()));
    ui->progressBar->setValue(54);
    xclient->wait_();
    xclient->write(string_.shs(("219.32,462.86"), ("2.29"), ("270"), lblr[7][1]->text()));
    ui->progressBar->setValue(56);
    xclient->wait_();
    xclient->write(string_.shs(("214.21,462.86"), ("2.29"), ("270"), lblr[8][1]->text()));
    ui->progressBar->setValue(58);
    xclient->wait_();
    xclient->write(string_.shs(("209.72,462.86"), ("2.29"), ("270"), lblr[9][1]->text()));
    ui->progressBar->setValue(60);
    xclient->wait_();
    xclient->write(string_.shs(("204.62,462.86"), ("2.29"), ("270"), lblr[10][1]->text()));
    ui->progressBar->setValue(62);
    xclient->wait_();
    xclient->write(string_.shs(("200.13,462.86"), ("2.29"), ("270"), lblr[11][1]->text()));
    ui->progressBar->setValue(64);
    xclient->wait_();
    xclient->write(string_.shs(("195.02,462.86"), ("2.29"), ("270"), lblr[12][1]->text()));
    ui->progressBar->setValue(66);
    xclient->wait_();
    xclient->write(string_.shs(("190.54,462.86"), ("2.29"), ("270"), lblr[13][1]->text()));
    ui->progressBar->setValue(68);
    xclient->wait_();
    xclient->write(string_.shs(("185.43,462.86"), ("2.29"), ("270"), lblr[14][1]->text()));
    ui->progressBar->setValue(70);
    xclient->wait_();
    xclient->write(string_.shs(("180.94,462.86"), ("2.29"), ("270"), lblr[15][1]->text()));
    ui->progressBar->setValue(72);
    xclient->wait_();
    xclient->write(string_.shs(("175.84,462.86"), ("2.29"), ("270"), lblr[16][1]->text()));
    ui->progressBar->setValue(74);
    xclient->wait_();
    xclient->write(string_.shs(("171.35,462.86"), ("2.29"), ("270"), lblr[17][1]->text()));
    ui->progressBar->setValue(76);
    xclient->wait_();
    xclient->write(string_.shs(("166.24,462.86"), ("2.29"), ("270"), lblr[18][1]->text()));
    ui->progressBar->setValue(78);
    xclient->wait_();
    xclient->write(string_.shs(("161.76,462.86"), ("2.29"), ("270"), lblr[19][1]->text()));
    ui->progressBar->setValue(80);
    xclient->wait_();
    xclient->write(string_.shs(("156.65,462.86"), ("2.29"), ("270"), lblr[20][1]->text()));
    ui->progressBar->setValue(82);
    xclient->wait_();
    xclient->write(string_.shs(("152.16,462.86"), ("2.29"), ("270"), lblr[21][1]->text()));
    ui->progressBar->setValue(84);
    xclient->wait_();
    xclient->write(string_.shs(("147.06,462.86"), ("2.29"), ("270"), lblr[22][1]->text()));
    ui->progressBar->setValue(86);
    xclient->wait_();
    xclient->write(string_.shs(("142.57,462.86"), ("2.29"), ("270"), lblr[23][1]->text()));
    ui->progressBar->setValue(88);
    xclient->wait_();
    xclient->write(string_.shs(("137.46,462.86"), ("2.29"), ("270"), lblr[24][1]->text()));
    ui->progressBar->setValue(90);
    xclient->wait_();
    xclient->write(string_.shs(("132.98,462.86"), ("2.29"), ("270"), lblr[25][1]->text()));
    ui->progressBar->setValue(92);
    xclient->wait_();
    xclient->write(string_.shs(("127.87,462.86"), ("2.29"), ("270"), lblr[26][1]->text()));
    ui->progressBar->setValue(94);
    xclient->wait_();
    xclient->write(string_.shs(("123.38,462.86"), ("2.29"), ("270"), lblr[27][1]->text()));
    ui->progressBar->setValue(96);
    xclient->wait_();
    xclient->write(string_.shs(("118.28,462.86"), ("2.29"), ("270"), lblr[28][1]->text()));
    ui->progressBar->setValue(98);
    xclient->wait_();
    xclient->write(string_.shs(("113.79,462.86"), ("2.29"), ("270"), lblr[29][1]->text()));
    ui->progressBar->setValue(100);
    xclient->wait_();

    sh1_save();
    xclient->wait_();

    sss();
}


#endif // SCHEDE_1_H
