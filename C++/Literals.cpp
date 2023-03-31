/*
=====================================
Integer literal
=====================================
*/
int d = 42;			// Decimal integer literal (base 10)
int o = 052;		// Octal integer literal (base 8)
int x = 0x2a;		// Hexadecimal integer literal
int X = 0X2A;		// Hexadecimal integer literal
int b = 0b101010; 	// Binary integer literal (C++14)

/*
=====================================
Floating-point literal
=====================================
*/
  std::cout 
    << "Literal       "   << "Printed value"
    << "\n58.           " << 58.          // double
    << "\n4e2           " << 4e2          // double
    << "\n123.456e-67   " << 123.456e-67  // double
    << "\n123.456e-67f  " << 123.456e-67f // float, truncated to zero
    << "\n.1E4f         " << .1E4f        // float
    << "\n0x10.1p0      " << 0x10.1p0     // double
    << "\n0x1p5         " << 0x1p5        // double
    << "\n0x1e5         " << 0x1e5        // integer literal, not floating-point
    << "\n3.14'15'92    " << 3.14'15'92   // double, single quotes ignored (C++14)
    << "\n1.18e-4932l   " << 1.18e-4932l  // long double
    << std::setprecision(39)
    << "\n3.4028234e38f " << 3.4028234e38f // float
    << "\n3.4028234e38  " << 3.4028234e38  // double
    << "\n3.4028234e38l " << 3.4028234e38l // long double
    << '\n';

/*
Literal       Printed value
58.           58
4e2           400
123.456e-67   1.23456e-65
123.456e-67f  0
.1E4f         1000
0x10.1p0      16.0625
0x1p5         32
0x1e5         485
3.14'15'92    3.14159
1.18e-4932l   1.18e-4932
3.4028234e38f 340282346638528859811704183484516925440
3.4028234e38  340282339999999992395853996843190976512
3.4028234e38l 340282339999999999995912555211526242304
*/

/*
=====================================
Character literals
=====================================
*/
char c1 = 'a';			// Ordinary character literals
char8_t C1 = u8'a';		// UTF-8 character literals
char16_t uc1 = u'a';	// UTF-16 character literals
char32_t Uc1 = U'a';	// UTF-32 character literals
wchar_t wc1 = L'a';		// Wide character literals

/*
=====================================
String literal
=====================================
*/
const char *s2 = "\nHello\n  World\n";								// Ordinary string literal
const char8_t *zxc = u8"TESTSETET";									// UTF-8 string literal
const char16_t *sA = u"MNOPQR";										// UTF-16 string literal
const char32_t *s7 = U"GHIJKL";										// UTF-32 string literal
const wchar_t *s4 = L"ABCDEF";										// Wide string literal
const wchar_t *raw = R"(<a href="file">C:\Program Files\</a>)"; 	// Raw string literal
