//
//  TestWebSocket.hpp
//  ArmatureDemo
//
//  Created by a on 16/4/7.
//
//

#ifndef TestWebSocket_hpp
#define TestWebSocket_hpp

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
#include "network/WebSocket.h"
using namespace cocos2d::network;


class TestWebSocket:public Layer,public network::WebSocket::Delegate {
    
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TestWebSocket);
    void initUI();
#pragma mark WEBDEL
    void onOpen(cocos2d::network::WebSocket* ws);
    void onMessage(cocos2d::network::WebSocket* ws, const network::WebSocket::Data& data);
    void onClose(cocos2d::network::WebSocket* ws);
    void onError(WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
    
    //显示状态
    Label* sendTextStatus;
    cocos2d::network::WebSocket* _wsiSendText;
    
    
    void menuCloseCallback(Ref* sender);
    void keepAlive(float dt);//时间调度，向服务器发送数据并且计算时间差值
    long currentTime;//记住服务器发送数据的时间
};

#endif /* TestWebSocket_hpp */
