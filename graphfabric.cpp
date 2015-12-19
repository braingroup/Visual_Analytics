#include "graphfabric.h"

GraphFabric::GraphFabric()
{

}

GraphFabric::~GraphFabric()
{

}

Graph* GraphFabric::BuildGraph(GraphType graphType, QWidget* _Area)
{
    switch(graphType)
    {
    case GraphType::CIRCLE:
        return new CircleGraph(_Area);
        break;
    case GraphType::COLUMN:
        return new ColumnGraph(_Area);
        break;
    case GraphType::FUNCTION:
        return new FunctionGraph(_Area);
        break;
    default:
        return nullptr;
        break;
    }
}


