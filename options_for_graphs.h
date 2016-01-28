#ifndef OPTIONS_FOR_GRAPHS_H
#define OPTIONS_FOR_GRAPHS_H

#include <QDialog>
#include <QVector>
#include <QComboBox>
#include <QString>

#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include "graphtype.h"

namespace Ui {
class options_for_graphs;
}

struct type_form_field{
    QComboBox *field;
    QLabel *label;
};

class options_for_graphs : public QDialog
{
    Q_OBJECT

public:
    explicit options_for_graphs(QWidget *parent = 0);
    virtual ~options_for_graphs();
    //геттеры
    int getGraphType();
    QVector <QString> getFields();
    QString getNameTable();
    QString getNameGraph();
    //для постройки графика
    virtual void BuildGraph(int _graphType, QWidget* _area, QString _nameGraph, QVector <QString> _fields, QString _nameTable) = 0;
private:
    Ui::options_for_graphs *ui;

    QLabel *namelabel;
    QLineEdit *namegraph; //название графика
    QVector <type_form_field> fields; //значение полей

    void delete_all_fields(); //удаление всех полей
    type_form_field* add_field(QString name_field); //метод добавления полей
public slots:
    void choose_type_graph(int index); //вызывается при выборе графика
    void add_field(); //создание еще одного поля
    void drawit(); //нажатие на кнопку "построить"
};


#endif // OPTIONS_FOR_GRAPHS_H
