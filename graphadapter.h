#ifndef GRAPHADAPTER_H
#define GRAPHADAPTER_H

#include <options_for_graphs.h>
#include <graphfabric.h>

class GraphAdapter : public options_for_graphs
{
public:
    GraphAdapter( GraphFabric* p );
    ~GraphAdapter();
    void BuildGraph(int _graphType, QWidget* _area, QString _nameGraph, QVector <QString> _fields, QString _nameTable);
  private:
    GraphFabric* fabric;
    QWidget *area;

};


#endif // GRAPHADAPTER_H
