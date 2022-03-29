#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QChar>
#include <QLabel>
#include <QInputDialog>
#include <string.h>
#include <stdlib.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void on_Import_Color_File_clicked();
	void on_Calc_Theme_clicked();
	QString create_line_source_target(QString &source,QString &target, int id);
	QString create_theme_line(QString &str, int id);
	int validation_source_target(QString source, QString target);
	void on_Create_Theme_clicked();
	void on_Import_Theme_clicked();
	void on_Save_Theme_clicked();
	void on_Last_Session_clicked();

private:
	Ui::MainWindow *ui;	
};
#endif // MAINWINDOW_H





