#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_proc, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui -> pushButton_division->setCheckable(true);
    ui -> pushButton_minus->setCheckable(true);
    ui -> pushButton_plus->setCheckable(true);
    ui -> pushButton_mult->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_label;

    if (ui->result->text().contains(".") && button->text()== "0")
    {
        new_label =ui->result->text()+ button->text();
    } else
    {
        all_numbers =(ui->result->text()+ button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 14);
    }
    ui->result->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result->text().contains(".")))
    ui->result->setText(ui->result->text()+ ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_label;
    if(button->text() == "+/-"){
        all_numbers =(ui->result->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 14);
        ui->result->setText(new_label);
    } else if (button->text() == "%"){
        all_numbers =(ui->result->text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers, 'g', 14);
        ui->result->setText(new_label);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->result->setText("0");
}

void MainWindow::on_pushButton_equals_clicked()
{
    double label_number, num_second;
    QString new_label;
    num_second = ui->result->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        label_number = num_first + num_second;
        new_label = QString::number(label_number, 'g', 14);
        ui->result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    } else if (ui->pushButton_minus->isChecked())
    {
        label_number = num_first - num_second;
        new_label = QString::number(label_number, 'g', 14);
        ui->result->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if (ui->pushButton_division->isChecked())
    {
        if (num_second == 0)
        {
            ui->result->setText("division by zero");
        } else {
        label_number = num_first / num_second;
        new_label = QString::number(label_number, 'g', 14);
        ui->result->setText(new_label);
        }
        ui->pushButton_division->setChecked(false);
    } else if (ui->pushButton_mult->isChecked())
    {
        label_number = num_first * num_second;
        new_label = QString::number(label_number, 'g', 14);
        ui->result->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
}
void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();
    num_first = ui->result->text().toDouble();
    ui->result->setText("");
    button->setChecked(true);
}

