#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bit7TextEdit_textChanged()
{
    QString bit7text = ui->bit7TextEdit->toPlainText();
    myString.fromBit7( bit7text );
    updateTexts();
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    myString.fromQString( text );
    updateTexts();
}

void MainWindow::on_ASCIItextEdit_textChanged()
{
   updateTexts();
}

void MainWindow::on_UCStextEdit_textChanged()
{
    updateTexts();
}

void MainWindow::on_UTF8textEdit_textChanged()
{
    updateTexts();
}

void MainWindow::updateTexts() {
    //ui->bit7TextEdit->setPlainText( myString.toBit7() );
    QString myText = myString.toASCII();
    ui->ASCIItextEdit->setPlainText( myText );
    ui->UCStextEdit->setPlainText( myString.toUCS() );
    ui->UTF8textEdit->setPlainText( myString.toUTF8() );
    ui->textEdit->setPlainText( myString.toQString() );
}

