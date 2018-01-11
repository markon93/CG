#version 330
in vec3 vPosition;
in vec3 vNormal;

//////////////////////////////////////////
in vec2 texCoords;
//////////////////////////////////////////


out vec3 fN;
out vec3 fE;
out vec3 fL;

//////////////////////////////////////////
out vec2 f_texCoords;
//////////////////////////////////////////

uniform vec4 lightPosition;
uniform mat4 M, V, P;

void main(){

    fN = vec3(M*vec4(vNormal, 0.0));
    fE = vec3(M*vec4(vPosition, 1.0));
    fL = lightPosition.xyz;

    if(lightPosition.w != 0.0){
        fL = lightPosition.xyz - vPosition.xyz;
    }

//////////////////////////////////////////
    f_texCoords = texCoords;
//////////////////////////////////////////

    gl_Position = P*V*M*vec4(vPosition, 1.0);
}


