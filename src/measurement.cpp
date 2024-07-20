#include "../include/measurement.h"
#include <sstream>

Measurement::Measurement(long long messungszeit, int sensorType, const std::string& sensorAdresse, int sequenceNumber, const std::vector<float>& values)
    : messungszeit(messungszeit), sensorType(sensorType), sensorAdresse(sensorAdresse), sequenceNumber(sequenceNumber), values(values) {}

long long Measurement::getMesszeit() {
    return messungszeit;
}

int Measurement::getSensorType() {
    return sensorType;
}

std::string Measurement::getSensorAdresse() {
    return sensorAdresse;
}

int Measurement::getSequenceNumber() {
    return sequenceNumber;
}

std::vector<float> Measurement::getValues() {
    return values;
}

//https://cplusplus.com/reference/sstream/ostringstream/

std::string Measurement::toString() {
    std::ostringstream erg;
    erg << "Messungszeit: " << messungszeit << ", " << "Type des Sensors: " << sensorType << ", " << "Sensor Address: " << sensorAdresse << ", " << "Sequence Number: " << sequenceNumber << ", " << "Values: ";
    for (const auto& value : values) {
        erg << value << " ";
    }
    return erg.str();
}
