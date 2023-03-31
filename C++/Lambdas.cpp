/*
=================================================
[] - captures nothing.
[=] - capture local objects (local variables, parameters) in scope by value.
[&] - capture local objects (local variables, parameters) in scope by reference.
[this] - capture this by reference.
[*this] - capture this by value.
[a, &b] - capture objects a by value, b by reference.
=================================================
*/
int x = 1;

auto getX = [=] { return x; };
getX(); // == 1

auto addX = [=](int y) { return x + y; };
addX(1); // == 2

auto getXRef = [&]() -> int& { return x; };
getXRef(); // int& to `x`

/*
=================================================
By default, value-captures cannot be modified inside the lambda because the compiler-generated method is marked as const.
The mutable keyword allows modifying captured variables. The keyword is placed after the parameter-list (which must be present even if it is empty).
=================================================
*/
int x = 1;

auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
// vs.
auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value
