#version 330

in vec3 InterpolatedColor;
uniform vec2 resolution;

out vec4 FragColor;

void main()
{

	vec2 pixelPositionInWindow = gl_FragCoord.xy*400;
	
	if((pixelPositionInWindow.x < 120000 && pixelPositionInWindow.x > 40000)  && (pixelPositionInWindow.y > 40000 && pixelPositionInWindow.y < 120000) ){
		discard;
	}
	FragColor = vec4(InterpolatedColor, 1.0f);
}
