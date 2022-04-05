#include "ThemeActionsWidget.h"
#include "mainwindow.h"


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
    saves->setObjectName(QString::fromUtf8("Save_Theme"));
    QObject::connect(saves, &QPushButton::clicked ,[=] {
        this->on_Save_Theme_clicked();
    });
    saves->setMinimumSize(QSize(0,70));
    saves->setMaximumSize(QSize(1600,100));
    actions->addWidget(saves,1);
    links_actions = new QVBoxLayout(this);
    
    //links_actions->setMargin(0);
    maj_import_on_link = new QPushButton("Maj/Importation \nd'un thème par\nlien internet");
    maj_import_on_link->setObjectName(QString::fromUtf8("Maj_Imp_Link_Theme"));
    QObject::connect(maj_import_on_link, &QPushButton::clicked ,[=] {
        this->on_Maj_Imp_Link_Theme_clicked();
    });
    links_actions->addStretch(0);
    maj_import_on_link->setMaximumSize(QSize(1600,70));
    links_actions->addWidget(maj_import_on_link,1);
    link_modify = new QPushButton("Modifier le lien");
    link_modify->setObjectName(QString::fromUtf8("Link_Modify"));
    QObject::connect(link_modify, &QPushButton::clicked ,[=] {
        this->on_Link_Modify_clicked();
    });
    link_modify->setMaximumSize(QSize(1600,30));
    links_actions->addWidget(link_modify,1);
    links_actions->addStretch(0);
    links_actions->setContentsMargins(0,0,0,0);
    links_actions->setSpacing(2);
    
    
    actions->addLayout(links_actions,1);
    add_color = new QPushButton("Ajouter une \nnouvelle\npaire de \ncouleurs");
    add_color->setObjectName(QString::fromUtf8("Add_Color"));
    QObject::connect(add_color, &QPushButton::clicked ,[=] {
        this->on_Add_Color_clicked();
    });
    add_color->setMaximumSize(QSize(1600,100));
    actions->addWidget(add_color,1);

    show_pair_source_target = new QPushButton("Afficher une \nliste de paires \nde couleurs\n sources/target");
    show_pair_source_target->setObjectName(QString::fromUtf8("Show_Pair_Source_Target"));
    QObject::connect(show_pair_source_target, &QPushButton::clicked ,[=] {
        this->on_Show_Pair_Source_Target_clicked();
    });
    show_pair_source_target->setMaximumSize(QSize(1600,100));
    actions->addWidget(show_pair_source_target,1);
    color_modify = new QPushButton("Modifier les\ncouleurs");
    color_modify->setObjectName(QString::fromUtf8("Color_Modify"));
    QObject::connect(color_modify, &QPushButton::clicked ,[=] {
        this->on_Color_Modify_clicked();
    });
    color_modify->setMaximumSize(QSize(1600,100));
    actions->addWidget(color_modify,1);
    application_theme_on_dr_file = new QPushButton("Appliquer le \nthème sur un\ndossier ou une \nliste de\nfichiers");
    application_theme_on_dr_file->setObjectName(QString::fromUtf8("Application_Theme_On_Dr_File"));
    QObject::connect(add_color, &QPushButton::clicked ,[=] {
        this->on_Application_Theme_On_Dr_File_clicked();
    });
    application_theme_on_dr_file->setMaximumSize(QSize(1600,100));
    actions->addWidget(application_theme_on_dr_file,1);

    actions->addStretch(1);
    title_and_actions->addWidget(actions_widget,4);
    title_and_actions->setSpacing(0);
}

void ThemeActionsWidget::on_Save_Theme_clicked() 
{
    // ?
}
void ThemeActionsWidget::on_Maj_Imp_Link_Theme_clicked() 
{
    //Attribuer un url a un themewidget
}
void ThemeActionsWidget::on_Link_Modify_clicked() 
{
    //Changer l'url de themewidget
}

