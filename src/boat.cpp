#include "boat.h"

Boat::Boat(int x){

    this->hull = Cuboid(0, 0, 0, 3, 4, 5, 0, 0, 0, COLOR_PINK);
    this->shaft = Cuboid(0, 3.5f, 0, 4, 0.25f, 0.25f, 0, 0, 0, COLOR_BLACK);
    this->sail = Cuboid(1, 4.5f, 0, 2, 2, 0.25f, 0, 0, 0, COLOR_YELLOW);
    this->cannon = Cuboid(0, 0.5, -3.5f, 1, 0.5, 2, 0, 0, 0, COLOR_BRICK);

   //Cuboid(0,)

    this->position.x = 0;
    this->position.y = 0;
    this->position.z = 0;

    this->velocity.x = 0;
    this->velocity.y = 0;
    this->velocity.z = 0;

    this->acceleration.x = 0;
    this->acceleration.y = 0;
    this->acceleration.z = 0;
    
}

void Boat::tick(){

    hull.angle_in_degrees = this->angle_in_degrees;
    shaft.angle_in_degrees = this->angle_in_degrees;
    sail.angle_in_degrees = this->angle_in_degrees;
    cannon.angle_in_degrees = this->angle_in_degrees;
    
    this->position += this->velocity;
    this->velocity += this->acceleration;

    hull.set_position(this->position.x, this->position.y, this->position.z);
    shaft.set_position(this->position.x, this->position.y + 3.5f, this->position.z);
    sail.set_position(this->position.x + 1, this->position.y + 4.5f, this->position.z);
    cannon.set_position(this->position.x, this->position.y + 0.5f, this->position.z - 3.5f);

    this->keep_at_bay();


}

void Boat::draw(glm::mat4 VP){
    hull.draw(VP);
    shaft.draw(VP);
    sail.draw(VP);
    cannon.draw(VP);
}

void Boat::keep_at_bay(){
    if (this-> position.y < 0){
        this-> position.y = 0;
        this-> acceleration.y = 0;
    }
}