#include <iostream>
#include <fstream>
#include "JSON/json/include/nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream file("configAeropuerto.json");
    
    if (!file.is_open()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    json config;
    try {
        file >> config;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing: " << e.what() << std::endl;
        return 1;
    }

    // Access and print specific fields in the JSON
    int simulationTime = config["simulacion"]["tiempo_simulacion"];
    int minPassengers = config["simulacion"]["cantidad_pasajeros"]["min"];
    int maxPassengers = config["simulacion"]["cantidad_pasajeros"]["max"];

    // Print the retrieved values
    std::cout << "Simulation Time: " << simulationTime << " seconds" << std::endl;
    std::cout << "Min Passengers: " << minPassengers << std::endl;
    std::cout << "Max Passengers: " << maxPassengers << std::endl;

    return 0;
}