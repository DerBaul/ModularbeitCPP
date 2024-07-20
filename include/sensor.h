#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <chrono>
#include <memory>
class Measurement; //Dammit ich die Measurement Class hier schon benutzen kann. ( Vor Declaration )

class Sensor {
protected: //protected weil ich die Variablen in den Unterklassen verwenden möchte.
    int type;
    std::string beschreibung;
    std::string adresse;
    int interval;
    std::chrono::steady_clock::time_point lastMeasurementTime;

public:
    /*
    Die strings als const referenz zu übergeben war eine Recomendation von CLion.
    Meine Notizen dazu: (All meine Notizen sind auch in einem extra PDF beigefügt.
    const: Sorgt dafür das die Variablen in der Funktion nichtmehr veränderbar sind.
    Referenz: Übergibt man mit string wird jedes mal eine Kopie erstellt. Mit string& wird nur der Pointer übergeben. Ist effizienter und hat den Vorteil das man den String, wenn nötig, nur an einer Stelle ändern muss.
     */
     Sensor(int type, const std::string& beschreibung, const std::string& adresse, int interval);

     // Die Funktionen sind const wenn sie keine Variablen der Klasse ändern.
    int getType() const;

    std::string getBeschreibung() const;

    std::string getAdresse() const;

    int getInterval() const;

    // virtual markiert das die Funktionen in den Unterklassen überschrieben werden.
    // =0 zeigt das die Funktionen in dieser Klasse keine Implementierung haben. Macht diese Klasse zur abstrakten Klasse
    virtual bool doMessung() = 0;

    virtual std::shared_ptr<Measurement> getMessdaten() const = 0;
};

#endif // SENSOR_H