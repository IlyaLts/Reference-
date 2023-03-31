### Program separation linkage

For example, given a vertex shader that provides these outputs:
```
layout(location = 0) out vec4 color;
layout(location = 1) out vec2 texCoord;
layout(location = 2) out vec3 normal;
```

This allows the consuming shader to use different names and even types:
```
layout(location = 0) in vec4 diffuseAlbedo;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 cameraSpaceNormal;
```

### Location sizes

Scalars and vector types that are not doubles all take up one location. The double and dvec2 types also take one location, while dvec3 and dvec4 take up 2 locations. Structs take up locations based on their member types, in-order. Arrays also take up locations based on their array sizes.
```
struct OutData
{
  vec3 data1;
  dvec4 data2;
  float val[3];
};

layout(location = 0) out vec3 vals[4];    // Consumes 4 locations
layout(location = 4) out OutData myOut;   // Consumes 6 locations. dvec4 uses 2, and `val[3]` uses 3 total
layout(location = 10) out vec2 texCoord;  // Consumes 1 location
```

### Block member locations

The block as a whole can have a location qualifier. This will allocate a sequential sets of locations, giving the first member the given location and incrementing from there. The size of the individual members is computed the same way as above.

A particular member of a block can have a location qualifier. However, this only works if the block itself is qualified or if all members of the block have a qualifier.

If the block has a qualifier, then a member's qualifier overrides the block computed qualifier. It also resets the block's computed qualifier, so that subsequent unqualified members will be computed relative to the most recent explicit qualifier. Here is an example:
```
layout(location = 0) out Block
{
  vec2 first;                        // Location 0.
  dvec4 second[3];                   // Location 1.
  vec4 third;                        // Location 7; dvec4 takes 2 each, and the prior one has 3 array members.
  layout(location = 10) vec2 fourth; // Location 10.
  dvec4 fifth;                       // Location 11. Starts from the most recent explicit location.
  layout(location = 8) dvec3 sixth;  // Location 8.
  vec3 seventh;                      // Location 10, overlaps with `fourth`, so causes an error.
};
```

### Interface components

```
layout(location = 0) out vec2 arr1[5];
layout(location = 0, component = 2) out vec2 arr2[4]; //Different sizes are fine.
layout(location = 4, component = 2) out float val;    //A non-array takes the last two fields from location 4.
```

### Binding points

```
layout(binding = 3) uniform sampler2D mainTexture;
layout(binding = 1, std140) uniform MainBlock
{
  vec3 data;
};
```
