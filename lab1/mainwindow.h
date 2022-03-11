#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "error_handler.h"
#include "action_handler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_Move_clicked();

    void on_button_Scale_clicked();

    void on_button_Turn_clicked();

    void on_actionOpen_triggered();


private:
    Ui::MainWindow *ui;
};

errors draw_action(Ui::MainWindow* ui);
errors transform_and_show(action_t req, Ui::MainWindow* ui);
#endif // MAINWINDOW_H
