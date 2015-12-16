#include "options_for_graphs.h"
#include "ui_options_for_graphs.h"
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

//заполнение тесторвыми данными
void testdata(QComboBox *pole){
    pole->addItem("Не выбрано");
    pole->addItem("строка 1");
    pole->addItem("строка 2");
    pole->addItem("строка 3");
    pole->addItem("строка 4");
}

options_for_graphs::options_for_graphs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options_for_graphs)
{
    ui->setupUi(this);

    //скрываем кнопку добавления полей
    ui->button_add_data->setVisible(0);
    QObject::connect(ui->button_add_data, SIGNAL(clicked()), this, SLOT(add_field()));

    //название графика
    namegraph = new QLineEdit(this);
    namegraph->setText("Новый график");
    namelabel = new QLabel("Название графика", this);
    ui->gridLayout->addWidget(namelabel, 0, 0);
    ui->gridLayout->addWidget(namegraph, 0, 1);

    type_form_field* new_field;

    //выбор таблицы
    new_field = add_field("Таблица");
    testdata(new_field->field); //заполнение тестовыми данными

    //выбор типа графика
    new_field = add_field("Тип графика");
    new_field->field->addItem("Не выбрано");
    new_field->field->addItem("Круговая диаграмма");
    new_field->field->addItem("Столбчатая диаграмма");
    new_field->field->addItem("График");

    //сделать валидацию, только потом закрытие!!!
    QObject::connect(new_field->field, SIGNAL(currentIndexChanged(int)), this, SLOT(choose_type_graph(int)));
    QObject::connect(ui->DrawGraphButton, SIGNAL(clicked()), this, SLOT(drawit()));
}

options_for_graphs::~options_for_graphs()
{
    fields.clear();
    delete ui;
}

//добавление поля с названием
type_form_field* options_for_graphs::add_field(QString name_field) {
    type_form_field news;
    news.field = new QComboBox(this);
    news.label = new QLabel(this);
    news.label->setText(name_field);
    ui->gridLayout->addWidget(news.label, fields.size() + 1, 0);
    ui->gridLayout->addWidget(news.field, fields.size() + 1, 1);
    fields.push_back(news);
    return &fields.last();
}

//добавление пустого поля
void options_for_graphs::add_field() {
    type_form_field* new_field =  add_field("Данные");
    testdata(new_field->field); //заполнение тестовыми данными
    if (fields.size() > 7) {
        ui->button_add_data->setVisible(0);
    }
    return;
}

//удаление лишних параметров
void options_for_graphs::delete_all_fields(){
    while (fields.size() > 2) {
        ui->gridLayout->removeWidget(fields.last().label);
        delete fields.last().label;
        ui->gridLayout->removeWidget(fields.last().field);
        delete fields.last().field;
        fields.pop_back();
    }
}

//выбор типа графика
void options_for_graphs::choose_type_graph(int index) {
    switch (index) {
    case 1: { //круговая диаграмма
        delete_all_fields();
        type_form_field* new_field = add_field("Столбец для анализа");
        testdata(new_field->field); //заполнение тестовыми данными
        ui->button_add_data->setVisible(0);
        break;
    }
    case 2:{ //столбчатая диаграмма
        delete_all_fields();
        type_form_field* new_field = add_field("Ось абсцисс");
        testdata(new_field->field); //заполнение тестовыми данными
        new_field = add_field("Данные");
        testdata(new_field->field); //заполнение тестовыми данными
        ui->button_add_data->setVisible(1);
        break;
    }
    case 3:{ //график
        delete_all_fields();
        type_form_field* new_field = add_field("Ось абсцисс");
        testdata(new_field->field); //заполнение тестовыми данными
        new_field = add_field("Данные");
        testdata(new_field->field); //заполнение тестовыми данными
        ui->button_add_data->setVisible(1);
        break;
    }
    default: { //ничего не выбрано
        delete_all_fields();
    }
    }

}

//проверка введеных данных при отрисовке
void options_for_graphs::drawit() {
    bool valid = 1; //флаг правильности внесенных данных
    //пустое ли название графика
    if (!((namegraph->text()).size())) {
        namelabel->setStyleSheet("color: rgb(255, 51, 0)");
        valid = 0;
    } else {
        namelabel->setStyleSheet(NULL);
    }
    //пустые ли поля графика
    for (int i = 0; i < fields.size(); i++) {
        if (fields[i].field->currentIndex()==0) {
            fields[i].label->setStyleSheet("color: rgb(255, 51, 0)");
            valid = 0;
        } else {
            fields[i].label->setStyleSheet(NULL);
        }
    }
    //если все поля заполнены правильно
    if (valid) {
        emit(close());
    }
}

//функция для отдачи данных
QString options_for_graphs::getdata(){
    QString result = "";
    result += "Название графика: " + namegraph->text() + "\n";
    for (int i = 0; i < fields.size(); i++) {
        result += fields[i].label->text() + ": " +fields[i].field->currentText() +"\n";
    }
    return result;
}

