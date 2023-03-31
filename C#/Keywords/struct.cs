/*
struct can include constructors, constants, fields, methods, properties, indexers, operators, events & nested types.
struct cannot include a parameterless constructor or a destructor.
struct can implement interfaces, same as class.
struct cannot inherit another structure or class, and it cannot be the base of a class.
struct members cannot be specified as abstract, sealed, virtual, or protected.
*/

public struct Coords
{
    public Coords(double x, double y)
    {
        X = x;
        Y = y;
    }

    public double X { get; }
    public double Y { get; }

    public override string ToString() => $"({X}, {Y})";
}

/*
================
readonly struct
================
*/
public readonly struct Coords
{
    public Coords(double x, double y)
    {
        X = x;
        Y = y;
    }

    public double X { get; init; }
    public double Y { get; init; }

    public override string ToString() => $"({X}, {Y})";
}

/*
================
readonly instance members

Within a readonly instance member, you can't assign to structure's instance fields.
However, a readonly member can call a non-readonly member. In that case the compiler creates
a copy of the structure instance and calls the non-readonly member on that copy. As a result,
the original structure instance isn't modified.
================
*/
public readonly double Sum()
{
    return X + Y;
}

// or properties and indexers:
private int counter;
public int Counter
{
    readonly get => counter;
    set => counter = value;
}

/*
================
Nondestructive mutation

Beginning with C# 10, you can use the with expression to produce a copy of a structure-type instance
with the specified properties and fields modified. You use object initializer syntax to specify what
members to modify and their new values, as the following example shows:
================
*/
public readonly struct Coords
{
    public Coords(double x, double y)
    {
        X = x;
        Y = y;
    }

    public double X { get; init; }
    public double Y { get; init; }

    public override string ToString() => $"({X}, {Y})";
}

public static void Main()
{
    var p1 = new Coords(0, 0);
    Console.WriteLine(p1);  // output: (0, 0)

    var p2 = p1 with { X = 3 };
    Console.WriteLine(p2);  // output: (3, 0)

    var p3 = p1 with { X = 1, Y = 4 };
    Console.WriteLine(p3);  // output: (1, 4)
}

