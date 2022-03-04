#ifndef COLORPAIR_H
#define COLORPAIR_H

#include "Widgets/mainwindow.h"
#include <QApplication>
#include <QColor>
#include <QString>
#include <QDebug>
#include <set>
#include <QFile>
#include <QtXml>
#include <QMessageBox>
#include <iostream>
using namespace std;


class ColorPair {
    private:
        QString m_id;
        QColor m_color1;
        QColor m_color2; 

    public:
        ColorPair(); //constructeur vide
        ColorPair(const ColorPair &color); //con. par copie
        ColorPair(const QString &id, const QColor &color1, const QColor &color2);
        ColorPair(const QString &id); //con. initialisant uniquement l’identifiant

        QString getid() const;
        QColor get_m_color1() const;
        QColor get_m_color2() const; 
};

QString toRGBA(const QColor &color);
QColor fromRGBA(const QString &colorStr);

void read_xml(QDomElement elem);


class CompareColorPair {
    public:
        CompareColorPair();
        bool operator()(const ColorPair& cp1,const ColorPair &cp2);
};




class ColorPairSet {
    public :
        using SetType = std::set<ColorPair,CompareColorPair>;

        ColorPairSet();
        SetType &set();
        void add_in_set(ColorPair &cp);

    private:
        SetType m_set;
};





class XMLReader {
    private:
        ColorPairSet cps;

    public:
        XMLReader();
        void read(const QString &filename);
        void read_xml(QDomElement elem);
        void set_cps();
};






#endif // COLORPAIR_H