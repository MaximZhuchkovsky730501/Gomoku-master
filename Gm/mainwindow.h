#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <mygraphicview.h>
#include <QTimer>
#include <bot.h>
//#include <admin.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//private slots:
//    void AlarmTimer();

//    void on_pushButton_clicked();

private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;     // Наш кастомный виджет
//    QTimer          *timer;
};

#endif // MAINWINDOW_H
