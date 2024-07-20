#ifndef SINUS_SENSOR_H
#define SINUS_SENSOR_H

#include "sensor.h"
#include "measurement.h"
#include <memory>
#include <cmath>

class SinusSensor : public Sensor {
private:
    std::shared_ptr<Measurement> letzteMessung;
    float winkel;
    float schrittweite;

public:
    SinusSensor(const std::string& beschreibung, const std::string& adresse, int interval, float schrittweite);

    virtual ~SinusSensor();

    virtual bool doMessung() override;

    virtual std::shared_ptr<Measurement> getMessdaten() const override;
};

#endif // SINUS_SENSOR_H
