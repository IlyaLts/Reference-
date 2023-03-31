/*
Non-destructive mutation provides a way to change immutable properties and fields of a record type.
This is achieved by using the with expression, which creates a copy of the record type and replaces
the existing values with the specified values in the copy.
*/

// Example
using System;
					
public class Program
{
	
	public record Student(string FirstName, string LastName)
	{
    public int Marks { get; init; }
	}
	public static void Main()
	{
		// create an object
		Student student1 = new("Sam", "Johnson") { Marks = 100 };
		// display object
		Console.WriteLine(student1);
		
		// create a copy of the object
		Student student2 = student1 with { FirstName = "Mark" };
		Console.WriteLine(student2);

		// change a non positional property
		student2 = student1 with { Marks = 50 };
		Console.WriteLine(student2);

		// display the two objects are different
		Console.WriteLine(student1 == student2); 
		
		// create a copy with identical fields
		student2 = student1 with { };
		Console.WriteLine(student1 == student2); 
	}
}

/*
Output
Student { FirstName = Sam, LastName = Johnson, Marks = 100 }
Student { FirstName = Mark, LastName = Johnson, Marks = 100 }
Student { FirstName = Sam, LastName = Johnson, Marks = 50 }
False
True
*/
