#include <ShaderProgram.h>
#include <fstream>

ShaderProgram::ShaderProgram()
{

}

ShaderProgram::~ShaderProgram()
{

}

bool ShaderProgram::link()
{
    if(!m_programID)
        return false;

    glLinkProgram(m_programID);

    GLint linkError = 0;
    glGetProgramiv(m_programID, GL_LINK_STATUS, &linkError);

    if(linkError != GL_TRUE)
    {
        GLint errorSize = 0;
        glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &errorSize);

        char *error = new char[errorSize + 1];

        glGetShaderInfoLog(m_programID, errorSize, &errorSize, error);
        error[errorSize] = '\0';

        std::cout << error << std::endl;

        delete[] error;
        glDeleteProgram(m_programID);
        m_programID = 0;

        return false;
    }

    return true;
}



bool ShaderProgram::compile(GLuint &shader, GLenum type, std::string source)
{

    // Create Shader
    shader = glCreateShader(type);
    if(!shader)
    {
        std::cout << "Error, shader type (" << type << ") does not exist" << std::endl;
        return false;
    }


    // Open filestream
    std::ifstream file(source.c_str());
    if(!file)
    {
        std::cout << "Error " << source << " does not exist" << std::endl;
        glDeleteShader(shader);
        shader = 0;
        return false;
    }


    // Read source
    std::string line;
    std::string code;
    while(getline(file, line))
        code += line + '\n';
    file.close();



    // Compile Shader
    const char* codestr = code.c_str();
    glShaderSource(shader, 1, &codestr, 0);
    glCompileShader(shader);



    // Check compilation
    GLint error = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &error);
    if(error != GL_TRUE)
    {
        GLint errorSize = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorSize);

        char *errorStr = new char[errorSize + 1];

        glGetShaderInfoLog(shader, errorSize, &errorSize, errorStr);
        errorStr[errorSize] = '\0';

        std::cout << source << " : " <<errorStr << std::endl;

        delete[] errorStr;
        glDeleteShader(shader);
        shader = 0;

        return false;
    }

    return true;
}

GLuint ShaderProgram::getProgramID()
{
    return m_programID;
}

void ShaderProgram::bind()
{
    glUseProgram(m_programID);
}

