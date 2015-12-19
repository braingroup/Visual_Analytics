#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Fabric = new GraphFabric();
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_2_clicked()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_3_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Fabric;
}

void MainWindow::on_pushButton_clicked()
{
    QWidget* _widget = new QWidget(this);
    Graph* G = Fabric->BuildGraph(GraphType::FUNCTION, _widget);
}


void MainWindow::on_pushButton_2_clicked()
{
    QWidget* _widget = new QWidget;
    _widget->setFixedSize(ui->scrollArea->width(), ui->scrollArea->height());
    Fabric->BuildGraph(GraphType::CIRCLE, _widget);
    ui->scrollArea->setWidget(_widget);
}


void MainWindow::on_pushButton_3_clicked()
{
    QWidget* _widget = new QWidget(this);
    Graph* G = Fabric->BuildGraph(GraphType::COLUMN, _widget);
}

