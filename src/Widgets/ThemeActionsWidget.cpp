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
   /* QWidget *contenuer_application = new QWidget();
    QVBoxLayout */
    //QWidget *conteneur_dr_file
    dr_file_layout = new QVBoxLayout;
    application_theme_on_file = new QPushButton("Fichiers");
    application_theme_on_file->setObjectName(QString::fromUtf8("Application_Theme_On_File"));
    application_theme_on_directory = new QPushButton("Dossier");
    application_theme_on_directory->setObjectName(QString::fromUtf8("Application_Theme_On_Directory"));

    /*dr_file_layout->addWidget(application_theme_on_file);
    dr_file_layout->addWidget(application_theme_on_directory);*/

    QObject::connect(application_theme_on_dr_file, &QPushButton::clicked ,[=] {
        this->on_Application_Theme_On_Dr_File_clicked();
    });
    application_theme_on_dr_file->setMaximumSize(QSize(1600,100));
    application_theme_on_directory->setMaximumSize(QSize(0,0));
    application_theme_on_file->setMaximumSize(QSize(0,0));
    dr_file_layout->addWidget(application_theme_on_dr_file);
    //dr_file_layout->addWidget(application_theme_on_file);
    //dr_file_layout->addWidget(application_theme_on_directory);
    //actions->addWidget(application,1);
    actions->addLayout(dr_file_layout);

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

QString ThemeActionsWidget::find_color(int id_max,QString line)//in theme
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

    for(j = 0; j < size_line && (line[j] != '#') ;j++);
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

    QFile modif_file("./themes/"+file);
    int size_colors = 10;
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
        int corrects_fields = MainWindow::validation_source_target(
                    field_src->text(),field_tgt->text());
        if(corrects_fields == 3) {
            QString *src = new QString(field_src->text());
            QString *tgt = new QString(field_tgt->text());
            field_src->setText("");
            field_tgt->setText("");
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
    QDir direct("themes/");

    QString str = title_widget->text();
    QString file("");			
    int size = str.length();
    int j = size;
    for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
    for(j=j+1; j < size; j++) 
        file += str[j];

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
    QLabel *nb_colors_to_see = new QLabel("Nombre de couleurs : \n(maximum = "+
                                            QString::number((id-2))+")");
    QSpinBox *field_nb_colors = new QSpinBox();
    field_nb_colors->setMinimum(1);
    field_nb_colors->setMaximum(id-2);

    QPushButton *valider = new QPushButton("Valider choix");
    hlayout->addWidget(nb_colors_to_see);
    hlayout->addWidget(field_nb_colors);
    vlayout->addLayout(hlayout);
    vlayout->addWidget(valider);
    Dbox->setLayout(vlayout);
    Dbox->show();


    QObject::connect(valider, &QPushButton::clicked ,[=]() {
        Dbox->close();

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
                    QLabel *color = new QLabel("couleur : "+
                            QString::number((id_color))+find_color((id-2),line));
                    v_box_layout->addWidget(color);
                }
                id_color++;
            }
        }
        outputFile.close();
        dialBox->show();
    });
}

int ThemeActionsWidget::extract_color_id(QString line) 
{
    int size_line = line.length();
    int i = 0;
    char ch;
    char ch2;
    while(((ch = line[i].toLatin1())!= 'i')&& (i+1 < size_line) && 
        ((ch2 = line[i+1].toLatin1()) != 'd')) 
        i++;
    i += 12; //on suppose que tout nos xml s'écrivent "Couleur ID"
    while(((ch = line[i].toLatin1()) != '"') && (i < size_line)) 
        i++;
  
    int j = i;
    while(((ch = line[j].toLatin1()) != ' ') && (j > 0))
        j--;
    QString id("");
    for(; j < i ; j++)
        id += line[j];
    return id.toInt();
}

