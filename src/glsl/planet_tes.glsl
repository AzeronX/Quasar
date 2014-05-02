#version 430 core

layout(triangles, equal_spacing, cw) in;

in vec3 tcPos[];
out vec3 tePos;

uniform mat4 MVP;

void main()
{
    vec3 p0 = gl_TessCoord.x * tcPos[0];
    vec3 p1 = gl_TessCoord.y * tcPos[1];
    vec3 p2 = gl_TessCoord.z * tcPos[2];
    tePos = normalize(p0 + p1 + p2);
    gl_Position = MVP * vec4(tePos, 1);
}
