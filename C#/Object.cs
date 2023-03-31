/*
=================================================================================================================
This is the ultimate base class of all .NET classes; it is the root of the type hierarchy.

============
Constructors
============
Object()	
Initializes a new instance of the Object class.

========
Methods
========
Equals(Object)	
Determines whether the specified object is equal to the current object.

Equals(Object, Object)	
Determines whether the specified object instances are considered equal.

Finalize()	
Allows an object to try to free resources and perform other cleanup operations before it is reclaimed by garbage collection.

GetHashCode()	
Serves as the default hash function.

GetType()	
Gets the Type of the current instance.

MemberwiseClone()	
Creates a shallow copy of the current Object.

ReferenceEquals(Object, Object)	
Determines whether the specified Object instances are the same instance.

ToString()	
Returns a string that represents the current object.
=================================================================================================================
*/

using System;

// The Point class is derived from System.Object.
class Point
{
    public int x, y;

    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public override bool Equals(object obj)
    {
        // If this and obj do not refer to the same type, then they are not equal.
        if (obj.GetType() != this.GetType()) return false;

        // Return true if  x and y fields match.
        var other = (Point) obj;
        return (this.x == other.x) && (this.y == other.y);
    }

    // Return the XOR of the x and y fields.
    public override int GetHashCode()
    {
        return x ^ y;
    }

    // Return the point's value as a string.
    public override String ToString()
    {
        return $"({x}, {y})";
    }

    // Return a copy of this point object by making a simple field copy.
    public Point Copy()
    {
        return (Point) this.MemberwiseClone();
    }
}

public sealed class App
{
    static void Main()
    {
        // Construct a Point object.
        var p1 = new Point(1,2);

        // Make another Point object that is a copy of the first.
        var p2 = p1.Copy();

        // Make another variable that references the first Point object.
        var p3 = p1;

        // The line below displays false because p1 and p2 refer to two different objects.
        Console.WriteLine(Object.ReferenceEquals(p1, p2));

        // The line below displays true because p1 and p2 refer to two different objects that have the same value.
        Console.WriteLine(Object.Equals(p1, p2));

        // The line below displays true because p1 and p3 refer to one object.
        Console.WriteLine(Object.ReferenceEquals(p1, p3));

        // The line below displays: p1's value is: (1, 2)
        Console.WriteLine($"p1's value is: {p1.ToString()}");
    }
}

// This code example produces the following output:
//
// False
// True
// True
// p1's value is: (1, 2)
//