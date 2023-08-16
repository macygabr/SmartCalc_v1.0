#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}


void MainWindow::on_pushButton_15_clicked()
{
    QString qstr = ui->lineEdit->text();
    QString qstr2 = ui->lineEdit_2->text();
    std::string str_expr = qstr.toStdString();
    std::string str_expr2 = qstr.toStdString();
    char *expr = (char *)str_expr.c_str();

    double x = qstr2.toDouble();

    double res = 0;

    res = calc(expr, x);

    ui->lineEdit->setText(QString::number(res));
}


void MainWindow::on_pushButton_16_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "+");
}


void MainWindow::on_pushButton_12_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "-");
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "/");
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}


void MainWindow::on_pushButton_17_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "mod");
}


void MainWindow::on_pushButton_20_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}


void MainWindow::on_pushButton_29_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}


void MainWindow::on_pushButton_31_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "(");
}


void MainWindow::on_pushButton_30_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_32_clicked()
{
   ui->lineEdit->setText(ui->lineEdit->text() + "x");
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3.14159265");
}


//void MainWindow::on_pushButton_33_clicked()
//{

//    ui->label->setText(ui->label->text() + "dbggbgbgb\n\n\tgtgrsrgtrgtn");
//}





void MainWindow::on_spinBox_2_textChanged(const QString &arg1)
{
    QString text;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    text = "Процент: " + QString::number(proc, 'f', 7) +"\n";
    for(int i=1; i<=ui->spinBox_2->value() ; i++){
        text += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }

    ui->textEdit->setText(text);
}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    QString text;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    text = "Процент: " + QString::number(proc, 'f', 7) +"\n";
    for(int i=1; i<=ui->spinBox_2->value() ; i++){
        text += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }

    ui->textEdit->setText(text);
}


void MainWindow::on_spinBox_3_textChanged(const QString &arg1)
{
    QString text;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    text = "Процент: " + QString::number(proc, 'f', 7) +"\n";
    for(int i=1; i<=ui->spinBox_2->value() ; i++){
        text += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }
    ui->textEdit->setText(text);
}

