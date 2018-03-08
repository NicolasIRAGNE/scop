#version 410 core

in vec3             coordTexture;
out vec4            out_Color;
uniform samplerCube cubeMap;

void main()
{
    out_Color = texture(cubeMap, coordTexture);
}