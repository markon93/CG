#version 330

in vec2 vPosition;
uniform mat4 M;
void
main()
{
    gl_Position =  M*vec4(vPosition, 0.0, 1.0);
}
