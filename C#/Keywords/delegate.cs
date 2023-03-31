using System;

public delegate int AnotherDelegate(int number);

public class HelloWorld
{
    public static int print(int number) { Console.WriteLine("print() " + number); return 0; }
    public static int print2(int number) { Console.WriteLine("print2() " + number); return 0; }
    
    public static void Main(string[] args)
    {
        AnotherDelegate test = print;
        test(123);
        
        test += print2;
        test(43);
    }
}

/*
OUTPUT:

print() 123
print() 43
print2() is 43
*/