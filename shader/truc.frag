#version 150 core


// Entr<E9>e

in vec2 coordTexture;


// Uniform

uniform sampler2D la_texture;


// Sortie

out vec4 out_Color;


// Fonction main

void main()
{
    // Couleur du pixel

    out_Color = texture(la_texture, coordTexture);
}