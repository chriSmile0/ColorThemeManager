#include "mainwindow.h"
#include "fileexploration.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent),
	ui(new Ui::MainWindow)
	
{
	ui->setupUi(this);
}
	

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_Import_Color_File_clicked()
{
	QFileDialog::getOpenFileName(this,
    tr("Importer fichier couleur"), "/home", tr("Color Files (*.xml)"));
}

void MainWindow::on_Calc_Theme_clicked()
{
    
}

void MainWindow::on_Create_Theme_clicked()
{
    
}

void MainWindow::on_Import_Theme_clicked()
{
	QFileDialog::getOpenFileName(this,
    tr("Importer Theme"), "/home", tr("Themes Files (*.xml)"));
    
}

void MainWindow::on_Save_Theme_clicked()
{
	QFileDialog::getSaveFileName(this,
    tr("Sauvegarder"), "/home", tr("Themes Files (*.xml)"));
	
}

void MainWindow::on_Last_Session_clicked()
{
    
}