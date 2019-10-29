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

#define DEFAULT_LEG_SIZE cocos2d::Size(5, 100)
#define DEFAULT_ANCHOR cocos2d::Vec2(0.5, 1)

class PlayerModel : public CoreModel
{
public:
    PlayerModel(cocos2d::Scene* scene);
    virtual ~PlayerModel();
    
    virtual void        init() override;
    virtual void        update(float dt) override;
    
private:
    cocos2d::Sprite*    m_leftLeg;
    cocos2d::Sprite*    m_rightLeg;
    
    void                initPhysics() override;
    void                initLegs();
};

#endif /* PlayerModel_hpp */
