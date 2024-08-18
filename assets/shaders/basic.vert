#version 460

layout (location = 0) in vec3 aPos;

out vec2 texCoords;

void main() {
  gl_Position = vec4(aPos, 1.0);
}