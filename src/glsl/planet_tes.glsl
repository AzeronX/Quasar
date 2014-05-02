#version 430 core

layout(quads, cw) in;

in vec3 tcPos[];
out vec3 tePos;

uniform mat4 MVP;

void main()
{
    float u = gl_TessCoord.x;
    float v = gl_TessCoord.y;

    vec3 a = mix(tcPos[0], tcPos[1], u);
    vec3 b = mix(tcPos[2], tcPos[3], u);
    tePos = normalize(mix(a, b, v));
    gl_Position = MVP * vec4(tePos,1);
}

