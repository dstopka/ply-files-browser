#version 330 

layout (location = 0) in vec3 aPos;
layout (location = 1) in float max;

uniform mat4 MVP;

out vec2 outcol;

void main()
{
   outcol = vec2(max, aPos.z);
   gl_Position = MVP*vec4(aPos.x, aPos.y, aPos.z, 1.0);
}