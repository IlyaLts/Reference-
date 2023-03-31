#include <iostream>

using namespace std;

int f()
{
	return 123;
}
// or
auto f() -> int
{
	return 123;
}

// lambda
auto g = []() -> int
{
	return 123;
};

// NOTE: This does not compile!
template <typename T, typename U> decltype(a + b) add(T a, U b)
{
    return a + b;
}
// But trailing return types allows this:
template <typename T, typename U> auto add(T a, U b) -> decltype(a + b)
{
    return a + b;
}

// decltype(auto) can be used since C++ 14
template <typename T, typename U> auto add(T a, U b) -> decltype(auto)
{
    return a + b;
}
