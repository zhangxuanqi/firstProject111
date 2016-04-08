//
//  TestWebSocket.cpp
//  ArmatureDemo
//
//  Created by a on 16/4/7.
//
//

#include "TestWebSocket.h"
Scene* TestWebSocket::createScene()
{   auto scene=Scene::create();
    auto layer=TestWebSocket::create();
    scene->addChild(layer);
    return scene;
    
}
bool TestWebSocket::init()
{
    if (!Layer::init()) {
        return false;
    }
    initUI();
    return true;
}

void TestWebSocket::initUI()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto closeItem = MenuItemImage::create("CloseNormal.png",
    "CloseSelected.png",CC_CALLBACK_1(TestWebSocket::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,origin.y + closeItem->getContentSize().height/2));
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    sendTextStatus=Label::createWithTTF("aaaa", "fonts/arial.ttf", 60);
    sendTextStatus->setPosition(Point(200,200));
    this->addChild(sendTextStatus,5);
    
    _wsiSendText = new WebSocket();
    //init第一个参数是delegate，设置为this，第二个参数是服务器地址。
    //URL中的”ws://”标识是WebSocket协议，加密的WebSocket为”wss://”.
    _wsiSendText->init(*this, "ws://echo.websocket.org");
    _wsiSendText->send("Hello ,I am websocket");
   
}

void TestWebSocket::menuCloseCallback(Ref* sender)
{
    _wsiSendText->send("Hello ,I am websocket");
}
#pragma mark WEBDEL
void TestWebSocket::onOpen(cocos2d::network::WebSocket* ws)
{
    log("onOpne");
}
void TestWebSocket::onMessage(cocos2d::network::WebSocket* ws, const network::WebSocket::Data& data)
{
    log("onmessage");
}
void TestWebSocket::onClose(cocos2d::network::WebSocket* ws)
{
    log("close");
}
void TestWebSocket::onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)
{
    log("errot");
}