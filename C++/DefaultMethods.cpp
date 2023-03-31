#include <iostream>

using namespace std;

struct A
{
	A() = default;
	A(int x) : x{x} {}
	int x {1};
};

struct B
{
	B() : x{1} {}
	int x;
};

struct C : B
{
	// Calls B::B
	C() = default;
};

//========================================
// main function
//========================================
int main()
{
    A a;			// a.x == 1
    A a2 {123};		// a.x == 123
    C c;			// c.x == 1

    return 0;
}
