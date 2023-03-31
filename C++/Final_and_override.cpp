/*
=============================
override
=============================
*/
struct A
{
	virtual void foo();
	void bar();
};

struct B : A
{
	void foo() override; 	// correct -- B::foo overrides A::foo
	void bar() override; 	// error -- A::bar is not virtual
	void baz() override; 	// error -- B::baz does not override A::baz
};

/*
=============================
Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.
=============================
*/
struct A
{
	virtual void foo();
};

struct B : A
{
	virtual void foo() final;
};

struct C : B
{
	virtual void foo(); // error -- declaration of 'foo' overrides a 'final' function
};

// Class cannot be inherited from.
struct A final {};
struct B : A {}; // error -- base 'A' is marked 'final'
