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
}

PlayerModel::~PlayerModel()
{
    // Destructor
}

void PlayerModel::init()
{
    m_sprite = cocos2d::Sprite::create("CloseNormal.png");
    m_sprite->setPosition(cocos2d::Vec2(100, 250));
    initLegs();
}

void PlayerModel::update(float dt)
{
    
}

void PlayerModel::initPhysics(cocos2d::PhysicsWorld* physicsWorld)
{
    CoreModel::initPhysics(physicsWorld);
    
    if (m_sprite != nullptr && m_rightLeg != nullptr && m_leftLeg != nullptr)
    {
        m_sprite->setPhysicsBody(cocos2d::PhysicsBody::createCircle(m_sprite->getContentSize().width / 2));
        m_leftLeg->setPhysicsBody(cocos2d::PhysicsBody::createBox(m_leftLeg->getContentSize()));
        m_rightLeg->setPhysicsBody(cocos2d::PhysicsBody::createBox(m_rightLeg->getContentSize()));
        
        m_physicsJointPin = cocos2d::PhysicsJointPin::construct(m_leftLeg->getPhysicsBody(), m_rightLeg->getPhysicsBody(), cocos2d::Vec2(m_visibleSize.width / 2, m_visibleSize.height / 2 - 25));
        m_physicsJointPin->createConstraints();
        physicsWorld->addJoint(m_physicsJointPin);
        
        m_scene->addChild(m_leftLeg);
        m_scene->addChild(m_sprite);
        m_scene->addChild(m_rightLeg);
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

bool PlayerModel::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
    return false;
}

bool PlayerModel::onTouchMoved(cocos2d::Touch*, cocos2d::Event*)
{
    return false;
}

void PlayerModel::onTouchEnded(cocos2d::Touch*, cocos2d::Event)
{
    
}
