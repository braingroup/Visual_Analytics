#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //предустановки связанные со скроллом
    Scroll_Widget = new QWidget(this);
    Scroll_Layout = new QVBoxLayout(this);
    Scroll_Widget->setLayout(Scroll_Layout);
    ui->scrollArea->setWidget(Scroll_Widget);  
    //связи
    QObject::connect(ui->connection_button, SIGNAL(clicked()), this, SLOT(connect_to_db()));
    QObject::connect(ui->draw_graph_button, SIGNAL(clicked()), this, SLOT(draw_graph()));

}

MainWindow::~MainWindow()
{
    //навсякий случай
    success_connections.clear();
    box_with_graph.clear();
    delete ui;
}

//валидация данных для будующего коннекта
bool validate_date(type_connect data) {
    if (!(data.host.length()) || !(data.login.length()) || !(data.pass.length()) || !(data.port.length()) || !(data.database.length()) ) {
        return 1;
    }
    return 0;
}

//коннект к базе данных
void MainWindow::connect_to_db() {
    type_connect new_connect;

    //добываем данные для соединения
    if (ui->case_of_connection->currentIndex()) {
        //старое соединение
        new_connect = success_connections[ui->case_of_connection->currentIndex() - 1];
        ui->data_host->clear();
        ui->data_login->clear();
        ui->data_pass->clear();
        ui->data_database->clear();
        ui->data_port->clear();
    } else {
        //новое соединение
        new_connect.host = ui->data_host->text();
        new_connect.login = ui->data_login->text();
        new_connect.pass = ui->data_pass->text();
        new_connect.port = ui->data_port->text();
        new_connect.database = ui->data_database->text();
    }

    if (validate_date(new_connect)) {
        ui->status_conection->setText("Не удалось соединиться. Данные введены не верно!");
        return;
    }
    // флаг установки контакта,
    //      0 - не соединено
    //      1 - соединено успешно
    bool connection_flag = 1;

    //процесс конекта

    /*
     *
     * БУДЕТ КАКОЙ-ТО КОД С КОННЕКТОМ
     *
    */

    //анализируем результат
    if (connection_flag) {
        //записываем результат в строку состояния
        ui->status_conection->setText("Установлено соединение с базой данных " + new_connect.database + " хоста " + new_connect.host + " (пользователь " + new_connect.login + ")");
        //добавляем в вектор соединений, если Новое соединение
        if (!(ui->case_of_connection->currentIndex())) {
            ui->case_of_connection->addItem(new_connect.host + "_" + new_connect.database);
            success_connections.push_back(new_connect);
            ui->data_host->clear();
            ui->data_login->clear();
            ui->data_pass->clear();
            ui->data_database->clear();
            ui->data_port->clear();
        }
        ui->draw_graph_button->setEnabled(1);
    } else {
        ui->status_conection->setText("Не удалось соединиться с базой данных " + new_connect.database + " хоста " + new_connect.host);
        ui->data_pass->clear();
    }
}

//постройка графика по нажатию на кнопку "Построить"
void MainWindow::draw_graph(){
    //модальное окно
    graph_options = new options_for_graphs(this);
    graph_options->exec();

    //создание обекта графика
    type_graph new_graphic;
    new_graphic.layout = new QVBoxLayout(this);
    new_graphic.hlayout = new QHBoxLayout(this);
    new_graphic.close = new QPushButton("Закрыть график", this);
    new_graphic.graphic = new GLWidget(this);
    new_graphic.graphic->setFixedHeight(400);

    new_graphic.hlayout->addStretch(1);
    new_graphic.hlayout->addWidget(new_graphic.close);

    new_graphic.layout->addLayout(new_graphic.hlayout);
    new_graphic.layout->addWidget(new_graphic.graphic);

    //push в вектор графиков
    box_with_graph.push_back(new_graphic);

    //налаживаем связь сигнал - слот
    QObject::connect(box_with_graph.last().close, SIGNAL(clicked()), this, SLOT(delete_graph()));

    /*
     *
     *
     *
    */
    QMessageBox::information(this, "data in mainwindow", "data for draw graph: \n" + graph_options->getdata() );
    /*
     * ПЕРЕДАЧА НА ОТРИСОВКУ
     *
     *
    */
    Scroll_Layout->addLayout(box_with_graph.last().layout);
}

//удаление графика по нажатию на кнопку "Закрыть график"
 void MainWindow::delete_graph() {
      for (int it=0; it < box_with_graph.size(); it++) {
          if (sender() == box_with_graph[it].close){
            //рвем связь сигнал - слот
            QObject::disconnect(sender(),SIGNAL(clicked()), this, SLOT(delete_graph()));

            //удаляем обекты графика
            delete box_with_graph[it].hlayout;
            delete box_with_graph[it].close;
            delete box_with_graph[it].layout;
            delete box_with_graph[it].graphic;

            //удаляем из вектора графиков
            std::swap(box_with_graph[it], box_with_graph.last());
            box_with_graph.pop_back();

            return;
          }
      }
 }

