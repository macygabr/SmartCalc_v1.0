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
    ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
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

void MainWindow::on_spinBox_2_textChanged(const QString &arg1)
{
    QString text1;
    QString text2;
    double res2=0;
    double per=0;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    double base = (rub/mounth);
    int i=0;
    for(i=1; i<=ui->spinBox_2->value() ; i++){
        text1 += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }
     if(i>0)    text1 += "Общая выплата: " + QString::number(res*(i-1), 'f', 2) + " Переплата: " + QString::number(res*(i-1)-rub, 'f', 2) +"\n";

    for(int j=1; j<=ui->spinBox_2->value() ; j++){
        res2=base+proc*(rub);
        text2 += "Выплата в " + QString::number(j) + " месяц составит: " + QString::number(res2, 'f', 2) + ", в счет процентов: "+ QString::number(proc*(rub), 'f', 2) + " \n";
        per += proc*(rub);
        rub -= base;
    }
      text2 += "Общая выплата: " + QString::number(ui->spinBox->value()+per, 'f', 2) + " Переплата: " + QString::number(per, 'f', 2) +"\n";

    if((ui->spinBox->value()) == 0.0 || proc == 0 || mounth==0) text1 = "Переплата: 0\n";
    ui->textEdit->setText(text1);
    ui->textEdit_2->setText(text2);
}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    QString text1;
    QString text2;
    double res2=0;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    double base = (rub/mounth);
    double per=0;
    int i=0;
    for(i=1; i<=ui->spinBox_2->value() ; i++){
        text1 += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }
     if(i>0)    text1 += "Общая выплата: " + QString::number(res*(i-1), 'f', 2) + " Переплата: " + QString::number(res*(i-1)-rub, 'f', 2) +"\n";

    for(int j=1; j<=ui->spinBox_2->value() ; j++){
        res2=base+proc*(rub);
        text2 += "Выплата в " + QString::number(j) + " месяц составит: " + QString::number(res2, 'f', 2) + ", в счет процентов: "+ QString::number(proc*(rub), 'f', 2) + " \n";
        per += proc*(rub);
        rub -= base;
    }
     text2 += "Общая выплата: " + QString::number(ui->spinBox->value()+per, 'f', 2) + " Переплата: " + QString::number(per, 'f', 2) +"\n";

    if((ui->spinBox->value()) == 0.0 || proc == 0 || mounth==0) text1 = "Переплата: 0\n";
    ui->textEdit->setText(text1);
    ui->textEdit_2->setText(text2);
}


void MainWindow::on_spinBox_3_textChanged(const QString &arg1)
{
    QString text1;
    QString text2;
    double res2=0;
     double per=0;
    double rub = (ui->spinBox->value());
    double proc = ((ui->spinBox_3->value())/12.0)/100.0;
    double mounth = ui->spinBox_2->value();
    double res = rub*(proc+(proc/(qPow((1+proc),mounth) - 1)));
    double base = (rub/mounth);
    int i=0;
    for(i=1; i<=ui->spinBox_2->value() ; i++){
        text1 += "Выплата в " + QString::number(i) + " месяц составит: " + QString::number(res, 'f', 2) + " \n";
    }
     if(i>0)    text1 += "Общая выплата: " + QString::number(res*(i-1), 'f', 2) + " Переплата: " + QString::number(res*(i-1)-rub, 'f', 2) +"\n";

    for(int j=1; j<=ui->spinBox_2->value() ; j++){
        res2=base+proc*(rub);
        text2 += "Выплата в " + QString::number(j) + " месяц составит: " + QString::number(res2, 'f', 2) + ", в счет процентов: "+ QString::number(proc*(rub), 'f', 2) + " \n";
        per += proc*(rub);
        rub -= base;
    }
         text2 += "Общая выплата: " + QString::number(ui->spinBox->value()+per, 'f', 2) + " Переплата: " + QString::number(per, 'f', 2) +"\n";

    if((ui->spinBox->value()) == 0.0 || proc == 0 || mounth==0) text1 = "Переплата: 0\n";
    ui->textEdit->setText(text1);
    ui->textEdit_2->setText(text2);
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lineEdit_6->setText(ui->lineEdit->text());
}


