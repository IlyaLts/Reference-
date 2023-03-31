#include <iostream>

using namespace std;

class Object
{
public:

    Object(){}
    Object(const Object &other) : x(other.x){}

    // Prefix
    const Object &operator ++() { cout << "++obj;" << endl; x++; return *this; };
    // Postfix
    Object operator ++(int) { cout << "obj++;" << endl; Object a(*this); x++; return a; };

    int x = 0;
};

int main()
{
    Object obj;
    cout << "X = " << obj.x << endl;
    obj++;
    cout << "X++ = " << obj.x << endl;
    ++obj;
    cout << "++X = " << obj.x << endl;

    
    return 0;
}
