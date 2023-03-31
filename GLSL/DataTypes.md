## Scalars

```
bool        // conditional type, values may be either true or false
int         // a signed, two's complement, 32-bit integer
uint        // an unsigned 32-bit integer
float       // an IEEE-754 single-precision floating point number
double      // an IEEE-754 double-precision floating-point number
```

## Vectors
Each of the scalar types, including booleans, have 2, 3, and 4-component vector equivalents. The n digit below can be 2, 3, or 4:

```
bvecn   // a vector of booleans
ivecn   // a vector of signed integers
uvecn   // a vector of unsigned integers
vecn    // a vector of single-precision floating-point numbers
dvecn   // a vector of double-precision floating-point numbers
```

## Swizzling

xyzw, rgba (for colors), or stpq (for texture coordinates)

```
vec2 someVec;
vec4 otherVec = someVec.xyxx;
vec3 thirdVec = otherVec.zyy;
```
```
vec4 someVec;
someVec.wzyx = vec4(1.0, 2.0, 3.0, 4.0); // Reverses the order.
someVec.zx = vec2(3.0, 5.0); // Sets the 3rd component of someVec to 3.0 and the 1st component to 5.0
```
```
float aFloat;
vec4 someVec = aFloat.xxxx;
```

## Matrices
**matnxm**: A matrix with n columns and m rows (examples: mat2x2, mat4x3). Note that this is backward from convention in mathematics!  
**matn**: Common shorthand for matnxn: a square matrix with n columns and n rows.
```
mat3 theMatrix;
theMatrix[1] = vec3(3.0, 3.0, 3.0); // Sets the second column to all 3.0s
theMatrix[2][0] = 16.0; // Sets the first entry of the third column to 16.0.
```
```
mat3 theMatrix;
theMatrix[1].yzx = vec3(3.0, 1.0, 2.0);
```

## Structs
```
struct Light
{
  vec3 eyePosOrDir;
  bool isDirectional;
  vec3 intensity;
  float attenuation;
} variableName;
```

## Matrix constructors
If a matrix is constructed with a single scalar value, then that value is used to initialize all the values along the diagonal of the matrix; the rest are given zeros. Therefore, mat4(1.0) is a 4x4 identity matrix.

For multiple values, matrices are filled in in column-major order. That is, the first X values are the first column, the second X values are the next column, and so forth. Examples:

```
mat2(
  float, float,   // first column
  float, float);  // second column

mat4(
  vec4,           // first column
  vec4,           // second column
  vec4,           // third column
  vec4);          // fourth column

mat3(
  vec2, float,    // first column
  vec2, float,    // second column
  vec2, float);   // third column
```
```
 mat3 diagMatrix = mat3(5.0);  // Diagonal matrix with 5.0 on the diagonal.
 mat4 otherMatrix = mat4(diagMatrix);
```

## Array constructors
```
const float array[3] = float[3](2.5, 7.0, 1.5);
```

## Struct constructors
```
struct Data
{
  float first;
  vec2 second;
};

Data dataValue = Data(1.4, vec2(16.0, 22.5));
```
Notice the vector constructor in the middle of the struct constructor. Constructors can be nested. So if you have an array of structs of the above type, you can construct it as follows:
```
Data dataArray[3] = Data[3](
  Data(1.0, vec2(-19.0, 4.5)),
  Data(-3.0, vec2(2.718, 2.0)),
  Data(29.5, vec2(3.142, 3.333)));
```
## Initializer lists
```
Data dataArray[3] = Data[3](
  Data(1.0, vec2(-19.0, 4.5)),
  Data(-3.0, vec2(2.718, 2.0)),
  Data(29.5, vec2(3.142, 3.333)));
```
```
Data dataArray[3] = {
  {1.0, {-19.0, 4.5} },
  {-3.0, {2.718, 2.0} },
  {29.5, {3.142, 3.333} } };
```