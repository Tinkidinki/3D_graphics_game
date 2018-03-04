#include "main.h"
#include "cuboid.h"
#include "boat.h"

#ifndef FIREBALL_H
#define FIREBALL_H


class Fireball: public Cuboid{
public:
    Fireball(){};
    Fireball(glm::vec3 cannon_position, float x_pos, float y_pos);

    // Functions
    void keep_at_bay(Boat* boat);
    void tick(Boat* boat);

  

    // Properties
    static bool exists;
    glm::vec3 velocity;
    glm::vec3 acceleration;

private:
    VAO *object;
};

#endif // CUBOID_H
