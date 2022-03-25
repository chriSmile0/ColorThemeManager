#ifndef FILEEXPLORATION_H
#define FILEEXPLORATION_H
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

/*QT_BEGIN_NAMESPACE
namespace Ui { class FileExploration; }
QT_END_NAMESPACE
*/
class FileExploration : public QWidget
{
    Q_OBJECT

public:
    FileExploration(QWidget *parent = nullptr);
    ~FileExploration();

/*private slots:
    void browse();
    void find();
    void animateFindClick();
    void openFileOfItem(int row, int column);
    void contextMenu(const QPoint &pos);

private:
    QStringList findFiles(const QStringList &files, const QString &text);
    void showFiles(const QStringList &paths);
    QComboBox *createComboBox(const QString &text = QString());
    void createFilesTable();

    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QComboBox *directoryComboBox;
    QLabel *filesFoundLabel;
    QPushButton *findButton;
    QTableWidget *filesTable;

    QDir currentDir;*/
    //Ui::FileExploration *ui;
};

#endif // FILEEXPLORATION_H