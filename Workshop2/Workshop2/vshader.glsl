#version 330

in vec3 vPosition;
in vec4 vNormal;

uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
out vec4 color;

void
main()
{
    gl_Position =  P*V*M*vec4(vPosition, 1.0);
    ambient =
    color = ambient + diffuse + specular;
}
