#include "barrel_and_gift.h"
#include <iostream>
using namespace std;


BarrelAndGift::BarrelAndGift(float x, float z){
    this->position.x = x;
    this->position.z = z;
    this->position.y = 3.5f;
    this->barrel = Cuboid(this->position.x, 0, this->position.z, 1, 4, 1, 0, 0, 0, COLOR_GREEN);
    this->gift = Cuboid(this->position.x, 5.0f, this->position.z, 1.0f, 1.0f, 1.0f, 0, 0, 0, COLOR_RED);


}

void BarrelAndGift::tick(Boat* boat){
    if (Cuboid::detect_collision(&(this->gift), &(boat->hull))){
        this->gift.position.y = -10.0f;
    }
}

void BarrelAndGift::draw(glm::mat4 VP){
    this->barrel.draw(VP);
    this->gift.draw(VP);
}