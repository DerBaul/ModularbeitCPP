#include "../include/SinusSensor.h"
#include "../include/measurement.h"
#include <chrono>

// Konstruktor
SinusSensor::SinusSensor(const std::string& beschreibung, const std::string& adresse, int interval, float schrittweite)
        : Sensor(2, beschreibung, adresse, interval), winkel(0.0), schrittweite(schrittweite) {}

// Destruktor
SinusSensor::~SinusSensor() {}

// Messung durchführen
bool SinusSensor::doMessung() {
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMeasurementTime).count() >= interval) {
        // Sinuswert berechnen
        float value = std::sin(winkel);

        // Messung erstellen
        letzteMessung = std::make_shared<Measurement>(
                std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count(),
                type,
                adresse,
                0, // Sequenznummer, hier 0 für Vereinfachung
                std::vector<float>{winkel, value}
        );

        lastMeasurementTime = now;
        winkel += schrittweite;
        return true;
    }
    return false;
}

// Messdaten abrufen
std::shared_ptr<Measurement> SinusSensor::getMessdaten() const {
    return letzteMessung;
}
