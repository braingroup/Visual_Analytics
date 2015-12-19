#include "circlegraph.h"

CircleGraph::CircleGraph()
{

}

CircleGraph::CircleGraph(QWidget *_Area)
{
    Draw(_Area,  _DrawableObject);
}

CircleGraph::~CircleGraph()
{

}

void CircleGraph::Draw(QWidget* _Area, DrawableObject * _DrawableObject)
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    QCustomPlot* _Graph = new QCustomPlot(_Area);
    _Graph->setFixedSize(_Area->width(), _Area->height());
    qDebug() << _Area->width() << " " << _Area->height() << " " << _Graph->width() << " " << _Graph->height();
    _Graph->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    _Graph->addGraph();
    _Graph->graph(0)->setData(x, y);
    _Graph->xAxis->setLabel("X");
    _Graph->yAxis->setLabel("Y");
    _Graph->xAxis->setRange(-1, 1);
    _Graph->yAxis->setRange(0, 1);
    _Graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    _Graph->replot();
}

