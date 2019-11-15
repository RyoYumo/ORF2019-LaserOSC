#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;
out vec4 vPos;

void main(){
    vPos = position;
    gl_Position = modelViewProjectionMatrix * position;
}
