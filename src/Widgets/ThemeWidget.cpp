#include "ThemeWidget.h"


ThemeWidget::ThemeWidget(QWidget * parent) 
    :QWidget(parent)
{
    this->setObjectName(QString::fromUtf8("th3"));
    this->setMaximumSize(QSize(400, 100));
    this->setMinimumSize(QSize(100,100));
}

void ThemeWidget::setTh_Widget(QString str,int id)
{

    theme_name = str;
    id = id;
    QString id_inqstr = QString::number(id);
    
    //Create VBoxLayout name
    th_3 = new QVBoxLayout(this);
    th_3->setSpacing(0);
	th_3->setObjectName(QString::fromUtf8("th_3"));
    //Create Widget name
    widget_t =  new QWidget(this);
	widget_t->setObjectName(QString::fromUtf8("widget_t"));
    

    //Create button name
    pushButton = new QPushButton(widget_t);
    pushButton->setObjectName(QString::fromUtf8("pushButton12"));
	pushButton->setGeometry(QRect(25, 5, 50, 40));
    icon.addFile(QString::fromUtf8(":/images/theme.png"), QSize(), QIcon::Normal, QIcon::Off);
    pushButton->setIcon(icon);
	pushButton->setIconSize(QSize(32, 32));
    widget_t->setMaximumSize(QSize(120,50));
    th_3->addWidget(widget_t);

    widget_c =  new QWidget(this);
	widget_c->setObjectName(QString::fromUtf8("widget_c"));
   

    //Create label name
    widget_c->setMaximumSize(QSize(120,30));
    
    label = new QLabel(widget_c);
	label->setObjectName(QString::fromUtf8("label_")+id_inqstr);
	label->setAlignment(Qt::AlignCenter);
    /*QByteArray ba = theme_name.toLocal8Bit();
    const char *label_name = ba.data();
    QFontMetrics metrics(label->font());
    QString elidedText = metrics.elidedText(label_name, Qt::ElideRight, label->width());*/
	label->setText(theme_name);
	th_3->addWidget(widget_c);

}

QString ThemeWidget::getname() const
{
    return theme_name;
}

int ThemeWidget::getid() const
{
    return id;
}



ThemeWidget::~ThemeWidget() {}