#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "action_handler.h"
#include "error_handler.h"
#include "operations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    action_t act;
    act.type = NO_ACTION;
    action_handler(act);
}


MainWindow::~MainWindow()
{
    action_t act;
    act.type = QUIT;
    action_handler(act);
    delete ui;
}

errors draw_action(Ui::MainWindow* ui)
{
    draw_data_t draw_data;

    draw_data.gView = ui->graphicsView;
    draw_data.height = ui->graphicsView->height();
    draw_data.width = ui->graphicsView->width();

    action_t act;
    act.type = DRAW;
    act.draw_data = draw_data;

    errors err = (errors) action_handler(act);
    return err;
}

errors transform_and_show(action_t act, Ui::MainWindow* ui)
{
    errors err = (errors) action_handler(act);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}

void MainWindow::on_actionOpen_triggered()
{
    action_t act;
    act.type = LOAD_FILE;
    act.file_data.filename = "figure.txt";

    errors err = transform_and_show(act, ui);
    if (err)
        display_error_message(err);
}


void MainWindow::on_button_Move_clicked()
{
    action_t act;
    act.type = MOVE;

    act.move_data.dx = ui->lineEdit_MoveX->text().toInt();
    act.move_data.dy = ui->lineEdit_MoveY->text().toInt();
    act.move_data.dz = ui->lineEdit_MoveZ->text().toInt();

    errors err = transform_and_show(act, ui);
    if (err)
        display_error_message(err);
}

void MainWindow::on_button_Scale_clicked()
{
    action_t act;
    act.type = SCALE;

    act.scale_data.kx = ui->lineEdit_ScaleX->text().toFloat();
    act.scale_data.ky = ui->lineEdit_ScaleY->text().toFloat();
    act.scale_data.kz = ui->lineEdit_ScaleZ->text().toFloat();

    point_t center;
    center.x = ui->lineEdit_centerX->text().toFloat();
    center.y = ui->lineEdit_centerY->text().toFloat();
    center.z = ui->lineEdit_centerZ->text().toFloat();

    act.scale_data.center = center;

    errors err = transform_and_show(act, ui);
    if (err)
        display_error_message(err);
}

void MainWindow::on_button_Turn_clicked()
{
    action_t act;
    act.type = TURN;

    act.turn_data.ox = ui->lineEdit_TurnX->text().toFloat();
    act.turn_data.oy = ui->lineEdit_TurnY->text().toFloat();
    act.turn_data.oz = ui->lineEdit_TurnZ->text().toFloat();

    point_t center;
    center.x = ui->lineEdit_centerX->text().toFloat();
    center.y = ui->lineEdit_centerY->text().toFloat();
    center.z = ui->lineEdit_centerZ->text().toFloat();

    act.turn_data.center = center;

    errors err = transform_and_show(act, ui);
    if (err)
        display_error_message(err);
}
