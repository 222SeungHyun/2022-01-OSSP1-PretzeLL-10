/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "StartingMenuScene.h"
#include "GameScene.h"
#include "MenuSettingScene.h"
#include "SimpleAudioEngine.h"

#include "Utility.h"
#include "SlotMachine.h"
#include "Timer.h"

USING_NS_CC;

Scene* StartingMenu::createScene()
{
	return StartingMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartingMenu::init()
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
	// 2. add menu Item
    cocos2d::Sprite* menu_sprite[3][2];
    menu_sprite[0][0] = cocos2d::Sprite::create("frames/PlayNonClick.png");
    menu_sprite[0][1] = cocos2d::Sprite::create("frames/PlayOnClick.png");
    menu_sprite[1][0] = cocos2d::Sprite::create("frames/SettingNonClick.png");
    menu_sprite[1][1] = cocos2d::Sprite::create("frames/SettingOnClick.png");
    menu_sprite[2][0] = cocos2d::Sprite::create("frames/ExitNonClick.png");
    menu_sprite[2][1] = cocos2d::Sprite::create("frames/ExitOnClick.png");
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            menu_sprite[i][j]->setScale(0.75f);
            menu_sprite[i][j]->getTexture()->setTexParameters(TEX_PARA);
        }
    }
    
    auto playItem = MenuItemSprite::create(menu_sprite[0][0], menu_sprite[0][1], CC_CALLBACK_1(StartingMenu::menuPlayCallback, this));
    auto settingItem = MenuItemSprite::create(menu_sprite[1][0], menu_sprite[1][1], CC_CALLBACK_1(StartingMenu::menuSettingCallback, this));
    auto closeItem = MenuItemSprite::create(menu_sprite[2][0], menu_sprite[2][1], CC_CALLBACK_1(StartingMenu::menuCloseCallback, this));

	// create menu, it's an autorelease object
	auto menu = Menu::create(playItem, settingItem, closeItem, NULL);
    menu->alignItemsVerticallyWithPadding(-20.0f);
	menu->setPosition(Vec2(visibleSize.width / 2 + 50.0f, visibleSize.height / 2 - 200));
	this->addChild(menu, 1);

	/////////////////////////////
	// 3.
	auto titleSprite = Sprite::create("frames/MoiraiLabel.png");
	if (titleSprite == nullptr)
	{
		problemLoading("'MoiraiLabel fault'");
	}
	else
	{
		// position the label on the center of the screen
		titleSprite->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - titleSprite->getContentSize().height - 200));

		titleSprite->setScale(3.0f);
		titleSprite->getTexture()->setTexParameters(TEX_PARA);
		// add the label as a child to this layer
		this->addChild(titleSprite, 2);
	}

	auto logoSprite = Sprite::create("frames/HourGlass.png");
	if (logoSprite == nullptr)
	{
		problemLoading("'Moirailogo fault'");
	}
	else
	{
		// position the label on the center of the screen
		logoSprite->setPosition(Vec2(origin.x + visibleSize.width / 2 + 420,
			origin.y + visibleSize.height - logoSprite->getContentSize().height - 125));

		logoSprite->setScale(1.5f);
		logoSprite->getTexture()->setTexParameters(TEX_PARA);
		// add the label as a child to this layer
		this->addChild(logoSprite, 1);
	}
	// 여기 추가 
	auto logoSprite2 = Sprite::create("frames/MoiraiLogo.png");
	if (logoSprite2 == nullptr)
	{
		problemLoading("'Moirailogo fault'");
	}
	else
	{
		// position the label on the center of the screen
		logoSprite2->setPosition(Vec2(origin.x + visibleSize.width / 2 -400,
			origin.y + visibleSize.height - logoSprite->getContentSize().height - 125));

		logoSprite2->setScale(1.5f);
		logoSprite2->getTexture()->setTexParameters(TEX_PARA);
		// add the label as a child to this layer
		this->addChild(logoSprite2, 1);
	}
	// 여기 추가 

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("sprite/MoiraiBackground2.png");
	if (sprite == nullptr)
	{
		problemLoading("'sprite/MoiraiBackground2.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}

	//auto timer = _Timer::create();
	//this->addChild(timer);
    
#ifdef __APPLE__
	if (!Audio::getInstance()->isBackgroundMusicPlaying()) {
		Audio::getInstance()->playBackgroundMusic("bgm/game_bgm1.mp3", true);
		Audio::getInstance()->setBackgroundMusicVolume(0.2f);
	}
#else
    experimental::AudioEngine::stopAll();
	experimental::AudioEngine::play2d("bgm/game_bgm1.mp3", true, 0.2f);
#endif

	return true;
}


void StartingMenu::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void StartingMenu::menuPlayCallback(Ref* pSender)
{
	const auto scene = GameScene::createScene();
	IF_RV(!scene, "Failed to create scene");
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, scene));
}

void StartingMenu::menuSettingCallback(Ref* pSender)
{
	const auto scene = MenuSetting::create();
	IF_RV(!scene, "Failed to create scene");
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5, scene));
}
