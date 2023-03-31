#include <iostream>

using namespace std;

struct A
{
  operator bool() const { return true; }
};

struct B
{
  explicit operator bool() const { return true; }
};


//========================================
// main function
//========================================
int main()
{
    A a;
    if (a);         // OK calls A::operator bool()
    bool ba = a;    // OK copy-initialization selects A::operator bool()
    
    B b;
    if (b);         // OK calls B::operator bool()
    bool bb = b;    // error copy-initialization does not consider B::operator bool()

    return 0;
}
