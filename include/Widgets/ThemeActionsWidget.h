#ifndef THEMEACTIONSWIDGET_H
#define THEMEACTIONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QCoreApplication>
#include "mainwindow.h" //for create line theme and ...
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

        void on_Save_Theme_clicked();
        void on_Maj_Imp_Link_Theme_clicked();
        void on_Link_Modify_clicked();
        void on_Add_Color_clicked();
        void on_Show_Pair_Source_Target_clicked();
        void on_Color_Modify_clicked();
        void on_Application_Theme_On_Dr_File_clicked();


    private:
       
};
#endif //THEMEACTIONSWIDGET_H