#pragma once

#include <opengl.h>
#include <RenderProgram.h>
#include <Camera.h>
#include <Planet.h>

class App
{
public:

    App();
    ~App();

    void run();


private:

    bool init();
    void update(double diff);
    void draw();

    GLFWwindow* window;
    Camera camera;
    Planet *planet;

};
