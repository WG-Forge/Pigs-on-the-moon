#pragma once

#include "client/client.h"
#include "game/game.h"
#include "enums/vehicle_types.h"


class GameClient {
public:
    explicit GameClient(bool debug = false);

    // must be called once and first.
    bool InitGame(const std::string &name, const std::string &password = "",
                  const std::string &gameName = "", int numTurns = 0, int numPlayers = 1,
                  bool isObserver = false);


    [[nodiscard]] bool GameIsFinished() const { return game->IsFinished(); }

    void UpdateGameState();

    //    void CheckGameAction();  Do we really need this?

    ~GameClient();

    bool SendTurn() const;

    void SendAction() const;

    void InitPlayersId();

    Client *GetClient() const { return client; }

    [[nodiscard]] bool IsPlayTime() const { return game->IsPlayerTurn(); }

private:
    // entities
    Game* game;
    Client* client;

    static tuple<int, int, int> MakePosTuple(nlohmann::ordered_json coordinate);

    tuple<int, int, int> MakePosTuple(const nlohmann::ordered_json &coordinate);
};
