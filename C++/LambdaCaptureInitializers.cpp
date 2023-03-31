#include <iostream>

using namespace std;

/*
=======================================
Lambda capture initializers are static!
=======================================
*/

int factory(int i) { return i * 10; }
auto f = [x = factory(2)] { return x; }; // returns 20

// x is static
auto generator = [x = 0] () mutable
{
  // this would not compile without 'mutable' as we are modifying x on each call
  return x++;
};


int main()
{
    cout << generator() << endl; // == 0
    cout << generator() << endl; // == 1
    cout << generator() << endl; // == 2

    return 0;
}
