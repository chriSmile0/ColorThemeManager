#ifndef THEMEACTIONSWIDGET_H
#define THEMEACTIONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QtCore>
#include <QCoreApplication>
#include <QSpinBox>
#include "mainwindow.h" //for create line theme and ...
#include "ColorPair.h"
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
        QPushButton *application_theme_on_file;
        QPushButton *application_theme_on_directory;
        QVBoxLayout *dr_file_layout;

        ThemeActionsWidget(QWidget * parent = nullptr);
        void setThAct_Widget();
        ~ThemeActionsWidget();

        void on_Save_Theme_clicked();
        void on_Maj_Imp_Link_Theme_clicked();
        void on_Link_Modify_clicked();
        void on_Add_Color_clicked();//check
        void on_Show_Pair_Source_Target_clicked();//step 2
        void on_Color_Modify_clicked();//next
        void on_Application_Theme_On_Dr_File_clicked();//end
        QString find_color(int id_max,QString line);
        int compare_string(QString str1,QString str2);
        int  extract_color_id(QString line);
        int main_application(QString filename_color,QString filename_theme,ColorPairSet cps);
        QString extract_source_color_in_line(QString color_line); 

    private:
       
};
#endif //THEMEACTIONSWIDGET_H