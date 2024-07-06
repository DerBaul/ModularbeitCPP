#include "./include/randomSensor.h"
#include <chrono>
#include <iostream> // Für die Ausgabe des Zufallswerts

RandomSensor::RandomSensor(const std::string& beschreibung, const std::string& adresse, int interval)
    : Sensor(1, beschreibung, adresse, interval){
        total_number_messungen = 0;
    }

RandomSensor::~RandomSensor() {}

bool RandomSensor::doMessung() {
    auto now = std::chrono::steady_clock::now();
    auto zeit_zwischen_Messung = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMeasurementTime).count();

    if (zeit_zwischen_Messung >= interval) {
        //Code für RandomZahlen
        //https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

        std::cout << dist6(rng) << std::endl;

        double value = dist6(rng); // Generiere einen zufälligen Wert zwischen 0 und 1
        std::cout << "Zufällige Zahl: " << value << std::endl;

        // Erstellen einer neuen Measurement-Instanz mit den entsprechenden Parametern
        letzteMessung = std::make_shared<Measurement>(now, type, adresse, total_number_messungen, std::vector<double>{value});
        total_number_messungen += 1;
        lastMeasurementTime = now;
        return true;
    }
    return false;
}

std::shared_ptr<const Measurement> RandomSensor::getMessdaten() const {
    return letzteMessung;
}
