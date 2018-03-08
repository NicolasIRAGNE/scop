#version 410 core

in vec3         in_Position;
out vec3        coordTexture;
uniform mat4 projection;
uniform mat4 modelview;
uniform mat4 translate;
uniform mat4 look;

void main()
{
    gl_Position = projection * look * translate * modelview * vec4(in_Position, 1.0);
    coordTexture = in_Position;
}