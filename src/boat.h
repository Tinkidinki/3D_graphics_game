#include "main.h"
#include "cuboid.h"

#ifndef BOAT_H
#define BOAT_H


class Boat {
public:
    Boat(){};
    Boat(int x);

    // Functions
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void set_velocity(float x, float y, float z);
    void set_acceleration(float x, float y, float z);
    void keep_at_bay();
    void tick();

    // Parts
    Cuboid hull;
    Cuboid shaft;
    Cuboid sail;
    Cuboid cannon;

    // Properties
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float angle_in_degrees;

private:
    VAO *object;
};

#endif // CUBOID_H
