#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <string>
#include <vector>
#include <memory>
#include "measurement.h"

class FileWriter {
private:
    std::string dateiPfad;
    std::string OutputName;
    std::vector<std::shared_ptr<Measurement>> puffer;
    size_t pufferSize;

    void PufferAbspeichern();

public:
    FileWriter(const std::string& filePath, const std::string& fileName, size_t pufferSize);

    ~FileWriter(); //ein Destructor. Wird aufgerufen, wenn die Klasse zerstört wird.

    void addMessung(std::shared_ptr<Measurement> messung);

    void close(); //zum Aufräumen und Prozesse abschließen
};

#endif // FILE_WRITER_H
