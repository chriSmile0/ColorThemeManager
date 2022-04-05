#ifndef THEMEACTIONSWIDGET_H
#define THEMEACTIONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QCoreApplication>
#include <iostream>
using namespace std;

class ThemeActionsWidget : public QWidget 
{
    Q_OBJECT

    public:
        QVBoxLayout *title_and_actions;
        QWidget *actions_widget;
        QHBoxLayout *actions;
        QLabel *title_widget;
        QPushButton *saves;
        QVBoxLayout *links_actions;
        QPushButton *link_modify;
        QPushButton *maj_import_on_link;
        QPushButton *add_color;
        QPushButton *show_pair_source_target;
        QPushButton *color_modify;
        QPushButton *application_theme_on_dr_file;

        ThemeActionsWidget(QWidget * parent = nullptr);
        void setThAct_Widget();
        ~ThemeActionsWidget();

    private:
       
};
#endif //THEMEACTIONSWIDGET_H