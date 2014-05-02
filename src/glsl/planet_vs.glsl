#version 430 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 Pos;
out vec3 vPos;


void main(){
    vPos = Pos;
}
