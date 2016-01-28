#ifndef FUNCTIONGRAPH_H
#define FUNCTIONGRAPH_H

#include "graph.h"

class FunctionGraph : public Graph
{
public:
    FunctionGraph();
    FunctionGraph(QWidget* _Area, DrawableObject * _DrawableObject);
    ~FunctionGraph();
    void Draw(QWidget* _Area, DrawableObject * _DrawableObject);
};

#endif // FUNCTIONGRAPH_H

