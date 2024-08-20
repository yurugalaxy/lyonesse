#version 460

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColour;

uniform vec3 offsets[100];

out vec3 colour;

void main()
{
  vec3 offset = offsets[gl_InstanceID];
  gl_Position = vec4(aPos.x + offset.x, aPos.y + offset.y, 0.0, 1.0);
  colour = aColour;
}