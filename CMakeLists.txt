cmake_minimum_required(VERSION 3.27)
project(Modularbeit)

set(CMAKE_CXX_STANDARD 17)

add_executable(Modularbeit main.cpp
        src/randomSensor.cpp
        src/measurement.cpp
        src/sensor.cpp
        include/SinusSensor.h
        src/SinusSensor.cpp
        include/fileWriter.h
        src/fileWriter.cpp
        include/sensorFactory.h
        src/sensorFactory.cpp
        include/scheduler.h
        src/scheduler.cpp)
