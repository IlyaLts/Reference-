// Requires C++ 11

#include <iostream>

using namespace std;

// Base template
template <class t> void Print(t arg)
{
    cout << arg << endl;
}

// Recursive template
template <class t, class... types> void Print(t arg, types... args)
{
    cout << arg << " - " << sizeof...(args) << endl;
    Print(args...);
}

int main()
{
    Print("string", 123, 150.5f);

    return 0;
}

/*
string - 2
123 - 1
150.5
*/
