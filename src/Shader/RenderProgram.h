#pragma once

#include <ShaderProgram.h>

class RenderProgram : public ShaderProgram
{

public:

    RenderProgram();
    RenderProgram(std::string vextexSource, std::string fragmentSource, std::string tessControlSource = "", std::string tessEvalSource = "", std::string geometrySource = "");
    ~RenderProgram();

    virtual void setSource(GLenum type, std::string source);
    virtual bool load();
    virtual void unload();

private:

    GLuint m_vertexID;
    GLuint m_fragmentID;
    GLuint m_geometryID;
    GLuint m_tessControlID;
    GLuint m_tessEvalID;

    std::string m_vertexSource;
    std::string m_fragmentSource;
    std::string m_geometrySource;
    std::string m_tessControlSource;
    std::string m_tessEvalSource;
};


