// Requires C++ 11

#include <cstdio>

template<class type> type variable = type(5);

using namespace std;

int main()
{
    printf("Before\n");
    printf("%d\n", variable<int>);
    printf("%f\n", variable<float>);

    variable<int> = 10;

    printf("After\n");
    printf("%d\n", variable<int>);
    printf("%f\n", variable<float>);
    
    return 0;
}

/*
Before
5
5.000000
After
10
5.000000
*/
