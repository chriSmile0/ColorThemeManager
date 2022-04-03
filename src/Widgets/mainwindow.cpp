#include "mainwindow.h"
#include "ThemeWidget.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent),
	ui(new Ui::MainWindow)
	
{
	ui->setupUi(this);
	/*Chargement des thèmes*/
	QDir direct("themes/");
	if (!direct.exists())
		direct.mkpath(".");
	QFileInfoList list = direct.entryInfoList();
	int nb_files = list.size();
	cout << nb_files << endl;
	QList<QString> files_names = QList<QString>() ;
	for(int i = 2 ; i < nb_files ; i++) {
		QFileInfo fileInfo = list.at(i);
		files_names.append(fileInfo.fileName());
	}
	int list_size = files_names.size();
	QString i_inqstr;
	//5 thèmes par ligne 
	int row = 0;
	for(int i = 0 ; i < list_size;i++) {
		i_inqstr = QString::number(i+2);
		QWidget *th3 = new QWidget(ui->Themes_list);
		th3->setObjectName(QString::fromUtf8("th")+i_inqstr);
		th3->setMaximumSize(QSize(1600, 200));
		ThemeWidget *w1 = new ThemeWidget(th3);
		w1->setTh_Widget(files_names[i],i+2);
		if((i%5 == 0) && (i!=0))
			row++;
		ui->gridLayout->addWidget(w1,row,i%5);
	}
	int horizontal_size = list_size/5 * 100;
	ui->Themes_list->setGeometry(QRect(0, 0, 557, horizontal_size));
	
	

}
	

MainWindow::~MainWindow()
{
	delete ui;
}

/**
 * Importer des fichiers couleurs pour les utilisés 
 * le traitement de ces derniers se fera ailleurs
 * 
*/

void MainWindow::on_Import_Color_File_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
    tr("Importer fichier couleur"), "/home", tr("Color Files (*)"));
	/*Checker que c'est bien un fichier couleur*/
	QFile inputFile(filename);
	int color_file = 0;
	int nb_color = 0;
	if (inputFile.open(QIODevice::ReadOnly)) {
		QTextStream in(&inputFile);
		while (!in.atEnd()) {
			QString line = in.readLine();
			int size = line.length();
			int i = 0;
			int possible_color = 0;
			for(i = 0 ; i < size ;i++) {
				if(possible_color == 0) {
					if(line[i] == '#') 
						possible_color = 1;
				}
				else {
					QChar c(line[i]);
					char letter = c.toLatin1();
					int line_int = (int) letter;
					if((line_int >= '0' && (line_int <= '9')) || 
						((line_int >= 'a') && (line_int <= 'f'))) 
							color_file++;
					else {
						color_file = 0;
						possible_color = 0;
					}
					if(color_file == 8) {
						color_file = 0;
						nb_color++;
					}
				}
			}
		}
		inputFile.close();
	}
	if(nb_color > 0) {// ok on a des couleurs 
		/*Parser le nom*/
		int i = filename.length();
		QByteArray ba = filename.toLocal8Bit();
		char *c_str2 = ba.data();
		int j = 0;
		while(c_str2[i] != '/') {
			j++;
			i--;
		}
		i++;
		j--;
		char new_place[100];
		QDir direct("colorfile/");
			if (!direct.exists())
				direct.mkpath(".");
		snprintf(new_place,11,"%s","colorfile/");
		snprintf(c_str2,j+1,"%s",c_str2+i);
		snprintf(new_place+10,11+j,"%s",c_str2);
		QFile::copy(filename,new_place);
	}
	else {//Message d'erreur
		if(!filename.isNull()) {
			QMessageBox msgBox;
			msgBox.setWindowTitle("Erreur fichier");
			msgBox.setText("Choississez un fichier qui contient des couleurs , exemples : #rrggbbaa.");
			msgBox.exec();
		}
	}
}


