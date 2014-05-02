#include <ComputeProgram.h>
#include <opengl.h>

ComputeProgram::ComputeProgram()
{
    m_computeID = 0;
    m_programID = 0;
}

ComputeProgram::ComputeProgram(std::string computeSource)
    : m_computeSource(computeSource)
{
    ComputeProgram();
}

ComputeProgram::~ComputeProgram()
{
    unload();
}

bool ComputeProgram::load()
{
    if(m_programID)
        unload();

    if(!m_computeSource.empty())
        if(!compile(m_computeID, GL_COMPUTE_SHADER, m_computeSource))
            return false;

    m_programID = glCreateProgram();

    if(!m_computeSource.empty())
        glAttachShader(m_programID, m_computeID);

    return link();
}

void ComputeProgram::unload()
{
    glDetachShader(m_programID, m_computeID);
    glDeleteShader(m_computeID);
    glDeleteProgram(m_programID);

    m_computeID = 0;
    m_programID = 0;
}

void ComputeProgram::setSource(GLenum type, std::string source)
{
    switch(type)
    {
    case GL_COMPUTE_SHADER:
        m_computeSource = source;
        break;
    default:
        break;
    }
}
