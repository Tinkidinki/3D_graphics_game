#include "main.h"
#include "cuboid.h"
#include "boat.h"

#ifndef MONSTER_H
#define MONSTER_H


class Monster{
public:
    Monster() {};
    Monster(float x, float z);
    void tick(Boat* boat);
    void draw(glm::mat4 VP);
    void set_position(glm::vec3 position);
    
    Cuboid body;
    Cuboid head;
    glm::vec3 position;
    
    static int number_of_monsters;



private:
    VAO *object;
};

#endif // BARREL_AND_GIFT_H
