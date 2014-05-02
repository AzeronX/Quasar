#pragma once

#include <opengl.h>


/// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

class Camera
{
public:

    Camera();

    void setPosition(glm::vec3 pos);
    void setPosition(float x, float y, float z) { setPosition(glm::vec3(x, y, z)); }

    void setTarget(glm::vec3 pos);
    void setTarget(float x, float y, float z) { setTarget(glm::vec3(x, y, z)); }

    void setDirection(glm::vec3 dir);
    void setDirection(float x, float y, float z) { setDirection(glm::vec3(x, y, z)); }

    void move(glm::vec3 mov);
    void move(float x, float y, float z) { move(glm::vec3(x, y, z)); }

    void rotate(glm::vec3 rot);
    void rotate(float x, float y, float z) { rotate(glm::vec3(x, y, z)); }

    void setAspectRatio(float val) { aspectRatio = val; }
    void setNearClip(float val) { nearClip = val; }
    void setFarClip(float val) { farClip = val; }
    void setFOV(float val) { FOV = val; }

    glm::mat4 getCameraMat();


private:

    glm::vec3 position;
    glm::vec3 direction;

    float FOV;
    float aspectRatio;
    float nearClip;
    float farClip;

};
