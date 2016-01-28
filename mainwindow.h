#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "options_for_graphs.h"
#include "graphfabric.h"

namespace Ui {
class MainWindow;
}

struct type_connect {
    QString host;
    QString login;
    QString database;
    QString pass;
    QString port;
};

struct type_graph{
    QPushButton *close; //кнопка "Закрыть график"
    QWidget *graphic; //класс графика
    QVBoxLayout *layout;
    QHBoxLayout *hlayout;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~MainWindow();
    GraphFabric* Fabric;
    static MainWindow* getWindow();
    static void clearInstance()
    {
        if (MainWindow::instance != NULL)
        {
            delete MainWindow::instance;
        }
    }

private:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow* instance;
    Ui::MainWindow *ui;
    QWidget *Scroll_Widget;
    QVBoxLayout *Scroll_Layout;
    //вектор соединений
    QVector <type_connect> success_connections;
    QVector <type_graph> box_with_graph;
    options_for_graphs *graph_options;
public slots:
    void connect_to_db();
    void draw_graph();
    void delete_graph();
};


#endif // MAINWINDOW_H
