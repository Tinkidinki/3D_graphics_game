#include "monster.h"
#include <iostream>
using namespace std;


Monster::Monster(float x, float z){
    this->position.x = x;
    this->position.z = z;
    this->position.y = 3.5f;
    this->body = Cuboid(this->position.x, 0, this->position.z, 3, 2, 2, 0, 0, 0, COLOR_GREEN);
    this->head = Cuboid(this->position.x, 3.0f, this->position.z, 1.5f, 1.5f, 1.5f, 0, 0, 0, COLOR_GREEN);

    Monster::number_of_monsters++;


}

void Monster::tick(Boat* boat){
    if (Cuboid::detect_collision(&(this->body), &(boat->hull))){
        boat->velocity = -boat->velocity;
    }
}

void Monster::draw(glm::mat4 VP){
    this->head.draw(VP);
    this->body.draw(VP);
}
// or Cuboid::detect_collision(&(this->body), fireball))