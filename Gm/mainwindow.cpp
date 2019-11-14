#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Инициализируем виджет с графикой */
    myPicture   = new MyGraphicView();
    /* и добавляем его на слой */
    ui->graphicLayout->addWidget(myPicture);
    //timer = new QTimer();               // Инициализируем Таймер
    //timer->setSingleShot(true);
    // Подключаем СЛОТ для отрисовки к таймеру
    //connect(timer, SIGNAL(timeout()), this, SLOT(AlarmTimer()));
    //timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::AlarmTimer()
{
    static int i;
    if (master.isgame())
    {
        ui->label->setNum(i++);
        timer->start(1000);
    }
    else
    {
        timer->stop();
        i=0;
        ui->label->setNum(i);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->radioButton_2->isChecked())
    master.algorithm();
    myPicture->picture();
}
*/
