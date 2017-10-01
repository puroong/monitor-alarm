#include "regularalarm.h"
#include "alarmlist.h"
#include "alarminfo.h"
#include "alarmtype.h"
#include <QSound>
#include <QMessageBox>

RegularAlarm::RegularAlarm(QTime startTime, QTime endTime, int period)
{
    this->startTime = startTime;
    this->endTime = endTime;
    this->period = period;

    QTime temp = startTime;
    while(temp < endTime)
    {
        AlarmInfo* alarmInfo = new AlarmInfo(temp, AlarmType::regular);

        AlarmList::getInstance()->addAlarm(alarmInfo);
        temp = temp.addSecs(period * 60);
    }

    AlarmInfo* alarmInfo = new AlarmInfo(endTime, AlarmType::regular);
    AlarmList::getInstance()->addAlarm(alarmInfo);

}

RegularAlarm::~RegularAlarm()
{
    // TODO: delete all regular alarms
}

void RegularAlarm::ring()
{
    qDebug() << "RegualrAlarm::ring";
    AlarmList::getInstance()->removeNextAlarm();

    QString path("");
    char * MONITORALARMPATH;
    MONITORALARMPATH = getenv ("MONITORALARMPATH");
    path.append(MONITORALARMPATH);
    path.append("/bells/analog.wav");

    QSound bell(path);
    bell.play();
    QMessageBox::information(0, "Information", "Regular Alarm!", QMessageBox::Ok);
    bell.stop();
}
