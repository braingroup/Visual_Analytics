#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makeGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeGraph()
{
    // create empty bar chart objects:
    QCPBars *_green = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *_blue = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *_red = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(_green);
    ui->customPlot->addPlottable(_blue);
    ui->customPlot->addPlottable(_red);
    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    _red->setName("RED");
    pen.setColor(QColor(255, 131, 0));
    _red->setPen(pen);
    _red->setBrush(QColor(255, 131, 0, 50));
    _blue->setName("BLUE");
    pen.setColor(QColor(1, 92, 191));
    _blue->setPen(pen);
    _blue->setBrush(QColor(1, 92, 191, 50));
    _green->setName("GREEN");
    pen.setColor(QColor(150, 222, 0));
    _green->setPen(pen);
    _green->setBrush(QColor(150, 222, 0, 70));
    // stack bars ontop of each other:
    _blue->moveAbove(_red);
    _green->moveAbove(_blue);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "ONE" << "TWO" << "THREE" << "FOUR" << "FIVE" << "SIX" << "SEVEN";
    ui->customPlot->xAxis->setAutoTicks(false);
    ui->customPlot->xAxis->setAutoTickLabels(false);
    ui->customPlot->xAxis->setTickVector(ticks);
    ui->customPlot->xAxis->setTickVectorLabels(labels);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTickCount(0);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->setRange(0, 8);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("SOME TEST PLOT");
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> _redData, _blueData, _greenData;
    _redData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    _blueData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    _greenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    _red->setData(ticks, _redData);
    _blue->setData(ticks, _blueData);
    _green->setData(ticks, _greenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    ui->customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
