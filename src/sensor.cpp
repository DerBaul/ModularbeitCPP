#include "sensor.h"
#include <iostream> // Optional, falls Sie Standardausgaben zur Fehlerdiagnose benötigen

Sensor::Sensor(int type, const std::string& beschreibung, const std::string& adresse, int interval)
    : type(type), beschreibung(beschreibung), adresse(adresse), interval(interval),
      lastMeasurementTime(std::chrono::steady_clock::now()) {}

Sensor::~Sensor() {
    // Hier können Sie Aufräumarbeiten durchführen, falls erforderlich
}

int Sensor::getType() const {
    return type;
}

std::string Sensor::getBeschreibung() const {
    return beschreibung;
}

std::string Sensor::getAdresse() const {
    return adresse;
}

int Sensor::getInterval() const {
    return interval;
}
