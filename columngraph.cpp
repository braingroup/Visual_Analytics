#include "columngraph.h"

ColumnGraph::ColumnGraph()
{

}

ColumnGraph::ColumnGraph(QWidget* _Area, DrawableObject * _DrawableObject)
{
    Draw(_Area, _DrawableObject);
}

ColumnGraph::~ColumnGraph()
{

}

void ColumnGraph::Draw(QWidget* _Area, DrawableObject * _DrawableObject)
{
    QCustomPlot* customPlot = new QCustomPlot(_Area);
    customPlot->setFixedSize(_Area->width(), _Area->height());
    // prepare data:
    QVector<double> y;
    y = _DrawableObject->getValues(_DrawableObject->fields.first(), _DrawableObject->nameTable);

    QVector<double> x;
    for (int i = 0; i < y.size(); i++) {
        x.push_back(i);
    }

    QCPBars *bars1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(bars1);
    bars1->setData(x, y);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    customPlot->addLayer("abovemain", customPlot->layer("main"), QCustomPlot::limAbove);
    customPlot->addLayer("belowmain", customPlot->layer("main"), QCustomPlot::limBelow);
    customPlot->xAxis->grid()->setLayer("belowmain");
    customPlot->yAxis->grid()->setLayer("belowmain");

    customPlot->xAxis->setBasePen(QPen(Qt::black, 1));
    customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
    customPlot->xAxis->setTickPen(QPen(Qt::black, 1));
    customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
    customPlot->xAxis->setSubTickPen(QPen(Qt::black, 1));
    customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));
    customPlot->xAxis->setTickLabelColor(Qt::black);
    customPlot->yAxis->setTickLabelColor(Qt::black);
    customPlot->xAxis->grid()->setPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(70, 70, 70), 1, Qt::DotLine));
    customPlot->xAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->xAxis->setLabel("Номер значения в строке " + _DrawableObject->fields.first() + "\n " + _DrawableObject->nameGraph + " по таблице " + _DrawableObject->nameTable);
    customPlot->yAxis->setLabel(_DrawableObject->fields.first());
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(240, 240, 240));
    plotGradient.setColorAt(1, QColor(240, 240, 240));
    customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(240, 240, 240));
    axisRectGradient.setColorAt(1, QColor(240, 240, 240));
    customPlot->axisRect()->setBackground(axisRectGradient);

    customPlot->xAxis->setRange(x.first()*1.05, x.last()*1.05);
    customPlot->yAxis->setRange(y.first()*1.05, y.last()*1.05);
}

