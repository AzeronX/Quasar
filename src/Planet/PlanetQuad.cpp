#include <PlanetQuad.h>

PlanetQuad::PlanetQuad()
{
    vertices[0] = 1.f;
    vertices[1] = 1.f;
    vertices[2] = 0.f;

    vertices[3] = 1.f;
    vertices[4] = -1.f;
    vertices[5] = 0.f;

    vertices[6] = -1.f;
    vertices[7] = -1.f;
    vertices[8] = 0.f;

    vertices[9] = -1.f;
    vertices[10] = 1.f;
    vertices[11] = 0.f;
}

PlanetQuad::~PlanetQuad()
{

}

void PlanetQuad::fillPatch(std::vector<float> &patch)
{
    for(uint8 i = 0; i<(4*3); ++i)
        patch.push_back(vertices[i]);
}
