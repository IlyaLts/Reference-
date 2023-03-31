/*
===================================
A.cpp (primary module interface unit of 'A')
===================================
*/
export module A;

// headers can also be imported with an import
import <string_view>;

// imported headers can be exported in a module interface unit.
// That is, if module A export-imports B, then importing A will also make visible all exports from B.
export import <iostream>;
 
export char const* hello() { return "hello"; }
 
/*
===================================
B.cpp (primary module interface unit of 'B')
===================================
*/
export module B;
 
// Import declarations can be exported in a module interface unit.
// That is, if module A export-imports B, then importing A will also make visible all exports from B.
export import A;
 
export char const* world() { return "world"; }
 
/*
===================================
main.cpp (not a module unit)
===================================
*/
#include <iostream>
import B;
 
int main()
{
    std::cout << hello() << ' ' << world() << '\n';
}
