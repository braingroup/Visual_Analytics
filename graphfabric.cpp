#include "graphfabric.h"

GraphFabric::GraphFabric()
{

}

GraphFabric::~GraphFabric()
{

}

Graph* GraphFabric::BuildGraph(GraphType graphType, QWidget* _Area, DrawableObject * _drawableObject)
{
    switch(graphType)
    {
    case GraphType::CIRCLE:
        return new CircleGraph(_Area, _drawableObject);
        break;
    case GraphType::COLUMN:
        return new ColumnGraph(_Area, _drawableObject);
        break;
    case GraphType::FUNCTION:
        return new FunctionGraph(_Area, _drawableObject);
        break;
    default:
        return nullptr;
        break;
    }
}
