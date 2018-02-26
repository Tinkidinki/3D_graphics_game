#include "cuboid.h"
#include "main.h"

Cuboid::Cuboid(float x, float y, float z, 
                float height, float length, float width, 
                float rot_x, float rot_y, float rot_z,
                color_t color) {
    
    this->initial_position = glm::vec3(x, y, z);
    this->position = this->initial_position;
    this->rotation = glm::vec3(rot_x, rot_y, rot_z);
    this->angle_in_degrees = 0;

    this->height = height; // Corresponds to y coordinate
    this->width = width;   // Corresponds to z coordinate
    this->length = length;  // Corresponds to x coordintate
    float h = height/2;
    float w = width/2;
    float l = length/2;
    this->speed = 1;

    
    const GLfloat vertex_buffer_data[] = {
        // Front rectangle
        //----Top triangle
        -l, h, w,
        l, h, w,
        -l, -h, w,
        //---Bottom triangle
        -l, -h, w,
        l, h, w, 
        l, -h, w,

        // Back rectangle
        //----Top triangle
        -l, h, -w,
        l, h, -w,
        -l, -h, -w,
        //---Bottom triangle
        -l, -h, -w,
        l, h, -w, 
        l, -h, -w,
        
        // Left rectangle
        //----Top triangle
        -l, h, -w,
        -l, -h, -w,
        -l, h, w,
        //---Bottom triangle
        -l, h, w,
        -l,-h, -w, 
        -l, -h, w,

        // Right rectangle
        //----Top triangle
        l, h, -w,
        l, -h, -w,
        l, h, w,
        //---Bottom triangle
        l, h, w,
        l,-h, -w, 
        l, -h, w,

        // Up rectangle
        //----Top triangle
        -l, h, -w,
        -l, h, w,
        l, h, -w,
        //---Bottom triangle
        l, h, -w,
        -l, h, w, 
        l, h, w,

        // Down rectangle
        //----Top triangle
        -l, -h, -w,
        -l, -h, w,
        l, -h, -w,
        //---Bottom triangle
        l, -h, -w,
        -l, -h, w, 
        l, -h, w

    };

    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
}

void Cuboid::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation.x * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 translate_initial = glm::translate(this->initial_position);
    glm::mat4 rotate    = glm::rotate((float) (this->angle_in_degrees * M_PI / 180.0f), glm::vec3(0, 1, 0));
    
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    
    // How to use glm::rotate :
    // Model = glm::rotate(Model, angle_in_degrees, glm::vec3(x, y, z)); 
    // where x, y, z is axis of rotation (e.g. 0 1 0)
    // So take the model, specify the angle, and specify the axis to rotate about.
    // Seems really simple!

    // Matrices.model *= (translate *-translate_initial * rotate * translate_initial);
    Matrices.model *= (rotate * translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Cuboid::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Cuboid::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

