#version 330
in vec3 vPosition;

//////
in vec3 vNormal;

out vec3 fN;
out vec3 fE;
out vec3 fL;

uniform vec4 lightPosition = vec4(2.0, 0.5, 5.0, 0.0);
//////

uniform mat4 M, V, P;
void
main(){

    fN = vNormal;
    fE = vPosition.xyz;
    fL = lightPosition.xyz;

    if(lightPosition.w != 0.0){
        fL = lightPosition.xyz - vPosition.xyz;
    }

    gl_Position = P*V*M*vec4(vPosition, 1.0);

    ///////
   // vec4 r = 2*(vNormal*l)*vNormal - l;

//    vec4 h = l + v;
//    h = normalize(h);


//    vec4 I_ambient = I_a * k_a;
//    vec4 I_diffuse = I_l*k_d*dot(vNormal,l);
//    vec4 I_specular = I_l*k_s*(pow(dot(vNormal,h),alpha));

//    color = I_ambient + I_diffuse + I_specular;
//    color.a = alpha;

    ///////

}