QString MainWindow::create_line_source_target(QString &source,QString &target, int id) {
	//QString str("<color id="Couleur 01" source="#003265ff" target="#123225ff"/>")
	QString add_id("");
	QString couleur(source);
	QString cible(target);
	if(id < 10) 
		add_id += "0";
	add_id += '0' + id;
	QString strin("    <color id=");
	strin += '"';
	strin += "Couleur ";
	strin += add_id;
	strin += '"';
	strin += " source="; 
	strin += '"';
	strin += couleur;
	strin += '"';
	strin += " target=";
	strin += '"';
	strin += cible;
	strin += '"';
	strin += "/>";
	return strin;
}


int MainWindow::validation_source_target(QString source, QString target) {
	int possible_color = 0;
	int source_size = source.length();
	int target_size = target.length();
	int nb_true = 0;
	int i = 0;
	int color_file = 0;
	//0 aucunes string n'est juste, 1 source ok,, 2 target ok, 3 les 3 ok 
	//source
	for(i = 0 ; i < source_size ;i++) {
		if(possible_color == 0) {
			if(source[i] == '#') 
				possible_color = 1;
		}
		else {
			QChar c(source[i]);
			char letter = c.toLatin1();
			int line_int = (int) letter;
			if((line_int >= '0' && (line_int <= '9')) || 
				((line_int >= 'a') && (line_int <= 'f'))) 
					color_file++;
			else {
				color_file = 0;
				possible_color = 0;
			}
			if(color_file == 8) {
				color_file = 0;
				i = source_size;//on stop
				nb_true = 1; 
			}

		}	
	}
	//target
	color_file = 0;
	possible_color = 0;
	for(i = 0 ; i < target_size ;i++) {
		if(possible_color == 0) {
			if(target[i] == '#') 
				possible_color = 1;
		}
		else {
			QChar c(target[i]);
			char letter = c.toLatin1();
			int line_int = (int) letter;
			if((line_int >= '0' && (line_int <= '9')) || 
				((line_int >= 'a') && (line_int <= 'f'))) 
					color_file++;
			else {
				color_file = 0;
				possible_color = 0;
			}
			if(color_file == 8) {
				color_file = 0;
				i = source_size;//on stop
				nb_true += 2; 
			}
		}	
	}
	return nb_true;
} 

