cmake_minimum_required(VERSION 3.0)
project(Obserwator)

#file(GLOB_RECURSE SOURCES "*.cpp")
#file(GLOB_RECURSE HEADERS "*.h")
#set(SOURCES main.cpp)
add_library(ObserverHead 
	Subject.cpp
		#FileSaver.cpp
		#MHZ14A-co2/CarbonDioxideSensor.cpp
	Sensor.h
	Observer.cpp)

add_executable(data_acquirer main.cpp)
target_link_libraries(data_acquirer ObserverHead)
