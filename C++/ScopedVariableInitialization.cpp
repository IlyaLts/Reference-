/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int asd;

class HelloWorld
{
public:
    
    static HelloWorld *Get() { return new HelloWorld; }
    void Print() { printf("Hello, world!\n"); }
};

int *get()
{
    int *q = &asd;
    return q;
}

int main()
{
    // Scoped variable initialization
    if (HelloWorld *p = HelloWorld::Get())
    {
        p->Print();
    }

    return 0;
}
