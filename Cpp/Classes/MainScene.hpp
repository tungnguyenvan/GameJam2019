//
//  MainScene.hpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 10/26/19.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Model/player/PlayerModel.hpp"
#include "GameDefinition.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
    
    bool    onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    bool    onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void    onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void    update(float);
    
private:
    bool                                    m_isTouch;
    PlayerModel*                            m_player;
    cocos2d::PhysicsWorld*                  m_physicsWorld;
    cocos2d::PhysicsBody*                   edgeBody;
    cocos2d::EventListenerTouchOneByOne*    m_touchEvent;
    
    void                setPhysicsWorld(cocos2d::PhysicsWorld* physics);
    void                initPhysicsWorld();
};

#endif /* MainScene_hpp */
