#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <chrono>
#include <memory>

// Vor Declaration der Measurement-Klasse
class Measurement;

class Sensor {
protected:
    int type;
    std::string beschreibung;
    std::string adresse;
    int interval;
    std::chrono::steady_clock::time_point lastMeasurementTime;

public:
    Sensor(int type, const std::string& beschreibung, const std::string& adresse, int interval);

    virtual ~Sensor();

    int getType() const;

    std::string getBeschreibung() const;

    std::string getAdresse() const;

    int getInterval() const;

    virtual bool doMessung() = 0;

    virtual std::shared_ptr<const Measurement> getMessdaten() const = 0;
};

#endif // SENSOR_H