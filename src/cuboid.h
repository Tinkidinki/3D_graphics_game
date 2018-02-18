#include "main.h"

#ifndef CUBOID_H
#define CUBOID_H


class Cuboid {
public:
    Cuboid() {}
    Cuboid(float x, float y, float z, 
            float height, float length, float width, 
            float rot_x, float rot_y, float rot_z,
            color_t color);
    glm::vec3 position;
    glm::vec3 rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();

    float height;
    float length;
    float width;

    float speed;
private:
    VAO *object;
};

#endif // CUBOID_H
