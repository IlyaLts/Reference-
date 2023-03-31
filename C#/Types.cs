sbyte	-128 to 127													Signed 8-bit integer
byte	0 to 255													Unsigned 8-bit integer	System.Byte
short	-32,768 to 32,767											Signed 16-bit integer
ushort	0 to 65,535													Unsigned 16-bit integer
int		-2,147,483,648 to 2,147,483,647								Signed 32-bit integer
uint	0 to 4,294,967,295											Unsigned 32-bit integer
long	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807		Signed 64-bit integer
ulong	0 to 18,446,744,073,709,551,615								Unsigned 64-bit integer
nint	Depends on platform (computed at runtime)					Signed 32-bit or 64-bit integer
nuint	Depends on platform (computed at runtime)					Unsigned 32-bit or 64-bit integer

float	±1.5 x 10−45 to ±3.4 x 1038			~6-9 digits				4 bytes
double	±5.0 × 10−324 to ±1.7 × 10308		~15-17 digits			8 bytes
decimal	±1.0 x 10-28 to ±7.9228 x 1028		28-29 digits			16 bytes

// The char type keyword is an alias for the .NET System.Char structure type that represents a Unicode UTF-16 character.
char	U+0000 to U+FFFF											16 bit

// You can also use a cast to convert the value represented by an integer literal to the type other than the determined type of the literal:
var signedByte = (sbyte)42;
var longVariable = (long)42;