#include "mainwindow.h"
#include <QApplication>
#include "ColorPair.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
    w.show();
	QString str = "1";
	QColor color1 = "Blue";
	QColor color2 = "Red";
	ColorPair p = ColorPair(str);

	QString str2 = "2";
	ColorPair p2 = ColorPair(str2,color1,color2);
	return a.exec();
}
