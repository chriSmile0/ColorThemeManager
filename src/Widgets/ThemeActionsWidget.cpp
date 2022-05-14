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
        cout << this->parent()->objectName().toStdString() << endl;
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
    //faire un tableau de qurl dans l'appli
}

int ThemeActionsWidget::compare_string(QString str1,QString str2)//line , file
{
    int size_str1 = str1.length();
    int size_str2 = str2.length();
    int cpt = 0;
    QChar c1;
    QChar c2;
    char ch1;
    char ch2;
    int i = 0;
    for(i = 0 ; (i < size_str2) && (i < size_str1);i++) { 
        ch1 = str1[i].toLatin1();
        ch2 = str2[i].toLatin1();
        cout << ch1 << "," << ch2 << endl;
        if(ch1 == ch2) 
            cpt++;
    }
    for(int i = size_str2 ; i < size_str1 ;i++) {
        ch2 = str1[size_str2].toLatin1();
        if(ch2 != ' ')
            cpt = -1;
    }
    return cpt;
}

//pas de lien de plus de 500 caracteres
void ThemeActionsWidget::on_Link_Modify_clicked() 
{
    //fonctionne
    //Changer l'url de themewidget
    //search file
    QString str = title_widget->text();
    QString file("");
    int size = str.length();
    int j = size;
    for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
    for(j=j+1; j < size; j++) 
        file += str[j];
    //end search file
    cout << file.toStdString() << endl;


    QDialog *Dbox = new QDialog();
    Dbox->setWindowTitle("Modification du lien du thème");
    QVBoxLayout *vlayout = new QVBoxLayout;
    QVBoxLayout *v_fields_layout = new QVBoxLayout;
    Dbox->setFixedSize(280,150);
    QLabel *link = new QLabel(tr("Nouveau lien du thème : "));
    QLineEdit *field_link = new QLineEdit();
    QPushButton *valider = new QPushButton("Valider lien");
    vlayout->setSpacing(20);
    v_fields_layout->addWidget(link);
    v_fields_layout->addWidget(field_link);
    v_fields_layout->setAlignment(link,Qt::AlignHCenter);
    v_fields_layout->setSpacing(0);
    vlayout->addLayout(v_fields_layout);
    vlayout->addWidget(valider);
    Dbox->setLayout(vlayout);
    Dbox->show();
    QObject::connect(valider, &QPushButton::clicked ,[=]() {
        QFile links("links");
        int taille_last_line = 0;
        QString save_line("");
        if(links.open(QIODevice::ReadWrite)) {
            QTextStream in(&links);
            int goon = 1;
            QString line;
            while ((!in.atEnd()) && (goon)) {
                line = in.readLine();
                int compare = 0;
                if((compare =compare_string(line,file)) > 0) {
                    goon = 0;
                    taille_last_line += compare;
                    line = file;
                }
                else {
                    taille_last_line += line.length();
                }
            }
        }
        links.close();
        if(links.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream oute(&links);
            links.seek(taille_last_line);
            oute << " :" << field_link->text() << Qt::endl;
        }
        links.close();
        Dbox->close();
    });
}

