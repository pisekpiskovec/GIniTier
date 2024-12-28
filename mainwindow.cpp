#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "libs/systemanalyser.h"
#include <QFileDialog>

/*
 * Proces vytvareni novych projektu
 * * cd existing_folder
 * * git init --initial-branch=main
 * * git remote add origin https://gitlab.prumkadc.cz/honeymoon/test.git
 * * git add .
 * * git commit -m "Initial commit"
 * * git push --set-upstream origin main
*/

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }
MainWindow::~MainWindow() { delete ui; }
void MainWindow::on_pbProjectPath_clicked() {
    projectPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->leProjectPath->setText(projectPath);
}

void MainWindow::on_leProjectPath_editingFinished() { projectPath = ui->leProjectPath->text(); }
void MainWindow::on_leProjectBranch_editingFinished() { projectBranch = ui->leProjectBranch->text(); }
void MainWindow::on_leProjectURL_editingFinished() { projectURL = ui->leProjectURL->text(); }
void MainWindow::on_leCommitMessage_editingFinished() { commitMessage = ui->leCommitMessage->text(); }
void MainWindow::changesAddedSwitch() { changesAdded = !changesAdded; ui->pbGitAddDiscard->setEnabled(changesAdded); ui->pbGitAddConfirm->setEnabled(!changesAdded); }
void MainWindow::on_pbGitAddConfirm_clicked() { changesAddedSwitch(); }
void MainWindow::on_pbGitAddDiscard_clicked() { changesAddedSwitch(); }
void MainWindow::on_pbCommit_clicked()
{
    if(projectPath.isEmpty()) {ui->statusbar->showMessage("No project path specified.", 10000); return;}
    if(projectBranch.isEmpty()) {ui->statusbar->showMessage("No branch name specified.", 10000); return;}
    if(projectURL.isEmpty()) {ui->statusbar->showMessage("No remote specified.", 10000); return;}
    if(!changesAdded) {ui->statusbar->showMessage("No changes selected.", 10000); return;}
    ui->statusbar->showMessage("");
    anal.RunCommand(QString("cd %1").arg(projectURL).toStdString().c_str());
}



