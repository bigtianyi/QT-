#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString currentFile;

private slots:
    void on_pushButton_clicked();
    void setCurrentFile(const QString &fileName);
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);

    void on_actionAbout_triggered();
    void on_actionPaste_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionExit_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionNew_triggered();
};

#endif // MAINWINDOW_H
