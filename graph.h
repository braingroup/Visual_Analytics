#ifndef GRAPH_H
#define GRAPH_H

#include "drawablearea.h"
#include "drawableobject.h"



class Graph
{
public:
    Graph();
    virtual ~Graph();
    virtual void Draw() = 0;
protected:
    DrawableArea _DrawableArea;
    DrawableObject _DrawableObject;
};

#endif // GRAPH_H
