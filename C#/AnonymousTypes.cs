// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        var v = new { amount = 108, message = "Hello" };
        var b = new { name = "John", lastname = "Williams" };

        Console.WriteLine (v.amount + v.message);
        Console.WriteLine (b.name + " " + b.lastname);
        
        var product = new object();
        var bonus = new { note = "You won!" };
        var shipment = new { address = "Nowhere St.", product };
        var shipmentWithBonus = new { address = "Somewhere St.", product, bonus };
        
        // Array
        var anonArray = new[] { new { name = "apple", diam = 4 }, new { name = "grape", diam = 1 }};
        
        // With
        var apple = new { Item = "apples", Price = 1.35 };
        var onSale = apple with { Price = 0.79 };
        Console.WriteLine(apple);
        Console.WriteLine(onSale);
        
        var a = new { Title = "Hello", Age = 24 };

        Console.WriteLine(a.ToString()); // "{ Title = Hello, Age = 24 }"
    }
}

/*
output:

108Hello
John Williams
{ Item = apples, Price = 1.35 }
{ Item = apples, Price = 0.79 }
{ Title = Hello, Age = 24 }
*/