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
    
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    auto edgeBody = cocos2d::PhysicsBody::createEdgeBox(visibleSize, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = cocos2d::Node::create();
    edgeNode->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    edgeNode->setPhysicsBody(edgeBody);
    addChild(edgeNode);
    
    m_player = new PlayerModel(this);
    m_player->init();
    
    return true;
}

void MainScene::setPhysicsWorld(cocos2d::PhysicsWorld *physics)
{
    m_physicsWorld = physics;
}

void MainScene::initPhysicsWorld()
{
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    
    auto sprite = cocos2d::Sprite::create("CloseNormal.png");
    sprite->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    sprite->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
    sprite->setPhysicsBody(cocos2d::PhysicsBody::createCircle(sprite->getContentSize().width / 2));
    this->addChild(sprite);
}

bool MainScene::onTouchBegan(cocos2d::Touch*, cocos2d::Event*)
{
    return false;
}

bool MainScene::onTouchMoved(cocos2d::Touch*, cocos2d::Event*)
{
    return false;
}

void MainScene::onTouchEnded(cocos2d::Touch*, cocos2d::Event)
{
    
}
