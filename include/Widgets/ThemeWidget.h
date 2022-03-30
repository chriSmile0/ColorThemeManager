#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QCoreApplication>
#include <iostream>
using namespace std;

class ThemeWidget : public QWidget 
{
    Q_OBJECT


    public:
        QVBoxLayout *th_3;
        QWidget *widget_t;
        QWidget *widget_c;
        QPushButton *pushButton;
        QIcon icon;
        QIcon icon2;
        QLabel *label;
        QLabel *hide_label;
        QString theme_name;
        int id;

        ThemeWidget(QWidget * parent = nullptr);
        void setTh_Widget(QString str,int id);
        QString getname() const;
        int getid() const;
        ~ThemeWidget();

    private:
       
};
#endif // THEMEWIDGET_H