#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void digit_pressed();
//    void sigmind_slot();

    void on_pushButton_decimal_released();

    void on_pushButton_plusMinus_released();

    void on_pushButton_percent_released();

    void on_pushButton_binaryOperation_released();

    void on_pushButton_equals_released();

    void on_pushButton_clear_released();

private:
    Ui::MainWindow *ui;

signals:
//   void sigmind();

};

#endif // MAINWINDOW_H
