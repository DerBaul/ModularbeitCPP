#include "../include/randomSensor.h"
#include "../include/measurement.h"
#include <chrono>
#include <iostream> // Für die Ausgabe des Zufallswerts

RandomSensor::RandomSensor(const std::string& beschreibung, const std::string& adresse, int interval)
    : Sensor(1, beschreibung, adresse, interval){
        total_number_messungen = 0;
    }

bool RandomSensor::doMessung() {
    auto now = std::chrono::steady_clock::now(); //aktuelle Zeit
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMeasurementTime).count() >= interval) {

        // Hier wird der zufällige Wert erstellt.
        // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_real_distribution<> dist(0.0, 1.0);
        float value = dist(rng);

        letzteMessung = std::make_shared<Measurement>(
                std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count(),
                type,
                adresse,
                total_number_messungen, // Sequenznummer, hier 0 für Vereinfachung
                std::vector<float>{value}
        );
        total_number_messungen+=1; //Sequenz Number wurde erhöht
        lastMeasurementTime = now;
        return true;
    }
    return false;
}

std::shared_ptr<Measurement> RandomSensor::getMessdaten()const{
    return letzteMessung;
}
