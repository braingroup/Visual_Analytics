#ifndef GRAPHFABRIC_H
#define GRAPHFABRIC_H

#include "functiongraph.h"
#include "circlegraph.h"
#include "columngraph.h"
#include "graphtype.h"

class GraphFabric
{
public:
    GraphFabric();
    virtual ~GraphFabric();

    static Graph* BuildGraph(GraphType graphType, QWidget* _Area, DrawableObject * _drawableObject);
};

#endif // GRAPHFABRIC_H
