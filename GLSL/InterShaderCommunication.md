## Name based matching


Vertex shader
```
out vec4 color;
```

Geometry shader
```
in vec4 color[];
out vec4 colorFromGeom;
```

Fragment shader
```
in vec4 colorFromGeom;
```

## Location based matching

Vertex shader
```
layout (location = 0) out vec3 normalOut;
layout (location = 1) out vec4 colorOut;
```

Geometry shader
```
layout (location = 0) in vec3 normalIn[];
layout (location = 1) in vec4 colorIn[];
 
layout (location = 0) out vec3 normalOut;
layout (location = 1) out vec4 colorOut;
```

Fragment shader
```
layout (location = 0) in vec3 normalIn;
layout (location = 1) in vec4 colorIn;
```

## Block based matching

Vertex shader
```
out Data {
    vec3 normal;
    vec3 eye;
    vec3 lightDir;
    vec2 texCoord;
} DataOut;
```

Fragment shader
```
in Data {
    vec3 normal;
    vec3 eye;
    vec3 lightDir;
    vec2 texCoord;
} DataIn;
```