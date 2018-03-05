#include "fireball.h"
#include <stdio.h>
using namespace std;

Fireball::Fireball(glm::vec3 cannon_position, float x_pos, float y_pos):
    Cuboid(cannon_position.x, cannon_position.y, cannon_position.z, 
        1, 1, 1, 0, 0, 0, COLOR_BRICK){
            float theta = x_pos/4.0f * (M_PI/2.0f);
            float phi = y_pos/4.0f * (M_PI/2.0f);

            float vel = 0.1f;
            float x_vel = vel*cos(phi)*sin(theta);
            float y_vel =  - vel*sin(phi);
            float z_vel = -(vel*cos(phi)*cos(theta));

            this->velocity = glm::vec3(x_vel, y_vel, z_vel);
            this->acceleration = glm::vec3(0, -0.0005f, 0);
            Fireball::exists = true;


}

void Fireball::tick(Boat* boat, Monster* monster){
    this->velocity += this->acceleration;
    this->position += this->velocity;

    if (Monster::number_of_monsters > 0){
        if (Cuboid::detect_collision(this, &(monster->head))
            or Cuboid::detect_collision(this, &(monster->body))) {
            Monster::number_of_monsters--;
            cout << "Num of monsters" << Monster::number_of_monsters << endl;
            monster->position = glm::vec3(0, -20.0f, 0);
        }
    }

    // this->keep_at_bay(boat);
}

void Fireball::keep_at_bay(Boat* boat){
    if (this-> position.y < 0){
        Fireball:exists = false;
        delete this;

    }
}
