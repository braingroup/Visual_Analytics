#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <QString>
#include <QVector>

class DrawableObject
{
public:
    QString nameTable;
    QString nameGraph;
    QVector <QString> fields;

    //переопределено будет адаптером
    virtual QVector<double> getValues(QString _nameField, QString _nameTable) = 0;
};



#endif // DRAWABLEOBJECT_H
