//
//  PlayerModel.cpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 28/10/2019.
//

#include "PlayerModel.hpp"

PlayerModel::PlayerModel(cocos2d::Scene* scene) : CoreModel(scene)
{
    // Constructor
    m_isTouched = false;
    m_isMoveByRightLeg = false;
}

PlayerModel::~PlayerModel()
{
    // Destructor
}

void PlayerModel::init()
{
    m_sprite = cocos2d::Sprite::create("CloseNormal.png");
    m_sprite->setPosition(cocos2d::Vec2(m_visibleSize.width / 2, m_visibleSize.height / 2 + 30));
    initLegs();
    
    m_sprite->setPhysicsBody(cocos2d::PhysicsBody::createCircle(m_sprite->getContentSize().width / 2));
    m_sprite->getPhysicsBody()->setMass(PLAYER_MASS);
    m_leftLeg->setPhysicsBody(cocos2d::PhysicsBody::createBox(m_leftLeg->getContentSize()));
    m_rightLeg->setPhysicsBody(cocos2d::PhysicsBody::createBox(m_rightLeg->getContentSize()));
    
    m_scene->addChild(m_leftLeg);
    m_scene->addChild(m_sprite);
    m_scene->addChild(m_rightLeg);
}

void PlayerModel::update(float dt)
{
    if (m_isTouched)
    {
        m_distance = m_physicsJointDistanceLeg->getDistance();
        if (m_isMoveByRightLeg)
        {
            m_distance += LEG_SPEED;
        }
        else
        {
            m_distance -= LEG_SPEED;
        }
        m_physicsJointDistanceLeg->setDistance(m_distance);
    }
}

void PlayerModel::initPhysics(cocos2d::PhysicsWorld* physicsWorld)
{
    CoreModel::initPhysics(physicsWorld);
    
    if (m_sprite != nullptr && m_rightLeg != nullptr && m_leftLeg != nullptr)
    {
        m_physicsJointLeft = cocos2d::PhysicsJointSpring::construct(m_sprite->getPhysicsBody(), m_leftLeg->getPhysicsBody(), cocos2d::Vec2::ZERO, cocos2d::Vec2::ZERO, -GRAVITY_Y, PLAYER_MASS);
        m_physicsJointLeft->setCollisionEnable(false);
        
        m_physicsJointRight = cocos2d::PhysicsJointSpring::construct(m_sprite->getPhysicsBody(), m_rightLeg->getPhysicsBody(), cocos2d::Vec2::ZERO, cocos2d::Vec2::ZERO, -GRAVITY_Y, PLAYER_MASS);
        m_physicsJointRight->setCollisionEnable(false);
        
        m_physicsJointDistanceLeg = cocos2d::PhysicsJointDistance::construct(m_leftLeg->getPhysicsBody(), m_rightLeg->getPhysicsBody(), cocos2d::Vec2::ZERO, cocos2d::Vec2::ZERO);
        m_physicsJointDistanceLeg->setCollisionEnable(false);
        
        m_physicsJointPinLeg = cocos2d::PhysicsJointPin::construct(m_leftLeg->getPhysicsBody(), m_rightLeg->getPhysicsBody(), m_sprite->getPosition());
        m_physicsJointPinLeg->setCollisionEnable(false);
        
        physicsWorld->addJoint(m_physicsJointLeft);
        physicsWorld->addJoint(m_physicsJointRight);
        physicsWorld->addJoint(m_physicsJointDistanceLeg);
        physicsWorld->addJoint(m_physicsJointPinLeg);
    }
}

void PlayerModel::initLegs()
{
    m_leftLeg = cocos2d::Sprite::create();
    m_leftLeg->setContentSize(DEFAULT_LEG_SIZE);
    m_leftLeg->setPosition(cocos2d::Vec2(m_visibleSize.width / 2 - 25, m_visibleSize.height / 2));
    m_leftLeg->setAnchorPoint(DEFAULT_ANCHOR);
    m_leftLeg->setRotation(15);
    
    m_rightLeg = cocos2d::Sprite::create();
    m_rightLeg->setContentSize(DEFAULT_LEG_SIZE);
    m_rightLeg->setPosition(cocos2d::Vec2(m_visibleSize.width / 2 + 25, m_visibleSize.height / 2));
    m_rightLeg->setAnchorPoint(DEFAULT_ANCHOR);
    m_rightLeg->setRotation(-15);
}

bool PlayerModel::onTouchBegan(cocos2d::Touch*)
{
    m_isTouched = true;
    return true;
}

bool PlayerModel::onTouchMoved(cocos2d::Touch* touch)
{
    return true;
}

void PlayerModel::onTouchEnded(cocos2d::Touch*)
{
    m_isTouched = false;
}
