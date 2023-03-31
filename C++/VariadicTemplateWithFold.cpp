#include <iostream>

using namespace std;

template <class... types> void Print(types... args)
{
    cout << "sizeof... = " << sizeof...(args) << endl;
    ((cout << args << endl), ...);      // (pack op, ...)
    (..., (cout << args << endl));      // (..., op pack)
}

template<class... types> int sum(types... args)
{
    return (args + ...);
    return (... + args);
}

template<class t, class... types> int sum2(t init, types... args)
{
    return (init + ... + args);     // (init op ... op pack)
    return (args + ... + init);     // (pack op ... op init)
}

int main()
{
    Print("string", 123, 150.5f);

    cout << endl << "Sum() = " << sum(3, 8, 12, 1) << endl;
    cout << endl << "Sum2() = " << sum2(1000, 8, 12, 1) << endl;

    return 0;
}

/*
sizeof... = 3
string
123
150.5
string
123
150.5

Sum() = 24

Sum2() = 1021
*/
