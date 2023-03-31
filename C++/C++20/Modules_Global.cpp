/*
===================================
A.cpp (primary module interface unit of 'A')
===================================
*/

// Global
module;
 
// Defining _POSIX_C_SOURCE adds functions to standard headers, according to the POSIX standard.
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
 
export module A;
 
import <ctime>;

export double weak_random()
{
    std::timespec ts;
    std::timespec_get(&ts, TIME_UTC); // from <ctime>
	
    // Provided in <stdlib.h> according to the POSIX standard.
    srand48(ts.tv_nsec);
	
    // drand48() returns a random number between 0 and 1.
    return drand48();
}

// Private fragment 
module :private; // ends the portion of the module interface unit that
                 // can affect the behavior of other translation units
                 // starts a private module fragment
 
int f()			// definition not reachable from importers of foo
{
    return 42;
}
 
/*
===================================
main.cpp (not a module unit)
===================================
*/
import <iostream>;
import A;
 
int main()
{
    std::cout << "Random value between 0 and 1: " << weak_random() << '\n';
}