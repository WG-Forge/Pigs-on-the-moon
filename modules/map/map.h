#pragma once

#include "../constructions/base.h"
#include "../constructions/construction.h"
#include "hex.h"
#include <map>
#include <tuple>
#include <vector>

typedef std::tuple<int,int,int> Point;

//using namespace std;

class Map {
private:
    int size;
    std::vector<Construction *> content;
    std::map<Point, Hex *> grid;

    void InitGrid();

public:
    explicit Map(int size) : size(size) { InitGrid(); }

    void AddBase(std::vector<Point> &points);

    [[nodiscard]] Hex *Get(const Point &p) const { return grid.at(p); }

    static std::vector<Point> GetRing(Point center, int r);
};
