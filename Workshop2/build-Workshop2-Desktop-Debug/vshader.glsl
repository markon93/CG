#version 330

in vec3 vPosition;

uniform mat4 P;
uniform mat4 V;
uniform mat4 T;

void
main()
{
    gl_Position =  P*V*T*vec4(vPosition, 1.0);
}
