#pragma once

#include <opengl.h>

class ShaderProgram
{

public:

    ShaderProgram();
    ~ShaderProgram();

    virtual void setSource(GLenum type, std::string source) = 0;
    virtual bool load() = 0;
    virtual void unload() = 0;

    GLuint getProgramID();
    void bind();

protected:

    GLuint m_programID;

    bool compile(GLuint &shader, GLenum type, std::string source);
    bool link();
};

