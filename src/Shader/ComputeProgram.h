#pragma once

#include <ShaderProgram.h>

class ComputeProgram : public ShaderProgram
{

public:

    ComputeProgram();
    ComputeProgram(std::string computeSource);
    ~ComputeProgram();

    virtual void setSource(GLenum type, std::string source);
    virtual bool load();
    virtual void unload();

private:

    GLuint m_computeID;

    std::string m_computeSource;
};

