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
    std::vector<double> values;

public:
    Measurement(long long messungszeit, int sensorType, const std::string& sensorAdresse, int sequenceNumber, const std::vector<double>& values);

    long long getMesszeit() const;

    int getSensorType() const;

    std::string getSensorAdresse() const;

    int getSequenceNumber() const;

    std::vector<double> getValues() const;

    std::string toString() const;

};

#endif // MEASUREMENT_H
