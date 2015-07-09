$input a_position, a_normal, a_tangent, a_bitangent, a_texcoord0, a_indices, a_weight 
$output v_normal, v_tangent, v_bitangent, v_texcoord0 
#include <torque6.sc>
void main()
{    // Vertex Position
    vec4 vertPosition = vec4(a_position, 1.0);
    mat4 modelTransform = u_model[0];

    // Skinning
    modelTransform =    mul(u_model[int(a_indices[0])], a_weight[0]);
    modelTransform +=   mul(u_model[int(a_indices[1])], a_weight[1]);
    modelTransform +=   mul(u_model[int(a_indices[2])], a_weight[2]);
    modelTransform +=   mul(u_model[int(a_indices[3])], a_weight[3]); 
    vertPosition =      mul(modelTransform, vertPosition);

    // World Position Offset
    vertPosition += vec4(vec3(0.0, 0.0, 0.0), 0.0);

    // UV Coordinates
    v_texcoord0 = a_texcoord0;

    // Normal, Tangent, Bitangent
    v_normal = mul(modelTransform, vec4(a_normal.xyz, 0.0) ).xyz;
    v_tangent = mul(modelTransform, vec4(a_tangent.xyz, 0.0) ).xyz;
    v_bitangent = mul(modelTransform, vec4(a_bitangent.xyz, 0.0) ).xyz;

    // Output Final Vertex Position
    gl_Position = mul(u_modelViewProj, vertPosition);
}
