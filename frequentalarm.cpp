#include "frequentalarm.h"
#include "alarmlist.h"
#include "alarminfo.h"
#include "alarmtype.h"
#include <QSound>
#include <QMessageBox>

FrequentAlarm::FrequentAlarm(QTime time, int frequentPeriod)
{
    this->time = time;
    this->frequentPeriod = frequentPeriod;
    addFrequentAlarm(time);
}

FrequentAlarm::~FrequentAlarm()
{
    // TODO: delete all frequent alarms
}

void FrequentAlarm::ring()
{
    qDebug() << "FrequentAlarm::ring";
    AlarmList::getInstance()->removeNextAlarm();

    QString path("");
    char * MONITORALARMPATH;
    MONITORALARMPATH = getenv ("MONITORALARMPATH");
    path.append(MONITORALARMPATH);
    path.append("/bells/analog.wav");

    QSound bell(path);
    bell.play();
    QMessageBox::information(0, "Information", "Frequent Alarm!", QMessageBox::Ok);
    bell.stop();

    addFrequentAlarm(time);
}

int FrequentAlarm::generateRandomSec()
{
    int random = qrand()%frequentPeriod + 1;
    qDebug() << "FrequentAlarm::generateRandomSec: " << random;
    return random;
}

void FrequentAlarm::addFrequentAlarm(QTime time)
{
    qDebug() << "FrequentAlarm::addFrequentAlarm";
    this->time = time;
    this->time = this->time.addSecs(generateRandomSec());

    qDebug() << "FrequentAlarm::addFrequentAlarm; time: " << time;

    AlarmInfo* alarmInfo = new AlarmInfo(this->time, AlarmType::frequent);
    AlarmList::getInstance()->addAlarm(alarmInfo);

    qDebug() << "FrequentAlarm::addFrequentAlarm; addedAlarm: " << this->time;
}
