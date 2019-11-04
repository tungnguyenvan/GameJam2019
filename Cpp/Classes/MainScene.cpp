//
//  MainScene.cpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 10/26/19.
//

#include "MainScene.hpp"

cocos2d::Scene* MainScene::createScene()
{
    auto layer = MainScene::create();
    auto scene = cocos2d::Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(cocos2d::Vec2(0, GRAVITY_Y));
    scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    layer->initPhysicsWorld();
    
    scene->addChild(layer);
    return scene;
}

bool MainScene::init()
{
    if (!cocos2d::Scene::init())
    {
        return false;
    }
    
    // Init local variable
    m_isTouch = false;
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    edgeBody = cocos2d::PhysicsBody::createEdgeBox(visibleSize, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = cocos2d::Node::create();
    edgeNode->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeNode->setPhysicsBody(edgeBody);
    addChild(edgeNode);
    
    m_player = new PlayerModel(this);
    m_player->setEdgeBody(edgeBody);
    m_player->init();
    
    m_touchEvent = cocos2d::EventListenerTouchOneByOne::create();
    m_touchEvent->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    m_touchEvent->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    m_touchEvent->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_touchEvent, this);
    
    this->scheduleUpdate();
    return true;
}

void MainScene::setPhysicsWorld(cocos2d::PhysicsWorld *physics)
{
    m_physicsWorld = physics;
}

void MainScene::initPhysicsWorld()
{
    m_player->initPhysics(m_physicsWorld);
}

bool MainScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event*)
{
    m_player->onTouchBegan(touch);
    return true;
}

bool MainScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event*)
{
    m_player->onTouchMoved(touch);
    return true;
}

void MainScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    m_player->onTouchEnded(touch);
    m_isTouch = false;
}

void MainScene::update(float dt)
{
    m_player->update(dt);
}
