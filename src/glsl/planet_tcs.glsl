#version 430 core

layout (vertices = 3) out;

in vec3 vPos[];
out vec3 tcPos[];
uniform mat4 MVP;

#define ID gl_InvocationID

void main()
{
    tcPos[ID] = vPos[ID];

    gl_TessLevelInner[0] = 1;

    gl_TessLevelOuter[0] = 1;
    gl_TessLevelOuter[1] = 1;
    gl_TessLevelOuter[2] = 1;

}

