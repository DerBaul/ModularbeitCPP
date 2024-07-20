#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H
#include <string>
#include <vector>
#include <memory>
#include "sensor.h"
#include "randomSensor.h"
#include "SinusSensor.h"

class SensorFactory {
public:
    // Überladene Funktion. Erstellt den RandomSensor
    std::shared_ptr<Sensor> createSensor(int type, const std::string& beschreibung, const std::string& adresse, int interval);

    // Überladene Funktion. Erstellt den SinusSensor
    std::shared_ptr<Sensor> createSensor(int type, const std::string& beschreibung, const std::string& adresse, int interval, double winkelSchrittweite);
};

#endif // SENSOR_FACTORY_H
