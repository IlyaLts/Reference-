/*
=================
	interface
=================
1 - Can inherit any number of interfaces																			
2 - Can contain properties, methods, events, and indexers. Also static fields, static constructors, and static destructors.

=================
	abstract
=================
1 - Can only niherit from a signle abstract class
2 - Can contain fields, properties, methods, constructors, destructors, events, indexers
*/

// A class may only inherit from a single abstract class, but a class may implement any number of interfaces.

/*
===========================================
	abstract
===========================================
*/
abstract class Shape
{
    public abstract int GetArea();
}

class Square : Shape
{
    private int _side;

    public Square(int n) => _side = n;

    // GetArea method is required to avoid a compile-time error.
    public override int GetArea() => _side * _side;

    static void Main()
    {
        var sq = new Square(12);
        Console.WriteLine($"Area of the square = {sq.GetArea()}");
    }
}
// Output: Area of the square = 144

/*
===========================================
	interface
===========================================
*/
interface ISampleInterface
{
    void SampleMethod();
}

class ImplementationClass : ISampleInterface
{
    // Explicit interface member implementation:
    void ISampleInterface.SampleMethod()
    {
        // Method implementation.
    }

    static void Main()
    {
        // Declare an interface instance.
        ISampleInterface obj = new ImplementationClass();

        // Call the member.
        obj.SampleMethod();
    }
}