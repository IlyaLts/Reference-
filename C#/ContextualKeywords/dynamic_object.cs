/*
========================================================================================
Example #1
========================================================================================
*/
public static void ConsoleWrite(string inputArg)
{
    Console.WriteLine(inputArg);
}

// Object: the following code has compile error unless cast object to string:
public static void Main(string[] args)
{
    object obj = "String Sample";
    ConsoleWrite(obj);// compile error
    ConsoleWrite((string)obj); // correct
    Console.ReadKey();
}

// dynamic: the following code compiles successfully but if it contains a value except string it throws Runtime error
public static void Main(string[] args)
{
    dynamic dyn = "String Sample";
    ConsoleWrite(dyn); // correct
    dyn = 1;
    ConsoleWrite(dyn);// Runtime Error
    Console.ReadKey();
}

/*
========================================================================================
Example #2

========================================================================================
*/
// Dynamic: Casting is not required but you need to know the property
// and methods related to stored type to avoid error in run time.
dynamic dyn = 1;
Console.WriteLine(dyn);
int a = dyn;// works fine
Console.WriteLine(a);//print 1
Console.ReadKey();
The above code will work just fine but if dyn = 1.2 is supplied then it will throw exception as 1.2 cannot converted to int

// Object: Require to cast object variable explicitly.
object ob = 1;//or 1.2
Console.WriteLine(ob);
int a = ob;//Compile error because explicit casting is not done
Console.WriteLine(a);
Console.ReadKey();