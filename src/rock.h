#include "main.h"
#include "cuboid.h"
#include "boat.h"

#ifndef ROCK_H
#define ROCK_H


class Rock: public Cuboid {
public:
    Rock() {};
    Rock(float x, float y, float z);
    void tick(Boat* boat);

private:
    VAO *object;
};

#endif // ROCK_H
