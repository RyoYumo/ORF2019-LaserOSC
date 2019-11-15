#version 150

in vec4 vPos;
uniform float u_radius;
uniform vec2  u_center;
uniform float u_opacity;
uniform vec4  globalColor; // ofSetColor()
out vec4 outputColor;

void main(){
    vec2 p = vPos.xy - u_center;
    float dist = length(p);
    float alpha = 0.0;
    if(dist < u_radius){
        alpha = 1.0;
    }
    outputColor = vec4(globalColor.rgb, globalColor.a * alpha * u_opacity);
}
