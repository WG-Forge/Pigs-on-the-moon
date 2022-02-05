#pragma once

#include "../actors/player.h"
#include "../actors/vehicles/vehicle.h"
#include "../enums/action.h"
#include "../map/map.h"
#include "actionController.h"
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include "../enums/vehicle_types.h"

class Game {
private:
    std::vector<int> state;
    std::vector<std::vector<Vehicle *>> vehicles;

    // new: custom id start from 0 to numPlayers - 1
    std::map<int, int> playersIdAdapter;// [real id 1, ..]->[0, 1, 2]
    std::vector<int> tanksIdAdapter;    // save real id for server

    // order??

    std::vector<int> captures;
    std::vector<int> kills;

    const int numRounds = 15;

    int numTurns;
    int currentTurn;

    int numPlayers;
    int currentPlayerId;

    bool isFinished = false;

    std::vector<std::vector<int>> attackMatrix;// {"id" : "whom attack"}
    Map *map;

    Player *player;

    [[nodiscard]] Vehicle *Find(int adaptedPlayerId, const std::tuple<int, int, int> &spawn) const;

public:
    Game() = default;

    ~Game();

    // init methods
    // all inits must be called firstly!
    void InitMap(int size) { map = new Map(size); }

    void InitPlayer(int id, std::string name, std::string password = "") { player = new Player(id, name, password); }

    void InitVariables(int playersNum = 3);

    void InitPlayersId(const std::vector<int> &realId);

    void InitVehiclesIds(int playerId, const std::vector<int> &realId);

    // add methods
    void AddVehicle(int playerId, VehiclesTypes::Type type, std::tuple<int, int, int> spawn);

    void AddVehicle(int playerId, std::string &type, std::tuple<int, int, int> spawn);

    void AddBase(std::vector<std::tuple<int, int, int>> &points) { map->AddBase(points); }

    // get state
    void UpdateState(int currTurn, int currPlayer, bool finished = false);

    void UpdateVehicleState(int parentId, std::tuple<int, int, int> spawn, std::tuple<int, int, int> pos, int health,
                            int capturePoints);

    void UpdateAttackMatrix(int playerId, std::vector<int> attacked) {
        attackMatrix[playersIdAdapter.at(playerId)] = std::move(attacked);
    }

    void UpdateWinPoints(int playerId, int capture, int kill);

    [[nodiscard]] std::vector<std::tuple<Action, int, Hex *>> Play() const;

    // get action
    // ...

    // Getters

    [[nodiscard]] int GetNumPlayers() const;

    [[nodiscard]] bool IsFinished() const;

    [[nodiscard]] bool isPlayerTurn() const;

};
