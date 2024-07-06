#ifndef RANDOM_SENSOR_H
#define RANDOM_SENSOR_H

#include "sensor.h"
//#include "measurement.h"
#include <random>

class RandomSensor : public Sensor {
private:
    std::shared_ptr<Measurement> letzteMessung;
    int total_number_messungen;

public:
    RandomSensor(const std::string& beschreibung, const std::string& adresse, int interval);

    virtual ~RandomSensor();

    virtual bool doMessung() override;

    virtual std::shared_ptr<const Measurement> getMessdaten() const override;
};

#endif // RANDOM_SENSOR_H
