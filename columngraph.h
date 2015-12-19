#ifndef COLUMNGRAPH_H
#define COLUMNGRAPH_H

#include "graph.h"


class ColumnGraph : public Graph
{
public:
    ColumnGraph();
    ColumnGraph(QWidget* _Area);
    ~ColumnGraph();
    void Draw(QWidget* _Area, DrawableObject * _DrawableObject);
};

#endif // COLUMNGRAPH_H
