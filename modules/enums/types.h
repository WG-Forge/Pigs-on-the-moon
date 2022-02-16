#pragma once

#include <string>

namespace VehiclesTypes {
    enum Type { // turn order
        SPG, LIGHT_TANK, HEAVY_TANK, MEDIUM_TANK, AT_SPG
    };
    extern const int typesNum;
    extern const std::string sTypes[];
//    extern const int numPlayerVehicles;
}

namespace ConstructionsTypes {
    enum Type {
        BASE, OBSTACLE, EMPTY
    };
    extern const int typesNum;
    extern const std::string sTypes[];
}