// Version du GLSL

#version 150 core


// Entr<E9>es

in vec3 in_Vertex;
in vec2 in_TexCoord0;


// Uniform

uniform mat4 projection;
uniform mat4 modelview;
uniform mat4 look;


// Sortie

out vec2 coordTexture;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = projection * look * modelview * vec4(in_Vertex, 1.0);
    gl_Position.x /= gl_Position.w;
    gl_Position.y /= gl_Position.w;

    // Envoi des coordonn<E9>es de texture au Fragment Shader

    coordTexture = in_TexCoord0;
}