#pragma once

#include <PlanetQuad.h>
#include <RenderProgram.h>
#include <Camera.h>

class Planet
{

public:

    Planet();
    ~Planet();

    void update(double diff, Camera *camera);
    void draw(Camera *camera);

private:

    PlanetQuad quads;
    RenderProgram *shader;

    GLuint vao;
    GLuint positions;

};
