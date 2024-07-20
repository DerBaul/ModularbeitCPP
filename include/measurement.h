#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
#include <vector>
#include <chrono>
#include <memory>

class Measurement {
private:
    long long messungszeit;
    int sensorType;
    std::string sensorAdresse;
    int sequenceNumber;
    std::vector<float> values;

public:
    Measurement(long long messungszeit, int sensorType, const std::string& sensorAdresse, int sequenceNumber, const std::vector<float>& values);

    long long getMesszeit();

    int getSensorType();

    std::string getSensorAdresse();

    int getSequenceNumber();

    std::vector<float> getValues();

    std::string toString();

};

#endif // MEASUREMENT_H
