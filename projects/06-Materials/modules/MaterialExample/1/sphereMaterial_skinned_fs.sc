$input v_normal, v_tangent, v_bitangent, v_texcoord0 
#include <torque6.sc>
uniform vec4 sphereMetalVal;
uniform vec4 sphereRoughVal;
void main()
{
    // Base Color
    gl_FragData[0] = encodeRGBE8(vec3(1.0, 1.0, 1.0) + vec3(0.0, 0.0, 0.0) + vec3(0.00001, 0.00001, 0.00001));

    // Normals
    gl_FragData[1] = vec4(encodeNormalUint(v_normal), 1.0);

    // Material Info
    gl_FragData[2] = vec4(sphereMetalVal.x, sphereRoughVal.x, 0.5, 0.0);
}
