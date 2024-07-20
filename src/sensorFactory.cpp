#include "../include/sensorFactory.h"
#include <iostream>

// Implementierung für RandomSensor
std::shared_ptr<Sensor> SensorFactory::createSensor(int type, const std::string& beschreibung, const std::string& adresse, int interval) {
    if (type == 1) {
        return std::make_shared<RandomSensor>(beschreibung, adresse, interval);
    } else {
        throw std::invalid_argument("Falscher Sensor Typ für 'Random Sensor' ");
    }
}

// Implementierung für SinusSensor
std::shared_ptr<Sensor> SensorFactory::createSensor(int type, const std::string& beschreibung, const std::string& adresse, int interval, double winkelSchrittweite) {
    if (type == 2) {
        return std::make_shared<SinusSensor>(beschreibung, adresse, interval, winkelSchrittweite);
    } else {
        throw std::invalid_argument("Falscher Sensor Typ für 'Sinus Sensor' ");
    }
}
