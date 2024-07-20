#include "../include/fileWriter.h"
#include <fstream>
#include <iostream>

FileWriter::FileWriter(const std::string& dateiPfad, const std::string& OutputName, size_t pufferSize):
    dateiPfad(dateiPfad), OutputName(OutputName), pufferSize(pufferSize) {

    //Dieser Block sorgt dafür das beim Initialisieren der Klasse, das Dokument unter Pfad clear gemacht wird.
    //Stellt sicher, dass die messdaten.txt leer ist, wenn das erste Mal reingeschrieben wird.
    std::string pfad = dateiPfad + "/" + OutputName;
    std::ofstream file(pfad);
    if (!file.is_open()) {
        std::cout << "Konnte datei an diesem Pfad nicht finden: " << pfad << std::endl;
    }
    file.close();
}

//Wenn noch Messungen im Puffer sind aber das Program stoppt
FileWriter::~FileWriter() {
    close();
}

void FileWriter::addMessung(std::shared_ptr<Measurement> messung) {
    puffer.push_back(messung);
    if (puffer.size() >= pufferSize) {
        PufferAbspeichern();
    }
}

void FileWriter::PufferAbspeichern() {
    //https://stackoverflow.com/questions/26084885/appending-to-a-file-with-ofstream
    //Ich möchte jedes Mal neue Messungen hinzufügen/append (ios_base::app)
    std::string pfad = dateiPfad + "/" + OutputName;
    std::ofstream file(pfad, std::ios_base::app);
    if (!file.is_open()) {
        std::cout << "Konnte datei an diesem Pfad nicht finden: " << pfad << std::endl;
        return;
    }

    for (const auto& messung : puffer) {
        file << messung->toString() << std::endl;
    }

    puffer.clear();
    file.close();
}

void FileWriter::close() {
    if (!puffer.empty()) {
        PufferAbspeichern();
    }
}