void MainWindow::on_Create_Theme_clicked()
{
	bool ok;
	QString text;
	text = QInputDialog::getText(this, tr("Création d'un thème"),
			tr("Nom theme (exemple rouge.xml)"), QLineEdit::Normal,
			QDir::home().dirName(), &ok);
	int erreur = 0;
	if (ok && !text.isEmpty()) {
		int size_text = text.length();
		int i = 0;
		for(i = 0 ; i < size_text && text[i] != '.';i++);

		if(i == size_text) 
			erreur = 1;
		if((text[i] == '.') && (i != 0)){//pas de fichier '.xml' 'lettres.xml" éxigés
			if((text[i+1] != 'x') && (text[i+2] != 'm') && (text[i+3] != 'l') 
				&& (text[i+4] != '\0'))
				erreur = 1;
		}
		if(erreur == 1) {
			QMessageBox msgBox;
			msgBox.setWindowTitle("Erreur Nom thème");
			msgBox.setText("Essayez par exemple : rouge.xml");
			msgBox.exec();
		}
	}

	//Insérer un bouton pour annuler la tâche a tout moment et du coup déclencher la 
	//supression du thème 
	if(erreur == 0) {
		bool oki;
		int d = QInputDialog::getInt(this, tr("Nombre de couleurs"),
										tr("Nombre couleurs :"), 1, 0, 150, 1, &oki);
		
		if(oki) {
			QDir direct("themes/");
			if (!direct.exists())
				direct.mkpath(".");
			QFile outputFile("./themes/"+text);
			if(QFile::exists("./themes/"+text))
				QFile::resize("./themes/"+text,0);
			if(outputFile.open(QIODevice::ReadWrite)) {
				QTextStream out(&outputFile);
				out << "<colors>" << Qt::endl;
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
				QPushButton *valider = new QPushButton("Valider couleur 1");
				vlayout->addWidget(source);
				vlayout->addWidget(field_src);
				vlayout->addWidget(cible);
				vlayout->addWidget(field_tgt);
				vlayout->addWidget(valider);
				Dbox->setLayout(vlayout);
				Dbox->show();
				QObject::connect(valider, &QPushButton::clicked ,[=]() {
					/*Verification des champs a faire venir d'une autre fonction plus haut */
					int corrects_fields = validation_source_target(
								field_src->text(),field_tgt->text());
					if(corrects_fields == 3) {
						QString val = valider->text();
						QString nb_c("");
						//On récup tout les chiffres avant le '°'
						int size = val.length();
						int j = size;
						for(j = size-1 ; j > 0 && (val[j] != ' ') ;j--);
						for(j=j+1; j < size; j++) 
							nb_c += val[j];
						int digit = nb_c.toInt() + 1;
						QString *src = new QString(field_src->text());
						QString *tgt = new QString(field_tgt->text());
						field_src->setText("");
						field_tgt->setText("");
						//nos champs sont bon on peut les inclurent 
						QFile outputFil("./themes/"+text);
						if(outputFil.open(QIODevice::Append)) {
							QTextStream oute(&outputFil);
							oute << create_line_source_target(*src,*tgt,digit-1) << Qt::endl;
							outputFil.close();
						}
						QString str = "";

						if(digit > d) {
							Dbox->close();
							if(outputFil.open(QIODevice::Append)) {
								QTextStream oute(&outputFil);
								oute << "</colors>" << Qt::endl;
							}
							outputFil.close();
						}
						else {
							str += QString::number(digit);
							valider->setText("Valider couleur " + str);
						}
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
		}  
	}                       							
}


QString MainWindow::create_theme_line(QString &str, int id) {
	//QString str("<color id="Couleur 01" source="#003265ff" target="#123225ff"/>")
	QString add_id("");
	QString couleur(str);
	if(id < 10) 
		add_id += "0";
	add_id += '0' + id;
	QString strin("    <color id=");
	strin += '"';
	strin += "Couleur ";
	strin += add_id;
	strin += '"';
	strin += " source="; 
	strin += '"';
	strin += couleur;
	strin += '"';
	strin += " target=";
	strin += '"';
	strin += "#........";
	strin += '"';
	strin += "/>";
	return strin;
}

/**
 * Utiliser un fichier couleur pour créer un thème 
 * S'inspirer des 3 exemples dans le dossier XML pour faire en sorte que 
 * les couleurs trouvés dans le thème soient des sources et donc 
 * crée un fichier avec QFile puis écrire dans ce fichier des lignes comme dans les 3 
 * exemples mais insérer les couleurs juste après "source="
 * 
 * Attention fonctionne conséquente : a fragmenté ;-) ) 
*/

void MainWindow::on_Calc_Theme_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
    tr("Selectionner un fichier couleur"), "./colorfile", tr("Color Files (*)"));
	QFile inputFile(filename);
	QDir direct("themes/");
		if (!direct.exists())
			direct.mkpath(".");
	bool ok;
	QString text = QInputDialog::getText(this, tr("Nom du theme calculer"),
                tr("Nom theme (exemple rouge.xml)"), QLineEdit::Normal,
                QDir::home().dirName(), &ok);
	int erreur = 0;
	if (ok && !text.isEmpty()) {
		int size_text = text.length();
		int i = 0;
		for(i = 0 ; i < size_text && text[i] != '.';i++);

		if(i == size_text) 
			erreur = 1;
		if((text[i] == '.') && (i != 0)){//pas de fichier '.xml' 'lettres.xml" éxigés
			if((text[i+1] != 'x') && (text[i+2] != 'm') && (text[i+3] != 'l')
				&& (text[i+4] != '\0'))
				erreur = 1;
		}
		if(erreur == 1) {
			QMessageBox msgBox;
			msgBox.setWindowTitle("Erreur Nom thème");
			msgBox.setText("Erreur essayez rouge.xml");
			msgBox.exec();
		}
	}
	if(erreur == 1) 
		exit(1);
	QFile outputFile("./themes/"+text);
	int total_color = 0;
	if(outputFile.open(QIODevice::ReadWrite)) {
		QTextStream out(&outputFile);
		out << "<colors>" << Qt::endl;
		QList<QString> m_strList = QList<QString>() ;
		if (inputFile.open(QIODevice::ReadOnly)) {
			QTextStream in(&inputFile);
			while (!in.atEnd()) {
				QString line = in.readLine();
				int size = line.length();
				int i = 0;
				int possible_color = 0;
				int color_file = 0;
				int nb_color = 0;
				for(i = 0 ; i < size ;i++) {
					if(possible_color == 0) {
						if(line[i] == '#') 
							possible_color = 1;
					}
					else {
						QChar c(line[i]);
						char letter = c.toLatin1();
						int line_int = (int) letter;
						if((line_int >= '0' && (line_int <= '9')) || 
							((line_int >= 'a') && (line_int <= 'f'))) 
								color_file++;
						else {
							color_file = 0;
							possible_color = 0;
						}
						if(color_file == 8) {
							color_file = 0;
							m_strList.append(line.mid(i-8,i+1));
							nb_color++;
						}
					}
				}
				for(int j = 0 ; j < nb_color ; j++) 
					out << create_theme_line(m_strList[j],total_color+j+1) << Qt::endl;
				total_color += nb_color;
				m_strList.clear();
				//Trouver une couleur dans la ligne (attention la ligne ne doit pas être fragmentée (pour le moment ))
				//a la fin de chaque ligne on insere toutes les couleurs trouvées 
			}
			inputFile.close();
		}
		out << "</colors>" << Qt::endl;
		outputFile.close();
	}

 	
}

/**
 * Afficher les themes dans l'application (dans le bloc theme de l'appli)
 * 
*/

void MainWindow::on_Import_Theme_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
    tr("Importer Theme"), "/home", tr("Themes Files (*.xml)"));
	/*Parser le nom*/

	int i = filename.length();
	QByteArray ba = filename.toLocal8Bit();
  	char *c_str2 = ba.data();
	int j = 0;
	while(c_str2[i] != '/') {
		j++;
		i--;
	}
	i++;
	j--;
	char new_place[100];
	QDir direct("themes/");
		if (!direct.exists())
			direct.mkpath(".");
	QFileInfoList list = direct.entryInfoList();
	snprintf(new_place,8,"%s","themes/");
	snprintf(c_str2,j+1,"%s",c_str2+i);
	snprintf(new_place+7,8+j,"%s",c_str2);
	QFile::copy(filename,new_place);

	//a mettre dans une fonction générique 
	//mieux de refresh car sinon faudrait le faire pour création theme et pour
	//calc theme

	/*QString i_inqstr;
	//5 thèmes par ligne 
	int column = (nb_files-2)%5;
	int row = (nb_files-2)/5;
	cout << nb_files << endl;
	cout << row << endl;
	i_inqstr = QString::number(nb_files-2);
	QWidget *th3 = new QWidget(ui->Themes_list);
	th3->setObjectName(QString::fromUtf8("th11"));
	th3->setMaximumSize(QSize(1600, 200));
	ThemeWidget *w1 = new ThemeWidget(th3);
	w1->setTh_Widget(c_str2,12);
	ui->gridLayout->addWidget(w1,row+1,column);*/
}

/**
 * Sauvegarder tout les thèmes 
 * 		Je comprend par là que nous avons stocker nos themes en temporairement 
 * 		mais que nous pouvons en supprimer a tout moment
 * 		Tout les themes sauvegarder sont dans le bloc themes de l'appli
 *		Mais lors de l'importation on affiche aussi nos thèmes en stock dans le dossier associé 

		Pour le moment notre importation ne modifie pas la sesion actuel. 
		Le mieux est donc d'importer tout nos thèmes , de refresh puis 
		enfin commencer a utilisé l'application 
		Mais on peut faire la maj de suite si l'on veut à chaque import 
*/

void MainWindow::on_Save_Theme_clicked()
{
	QFileDialog::getSaveFileName(this,
    tr("Sauvegarder"), "/home", tr("Themes Files (*.xml)"));
	
}

void MainWindow::on_Last_Session_clicked()
{
    
}