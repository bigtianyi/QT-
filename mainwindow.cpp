#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <zhujiemian.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//以下为自定义函数
//setCurrentFile 函数用来设置 Cstring 类型的对象成员 currentFile 的值，currentFile 用来记录当前的文件名。
void MainWindow::setCurrentFile(const QString &fileName)
{
    currentFile = fileName;
    QString shownName;
    if (currentFile.isEmpty())
        shownName = "untitled";
    else
        shownName = QFileInfo(currentFile).fileName();
    setWindowTitle(shownName);
}
//loadFile 函数用来从文件中加载内容到文本框
void MainWindow::loadFile(const QString &fileName)
{
 QFile file(fileName);
 if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, tr("Application"),
    tr("Cannot read file %1:\n%2.")
    .arg(fileName)
    .arg(file.errorString()));
    return;
    }
 QTextStream in(&file);
 ui->textEdit->setPlainText(in.readAll());
 setCurrentFile(fileName);
}
//需要弹出对话框让用户选择保存保存文件名。
bool MainWindow::saveFile(const QString &fileName)
{
 QFile file(fileName);
 if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, tr("Application"),
    tr("Cannot write file %1:\n%2.")
    .arg(fileName)
     .arg(file.errorString()));
     return false;
 }
 QTextStream out(&file);
 out << ui->textEdit->toPlainText();
 setCurrentFile(fileName);
 return true;
}


//按键～
//new
void MainWindow::on_actionNew_triggered()
{
   ui->textEdit->clear();
   setCurrentFile("");
}
//open
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
     if (!fileName.isEmpty())
        loadFile(fileName);
}
//save
void MainWindow::on_actionSave_triggered()
{
     if (currentFile.isEmpty())
        on_actionSave_As_triggered();
     else
        saveFile(currentFile);
}
//save as
void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
     if(!fileName.isEmpty())
         saveFile(fileName);
}
//exit
void MainWindow::on_actionExit_triggered()
{
    this->close();
}
//cut
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}
//cppy
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
//paste
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
//about
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Application"),
     tr("The <b>Application</b> example demonstrates how to "
            "write modern GUI applications using Qt, with a menu bar, "
            "and toolbars."));
}
//返回
void MainWindow::on_pushButton_clicked()
{
    zhujiemian *zjm = new zhujiemian();
    zjm->show();
    this->close();
}
