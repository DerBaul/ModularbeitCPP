#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <memory>
#include "sensor.h"
#include "fileWriter.h"

class Scheduler {
private:
    std::vector<std::shared_ptr<Sensor>> alle_sensoren;
    FileWriter fileWriter;
public:
    Scheduler(const std::string& dateiPfad, const std::string& OutputName, size_t pufferSize);

    void addSensor(std::shared_ptr<Sensor> sensor);

    void messung_starten(int messungsZeitraum);
};

#endif // SCHEDULER_H
