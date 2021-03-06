uniform mat4 uProjMatrix;
uniform mat4 uModelViewMatrix;
uniform mat4 uNormalMatrix;

attribute vec3 aPosition;
attribute vec3 aNormal;
attribute vec4 aTangent;

varying vec3 vNormal;
varying vec3 vPosition;
varying vec3 vTangent;

void main() 
{
  vNormal = vec3(uNormalMatrix * vec4(aNormal, 0.0));

  // send position (eye coordinates) to fragment shader
  vec4 tPosition = uModelViewMatrix * vec4(aPosition, 1.0);
  vPosition = vec3(tPosition);
  vTangent = normalize(vec3(uModelViewMatrix * vec4(vec3(aTangent), 0.0)));
  gl_Position = uProjMatrix * tPosition;
}