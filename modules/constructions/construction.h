#pragma once

#include "actors/vehicles/vehicle.h"
#include "enums/types.h"
#include "map/hex.h"

#include <vector>

class Construction {
public:
    ~Construction() = default;

    [[nodiscard]] ConstructionsTypes::Type GetType() const { return type; }

    Construction(ConstructionsTypes::Type type, std::vector<Hex *> &basis);

private:
    ConstructionsTypes::Type type;
};
