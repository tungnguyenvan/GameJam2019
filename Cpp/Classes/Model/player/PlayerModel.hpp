//
//  PlayerModel.hpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 28/10/2019.
//

#ifndef PlayerModel_hpp
#define PlayerModel_hpp

#include <stdio.h>
#include <cocos2d.h>

#include "../CoreModel.hpp"

#define DEFAULT_LEG_SIZE cocos2d::Size(5, 120)
#define DEFAULT_ANCHOR cocos2d::Vec2(0.5, 0.9)
#define LEG_SPEED 1
#define PLAYER_MASS 10

class PlayerModel : public CoreModel
{
public:
    PlayerModel(cocos2d::Scene* scene);
    virtual ~PlayerModel();
    
    virtual void        init() override;
    virtual void        update(float dt) override;
    
    bool                onTouchBegan(cocos2d::Touch*);
    bool                onTouchMoved(cocos2d::Touch*);
    void                onTouchEnded(cocos2d::Touch*);
    
    void                initPhysics(cocos2d::PhysicsWorld* physicsWorld) override;
    
private:
    // private variable
    bool                            m_isTouched;
    bool                            m_isMoveByRightLeg;
    int                             m_distance;
    cocos2d::Sprite*                m_leftLeg;
    cocos2d::Sprite*                m_rightLeg;
    cocos2d::PhysicsJointSpring*    m_physicsJointLeft;
    cocos2d::PhysicsJointSpring*    m_physicsJointRight;
    cocos2d::PhysicsJointDistance*  m_physicsJointDistanceLeg;
    cocos2d::PhysicsJointPin*       m_physicsJointPinLeg;
    cocos2d::PhysicsJointPin*       m_physicsJointPinLeft;
    cocos2d::PhysicsJointPin*       m_physicsJointPinRight;
    
    // private function
    void                            initLegs();
};

#endif /* PlayerModel_hpp */
