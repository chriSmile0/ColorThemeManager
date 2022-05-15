#include "../include/ColorPair.h"


ColorPair::ColorPair() {} //constructeur vide

ColorPair::ColorPair(const ColorPair &color){
    m_id = color.m_id;
    m_color1 = color.m_color1;
    m_color2 = color.m_color2;
} //con. par copie

ColorPair::ColorPair(const QString &id, const QColor &color1, const QColor &color2) {
    m_id = id;
    m_color1 = color1;
    m_color2 = color2;
}

ColorPair::ColorPair(const QString &id) {
    m_id = id;
}//con. initialisant uniquement l’identifiant

QString toRGBA(const QColor &color) {//ici on pourrais changer pour gerer le rrggbb
    QString str;
    str = color.name(QColor::HexArgb);
    return str;
}


QColor fromRGBA(const QString &colorStr) {
    QColor rgb;
    rgb.setNamedColor(colorStr);
    return rgb;
}

QString ColorPair::getid() const {
    return m_id;
}

QColor ColorPair::get_m_color1() const {
    return m_color1;
}

QColor ColorPair::get_m_color2() const {
    return m_color2;
}

ColorPair &ColorPair::operator=(const ColorPair &cp1){
    m_id = cp1.getid();
    m_color1 = cp1.get_m_color1();
    m_color2 = cp1.get_m_color2();
    return *this;
}

CompareColorPair::CompareColorPair() {}

bool CompareColorPair::operator()(const ColorPair& cp1,const ColorPair &cp2) {
    int x = QString::compare(cp1.getid(),cp2.getid(),Qt::CaseInsensitive);
    if(x < 0) 
        return true;
    return false;
}

ColorPairSet::ColorPairSet() {}

ColorPairSet::SetType &ColorPairSet::set(int x) {
    //parcours du set moderne
    if (x == 2) {
        for(const ColorPair &cp : m_set) {
            cout << cp.getid().toStdString() << endl;
            cout << toRGBA(cp.get_m_color1()).toStdString() << endl;
            cout  << toRGBA(cp.get_m_color2()).toStdString() << endl;
        }   
    }
    else {
        for(const ColorPair &cp : m_set) {
            qDebug() << cp.getid();
            qDebug() << cp.get_m_color1();
            qDebug() << cp.get_m_color2();
        }   
    }
    return m_set;
}

void ColorPairSet::add_in_set(ColorPair &cp) {
    m_set.insert(cp);
}

QString ColorPairSet::in_set(const QString &colorStr) {//on extrait la target
    for(const ColorPair &cp : m_set) {
        if(toRGBA(cp.get_m_color1()) == colorStr)
            return toRGBA(cp.get_m_color2());
    }
    return "";
}



XMLReader::XMLReader() {}

void XMLReader::read_xml(QDomElement elem) {
    QDomElement root = elem;
    QString Type = root.tagName();
    cout << Type.toStdString() << endl;

    QDomElement Color = root.firstChild().toElement();
    QString id;
    QColor color1;
    QColor color2;
    ColorPair cp;
    while (!Color.isNull()) {
        if(Color.tagName() == "color") {
           id = Color.attribute("id");
           color1 = Color.attribute("source");
           color2 = Color.attribute("target");
           cp = ColorPair(id,color1,color2);
        }
        cps.add_in_set(cp);
        Color = Color.nextSibling().toElement(); 
    }
}


void XMLReader::read(const QString &filename) {
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        cout << (file.errorString()).toStdString() << endl;//No such file or directory
    else {
        cout << "good open" << endl;
        QDomDocument xmlColors;
        xmlColors.setContent(&file);
        file.close();
        read_xml(xmlColors.documentElement());
        /*
            Écrire dans le set de this : 
        */

    }
}




void XMLReader::set_cps(int x) {
    cps.set(x);
}

ColorPairSet XMLReader::get_cps() {
    return cps;
}