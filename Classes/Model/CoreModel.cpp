//
//  CoreModel.cpp
//  GameJam2019
//
//  Created by Nguyễn Văn Tùng on 10/22/19.
//

#include "CoreModel.hpp"

CoreModel::CoreModel()
{
    // Constructor
}

CoreModel::~CoreModel()
{
    //
}

void CoreModel::setVisible(const bool& visible)
{
    this->m_isVisible = visible;
    
    if (this->m_sprite != nullptr)
    {
        this->m_sprite->setVisible(m_isVisible);
    }
}

bool CoreModel::isVisible() const
{
    return m_isVisible;
}

void CoreModel::setPosition(const cocos2d::Vec2& position)
{
    this->m_position = position;
}

cocos2d::Vec2 CoreModel::getPosition() const
{
    return this->m_position;
}
