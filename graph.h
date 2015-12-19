#ifndef GRAPH_H
#define GRAPH_H

#include "drawableobject.h"
#include "qcustomplot.h"



class Graph
{
public:
    Graph();
    virtual ~Graph();
    virtual void Draw(QWidget * _DrawableArea, DrawableObject * _DrawableObject) = 0;
protected:
    QWidget * _DrawableArea;
    DrawableObject* _DrawableObject;
};

#endif // GRAPH_H
