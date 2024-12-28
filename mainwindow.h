#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libs/systemanalyser.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbProjectPath_clicked();

    void on_leProjectPath_editingFinished();

    void on_leProjectBranch_editingFinished();

    void on_leProjectURL_editingFinished();

    void on_leCommitMessage_editingFinished();

    void on_pbGitAddConfirm_clicked();

    void on_pbGitAddDiscard_clicked();

    void on_pbCommit_clicked();

private:
    Ui::MainWindow *ui;
    SystemAnalyser anal;

    enum commitItemsModes { ADDALL, ADDSELECTED };

    QString projectPath;
    QString projectURL;
    QString projectBranch = "main";
    bool changesAdded = false;
    QString commitMessage = "My compass was swallowed by the sea";
    int commitItemsMode = ADDALL;

    void changesAddedSwitch();

};
#endif // MAINWINDOW_H
