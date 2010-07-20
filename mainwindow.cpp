#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    updateAllowed = true;
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
    QObject *sender_obj = QObject::sender();
    QTextEdit *sender = dynamic_cast<QTextEdit*>(sender_obj);
    //QTextCursor cursor = sender->textCursor();
    int oldPos(sender->textCursor().selectionStart());


    ui->bit7TextEdit->blockSignals(true);
    ui->ASCIItextEdit->blockSignals(true);
    ui->UCStextEdit->blockSignals(true);
    ui->UTF8textEdit->blockSignals(true);
    ui->textEdit->blockSignals(true);

    ui->bit7TextEdit->setPlainText(  myString.toBit7() );
    //ui->ASCIItextEdit->setPlainText( myString.toASCII() );
    //ui->UCStextEdit->setPlainText(   myString.toUCS() );
    //hui->UTF8textEdit->setPlainText(  myString.toUTF8() );
    ui->textEdit->setPlainText(      myString.toQString() );

    ui->bit7TextEdit->blockSignals(false);
    ui->ASCIItextEdit->blockSignals(false);
    ui->UCStextEdit->blockSignals(false);
    ui->UTF8textEdit->blockSignals(false);
    ui->textEdit->blockSignals(false);
    //updateAllowed = true;

    //sender->setTextCursor(cursor);
    QTextCursor cursor(sender->textCursor());
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, oldPos);
    sender->setTextCursor(cursor);
}

