#include "cuboid.h"
#include "main.h"

Cuboid::Cuboid(float x, float y, float z, 
                float height, float length, float width, 
                float rot_x, float rot_y, float rot_z,
                color_t color) {
    
    this->position = glm::vec3(x, y, z);
    this->rotation = glm::vec3(rot_x, rot_y, rot_z);

    this->height = height; // Corresponds to y coordinate
    this->width = width;   // Corresponds to z coordinate
    this->length = length;  // Corresponds to x coordintate
    float h = height/2;
    float w = width/2;
    float l = length/2;
    this->speed = 1;

    
    static const GLfloat vertex_buffer_data[] = {
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
        l, h, w

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
    glm::mat4 rotate    = glm::rotate((float) (this->rotation.x * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Cuboid::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Cuboid::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

