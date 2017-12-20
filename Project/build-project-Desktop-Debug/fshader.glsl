#version 330
in vec3 fN;
in vec3 fL;
in vec3 fE;

// Light properties
uniform vec3 ambientLightRGB;

vec4 I_l = vec4(0.4, 0.4, 0.2, 0.0);

// Matrial properties
uniform float k_a = 1.0, k_d = 1.0, k_s = 1.0;
float alpha = 1;

out vec4  color;

void main(){

    // Modified Phong lighting model
     vec3 r = 2*(fN*fL)*fN - fL;
     vec3 h = fL + fE;
     h = normalize(h);

     // Ambient light intensity
     vec4 L_a = vec4(ambientLightRGB, 0.0);
     vec4 I_a = L_a*k_a;

     vec4 L_d = vec4(0.5,0.5,0.5,0);

     // Diffuse light intensity
     vec4 I_diffuse = k_d*max(dot(fN,fL),0)*L_d;

     // Specular light intensity
     vec4 I_specular = I_l*k_s*(pow(dot(fN,h),alpha));

     // Total light intensity
     color = I_a;// + I_diffuse + I_specular;

     // Shininess
     color.a = alpha;
}
