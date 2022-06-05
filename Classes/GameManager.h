#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <cocos2d.h>
#include <utility>
#include "GameMap.h"
#include "GameStateLayer.h"
#include "GameMapManager.h"
#include "BaseMonster.h"
#include "EventHandler.h"

class GameManager
{
public:
    static GameManager* getInstance();
    void init();

    cocos2d::Layer* getLayer() const;
    Hero* getHero() const;      // for test
    std::vector<BaseMonster*> monsterVec;

    void startNewGame();

    void deleteMonster(BaseMonster* dM);
    
    void clearLayer();
    void removeAllGameMap();
    void loadGameMap(int w, int h);

    void loadUpMap();
    void loadDownMap();
    void loadRightMap();
    void loadLeftMap();

    void update(float dt);

    void goNextStage(); // must move to private
private:
    GameManager();
    
    static GameManager* sharedGameMapManager;
    TMXTiledMap* doLoadGameMap(int w, int h);

    void createMonsters();
 
    void allocateGameMap();
    void makeGameMap();
    void deleteGameMap();
    void updateMapClear();

    void gameOver();
    void menuGotoSummarySceneCallback(cocos2d::Ref* pSender);

    cocos2d::Layer* _layer;
    GameStateLayer* _state_layer;
    GameMapManager mapManager;
    GameMap*** _gameMap;  // Must make data structure form;
    std::pair<int, int> currentPosition;

    Hero* _hero;

    bool isGameOver;

    int gameStage;
    int mapWidth, mapHeight;
};

#endif
