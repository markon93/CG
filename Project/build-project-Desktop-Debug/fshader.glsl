#version 330
in vec3 fN;
in vec3 fL;
in vec3 fE;

in vec2 f_texCoords;

// Light properties
uniform vec3 ambientLightRGB;
uniform vec3 lightLuminance;

// Matrial properties
uniform vec4 k_a, k_d, k_s;
float alpha = 100;

uniform sampler2D tex;

out vec4  color;

void main(){

    // Modified Phong lighting model
    vec3 NN = normalize(fN);
    vec3 EE = normalize(fE);
    vec3 LL = normalize(fL);

    vec3 r = 2*(fN*fL)*fN - fL;
    vec3 h = normalize(LL + EE);

    // Ambient light intensity
    vec4 L_a = vec4(ambientLightRGB, 0.0);
    vec4 I_a = L_a*k_a;

    // Diffuse light intensity
    vec4 I_l = vec4(lightLuminance,0.0);
    vec4 I_diffuse = I_l*k_d*max(dot(NN,LL),0);

    // Specular light intensity
    vec4 I_specular = I_l*k_s*(pow(max(dot(NN,h),0),alpha));

    // Total light intensity
    color = I_a + I_diffuse + I_specular;

    // Shininess
    color.a = alpha;
}
