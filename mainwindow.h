#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNEW_triggered();

    void on_actionOPEN_triggered();

    void on_actionSAVE_triggered();

    void on_actionSAVE_AS_triggered();

    void on_actioncut_triggered();

    void on_actionCopy_triggered();

    void on_actionPast_triggered();

    void on_actionRedo_triggered();

    void on_actionUdo_triggered();

    void on_actionAbout_Notepat_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path_;
};
#endif // MAINWINDOW_H
