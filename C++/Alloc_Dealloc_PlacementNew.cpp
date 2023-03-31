/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// Placement new operator
// new (address) (type) initializer

// new operator
// ::operator new(size)

// delete operator
// ::operator delete(address)

#include <new>

class Object
{
public:
    
    Object()                        { cout << "Object()\n"; }
    Object(const Object &other)     { cout << "Object(const Object &other)\n"; }
    ~Object()                       { cout << "~Object()\n"; }
};

int main()
{
    cout << "New/Delete expressions constructs and destructs objects.\n";
    Object *obj = new Object;                                                   // Allocates memory and construct Object
    delete obj;                                                                 // Calls destructor and deallocates memory
    
    cout << "\nNew/Delete operators allocates and deallocates memory.\n";
    Object *obj2 = static_cast<Object *>(::operator new(sizeof(Object)));       // Allocates memory only
    new (obj2) Object();                                                        // Construct by using placement new
    obj2->~Object();                                                            // Deconstruct (MANDATORY to call it manually)
    ::operator delete(obj2);                                                    // Deallocate memory

    cout << "\n";
    Object *obj3 = static_cast<Object *>(::operator new(sizeof(Object)));       // Allocates memory only
    new (obj3) Object(*obj2);                                                   // Construct using copy constructor
    ::operator delete(obj3);

    return 0;
}

/*
New/Delete expressions constructs and destructs objects.
Object()
~Object()

New/Delete operators allocates and deallocates memory.
Object()
~Object()

Object(const Object &other)
*/
