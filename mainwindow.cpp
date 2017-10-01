#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSound>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerRunning = false;
    scheduler = nullptr;

    connect(AlarmList::getInstance(), SIGNAL(updateAlarmList()), this, SLOT(sync_alarmList_lwAlarms()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStatus_clicked()
{
    if(timerRunning == false && validate())
    {
        QTime startTime = ui->teStartTime->time();
        QTime endTime = ui->teEndTime->time();
        int period = ui->sbPeriod->value();
        int frequentPeriod = ui->sbFrequentPeriod->value();

        scheduler = new Scheduler(startTime, endTime, period, frequentPeriod);
        scheduler->run();

        timerRunning = true;
        ui->btnStatus->setText("Stop");
    }
    else
    {
        if(scheduler != nullptr)
        {
            delete scheduler;
            scheduler = nullptr;
        }

        timerRunning = false;
        ui->btnStatus->setText("Start");
    }
}

void MainWindow::sync_alarmList_lwAlarms()
{
    qDebug() << "MainWindow::sync_alarmList_lwAlarms";
    ui->lwAlarms->clear();

    QLinkedList<AlarmInfo*>::iterator iter;
    for(iter=AlarmList::getInstance()->begin();iter!=AlarmList::getInstance()->end();iter++)
    {
        QString timeString = (*iter)->getTime().toString();
        ui->lwAlarms->addItem(timeString);
    }
}

bool MainWindow::validate()
{
    bool status = true;

    // start time should be greater than current time
    if(ui->teStartTime->time() <= QTime::currentTime())
    {
        QMessageBox::warning(this,"Warning","현재 시간이 시작 시간을 지났어요!", QMessageBox::Ok);

        status = false;
    }

    qDebug() << "MainWindow::validate; startTime: " << ui->teStartTime->time() << " endTime: " << ui->teEndTime->time() << " copare: " << (ui->teStartTime->time() >= ui->teEndTime->time());

    // time edit validation
    if(ui->teStartTime->time() >= ui->teEndTime->time())
    {
        QMessageBox::warning(this,"Warning","시작 시간과 끝 시간을 다시 확인해주세요!", QMessageBox::Ok);

        status = false;
    }
    // spin box validation
    if(ui->sbPeriod->value() <= 0)
    {
        QMessageBox::warning(this,"Warning","주기는 0보다 커야합니다!", QMessageBox::Ok);

        status = false;
    }

    return status;
}
