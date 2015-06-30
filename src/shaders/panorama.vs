uniform highp mat4 mvpm;
uniform highp mat4 texm;

attribute vec4 position;
attribute vec2 tex_coord;
varying highp vec2 oTexCoord;

void main()
{
   gl_Position = mvpm * position;
   oTexCoord = vec2( texm * vec4( tex_coord, 0, 1 ) );
}

		