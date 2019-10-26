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

#define GRAVITY_Y -980
#define USE_PHYSICS 1

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainScene);
    
private:
#if defined(USE_PHYSICS)
    cocos2d::PhysicsWorld *     m_physicsWorld;
    
    void        setPhysicsWorld(cocos2d::PhysicsWorld* physics);
    void        initPhysicsWorld();
#endif
};

#endif /* MainScene_hpp */
