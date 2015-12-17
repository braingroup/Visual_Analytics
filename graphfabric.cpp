#include "graphfabric.h"

GraphFabric::GraphFabric()
{

}

GraphFabric::~GraphFabric()
{

}

Graph* GraphFabric::BuildGraph(GraphType graphType)
{
    switch(graphType)
    {
    case GraphType::CIRCLE:
        return new CircleGraph();
        break;
    case GraphType::COLUMN:
        return new ColumnGraph();
        break;
    case GraphType::FUNCTION:
        return new FunctionGraph();
        break;
    default:
        return nullptr;
        break;
    }
}


