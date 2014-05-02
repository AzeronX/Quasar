#version 430 core

layout (vertices = 4) out;

in vec3 vPos[];
out vec3 tcPos[];
uniform mat4 MVP;

#define ID gl_InvocationID

void main()
{
    tcPos[ID] = vPos[ID];

    gl_TessLevelInner[0] = 10;
    gl_TessLevelInner[1] = 10;

    gl_TessLevelOuter[0] = 10;
    gl_TessLevelOuter[1] = 10;
    gl_TessLevelOuter[2] = 10;
    gl_TessLevelOuter[3] = 10;

}

