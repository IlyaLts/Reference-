/*
In C# 9 and later, the init keyword defines an accessor method in a property or indexer.
An init-only setter assigns a value to the property or the indexer element only during object construction.
This enforces immutability, so that once the object is initialized, it can't be changed again.
*/

// Example
class Person_InitExample
{
     private int _yearOfBirth;

     public int YearOfBirth
     {
         get { return _yearOfBirth; }
         init { _yearOfBirth = value; }
     }
}

// Usage
var john = new Person_InitExample
{
    YearOfBirth = 1984
};

john.YearOfBirth = 1926; //Not allowed, as its value can only be set once in the constructor

// The init accessor can be used as an expression-bodied member. Example:
class Person_InitExampleExpressionBodied
{
    private int _yearOfBirth;

    public int YearOfBirth
    {
        get => _yearOfBirth;
        init => _yearOfBirth = value;
    }
}

// The init accessor can also be used in auto-implemented properties as the following example code demonstrates:
class Person_InitExampleAutoProperty
{
    public int YearOfBirth { get; init; }
}
