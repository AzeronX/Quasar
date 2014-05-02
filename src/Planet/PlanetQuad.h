#pragma once

#include <opengl.h>

class PlanetQuad
{

public:

    PlanetQuad();
    ~PlanetQuad();

    void fillPatch(std::vector<float> &patch);

private:

    PlanetQuad* children[4];
    float vertices[4*3];
};
