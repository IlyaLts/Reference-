## Vertex shader inputs
```
in int gl_VertexID;
in int gl_InstanceID;
in int gl_DrawID; // Requires GLSL 4.60 or ARB_shader_draw_parameters
in int gl_BaseVertex; // Requires GLSL 4.60 or ARB_shader_draw_parameters
in int gl_BaseInstance; // Requires GLSL 4.60 or ARB_shader_draw_parameters
```
### gl_VertexID
the index of the vertex currently being processed. When using non-indexed rendering, it is the effective index of the current vertex (the number of vertices processed + the first​ value). For indexed rendering, it is the index used to fetch this vertex from the buffer.  

**Note**: gl_VertexID will have the baseVertex​ parameter added to the index, if there was such a parameter in the rendering command.

### gl_InstanceID
the index of the current instance when doing some form of instanced rendering. The instance count always starts at 0, even when using base instance calls. When not using instanced rendering, this value will be 0.  

**Warning**: This value **does not** follow the baseInstance​ provided by some instanced rendering functions. gl_InstanceID always falls on the half-open range (0, instancecount​). If you have GLSL 4.60, you may use gl_BaseInstance to compute the proper instance index.

### gl_DrawID
the index of the drawing command within multi-draw rendering commands (including indirect multi-draw commands). The first draw command has an ID of 0, increasing by one as the renderer passes through drawing commands.
This value will always be a Dynamically Uniform Expression.

### gl_BaseVertex
the value of the baseVertex​ parameter of the rendering command. If the rendering command did not include that parameter, the value of this input will be 0.

### gl_BaseInstance
the value of the baseInstance​ parameter of the instanced rendering command. If the rendering command did not include this parameter, the value of this input will be 0.

## Vertex shader outputs
```
out gl_PerVertex
{
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
};
```
### gl_PerVertex
defines an interface block for outputs. The block is defined without an instance name, so that prefixing the names is not required.

These variables only take on the meanings below if this shader is the last active Vertex Processing stage, and if rasterization is still active (ie: GL_RASTERIZER_DISCARD is not enabled). The text below explains how the Vertex Post-Processing system uses the variables. These variables may not be redeclared with interpolation qualifiers.

### gl_Position
the clip-space output position of the current vertex.  

### gl_PointSize
the pixel width/height of the point being rasterized. It only has a meaning when rendering point primitives. It will be clamped to the GL_POINT_SIZE_RANGE.  

### gl_ClipDistance
allows the shader to set the distance from the vertex to each user-defined clipping half-space. A non-negative distance means that the vertex is inside/behind the clip plane, and a negative distance means it is outside/in front of the clip plane. Each element in the array is one clip plane. In order to use this variable, the user must manually redeclare it with an explicit size. With GLSL 4.10 or ARB_separate_shader_objects, the whole gl_PerVertex block needs to be redeclared. Otherwise just the gl_ClipDistance built-in needs to be redeclared.