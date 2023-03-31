/*
===================================
A.cpp
===================================
*/
export module A;		// primary module interface unit
 
export import :B;		// Hello() is visible when importing 'A'.
import :C;				// WorldImpl() is now visible only for 'A.cpp'.
// export import :C;	// ERROR: Cannot export a module implementation unit.
 
// World() is visible by any translation unit importing 'A'.
export char const* World()
{
    return WorldImpl();
}

/*
===================================
A-B.cpp 
===================================
*/
export module A:B; 	// partition module interface unit
 
// Hello() is visible by any translation unit importing 'A'.
export char const* Hello() { return "Hello"; }

/*
===================================
A-C.cpp 
===================================
*/
module A:C;			// partition module implementation unit
 
// WorldImpl() is visible by any module unit of 'A' importing ':C'.
char const* WorldImpl() { return "World"; }

/*
===================================
main.cpp 
===================================
*/
import A;
import <iostream>;
 
int main()
{
    std::cout << Hello() << ' ' << World() << '\n';
    // WorldImpl(); // ERROR: WorldImpl() is not visible.
}