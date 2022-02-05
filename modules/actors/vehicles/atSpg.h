#ifndef PIGS_ON_THE_MOON_ATSPG_H
#define PIGS_ON_THE_MOON_ATSPG_H

#include "vehicle.h"

class AtSpg : public Vehicle {
public:
    explicit AtSpg(int playerId) : Vehicle(playerId, 2, 1) {};

    [[nodiscard]] std::multimap<int, Point> GetAvailableMovePoints(Point target, int r) const override;

    std::vector<bool> IsAvailableForShoot(const std::vector<Point>& points) override;

    Action PriorityAction() const override {return Action::SHOOT;}
};


#endif//PIGS_ON_THE_MOON_ATSPG_H