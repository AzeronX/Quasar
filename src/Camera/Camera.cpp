#include "Camera.h"

Camera::Camera()
{
    position = glm::vec3(0.f);
    direction = glm::vec3(0.f, 0.f, -1.f);

    FOV = 60.f;
    aspectRatio = 4.f/3.f;
    nearClip = 1.f;
    farClip = 100.f;
}

void Camera::setPosition(glm::vec3 pos)
{
    position = pos;
}

void Camera::setTarget(glm::vec3 pos)
{
    direction = glm::normalize(pos-position);
}

void Camera::setDirection(glm::vec3 dir)
{
    direction = glm::normalize(dir);
}

void Camera::move(glm::vec3 pos)
{
    position += pos;
}

void Camera::rotate(glm::vec3 rot)
{
    glm::mat4 rotation = glm::mat4(0.f);
    if(rot.x)
        rotation = glm::rotate(rotation, rot.x, glm::vec3(1.f, 0.f, 0.f));
    if(rot.y)
        rotation = glm::rotate(rotation, rot.y, glm::vec3(0.f, 1.f, 0.f));
    if(rot.z)
        rotation = glm::rotate(rotation, rot.z, glm::vec3(0.f, 0.f, 1.f));

    direction = glm::vec4(rotation * glm::vec4(direction, 0.f)).xyz();
}

glm::mat4 Camera::getCameraMat()
{
    glm::mat4 view = glm::lookAt(position, position+direction, glm::vec3(0.f, 1.f, 0.f));
    glm::mat4 projection = glm::perspective(FOV, aspectRatio, nearClip, farClip);
    return projection * view;
}
