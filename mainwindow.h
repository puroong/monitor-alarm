#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alarmlist.h"
#include "scheduler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnStatus_clicked();
    void sync_alarmList_lwAlarms();
    bool validate();
private:
    Ui::MainWindow *ui;
    bool timerRunning;
    Scheduler* scheduler;
};

#endif // MAINWINDOW_H
