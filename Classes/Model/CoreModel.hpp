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

class CoreModel
{
public:
    CoreModel();
    virtual ~CoreModel();
    
    virtual void        init() = 0;
    virtual void        update(float dt) = 0;
    
    void                setVisible(const bool& visible);
    bool                isVisible() const;
    
    void                setPosition(const cocos2d::Vec2& position);
    cocos2d::Vec2       getPosition() const;
    
protected:
    bool                m_isVisible;
    cocos2d::Vec2       m_position;
    cocos2d::Sprite*    m_sprite;
};

#endif /* CoreModel_hpp */
