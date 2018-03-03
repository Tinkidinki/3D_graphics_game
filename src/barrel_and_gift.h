// #include "boat.h"

// Boat::Boat(float x, float y){

//     this->barrel = Cuboid(0, 0, 0, 3, 4, 5, 0, 0, 0, COLOR_PINK);
//     this->gift = Cuboid(0, 3.5f, 0, 4, 0.25f, 0.25f, 0, 0, 0, COLOR_BLACK);


   
    
// }

// void Boat::tick(){

//     hull.angle_in_degrees = this->angle_in_degrees;
//     shaft.angle_in_degrees = this->angle_in_degrees;
//     sail.angle_in_degrees = this->angle_in_degrees;
//     cannon.angle_in_degrees = this->angle_in_degrees;
    
//     this->position.x += this->velocity.x;
//     this->position.y += this->velocity.y;
//     this->position.z += this->velocity.z;

//     this->velocity.x += this->acceleration.x;
//     this->velocity.y += this->acceleration.y;
//     this->velocity.z += this->acceleration.z;

//     hull.set_position(this->position.x, this->position.y, this->position.z);
//     shaft.set_position(this->position.x, this->position.y + 3.5f, this->position.z);
//     sail.set_position(this->position.x + 1, this->position.y + 4.5f, this->position.z);
//     cannon.set_position(this->position.x, this->position.y + 0.5f, this->position.z - 3.5f);

//     this->keep_at_bay();


// }

// void Boat::draw(glm::mat4 VP){
//     hull.draw(VP);
//     shaft.draw(VP);
//     sail.draw(VP);
//     cannon.draw(VP);
// }

// void Boat::keep_at_bay(){
//     if (this->position.y < 0){
//         this-> position.y = 0;
//         this-> acceleration.y = 0;
//     }
// }