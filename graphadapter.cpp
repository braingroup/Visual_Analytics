#include "graphadapter.h"

#include "queryadapter.h"

GraphAdapter::GraphAdapter( GraphFabric* p)
{
    fabric = p;
}
GraphAdapter::~GraphAdapter()
{
    delete fabric;
}

void GraphAdapter::BuildGraph(int _graphType, QWidget *_area, QString _nameGraph, QVector<QString> _fields, QString _nameTable)
{
    GraphType graphType;
    switch(_graphType)
    {
    case 2:
        graphType = GraphType::CIRCLE;
        break;
    case 1:
        graphType = GraphType::COLUMN;
        break;
    case 3:
        graphType = GraphType::FUNCTION;
        break;
    }
    DrawableObject* drawableObject = new QueryAdapter(new QueryResult,  _nameTable, _nameGraph, _fields);
    fabric->BuildGraph(graphType, _area, drawableObject);
}
