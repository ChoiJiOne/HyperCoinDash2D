#version 460 core

layout(location = 0) in vec2 inTexCoords;
layout(location = 1) in vec4 inColor;
layout(location = 2) flat in int inUnit;
layout(location = 3) in float inTransparent;

layout(location = 0) out vec4 outFragColor;

#define TEXTURE_UNIT_0 0
#define TEXTURE_UNIT_1 1
#define TEXTURE_UNIT_2 2
#define TEXTURE_UNIT_3 3
#define TEXTURE_UNIT_4 4
#define TEXTURE_UNIT_5 5
#define TEXTURE_UNIT_6 6
#define TEXTURE_UNIT_7 7
#define TEXTURE_UNIT_8 8
#define TEXTURE_UNIT_9 9

layout(binding = TEXTURE_UNIT_0) uniform sampler2D texture0;
layout(binding = TEXTURE_UNIT_1) uniform sampler2D texture1;
layout(binding = TEXTURE_UNIT_2) uniform sampler2D texture2;
layout(binding = TEXTURE_UNIT_3) uniform sampler2D texture3;
layout(binding = TEXTURE_UNIT_4) uniform sampler2D texture4;
layout(binding = TEXTURE_UNIT_5) uniform sampler2D texture5;
layout(binding = TEXTURE_UNIT_6) uniform sampler2D texture6;
layout(binding = TEXTURE_UNIT_7) uniform sampler2D texture7;
layout(binding = TEXTURE_UNIT_8) uniform sampler2D texture8;
layout(binding = TEXTURE_UNIT_9) uniform sampler2D texture9;

void main()
{
	vec3 fragColor = vec3(0.0f, 0.0f, 0.0f);
	float alpha = 0.0f;

	switch(inUnit)
	{
	case TEXTURE_UNIT_0:
		fragColor = texture(texture0, inTexCoords).rgb;
		alpha = texture(texture0, inTexCoords).a;
		break;
	case TEXTURE_UNIT_1:
		fragColor = texture(texture1, inTexCoords).rgb;
		alpha = texture(texture1, inTexCoords).a;
		break;

	case TEXTURE_UNIT_2:
		fragColor = texture(texture2, inTexCoords).rgb;
		alpha = texture(texture2, inTexCoords).a;
		break;

	case TEXTURE_UNIT_3:
		fragColor = texture(texture3, inTexCoords).rgb;
		alpha = texture(texture3, inTexCoords).a;
		break;

	case TEXTURE_UNIT_4:
		fragColor = texture(texture4, inTexCoords).rgb;
		alpha = texture(texture4, inTexCoords).a;
		break;

	case TEXTURE_UNIT_5:
		fragColor = texture(texture5, inTexCoords).rgb;
		alpha = texture(texture5, inTexCoords).a;
		break;

	case TEXTURE_UNIT_6:
		fragColor = texture(texture6, inTexCoords).rgb;
		alpha = texture(texture6, inTexCoords).a;
		break;

	case TEXTURE_UNIT_7:
		fragColor = texture(texture7, inTexCoords).rgb;
		alpha = texture(texture7, inTexCoords).a;
		break;

	case TEXTURE_UNIT_8:
		fragColor = texture(texture8, inTexCoords).rgb;
		alpha = texture(texture8, inTexCoords).a;
		break;

	case TEXTURE_UNIT_9:
		fragColor = texture(texture9, inTexCoords).rgb;
		alpha = texture(texture9, inTexCoords).a;
		break;
	}

	fragColor = mix(fragColor, inColor.rgb, inColor.a); /** Color Blending. */
	outFragColor = vec4(fragColor, alpha * inTransparent);
}