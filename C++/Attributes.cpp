#include <iostream>

using namespace std;

// In C++17 some of the rules regarding the use of “non-standard” attributes were relaxed
[[ gnu::always_inline, gnu::const, gnu::hot, nodiscard ]] int f();

/// Use of attribute namespaces without repetition
[[using gnu:const, always_inline]] int f() { return 0; }

// Ignoring unknown attributes
[[msvc::deprecated]][[gnu::deprecated]] char* gets(char* str) compilers

/*
========================================
[[expects]]

It specifies the conditions (in form of contract) that the arguments
must meet for a particular function to be executed.
========================================
*/
int f(int i)[[expects : i > 0]]
{
    // Code
}

/*
========================================
[[deprecated]] attribute
 
[[deprecated("Reason for deprecation")]]
========================================
*/
[[deprecated("Do not use it")]] void someFunction()
{
    int x;
}

// For Class/Struct/Union
struct [[deprecated]] S;

// For Functions
[[deprecated]] void f();

// For namespaces
namespace [[deprecated]] ns{}

// For variables (including static data members)
[[deprecated]] int x;

/*
========================================
[[fallthrough]] attribute
 
[[fallthrough]] indicates that a fallthrough in a switch statement is intentional.
Missing a break or return in a switch statement is usually considered a programmer’s error
but in some cases fallthrough can result in some very terse code and hence it is used.
Note: Unlike other attributes a fallthrough requires a semicolon after it is declared.
========================================
*/
void process_alert(Alert alert)
{
    switch (alert)
	{
		case Alert::Red:
			evacuate();
		// Compiler emits a warning here
		// thinking it is done by mistake
	  
		case Alert::Orange:
			trigger_alarm();
	  
			// this attribute needs semicolon
			[[fallthrough]];
			// Warning suppressed by [[fallthrough]]
	  
		case Alert::Yellow:
			record_alert();
			return;
	  
		case Alert::Green:
			return;
    }
}

/*
========================================
[[likely]] and [[unlikely]] attributes
 
For optimisation of certain statements that have more probability to execute than others.
Likely is now available in latest version of GCC compiler for experimentation purposes.
========================================
*/
int likely(int i)
{
    switch (i)
	{
		case 1:
			[[fallthrough]];
			[[likely]] case 2 : return 1;
			[[unlikely]] case 3: return 3;
    }
	
	int random = get_random_number_between_x_and_y(0, 3);
	if (random > 0) [[likely]]
	{
	  // body of if statement
	  // ...
	}

	while (unlikely_truthy_condition) [[unlikely]]
	{
	  // body of while statement
	  // ...
	}
	
    return 2;
}

/*
========================================
[[no_unique_address]]

Indicates that this data member need not have an address distinct from all other non-static data members of its class.
This means that if the class consist of an empty type then the compiler can perform empty base optimisation on it.
========================================
*/
struct Empty
{
};
  
struct X
{
    int i;
    Empty e;
};
  
struct Y
{
    int i;
    [[no_unique_address]] Empty e;
};

/*
========================================
[[nodiscard]]

The entities declared with nodiscard should not have their return values ignored by the caller.
Simply saying if a function returns a value and is marked nodiscard then the return value must be utilized by the caller and not discarded.
========================================
*/
// Return value must be utilized by the caller
[[nodiscard]] int nodiscard()
{
    return 0;
}
  
class[[nodiscard]] my_class{};
  
// Automatically becomes nodiscard marked
my_class fun()
{
    return my_class();
}

/*
========================================
[[noreturn]] void function
========================================
*/
[[noreturn]] void f()
{
    // Some code that does not return back the control to the caller
    // In this case the function returns back to the caller without a value
    // This is the reason why the warning "noreturn' function does return' arises
	
	// warning: ‘noreturn’ function does return
}
  
void g()
{
	f();
	// unreachable
    std::cout << "Code is intented to reach here";
}

/*
========================================
[[maybe_unused]] attribute

Does not emit any warnings or error on unused variables
========================================
*/
void func()
{
	[[maybe_unused]] char text = "Hello, World!";
}

/*
========================================
main
========================================
*/
int main()
{
    // Compiler does not emit any warnings or error on this unused variable
    [[maybe_unused]] char mg_brk = 'D';

//==============================================

    void someFunction(); // warning as the function is deprecated

//==============================================

    // the size of any object of
    // empty class type is at least 1
    static_assert(sizeof(Empty) >= 1);
  
    // at least one more byte is needed
    // to give e a unique address
    static_assert(sizeof(X) >= sizeof(int) + 1);
  
    // empty base optimization applied
    static_assert(sizeof(Y) == sizeof(int));

//==============================================

    int x{ 1 };
  
    // No error as value is utilised
     x = nodiscard();
  
    // Error : Value is not utilised
    //nodiscard();

    // Value not utilised error
    // fun();

//==============================================

    f(); // this function does not return
    g(); // and this function will not be called

    return 0;
}