void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->lineEdit->setText(ui->lineEdit_6->text());

    int a = ui->spinBox_6->text().toInt();
    int b =  ui->spinBox_5->text().toInt();
    if(a>=b) return;
    double N = 500;
    double h = (b-a)/N;
    double X = a;
    QVector<double> x(N), y(N);

    for (int i=0; i<N; X+=h, i++) {
      x[i] = X;
     QString qstr = ui->lineEdit->text();
     std::string str_expr = qstr.toStdString();
     char *expr = (char *)str_expr.c_str();
      y[i] = calc(expr,X);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);


    if(ui->spinBox_4->text().toInt() < ui->spinBox_7->text().toInt()) ui->widget->yAxis->setRange(ui->spinBox_4->text().toInt(), ui->spinBox_7->text().toInt());
    ui->widget->replot();
}


void MainWindow::on_spinBox_7_textChanged(const QString &arg1)
{
    ui->lineEdit->setText(ui->lineEdit_6->text());

    int a = ui->spinBox_6->text().toInt();
    int b =  ui->spinBox_5->text().toInt();
    if(a>=b) return;
    double N = 500;
    double h = (b-a)/N;
    double X = a;
    QVector<double> x(N), y(N);

    for (int i=0; i<N; X+=h, i++) {
      x[i] = X;
     QString qstr = ui->lineEdit->text();
     std::string str_expr = qstr.toStdString();
     char *expr = (char *)str_expr.c_str();
      y[i] = calc(expr,X);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);


    if(ui->spinBox_4->text().toInt() < ui->spinBox_7->text().toInt()) ui->widget->yAxis->setRange(ui->spinBox_4->text().toInt(), ui->spinBox_7->text().toInt());
    ui->widget->replot();
}


void MainWindow::on_spinBox_6_textChanged(const QString &arg1)
{
    ui->lineEdit->setText(ui->lineEdit_6->text());

    int a = ui->spinBox_6->text().toInt();
    int b =  ui->spinBox_5->text().toInt();
    if(a>=b) return;
    double N = 500;
    double h = (b-a)/N;
    double X = a;
    QVector<double> x(N), y(N);

    for (int i=0; i<N; X+=h, i++) {
      x[i] = X;
     QString qstr = ui->lineEdit->text();
     std::string str_expr = qstr.toStdString();
     char *expr = (char *)str_expr.c_str();
      y[i] = calc(expr,X);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);


    if(ui->spinBox_4->text().toInt() < ui->spinBox_7->text().toInt()) ui->widget->yAxis->setRange(ui->spinBox_4->text().toInt(), ui->spinBox_7->text().toInt());
    ui->widget->replot();
}


void MainWindow::on_spinBox_5_textChanged(const QString &arg1)
{
    ui->lineEdit->setText(ui->lineEdit_6->text());

    int a = ui->spinBox_6->text().toInt();
    int b =  ui->spinBox_5->text().toInt();
    if(a>=b) return;
    double N = 500;
    double h = (b-a)/N;
    double X = a;
    QVector<double> x(N), y(N);

    for (int i=0; i<N; X+=h, i++) {
      x[i] = X;
     QString qstr = ui->lineEdit->text();
     std::string str_expr = qstr.toStdString();
     char *expr = (char *)str_expr.c_str();
      y[i] = calc(expr,X);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);


    if(ui->spinBox_4->text().toInt() < ui->spinBox_7->text().toInt()) ui->widget->yAxis->setRange(ui->spinBox_4->text().toInt(), ui->spinBox_7->text().toInt());
    ui->widget->replot();

}


void MainWindow::on_spinBox_4_textChanged(const QString &arg1)
{
    ui->lineEdit->setText(ui->lineEdit_6->text());

    int a = ui->spinBox_6->text().toInt();
    int b =  ui->spinBox_5->text().toInt();
    if(a>=b) return;

    double N = 500;
    double h = (b-a)/N;
    double X = a;
    QVector<double> x(N), y(N);

    for (int i=0; i<N; X+=h, i++) {
      x[i] = X;
     QString qstr = ui->lineEdit->text();
     std::string str_expr = qstr.toStdString();
     char *expr = (char *)str_expr.c_str();
      y[i] = calc(expr,X);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);


    if(ui->spinBox_4->text().toInt() < ui->spinBox_7->text().toInt()) ui->widget->yAxis->setRange(ui->spinBox_4->text().toInt(), ui->spinBox_7->text().toInt());
    ui->widget->replot();
}

