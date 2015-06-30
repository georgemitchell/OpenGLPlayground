#extension GL_OES_EGL_image_external : require

uniform samplerExternalOES texture0;
uniform lowp vec4 uniform_color;
uniform lowp vec4 color_bias;
varying highp vec2 oTexCoord;
void main()
{
	gl_FragColor = color_bias + uniform_color * texture2D( texture0, oTexCoord );
}
