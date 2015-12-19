#ifndef CIRCLEGRAPH_H
#define CIRCLEGRAPH_H

#include "graph.h"


class CircleGraph : public Graph
{
public:
    CircleGraph();
    CircleGraph(QWidget* _Area);
    ~CircleGraph();
    void Draw(QWidget* _Area, DrawableObject * _DrawableObject);
};

#endif // CIRCLEGRAPH_H
