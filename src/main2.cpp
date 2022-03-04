#include "../include/ColorPair.h"


int main(int argc, char *argv[]) {
    QColor c1 = QColor("White");
    QColor c2 = QColor("Red");
    QColor c3 = QColor("Blue");
    QColor c4 = QColor("Green");
    QString id1 = QString("1");
    QString id2 = QString("2");
    ColorPair cp = ColorPair(id1,c1,c2);
    ColorPair cp2 = ColorPair(id2,c3,c4);

    cout << toRGBA(QColor("Blue")).toStdString() << endl;
    cout << fromRGBA("#FF1122").red() << endl;
    cout << "red of Blue : " <<  fromRGBA("#0000ff").red() << endl;
    cout << "blue of Blue : " << fromRGBA("#0000ff").blue() << endl;
    cout << "green of Blue : " << fromRGBA("#0000ff").green() << endl;

    CompareColorPair ccp;
    cout << ccp(cp,cp2) << endl;
    cout << ccp(cp2,cp) << endl;


    ColorPairSet cps;
    cps.add_in_set(cp);
    cps.set();

    XMLReader xr;
   /* QApplication app(argc,argv);
    MainWindow w;
	w.show():*/
    xr.read("../color-theme-manager/XML/redTheme.xml");
    xr.set_cps();
    //return app.exec();
    return 0;
}