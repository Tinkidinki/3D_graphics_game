#include "cuboid.h"
#include "rock.h"

#include <iostream>
using namespace std;

Rock::Rock(float x, float y, float z):Cuboid(x, y, z, 2, 2, 2, 0, 0, 0, COLOR_BRICK){}

void Rock::tick(Boat* boat){
    if (Cuboid::detect_collision(this, &(boat->hull))){
        boat->velocity = -boat->velocity;
        change_health(-1);
    }
}