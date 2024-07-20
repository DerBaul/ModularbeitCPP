#ifndef RANDOM_SENSOR_H
#define RANDOM_SENSOR_H

#include "sensor.h"
//#include "measurement.h"
#include <random>

class RandomSensor : public Sensor {
private:
    std::shared_ptr<Measurement> letzteMessung;
    int total_number_messungen; //für die Sequence Number

public:
    RandomSensor(const std::string& beschreibung, const std::string& adresse, int interval);

    //override markiert das hier eine Funktion der Basisklasse überschrieben wird.
    virtual bool doMessung() override;

    virtual std::shared_ptr<Measurement> getMessdaten() const override;
};

#endif // RANDOM_SENSOR_H
