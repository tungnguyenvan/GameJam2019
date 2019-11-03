//
//  CoreModel.hpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 10/22/19.
//

#ifndef CoreModel_hpp
#define CoreModel_hpp

#include <stdio.h>
#include <cocos2d.h>

#include "../GameDefinition.h"

class CoreModel
{
public:
    CoreModel(cocos2d::Scene* scene);
    virtual ~CoreModel();
    
    virtual void        init() = 0;
    virtual void        update(float dt) = 0;
    
    void                setVisible(const bool& visible);
    bool                isVisible() const;
    
    void                setPosition(const cocos2d::Vec2& position);
    cocos2d::Vec2       getPosition() const;
    
    virtual void        initPhysics(cocos2d::PhysicsWorld* physicsWorld);
    
protected:
    bool                            m_isVisible;
    cocos2d::Size                   m_visibleSize;
    cocos2d::Scene*                 m_scene;
    cocos2d::Vec2                   m_position;
    cocos2d::Sprite*                m_sprite;
    cocos2d::PhysicsWorld*          m_physicsWorld;
};

#endif /* CoreModel_hpp */
