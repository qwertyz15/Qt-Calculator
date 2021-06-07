#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
double firstNumber;
bool userIsTyingSecondNumber = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(on_pushButton_binaryOperation_released()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(on_pushButton_binaryOperation_released()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(on_pushButton_binaryOperation_released()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(on_pushButton_binaryOperation_released()));
//    connect(this, SIGNAL(sigmind()), this, SLOT(sigmind_slot()));
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
//   emit sigmind();
    qDebug() << "Digit pressed";
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked())
            && (!userIsTyingSecondNumber)) {
        labelNumber = button->text().toDouble();
        userIsTyingSecondNumber = true;

    }
//    ui->label->setText(button->text());
    else labelNumber = (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNumber, 'g', 15);
    ui->label->setText(newLabel);

}






//void MainWindow::sigmind_slot()
//{
//   qDebug()<<"sigmind_slot";
//}



void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}



void MainWindow::on_pushButton_plusMinus_released()
{
    double labelNumber;
    QString newLabel;
    QPushButton * button = (QPushButton*) sender();

    if(button->text() == "+/-") {
        labelNumber = ui->label->text().toDouble() * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_percent_released()
{
   // QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    labelNumber = (ui->label->text()).toDouble();
    labelNumber *= 0.01;
    newLabel = QString::number(labelNumber, 'g', 15);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_binaryOperation_released()
{
    QPushButton * button = (QPushButton*)sender();
    firstNumber = (ui->label->text()).toDouble();
    button->setChecked(true);
}


void MainWindow::on_pushButton_equals_released()
{
    double labelNumber, secondNumber;
    QString newLabel;
    secondNumber = (ui->label->text()).toDouble();
    if(ui->pushButton_plus->isChecked()) {
        labelNumber = firstNumber + secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()) {
        labelNumber = firstNumber - secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()) {
        labelNumber = firstNumber * secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()) {
        labelNumber = firstNumber / secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    userIsTyingSecondNumber = false;
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    userIsTyingSecondNumber = false;

    ui->label->setText("0");
}