QString ThemeActionsWidget::find_color(int id,int id_max,QString line)
{
    int size_line = line.length();
    int decal = 1;
    if(id_max >= 10) {
        decal++;
        if(id_max >= 100) {
            decal++;
            if(id_max >= 1000)
                decal++;
        }
    }

    QString decal_str = "";
    for(int i = 0 ; i < decal ; i++)
        decal_str += ' ';
    QString src(decal_str+"  source : ");
    QString tgt("");
    int j = size_line;
    cout << j << endl;
    for(j = 0; j < size_line && (line[j] != '#') ;j++) ;
    int i = j;
    for(i = j; i < size_line  && (line[i] != '"') ; i++) 
        src += line[i];

    int cpt_autre_decal = 8-(i-j);
    for(int k = 0 ; k < cpt_autre_decal;k++)
        src += ' ';
    src += "  cible : ";

    for(j = 0; j < size_line && (line[j] != '#') ;j++) ;
    for(i = j; i < size_line  && (line[i] != '"') ; i++)
        src += line[i];
    
    return src;
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
    //demander le nombre de couleurs a voir 
    //installer une scrollbar dans la fenêtre de vision
    // ou afficher dans la fenêtre de la partie de l'ihm

    //on part d'abord sur la fenêtre de dialogue
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
    Dbox->setWindowTitle("Voir paires de couleurs");
    QVBoxLayout *vlayout = new QVBoxLayout;
    Dbox->setFixedSize(200,150);
    QHBoxLayout *hlayout = new QHBoxLayout;
    QLabel *nb_colors_to_see = new QLabel("Nombre de couleurs : \n(maximum = "+QString::number((id-2))+")");
    QSpinBox *field_nb_colors = new QSpinBox();
    field_nb_colors->setMinimum(1);
    field_nb_colors->setMaximum(id-2);
    //QWidget *wid_hlayout = QWidget(hlayout);
    QPushButton *valider = new QPushButton("Valider choix");
    hlayout->addWidget(nb_colors_to_see);
    hlayout->addWidget(field_nb_colors);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(valider);
    Dbox->setLayout(vlayout);
    Dbox->show();


    QObject::connect(valider, &QPushButton::clicked ,[=]() {
        //Verification des champs a faire venir d'une autre fonction plus haut //
        Dbox->close();
        //Pour mettre dans le QLayout a droit de l'ihm 
        /*QLabel *lol = new QLabel("ok");
        
        /QList<QLayout*> subwidgets = this->parent()->parent()->findChildren<QLayout*>();
        QListIterator<QLayout*> it(subwidgets); // iterate through the list of widgets
        QLayout *awiget;

        while (it.hasNext()) {//find child
            awiget = it.next(); // take each widget in the list
            cout << awiget->objectName().toStdString() << endl;
            if(awiget->objectName() == "verticalLayout_2") {
                cout << "okkkkkk" << endl;
                awiget->addWidget(lol);
            }
        }*/
        cout << field_nb_colors->value() << endl;
        QDialog *dialBox = new QDialog();
        dialBox->setWindowTitle("Paires");
        dialBox->setFixedSize(420,300);
        QVBoxLayout *horizontalLayout = new QVBoxLayout(dialBox);
        QScrollArea *scrollArea = new QScrollArea(dialBox);
        scrollArea->setWidgetResizable(true);
        QWidget * w = new QWidget();
        w->setGeometry(QRect(0, 0, 420, 300));
        QVBoxLayout *v_box_layout_2 = new QVBoxLayout(w);
        QVBoxLayout *v_box_layout = new QVBoxLayout();
        v_box_layout->setSpacing(1);

        v_box_layout_2->addLayout(v_box_layout);
        scrollArea->setWidget(w);
        horizontalLayout->addWidget(scrollArea);
       

        QFile outputFile("./themes/"+file);
        int id_color = 0;
        QString tgt = "";
        QString src = "";
        int stop = field_nb_colors->value()+1;
        if(outputFile.open(QIODevice::ReadOnly)) {
            QTextStream in(&outputFile);
            while (id_color < stop) {
                QString line = in.readLine();
                if(id_color > 0) {
                    QLabel *color = new QLabel("couleur : "+QString::number((id_color))+find_color(id_color,(id-2),line));
                    v_box_layout->addWidget(color);
                }
                id_color++;
            }
        }
        outputFile.close();
        dialBox->show();
    });
}
void ThemeActionsWidget::on_Color_Modify_clicked() 
{
    //Tant que l'utilisateur le désir il peut modifier
    //les couleurs d'un fichier .xml
    //Reprendre l'idée de la création des couleurs dans mainwindow.cpp

    //************************************************CELUI CI MTN***********
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

