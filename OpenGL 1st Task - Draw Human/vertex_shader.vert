#version 330 core
layout (location = 0) in vec4 pos;			
layout (location = 1) in vec4 incolor;

out vec4 finalColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	gl_Position = projection * view * model * pos;
	finalColor = incolor;
}