#include "include/sensorFactory.h"
#include "include/scheduler.h"
#include <iostream>

int main() {
    SensorFactory sensorFactory;
    Scheduler scheduler("../Messdaten", "messdaten.txt", 7);

    //https://stackoverflow.com/questions/10925675/c-exception-handling
    //Exception, falls ein falscher Input übergeben wird.
    try{
        // SensorFactory erstellt zwei Sensoren
        auto randomSensor = sensorFactory.createSensor(1, "Random Sensor", "Ran_1", 500);
        auto sinusSensor = sensorFactory.createSensor(2, "Sinus Sensor", "Sin_1", 500, 0.1);

        /* Dieser Code triggert eine Fehlerausgabe
        auto randomSensor = sensorFactory.createSensor(4, "Random Sensor", "Ran_1", 500);
        auto sinusSensor = sensorFactory.createSensor(5, "Sinus Sensor", "Sin_1", 500, 0.1);
         */
    // Die Sensoren zum Scheduler hinzufügen
    // Muss im try block sein, weil die Sensoren nur im Scope des try blocks aufrufbar sind.
    scheduler.addSensor(randomSensor);
    scheduler.addSensor(sinusSensor);

    //Wenn in einer der createSensor Funktionen ein Fehler geworfen wird, wird er hier gefangen.
    } catch (const std::exception& e){
        std::cout << "Fehler: " << e.what() << std::endl;
    }
    // Messung starten und einstellen der Zeit. 1000ms == 1sec
    scheduler.messung_starten(5000);

    return 0;
}

