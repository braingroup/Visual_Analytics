#include "functiongraph.h"

FunctionGraph::FunctionGraph()
{

}

FunctionGraph::FunctionGraph(QWidget *_Area, DrawableObject * _DrawableObject)
{
    Draw(_Area, _DrawableObject);
}

FunctionGraph::~FunctionGraph()
{

}

void FunctionGraph::Draw(QWidget* _Area, DrawableObject * _DrawableObject)
{
    QString colorGraph[8] = {"#9c27b0",  "#f44336", "#3f51b5", "#009688", "#cddc39", "#ffc107", "#795548", "#e91e63"};
    QCustomPlot* _Graph = new QCustomPlot(_Area);
    _Graph->setFixedSize(_Area->width(), _Area->height());
    _Graph->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _Graph->legend->setVisible(true);
    _Graph->legend->setFont(QFont("Helvetica", 9));

    // ось абсцисс
    QVector<double> x;
    x = _DrawableObject->getValues(_DrawableObject->fields[0], _DrawableObject->nameTable);

    //первые данные

    QVector<double> y0;
    y0 = _DrawableObject->getValues(_DrawableObject->fields[1], _DrawableObject->nameTable);
    _Graph->addGraph();
    _Graph->graph(0)->setName(_DrawableObject->fields[1]);
    _Graph->graph(0)->setPen(QPen(QColor(colorGraph[0]), 2));
    _Graph->graph(0)->setData(x, y0);
    double maxYValue = y0[0];
    double minYValue = y0[0];
    double maxXValue = x[0];
    double minXValue = x[0];
    for (int j = 0; j < y0.size(); j++) {
        if (maxYValue < y0[j]) maxYValue = y0[j];
        if (minYValue > y0[j]) minYValue = y0[j];
        if (maxXValue < x[j]) maxXValue = x[j];
        if (minXValue > x[j]) minXValue = x[j];
    }


    //остальные данные
    for (int i = 2; i < _DrawableObject->fields.size(); i++) {
        QVector<double> y1;
        y1 = _DrawableObject->getValues(_DrawableObject->fields[i], _DrawableObject->nameTable);
        _Graph->addGraph();
        _Graph->graph(i - 1)->setData(x, y1);
        _Graph->graph(i - 1)->setName(_DrawableObject->fields[i]);
        _Graph->graph(i - 1)->setPen(QPen(QColor(colorGraph[i-1]), 2));
        for (int j = 0; j < y1.size(); j++) {
            if (maxYValue < y1[j]) maxYValue = y1[j];
            if (minYValue > y1[j]) minYValue = y1[j];
        }
    }


    _Graph->xAxis->setLabel("Номер элемента столбца\n " + _DrawableObject->nameGraph);
    _Graph->yAxis->setLabel(_DrawableObject->fields.first());
    _Graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    _Graph->replot();


    _Graph->addLayer("abovemain", _Graph->layer("main"), QCustomPlot::limAbove);
    _Graph->addLayer("belowmain", _Graph->layer("main"), QCustomPlot::limBelow);
    _Graph->xAxis->grid()->setLayer("belowmain");
    _Graph->yAxis->grid()->setLayer("belowmain");

    _Graph->xAxis->setBasePen(QPen(Qt::black, 1));
    _Graph->yAxis->setBasePen(QPen(Qt::black, 1));
    _Graph->xAxis->setTickPen(QPen(Qt::black, 1));
    _Graph->yAxis->setTickPen(QPen(Qt::black, 1));
    _Graph->xAxis->setSubTickPen(QPen(Qt::black, 1));
    _Graph->yAxis->setSubTickPen(QPen(Qt::black, 1));
    _Graph->xAxis->setTickLabelColor(Qt::black);
    _Graph->yAxis->setTickLabelColor(Qt::black);
    _Graph->xAxis->grid()->setPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    _Graph->yAxis->grid()->setPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    _Graph->xAxis->grid()->setSubGridPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    _Graph->yAxis->grid()->setSubGridPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    _Graph->xAxis->grid()->setSubGridVisible(true);
    _Graph->yAxis->grid()->setSubGridVisible(true);
    _Graph->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    _Graph->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    _Graph->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    _Graph->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    _Graph->xAxis->setLabel( _DrawableObject->fields.first() + "\n " + _DrawableObject->nameGraph + " по таблице " + _DrawableObject->nameTable);
    _Graph->yAxis->setLabel("Данные");
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(240, 240, 240));
    plotGradient.setColorAt(1, QColor(240, 240, 240));
    _Graph->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(240, 240, 240));
    axisRectGradient.setColorAt(1, QColor(240, 240, 240));
    _Graph->axisRect()->setBackground(axisRectGradient);

    _Graph->xAxis->setRange(minXValue*1.05, maxXValue*1.05);
    _Graph->yAxis->setRange(minYValue*1.05, maxYValue*1.05);
}
