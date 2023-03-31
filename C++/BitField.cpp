#include <iostream>
 
/*
=============================
basic
=============================
*/
 
struct S
{
    // three-bit unsigned field, allowed values are 0...7
    unsigned int b : 3;
};
 
 struct S2
{
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};
 
int a;
const int b = 0;
 
struct S3
{
    // simple cases
    int x1 : 8 = 42;              // OK; "= 42" is brace-or-equal-initializer
    int x2 : 8 { 42 };            // OK; "{ 42 }" is brace-or-equal-initializer
 
    // ambiguities
    int y1 : true ? 8 : a = 42;   // OK; brace-or-equal-initializer is absent
    int y2 : true ? 8 : b = 42;   // error: cannot assign to const int
    int y3 : (true ? 8 : b) = 42; // OK; "= 42" is brace-or-equal-initializer
    int z : 1 || new int { 0 };   // OK; brace-or-equal-initializer is absent
};

 
int main()
{
    S s = {6};
 
    ++s.b; // store the value 7 in the bit-field
    std::cout << s.b << '\n';
 
    ++s.b; // the value 8 does not fit in this bit-field
    std::cout << s.b << '\n'; // formally implementation-defined, typically 0
	
	std::cout << sizeof(S2) << '\n'; // usually prints 2
}

/*
returns:

7
0
2
*/
