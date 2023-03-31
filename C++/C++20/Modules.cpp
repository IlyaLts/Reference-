/*
===================================
module.cpp
===================================
*/

// dots in module name are for readability purpose, they have no special meaning
export module my.tool;  // module declaration

// f() will be visible by translations units importing 'my.tool'
export void f(){}

// g() will NOT be visible.
void g(){}

// Both one() and zero() will be visible.
export
{
    int one()  { return 1; }
    int zero() { return 0; }
}

// Exporting namespaces also works: hi::english() and hi::french() will be visible.
export namespace hi
{
    char const* english() { return "Hi!"; }
    char const* french()  { return "Salut!"; }
}

/*
===================================
client.cpp
===================================
*/
import my.tool;

f();    // OK
g();    // error, not exported
