#version 460

in vec3 colour;

out vec4 fragColour;

void main()
{
  fragColour = vec4(colour, 1.0);
}