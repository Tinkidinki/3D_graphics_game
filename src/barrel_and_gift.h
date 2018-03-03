#include "main.h"
#include "cuboid.h"
#include "boat.h"

#ifndef BARREL_AND_GIFT_H
#define BARREL_AND_GIFT_H


class BarrelAndGift{
public:
    BarrelAndGift() {};
    BarrelAndGift(float x, float z);
    void tick(Boat* boat);
    void draw(glm::mat4 VP);
    
    Cuboid barrel;
    Cuboid gift;
    glm::vec3 position;



private:
    VAO *object;
};

#endif // BARREL_AND_GIFT_H
