#include "GameSummaryScene.h"
#include "GameScene.h"
#include "MenuSettingScene.h"
#include "SimpleAudioEngine.h"

#include "Utility.h"
#include "SlotMachine.h"
#include "Timer.h"

USING_NS_CC;

Scene* GameSummary::createScene()
{
    return GameSummary::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameSummary::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(GameSummary::menuGotoStartingMenuCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(closeItem, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
    this->addChild(menu, 1);

    std::string time_str = _Timer::getTimeStringFormat("%02d : %02d", int(GameManager::getInstance()->runningInfo.run_time / 60), int(GameManager::getInstance()->runningInfo.run_time) % 60);
    std::string damage_str = std::to_string(GameManager::getInstance()->runningInfo.damage);
    std::string gold_str = std::to_string(GameManager::getInstance()->runningInfo.gold_earn);
    std::string slot_str = std::to_string(GameManager::getInstance()->runningInfo.slot_run);
    std::string stage_str = std::to_string(GameManager::getInstance()->runningInfo.stage);
  
    auto time_label = Label::createWithTTF(time_str, "fonts/Marker Felt.ttf", 600);
    auto damage_label = Label::createWithTTF(damage_str, "fonts/Marker Felt.ttf", 600);
    auto gold_label = Label::createWithTTF(gold_str, "fonts/Marker Felt.ttf", 600);
    auto slot_label = Label::createWithTTF(slot_str, "fonts/Marker Felt.ttf", 600);
    auto stage_label = Label::createWithTTF(stage_str, "fonts/Marker Felt.ttf", 600);

    // add child time_label
    time_label->setScale(0.1f);
    if (time_label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        time_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - time_label->getContentSize().height * time_label->getScale()));

        // add the label as a child to this layer
        this->addChild(time_label, 1);
    }

    // add child damage_label
    damage_label->setScale(0.1f);
    if (damage_label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        damage_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - damage_label->getContentSize().height * time_label->getScale() - 100));

        // add the label as a child to this layer
        this->addChild(damage_label, 1);
    }

    // add child gold_label
    gold_label->setScale(0.1f);
    if (gold_label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        gold_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - gold_label->getContentSize().height * time_label->getScale() - 200));

        // add the label as a child to this layer
        this->addChild(gold_label, 1);
    }

    // add child slot_label
    slot_label->setScale(0.1f);
    if (slot_label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        slot_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - slot_label->getContentSize().height * time_label->getScale() - 300));

        // add the label as a child to this layer
        this->addChild(slot_label, 1);
    }

    // add child slot_label
    stage_label->setScale(0.1f);
    if (stage_label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        stage_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - stage_label->getContentSize().height * time_label->getScale() - 400));

        // add the label as a child to this layer
        this->addChild(stage_label, 1);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    return true;
}


void GameSummary::menuGotoStartingMenuCallback(Ref* pSender)
{
    const auto scene = StartingMenu::create();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, scene));
}
