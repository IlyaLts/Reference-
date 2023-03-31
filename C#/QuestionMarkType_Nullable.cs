/*
int? is shorthand for Nullable<int>. The two forms are interchangeable.
Nullable<T> is an operator that you can use with a value type T to make it accept null.
*/

using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        int x;
        int? y;
        
        x = 123;
        x = null; // error: Cannot convert null to 'int' because it is a non-nullable value type
        y = 321;
        y = null;
        
        Console.WriteLine ("Hello Mono World");
    }
}

/*
In your example, the point is that if a is null, then a?.PropertyOfA will evaluate to null rather
than throwing an exception - it will then compare that null reference with foo (using string's == overload),
find they're not equal and execution will go into the body of the if statement.

In other words, it's like this:

string bar = (a == null ? null : a.PropertyOfA);
if (bar != foo)
{
    ...
}
*/
using System;

public class Obj
{
    public int value;
}

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Obj obj = new Obj();
        obj.value = 789;
        Console.WriteLine ("value: " + obj?.value);
        obj = null;
        Console.WriteLine ("value: " + obj?.value);
    }
}

/*
OUTPUT:

value: 789
value: 
*/
