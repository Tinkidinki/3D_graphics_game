#include "main.h"
#include "timer.h"
#include "ball.h"
#include "cuboid.h"
#include "boat.h"
#include "rock.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

// Ball ball1;
// Cuboid cuboid1;
// Cuboid cuboid2;
// Cuboid cuboid3;
Cuboid ground;
Boat boat;
Rock rock;


float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float theta = 0; //the horizontal angle
float phi = 0; //the vertical angle
float r = 5; //Length from the target
float phi_rad;
float theta_rad;
float FoV = 45.0f;
double xpos = 0;
double ypos = 0;
double normalised_xpos = 0;
double normalised_ypos = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
       phi_rad = phi* M_PI/180.0f;
       theta_rad = theta* M_PI/180.0f;
       glm::vec3 eye(r*cos(phi_rad)*sin(theta_rad), r*sin(phi_rad), r*cos(phi_rad)*cos(theta_rad));
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (boat.position.x, boat.position.y, boat.position.z);
    // glm::vec3 target (normalised_xpos, normalised_ypos, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    // ball1.draw(VP);
    // cuboid1.draw(VP);
    // cuboid2.draw(VP);
    // cuboid3.draw(VP);
    ground.draw(VP);
    boat.draw(VP);
    rock.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_A);
    int right = glfwGetKey(window, GLFW_KEY_D);
    int up = glfwGetKey(window, GLFW_KEY_W);
    int down = glfwGetKey(window, GLFW_KEY_S);
    int front = glfwGetKey(window, GLFW_KEY_R);
    int back = glfwGetKey(window, GLFW_KEY_F);

    if (left && theta > -89) {
        theta -= 1;
    }
    else if (right && theta < 89){
        theta += 1;
    }
    else if (up && phi < 89){
        phi+= 1;
    }
    else if (down && phi > 1){
        phi-= 1;
    }
    else if (back){
        r+=1;
    }
    else if (front && r>2){
        r-=1;
    }
    
    // cout << "Phi:" << phi <<endl;
    // cout << "Theta:" << theta <<endl;
    // cout << "R:" << r <<endl;

    glfwGetCursorPos(window, &xpos, &ypos);
    normalised_xpos = (8.0f* xpos)/1368.0f - 4.0f;
    normalised_ypos = (8.0f* ypos)/768.0f - 4.0f;


}

void tick_elements() {
   // ball1.tick();
   boat.tick();
    
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    // cuboid1 = Cuboid(0,0,0, 1.0f, 1.0f, 1.0f, 0, 0, 0, COLOR_GREEN);
    // cuboid2 = Cuboid(2,2,2, 0.5f, 1.0f, 0.25f, 0, 0, 0, COLOR_RED);
    // cuboid3 = Cuboid(1,0,0, 0.5f, 0.5f, 0.5f, 0, 0, 0, COLOR_RED);
    ground = Cuboid(0,-500,0,1000.0f, 1000.0f, 1000.0f, 0, 0, 0, COLOR_INDIGO);
    boat = Boat(0);
    rock = Rock(3,0,3);
    
    
    

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    cout<< "Ground height:" << ground.height << endl;
    cout<< "Ground width:" << ground.width << endl;
    cout<< "Ground length:" << ground.length << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 768;
    int height = 1368;

   

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

// bool detect_collision(Cuboid* a, Cuboid* b) {
//     return true;
// }

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
   // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
   Matrices.projection = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
}

// own functions
void boat_control(char action){
    cout << "Called:"<< action <<endl;
    switch(action){
        case 'f':
            boat.velocity.z = -0.03 * cos(boat.angle_in_degrees * M_PI / 180.0f);
            boat.velocity.x = -0.03 * sin(boat.angle_in_degrees * M_PI / 180.0f);
            break;
        case 'b':
            boat.velocity.z = 0.03 * cos(boat.angle_in_degrees * M_PI / 180.0f);
            boat.velocity.x = 0.03 * sin(boat.angle_in_degrees * M_PI / 180.0f);
            break;
        case 'l':
            boat.angle_in_degrees +=5;
            break;
        case 'r':
            boat.angle_in_degrees -=5;
    }
}

void jump(){
    if (boat.position.y == 0){
        boat.velocity.y = 0.1;
        boat.acceleration.y = -0.001;
    }
}