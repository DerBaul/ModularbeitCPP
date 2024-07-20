#include "../include/scheduler.h"
#include <thread>
#include <chrono>
#include <iostream>

Scheduler::Scheduler(const std::string& dateiPfad, const std::string& OutputName, size_t pufferSize):
    fileWriter(dateiPfad, OutputName, pufferSize){}

void Scheduler::addSensor(std::shared_ptr<Sensor> neuer_sensor) {
    alle_sensoren.push_back(neuer_sensor);
}

void Scheduler::messung_starten(int messungsZeitraum) {
    auto startTime = std::chrono::high_resolution_clock::now();
    //https://stackoverflow.com/questions/60064625/how-to-get-the-difference-in-milliseconds-between-the-start-time-and-now-in-c
    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() <= messungsZeitraum) {
        for (auto& sensor : alle_sensoren) // Wir schauen uns jeden Sensor an.
            {
            if (sensor->doMessung()) //doMessung() führt die Messung aus, gibt aber nicht die Messdaten, sondern True für erfolgreich zurück
                {
                auto messdaten = sensor->getMessdaten();
                if (messdaten) {
                    std::cout << messdaten->toString() << std::endl;
                    fileWriter.addMessung(messdaten);
                }
            } else{
                std::cout<<"Intervall zwischen Messung noch nicht verstrichen"<<std::endl;
            }
        }
        //https://en.cppreference.com/w/cpp/thread/sleep_for
        //Wird auch verwendet, wenn man mit mehreren Threads arbeitet.
        //Mein Code hat nur einen Thread, die sleep funktion ist aber am ähnlichsten zu dem wie ich es Python kenne.
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); //Sleep damit nich zu viele anfragen kommen.
    }
    fileWriter.close();
}