void ThemeActionsWidget::on_Add_Color_clicked() 
{
    QDir direct("themes/");
    //search file
    QString str = title_widget->text();
    QString file("");			
    int size = str.length();
    int j = size;
    for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
    for(j=j+1; j < size; j++) 
        file += str[j];
    //end search file
    QFile modif_file("./themes/"+file);
    int size_colors = 10;
    //</colors> = 10
    QFile::resize("./themes/"+file,modif_file.size()-size_colors);
    QFile outputFile("./themes/"+file);
    int id = 0;
    if(outputFile.open(QIODevice::ReadOnly)) {
       	QTextStream in(&outputFile);
		while (!in.atEnd()) {
			QString line = in.readLine();
            id++;
        }
    }
    outputFile.close();

    QDialog *Dbox = new QDialog();
    Dbox->setWindowTitle("Choix des couleurs");
    QVBoxLayout *vlayout = new QVBoxLayout;
    Dbox->setFixedSize(200,150);
    QLabel *source = new QLabel(tr("Source"));
    QLabel *cible = new QLabel("Cible");
    QLineEdit *field_src = new QLineEdit();
    QLineEdit *field_tgt = new QLineEdit();
    QString nb_colors("");
    QPushButton *valider = new QPushButton("Valider couleur");
    vlayout->addWidget(source);
    vlayout->addWidget(field_src);
    vlayout->addWidget(cible);
    vlayout->addWidget(field_tgt);
    vlayout->addWidget(valider);
    Dbox->setLayout(vlayout);
    Dbox->show();
    
    QObject::connect(valider, &QPushButton::clicked ,[=]() {
        //Verification des champs a faire venir d'une autre fonction plus haut //
        int corrects_fields = MainWindow::validation_source_target(
                    field_src->text(),field_tgt->text());
        if(corrects_fields == 3) {
            QString *src = new QString(field_src->text());
            QString *tgt = new QString(field_tgt->text());
            field_src->setText("");
            field_tgt->setText("");
            //nos champs sont bon on peut les inclurent 
            QFile outputFil("./themes/"+file);
            if(outputFil.open(QIODevice::Append)) {
                QTextStream oute(&outputFil);
                oute << MainWindow::create_line_source_target(*src,*tgt,id) << Qt::endl;
                oute << "</colors>" << Qt::endl;
                outputFil.close();
            }
            Dbox->close();
        }
        else {
            QString error_src_tgt("");
            if(corrects_fields == 2)
                error_src_tgt += "Erreur couleur source";
            else if(corrects_fields == 1)
                error_src_tgt += "Erreur couleur cible";
            else 
                error_src_tgt += "Erreur sur les 2 champs";
            QMessageBox msgBox;
            msgBox.setWindowTitle("Erreur Couleurs");
            msgBox.setText(error_src_tgt +", suivez le modele : #rrggbbaa");
            msgBox.exec();
        }
    });
}

void ThemeActionsWidget::on_Show_Pair_Source_Target_clicked() 
{
    //ouvrir le fichier et le lire dans une QDialog ?
    //ou un minimum de mise en page
}
void ThemeActionsWidget::on_Color_Modify_clicked() 
{
    //Tant que l'utilisateur le désir il peut modifier
    //les couleurs d'un fichier .xml
    //Reprendre l'idée de la création des couleurs dans mainwindow.cpp
}
void ThemeActionsWidget::on_Application_Theme_On_Dr_File_clicked()
{
    //Fonction principale qui consiste a appliquer les 
    //couleurs d'un thème sur un fichier couleur
    //en modifiant les couleurs que l'on trouve dans les sources
    //du fichier en target de ce dernier 

    //Pour le choix on ouvrira une QDialog pour choisir entre la liste
    //de fichier et un dossier complet .
    //bien-sür la liste peut contenir 0 ou 1 seul fichier 
}

ThemeActionsWidget::~ThemeActionsWidget()
{

}

