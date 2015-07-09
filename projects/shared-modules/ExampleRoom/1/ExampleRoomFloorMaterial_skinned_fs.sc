$input v_normal, v_tangent, v_bitangent, v_texcoord0 
#include <torque6.sc>
SAMPLER2D(Texture0, 0);
void main()
{    // Texture Node
    vec4 Texture0Sample = toLinear(texture2D(Texture0, v_texcoord0));


    // Base Color
    gl_FragData[0] = encodeRGBE8(Texture0Sample.rgb + vec3(0.0, 0.0, 0.0) + vec3(0.00001, 0.00001, 0.00001));

    // Normals
    gl_FragData[1] = vec4(encodeNormalUint(v_normal), 1.0);

    // Material Info
    gl_FragData[2] = vec4(0.000000, 0.482353, 0.5, 0.0);
}
