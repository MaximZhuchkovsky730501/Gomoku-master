#include "mygraphicview.h"
#include <mainwindow.h>
#include <QPointF>
#include <QApplication>
#include <QMouseEvent>
#include <QMessageBox>


MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{


    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета
     * */
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    begin = true;

    textItem = new QGraphicsTextItem("кликните по полю\nдля начала игры");

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов

    scene->addItem(group_1);            // Добавляем первую группу в сцену
    scene->addItem(group_2);            // Добавляем вторую группу в сцену
    scene->addItem(textItem);

    setBackgroundBrush(QColor(150,75,0,255)); // Задаём задний фон


    //textItem->setPos(2,3);

    QFont f;
    f.setPointSize(36);
    textItem->setFont(f);
    textItem->show();
    /*timer = new QTimer();               // Инициализируем Таймер
    timer->setSingleShot(true);
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);        */           // Стартуем таймер на 50 миллисекунд
}

MyGraphicView::~MyGraphicView()
{

}

//void MyGraphicView::slotAlarmTimer()
//{
//    picture();
//}

/* Этим методом перехватываем событие изменения размера виджет
 * */
//void MyGraphicView::resizeEvent(QResizeEvent *event)
//{
//    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
//    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
//}


/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}

void MyGraphicView::mousePressEvent(QMouseEvent *event)
{
    QApplication::beep();
    this->setEnabled(false);
    if(begin)
    {
        delete textItem;
        begin = false;
        picture();
    }
    else
    {
        if (master.isgame())
        {
            int side=(this->width())/(master.takesize()+2);
            int x=(event->pos().x()-side/2)/side;
            int y=(event->pos().y()-side/2)/side;
            if (master.isgame())
                if (master.take(x,y)==0)
                {
                    master.give(x,y);
                    master.changeborders(x,y);
                    master.algorithm();
                    picture();
                    this->update();
                }
        }
        else
        {
            master.newgame();
            deleteItemsFromGroup(group_2);
            picture();
        }
    }
    this->setEnabled(true);
}

void MyGraphicView::picture()
{

    /* Удаляем все элементы со сцены,
     * если они есть перед новой отрисовкой
     * */
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета
    /* Устанавливаем размер сцены по размеру виджета
     * Первая координата - это левый верхний угол,
     * а Вторая - это правый нижний угол
     * */
    scene->setSceneRect(0,0,width,height);

    /* Приступаем к отрисовке картинки
     * */
    setBackgroundBrush(QColor(150,75,0,255)); // Задаём задний фон
    QPen penBlack(Qt::black); // Задаём чёрную кисть
    QPen penWhite(Qt::white); // Задаём белую кисть
    penBlack.setWidth(3); // Задаём ширину кисти
    penBlack.setCapStyle(Qt::RoundCap); // Задаём стиль кисти

    int side=this->width()/(master.takesize()+2); // Задаём размер стороны клетки поля
    for (int i=1;i<20;i++) // рисуем игровое поле
    {
        int cord=i*side; // определяем координаты начала линии
        group_1->addToGroup(scene->addLine(side/2,cord, width - side/2, cord, penBlack)); //рисуем горизонтальную линию
        group_1->addToGroup(scene->addLine(cord,side/2, cord, height-side/2, penBlack)); //рисуем вертикальную линию
    }
    for (int i=0;i<19;i++) // расставляем фишки на игровом поле
    {
        for (int j=0;j<19;j++)
        {
            int rad=5; // Задаём радиус для черной фишки
            int x=(i+1)*side; // Задаём координаты по х
            int y=(j+1)*side; // Задаём координаты по у
            if (master.take(i,j)==1) group_2->addToGroup(scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,
                                                       penBlack, QBrush(Qt::SolidPattern))); // рисуем черную фишку
            rad=3; // Задаём радиус для черной фишки
            penWhite.setWidth(6); // Задаём ширину белого пера
            if (master.take(i,j)==2) group_2->addToGroup(scene->addEllipse(x-rad, y-rad, rad*2.0, rad*2.0,
                                                       penWhite, QBrush(Qt::SolidPattern))); // рисуем белую фишку
        }
    }
    if (!master.isgame()) QMessageBox::information(this,"игра окончена",master.letter()); // если игра окончена
                                                                                          //выводим сообщение о конце игры
}
