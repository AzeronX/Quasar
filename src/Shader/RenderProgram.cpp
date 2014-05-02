#include <RenderProgram.h>
#include <opengl.h>

RenderProgram::RenderProgram()
{
    m_vertexID = 0;
    m_fragmentID = 0;
    m_geometryID = 0;
    m_tessControlID = 0;
    m_tessEvalID = 0;
    m_programID = 0;
}

RenderProgram::RenderProgram(std::string vertexSource, std::string fragmentSource, std::string tessControlSource, std::string tessEvalSource, std::string geometrySource)
    : m_vertexSource(vertexSource), m_fragmentSource(fragmentSource), m_geometrySource(geometrySource), m_tessControlSource(tessControlSource), m_tessEvalSource(tessEvalSource)
{
    RenderProgram();
}

RenderProgram::~RenderProgram()
{
    unload();
}

bool RenderProgram::load()
{
    if(m_programID)
        unload();

    if(m_vertexSource.empty() || m_fragmentSource.empty())
        return false;

    if(!compile(m_vertexID, GL_VERTEX_SHADER, m_vertexSource))
        return false;

    if(!compile(m_fragmentID, GL_FRAGMENT_SHADER, m_fragmentSource))
        return false;

    if(!m_geometrySource.empty())
        if(!compile(m_geometryID, GL_GEOMETRY_SHADER, m_geometrySource))
            return false;

    if(!m_tessControlSource.empty())
        if(!compile(m_tessControlID, GL_TESS_CONTROL_SHADER, m_tessControlSource))
            return false;

    if(!m_tessEvalSource.empty())
        if(!compile(m_tessEvalID, GL_TESS_EVALUATION_SHADER, m_tessEvalSource))
            return false;

    m_programID = glCreateProgram();

    glAttachShader(m_programID, m_vertexID);
    glAttachShader(m_programID, m_fragmentID);
    if(!m_geometrySource.empty())
        glAttachShader(m_programID, m_geometryID);
    if(!m_tessControlSource.empty())
        glAttachShader(m_programID, m_tessControlID);
    if(!m_tessEvalSource.empty())
        glAttachShader(m_programID, m_tessEvalID);

    return link();
}

void RenderProgram::unload()
{
    glDetachShader(m_programID, m_vertexID);
    glDetachShader(m_programID, m_fragmentID);
    glDetachShader(m_programID, m_geometryID);
    glDetachShader(m_programID, m_tessControlID);
    glDetachShader(m_programID, m_tessEvalID);
    glDeleteShader(m_vertexID);
    glDeleteShader(m_fragmentID);
    glDeleteShader(m_geometryID);
    glDeleteShader(m_tessControlID);
    glDeleteShader(m_tessEvalID);
    glDeleteProgram(m_programID);

    m_vertexID = 0;
    m_fragmentID = 0;
    m_geometryID = 0;
    m_tessControlID = 0;
    m_tessEvalID = 0;
    m_programID = 0;
}

void RenderProgram::setSource(GLenum type, std::string source)
{
    switch(type)
    {
    case GL_VERTEX_SHADER:
        m_vertexSource = source;
        break;
    case GL_FRAGMENT_SHADER:
        m_fragmentSource = source;
        break;
    case GL_GEOMETRY_SHADER:
        m_geometrySource = source;
        break;
    case GL_TESS_CONTROL_SHADER:
        m_tessControlSource = source;
        break;
    case GL_TESS_EVALUATION_SHADER:
        m_tessEvalSource = source;
        break;
    default:
        break;
    }
}
