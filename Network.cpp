#include <iostream>
#include <string>
#include "Network.h"
#include <stdexcept>
#include <fstream>
#include <string>

Network::Network(const std::string &filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Could not. find file");
    }
}