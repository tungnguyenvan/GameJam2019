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

class PlayerModel : public CoreModel
{
public:
    PlayerModel(cocos2d::Scene* scene);
    virtual ~PlayerModel();
    
    virtual void        init() override;
    virtual void        update(float dt) override;
    
    void                initPhysics();
    
private:
};

#endif /* PlayerModel_hpp */
