#include <opengl.h>
#include <Planet.h>

Planet::Planet()
{
    shader = new RenderProgram("glsl/planet_vs.glsl", "glsl/planet_fs.glsl", "glsl/planet_tcs.glsl", "glsl/planet_tes.glsl");
    shader->load();

    float patch[] =
    {
        -1, 1, -1,
        1, 1, -1,
        -1, 1, 1,
        1, 1, 1,
    };

    // Create the VAO:
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    // Create the VBO for positions:
    GLsizei stride = 3 * sizeof(float);
    glGenBuffers(1, &positions);
    glBindBuffer(GL_ARRAY_BUFFER, positions);
    glBufferData(GL_ARRAY_BUFFER, sizeof(patch), patch, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0);

}

Planet::~Planet()
{

}

void Planet::update(double diff, Camera *camera)
{

}

void Planet::draw(Camera *camera)
{
    shader->bind();
    glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(),"MVP"), 1, GL_FALSE, &(camera->getCameraMat()[0][0]));

    glPatchParameteri(GL_PATCH_VERTICES, 4);

    glUniform4f(glGetUniformLocation(shader->getProgramID(),"Color"), 1, 1, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_PATCHES, 0, 4);



}
