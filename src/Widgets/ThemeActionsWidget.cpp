#include "ThemeActionsWidget.h"


ThemeActionsWidget::ThemeActionsWidget(QWidget * parent) 
    :QWidget(parent)
{
    title_and_actions  = new QVBoxLayout(this);
    title_widget = new QLabel();
    title_widget->setText("Actions sur un thème");
    title_widget->setAlignment(Qt::AlignCenter);
    title_widget->setStyleSheet("background-color: lightblue");
    title_and_actions->addWidget(title_widget,1);

    actions_widget = new QWidget(this);
    
    

    actions = new QHBoxLayout(actions_widget);
    saves = new QPushButton("Sauvegarder");
    saves->setMinimumSize(QSize(0,70));
    saves->setMaximumSize(QSize(1600,100));
    actions->addWidget(saves,1);

    links_actions = new QVBoxLayout(this);
    
    //links_actions->setMargin(0);
    maj_import_on_link = new QPushButton("Maj/Importation \nd'un thème par\nlien internet");
    links_actions->addStretch(0);
    maj_import_on_link->setMaximumSize(QSize(1600,70));
    links_actions->addWidget(maj_import_on_link,1);
    link_modify = new QPushButton("Modifier le lien");
    link_modify->setMaximumSize(QSize(1600,30));
    links_actions->addWidget(link_modify,1);
    links_actions->addStretch(0);
    links_actions->setContentsMargins(0,0,0,0);
    links_actions->setSpacing(2);
    
    
    actions->addLayout(links_actions,1);
    


    add_color = new QPushButton("Ajouter une \nnouvelle\npaire de \ncouleurs");
    add_color->setMaximumSize(QSize(1600,100));
    actions->addWidget(add_color,1);

    show_pair_source_target = new QPushButton("Afficher une \nliste de paires \nde couleurs\n sources/target");
    show_pair_source_target->setMaximumSize(QSize(1600,100));
    actions->addWidget(show_pair_source_target,1);
    color_modify = new QPushButton("Modifier les\ncouleurs");
    color_modify->setMaximumSize(QSize(1600,100));
    actions->addWidget(color_modify,1);
    application_theme_on_dr_file = new QPushButton("Appliquer le \nthème sur un\ndossier ou une \nliste de\nfichiers");
    application_theme_on_dr_file->setMaximumSize(QSize(1600,100));
    actions->addWidget(application_theme_on_dr_file,1);

    actions->addStretch(1);
    title_and_actions->addWidget(actions_widget,4);
    title_and_actions->setSpacing(0);
    

   /* title_and_actions->setStretch(0,0);
    title_and_actions->setStretch(1,2);*/


}

void ThemeActionsWidget::setThAct_Widget()
{


}



ThemeActionsWidget::~ThemeActionsWidget()
{

}

