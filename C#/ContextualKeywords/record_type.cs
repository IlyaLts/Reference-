/*
Records add another way to define types. You use class definitions to create object-oriented hierarchies that focus on
the responsibilities and behavior of objects. You create struct types for data structures that store data and are small enough
to copy efficiently. You create record types when you want value-based equality and comparison, don't want to copy values,
and want to use reference variables. You create record struct types when you want the features of records for a type that
is small enough to copy efficiently.
*/
using System;

public record Foo(string Bar)
{
    public double MutableProperty { get; set; } = 10.0;
}

public class HelloWorld
{
    
    public static void Main(string[] args)
    {
        var test = new Foo("a");
        Console.WriteLine(test.MutableProperty);
        test.MutableProperty = 15;
        Console.WriteLine(test.MutableProperty);
        //test.Bar = "new string"; // will not compile
    }
}
