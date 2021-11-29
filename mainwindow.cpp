#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNEW_triggered()
{

    file_path_ = "" ;
    ui->textEdit->setText("");

}


void MainWindow::on_actionOPEN_triggered()
{
    QString file_name = QFileDialog:: getOpenFileName(this,"open the flie");
    QFile file(file_name);
    file_path_=file_name;
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        QMessageBox :: warning(this,"..","file not Open");
        return;
    }
    QTextStream in (&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSAVE_triggered()
{


    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly |QFile::Text))
    {
        QMessageBox :: warning(this,"..","file not Open");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSAVE_AS_triggered()
{

    QString file_name = QFileDialog:: getSaveFileName(this,"open the flie");
    QFile file(file_name);
    file_path_=file_name;
    if(!file.open(QFile::WriteOnly |QFile::Text))
    {
        QMessageBox :: warning(this,"..","file not Open");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();

}


void MainWindow::on_actionPast_triggered()
{
   ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
   ui->textEdit->redo();
}


void MainWindow::on_actionUdo_triggered()
{
   ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepat_triggered()
{

    QString about_text;
    about_text = "Auther : Sharaf \n";
    about_text +="Date: 12/05/2021 \n";
    about_text += "(C) NotePad (R) \n";
    QMessageBox :: about(this,"About NotePad",about_text);
}