void ThemeActionsWidget::on_Color_Modify_clicked() 
{
    QDir direct("themes/");
    QString str = title_widget->text();
    QString file("");			
    int size = str.length();
    int j = size;
    for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
    for(j=j+1; j < size; j++) 
        file += str[j];
    QFile modif_file("./themes/"+file);

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
    Dbox->setWindowTitle("Modifier des couleurs");
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;
    Dbox->setFixedSize(390,150);
    QLabel *cible = new QLabel("Couleur a modifiée (max = "+QString::number((id-2))+")");
    QSpinBox *field_nb_colors = new QSpinBox();
    field_nb_colors->setMinimum(1);
    field_nb_colors->setMaximum(id-2);
    hlayout->addWidget(cible);
    hlayout->addWidget(field_nb_colors);
    QLabel *choice = new QLabel("");
    vlayout->addLayout(hlayout);
    vlayout->addWidget(choice);

    QPushButton *valider = new QPushButton("Valider choix");
    vlayout->addWidget(valider);
    Dbox->setLayout(vlayout);
    Dbox->show();
    int id_color = 0 ;
    QObject::connect(field_nb_colors, QOverload<int>::of(&QSpinBox::valueChanged) ,[=]() {
        int id_color = field_nb_colors->value();
        int goon = 1;
        QFile outputFil("./themes/"+file);
        if(outputFil.open(QIODevice::ReadWrite)) {
            QTextStream in(&outputFil);
            QString line("");
            while((!in.atEnd()) && (goon)) {
                line = in.readLine();
                if(extract_color_id(line) == id_color)
                    goon = 0;
            }
            if(goon == 0)
                choice->setText(find_color(id-2,line));
        } 
    }); 
    QDialog *Dbox2 = new QDialog();
    Dbox2->setWindowTitle("Choix des couleurs");
    QVBoxLayout *vlayout2 = new QVBoxLayout;
    Dbox2->setFixedSize(200,150);
    QLabel *source = new QLabel(tr("Source"));
    QLabel *cible_c = new QLabel("Cible");
    QLineEdit *field_src = new QLineEdit();
    QLineEdit *field_tgt = new QLineEdit();
    QString nb_colors("");
    QPushButton *valider2 = new QPushButton("Valider couleur");
    vlayout2->addWidget(source);
    vlayout2->addWidget(field_src);
    vlayout2->addWidget(cible_c);
    vlayout2->addWidget(field_tgt);
    vlayout2->addWidget(valider2);
    Dbox2->setLayout(vlayout2);

    QObject::connect(valider, &QPushButton::clicked ,[=]() {
        Dbox->close();
        Dbox2->show(); 
    });
    QObject::connect(valider2, &QPushButton::clicked ,[=]() {
        int corrects_fields = MainWindow::validation_source_target(
                    field_src->text(),field_tgt->text());
        if(corrects_fields == 3) {
            QString *src = new QString(field_src->text());
            QString *tgt = new QString(field_tgt->text());
            field_src->setText("");
            field_tgt->setText("");

            QFile outputFil("./themes/"+file);
            if(outputFil.open(QIODevice::ReadWrite)) {
                QTextStream oute(&outputFil);
                int cpt = 0;
                int final_id_color = field_nb_colors->value();
                int taille_parcouru = 0;
                while((!oute.atEnd()) && (cpt < final_id_color)) {
                    QString linE = oute.readLine();
                    cout << linE.length() << endl;
                    taille_parcouru += linE.length()+1;
                    cpt++;
                }
                outputFil.seek(taille_parcouru);
                oute << MainWindow::create_line_source_target(*src,*tgt,id_color) << Qt::endl;
                outputFil.close();
            }
            Dbox2->close();
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

QString ThemeActionsWidget::extract_source_color_in_line(QString color_line) 
{
    QString retour("");
    int size_line = color_line.length();
    int i = 0;
    char c;
    int nb_color = 0;
    while(i < size_line) {
        if((c = color_line[i].toLatin1()) == '#') {
            while((i < size_line) && ((c = color_line[i].toLatin1()) != ' ')) {
                retour += c;
                i++;
            }
            nb_color++;
            retour += ',';
        }
        i++;
    }
    return retour;
}

int ThemeActionsWidget::main_application(QString filename_color,
                    QString filename_theme,ColorPairSet cps)//renvoie le nombre de couleurs modifiés
{
    QFile f_color(filename_color);
    QFile f_theme(filename_theme);

    int nb_colors_modify_in_file = 0;
    int color_in_file = 0;
    int id = 0;
    int taille_parcouru = 0;
    int nb_lignes = 0;
    ColorPairSet cp_result;
    QList<QString> list_lines = QList<QString>();
    if(f_color.open(QIODevice::ReadWrite)) {
        QTextStream in(&f_color);
        while(!in.atEnd()) {
            nb_lignes++;
            int color_line = 0;
            int nb_color_line = 0;
            QString line = in.readLine();
            
            int size_line = line.length();
            QList<int> list_index = QList<int>();
            int id_in_line = 0;
            int possible_color = -1;
            for(int i = 0 ; i < size_line ;i++) {
                QChar c(line[i]);
				if(possible_color == -1) {
					if(c.toLatin1() == '#') 
						possible_color = i;
				}
				else {
					char letter = c.toLatin1();
					int line_int = (int) letter;
					if((line_int >= '0' && (line_int <= '9')) || 
						((line_int >= 'a') && (line_int <= 'f'))) 
							color_line++;
					else {
                        color_line = 0;
						possible_color = -1;
					}
					if(color_line == 8) {
						color_line = 0;
                        list_index.append(possible_color);
                        possible_color = -1;
						nb_color_line++;
					}
				}
                
			}
            QString extract = extract_source_color_in_line(line);
            int size_extract = extract.length();
            char c;
            QString color("#........");
            int found_color = 0;
            int cpt_color = 8;
            while((size_extract>=0)) {
                if(found_color == 1) {
                    if(((c = extract[size_extract].toLatin1())==',')
                            ||(size_extract == 0)) {
                        found_color = 0;
                        color_in_file++;
                        cout << "color file :" << color_in_file << endl;
                        QString result(cps.in_set(color));
                        if(result!= "") {
                            ColorPair cp(QString::number(id),fromRGBA(color),fromRGBA(result));
                            cp_result.add_in_set(cp);
                            int debut = list_index[id_in_line];
                            int result_size = result.length();
                            for(int i = 0 ; i < result_size; i++)
                                line[i+debut] = result[i];
                            id++;
                        }
                        id_in_line++;
                        cpt_color = 8;
                    }
                    else {
                        color[cpt_color] = c;
                        cpt_color--;
                    }
                }
                if((c = extract[size_extract].toLatin1())==',') {
                    found_color = 1;
                }
                size_extract--;
            }
            list_lines.append(line);
            taille_parcouru += size_line;
        }
        nb_colors_modify_in_file += id;
        f_color.close();       
    }
    QFile::resize(filename_color,0);
    QFile new_f_color(filename_color);
    if(new_f_color.open(QIODevice::Append)) {
        for(int i = 0 ; i < nb_lignes;i++) {
            QTextStream oute(&new_f_color);
            oute << list_lines[i] << Qt::endl;
        }
    }
    if(color_in_file == 0)
            return -1;
    return nb_colors_modify_in_file;
}

void ThemeActionsWidget::on_Application_Theme_On_Dr_File_clicked()
{
    application_theme_on_dr_file->setMaximumSize(QSize(1600,0));
    application_theme_on_file->setMaximumSize(QSize(1600,48));
    application_theme_on_file->show();
    dr_file_layout->addWidget(application_theme_on_file);
    application_theme_on_directory->setMaximumSize(QSize(1600,48));
    application_theme_on_directory->show();
    dr_file_layout->addWidget(application_theme_on_directory);
    dr_file_layout->setSpacing(0);

    QObject::connect(application_theme_on_directory, &QPushButton::clicked ,[=]() {
        QString directory_name = QFileDialog::getExistingDirectory(this,
            tr("Choisir un dossier "), "/home");

        QString str = title_widget->text();
        QString file_theme("");			
        int size = str.length();
        int j = size;
        for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
        for(j=j+1; j < size; j++) 
            file_theme += str[j];

        //inclure le cps et le xml reader ici 
        XMLReader *theme_read = new XMLReader();
        QString dire("");			
        size = directory_name.length();
        j = size;
        for(j = size-1 ; j > 0 && (directory_name[j] != '/') ;j--);
        for(j=j+1; j < size; j++) 
            dire += directory_name[j];

        QDir direct(directory_name);
		if (!direct.exists())
			direct.mkpath(".");
	    QFileInfoList list = direct.entryInfoList();
        int nb_files = list.size();
        cout << "nbfiles " << endl;
        int nb_file_modifier = 0;
        int nb_color_file = 0;
        QList<QString> files_names = QList<QString>() ;
        QList<QString> files_names_modify = QList<QString>();
        for(int i = 2 ; i < nb_files ; i++) {
            QFileInfo fileInfo = list.at(i);
            files_names.append(fileInfo.fileName());
            QString filename =  list.at(i).fileName();
            cout << "filename:" << filename.toStdString() << endl;
            if((QFile::exists("./themes/"+file_theme))) {
                cout << "open theme" << endl;
                QFile outputFile("./themes/"+file_theme);
                theme_read->read("./themes/"+file_theme);
                main_application(filename,file_theme,theme_read->get_cps());
                int nb_color_modify = main_application(filename,file_theme,theme_read->get_cps());
                if(nb_color_modify >= 0) {
                    nb_file_modifier++;
                    files_names_modify.append(fileInfo.fileName());
                    nb_color_file++;
                }
            }
        }
        QMessageBox msgBox;
        QString message_title("Modification des fichiers du dossier "+dire);
        QString message_text("");
        if(nb_color_file == 0) 
            message_text += "Le dossier "+dire+" ne contient pas de fichiers couleurs";
        else {
            message_text += "Nombre de fichiers modifiées : "+QString::number(nb_file_modifier) + "\n";
            message_text += "Liste des fichiers modifiés :";
            for(int i = 0 ; i < nb_file_modifier;i++) {
                if(i%4 == 0)
                    message_text += "\n";
                message_text += " "+files_names_modify[i]+", ";
            }
        }
        msgBox.setWindowTitle(message_title);
        msgBox.setText(message_text);
        msgBox.exec();
    
        application_theme_on_dr_file->setMaximumSize(QSize(1600,100));
        application_theme_on_file->setMaximumSize(QSize(0,0));
        application_theme_on_file->hide();
        application_theme_on_directory->setMaximumSize(QSize(0,0));
        application_theme_on_directory->hide();           
    });

    QObject::connect(application_theme_on_file, &QPushButton::clicked ,[=]() {
        QString filename = QFileDialog::getOpenFileName(this,
            tr("Choisir un fichier couleur"), "./");
        int files = 0;
        QString file("");			
        int size = filename.length();
        int j = size;
        for(j = size-1 ; j > 0 && (filename[j] != '/') ;j--);
        for(j=j+1; j < size; j++) 
            file += filename[j];
        if(QFile::exists("./colorfile/"+file))
            files++;

        QString str = title_widget->text();
        QString file_theme("");			
        size = str.length();
        j = size;
        for(j = size-1 ; j > 0 && (str[j] != ' ') ;j--);
        for(j=j+1; j < size; j++) 
            file_theme += str[j];
    
        if((QFile::exists("./themes/"+file_theme)) && (files==1)) {
            QFile outputFile("./themes/"+file_theme);
            XMLReader *theme_read = new XMLReader();
            theme_read->read("./themes/"+file_theme);

            int nb_color_modify = main_application(filename,file_theme,theme_read->get_cps());
            cout << "color modify : " << nb_color_modify << endl;
            QMessageBox msgBox;
            QString message_title("Modification sur le fichier "+file);
            QString message_text("");
            if(nb_color_modify == -1) 
                message_text += "Le fichier "+file+" ne contient pas de couleurs";
            else 
                message_text += "Nombre de couleurs modifiées : "+QString::number(nb_color_modify);

            msgBox.setWindowTitle(message_title);
            msgBox.setText(message_text);
            msgBox.exec();
        }
        application_theme_on_dr_file->setMaximumSize(QSize(1600,100));
        application_theme_on_file->setMaximumSize(QSize(0,0));
        application_theme_on_file->hide();
        application_theme_on_directory->setMaximumSize(QSize(0,0));
        application_theme_on_directory->hide();
    });
}

ThemeActionsWidget::~ThemeActionsWidget()
{
}