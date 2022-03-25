#include "fileexploration.h"


FileExploration::FileExploration(QWidget *parent)
    : QWidget(parent)//, ui(new Ui::FileExploration)
{
    //QMessageBox::information(this, "Titre de la fenêtre", "Bonjour et bienvenueà tous les Zéros !");
    QFileDialog::getOpenFileName(this,
    tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
    /*msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);*/
    /*connect(browseButton, &QAbstractButton::clicked, this, &FileExploration::browse);
    findButton = new QPushButton(tr("&Find"), this);
    connect(findButton, &QAbstractButton::clicked, this, &FileExploration::find);

    fileComboBox = createComboBox(tr("*"));
    connect(fileComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &::animateFindClick);
    textComboBox = createComboBox();
    connect(textComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &Window::animateFindClick);
    directoryComboBox = createComboBox(QDir::toNativeSeparators(QDir::currentPath()));
    connect(directoryComboBox->lineEdit(), &QLineEdit::returnPressed,
            this, &Window::animateFindClick);

    filesFoundLabel = new QLabel;

    createFilesTable();

    QGridLayout *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(new QLabel(tr("Named:")), 0, 0);
    mainLayout->addWidget(fileComboBox, 0, 1, 1, 2);
    mainLayout->addWidget(new QLabel(tr("Containing text:")), 1, 0);
    mainLayout->addWidget(textComboBox, 1, 1, 1, 2);
    mainLayout->addWidget(new QLabel(tr("In directory:")), 2, 0);
    mainLayout->addWidget(directoryComboBox, 2, 1);
    mainLayout->addWidget(browseButton, 2, 2);
    mainLayout->addWidget(filesTable, 3, 0, 1, 3);
    mainLayout->addWidget(filesFoundLabel, 4, 0, 1, 2);
    mainLayout->addWidget(findButton, 4, 2);*/
}

FileExploration::~FileExploration()
{
    
}