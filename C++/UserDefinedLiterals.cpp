// C++ code to demonstrate working of
// user defined literals (UDLs)

#include <iomanip>
#include <iostream>

using namespace std;
 
/*
=============================
User defined literals
=============================
*/
 
// Kilogram
long double operator"" _kg(long double x) { return x * 1000; }

// Gram
long double operator"" _g(long double x) { return x; }
 
// Miligram
long double operator"" _mg(long double x) { return x / 1000; }

int main()
{
    long double weight = 3.6_kg;
	
    cout << weight << endl;
    cout << setprecision(8) << (weight + 2.3_mg) << endl;
    cout << (32.3_kg / 2.0_g) << endl;
    cout << (32.3_mg * 2.0_g) << endl;
	
    return 0;
}

/*
Returns:

3600
3600.0023
16150
0.0646
*/

/*
Only the following parameter lists are allowed on literal operators:

( const char * )
( unsigned long long int )
( long double )
( char )
( wchar_t )
( char8_t ) (since C++20)
( char16_t )
( char32_t )
( const char * , std::size_t )
( const wchar_t * , std::size_t )
( const char8_t * , std::size_t ) (since C++20)
( const char16_t * , std::size_t )
( const char32_t * , std::size_t )
*/
