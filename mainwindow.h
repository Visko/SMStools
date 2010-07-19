#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smstring.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SMString myString;
    void updateTexts();
    bool updateAllowed;

private slots:
    void on_bit7TextEdit_textChanged();
    void on_textEdit_textChanged();
    void on_ASCIItextEdit_textChanged();
    void on_UCStextEdit_textChanged();
    void on_UTF8textEdit_textChanged();
};

#endif // MAINWINDOW_H
