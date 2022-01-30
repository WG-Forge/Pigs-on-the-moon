#ifndef PIGS_ON_THE_MOON_GAME_CLIENT_H
#define PIGS_ON_THE_MOON_GAME_CLIENT_H

#include "../libs/json-3.10.5/include/nlohmann/json.hpp"
#include "client/client.h"
#include "game/game.h"

class GameClient {
public:
    GameClient();

    // must be called once and first.
    bool initGame(const std::string& name, const std::string& password = "",
                  const std::string& game_name="", int num_turns = 45, int num_players = 3,
                  bool is_observer = false);

    [[nodiscard]] bool GameIsFinished() const;

    void CheckGameState();

//    void CheckGameAction();  Do we really need this?

    ~GameClient();

    [[nodiscard]] bool SendTurn() const;

    void SendAction() const;

private:

    // entities
    Game* game;
    Client* client;

    void InitPlayersId();
    tuple<int, int, int> MakePosTuple(nlohmann::json coordinate);

};




#endif //PIGS_ON_THE_MOON_GAME_CLIENT_H
