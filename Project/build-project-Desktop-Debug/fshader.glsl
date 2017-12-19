#version 330
in vec3 fN;
in vec3 fL;
in vec3 fE;

vec4 I_a = vec4(0.1, 0.1, 0.1, 0.0);
vec4 I_l = vec4(0.4, 0.4, 0.2, 0.0);
float k_a = 1.0, k_d = 1.0, k_s = 1.0;

out vec4  color;

float alpha = 1;

void main(){

     vec3 r = 2*(fN*fL)*fN - fL;

     vec3 h = fL + fE;
     h = normalize(h);


     vec4 I_ambient = I_a * k_a;
     vec4 I_diffuse = I_l*k_d*dot(fN,fL);
     vec4 I_specular = I_l*k_s*(pow(dot(fN,h),alpha));

     color = I_ambient + I_diffuse + I_specular;
     color.a = alpha;
}
