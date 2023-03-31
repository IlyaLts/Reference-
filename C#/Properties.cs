/*
A property is a member that provides a flexible mechanism to read, write,
or compute the value of a private field. Properties can be used as if they're public data members,
but they're special methods called accessors. This feature enables data to be accessed easily
and still helps promote the safety and flexibility of methods.
*/
public class TimePeriod
{
    private double _seconds;

    public double Hours
    {
        get { return _seconds / 3600; }
        set
        {
            if (value < 0 || value > 24)
                throw new ArgumentOutOfRangeException(nameof(value),
                      "The valid range is between 0 and 24.");

            _seconds = value * 3600;
        }
    }
}

/*	Example	*/
TimePeriod t = new TimePeriod();
// The property assignment causes the 'set' accessor to be called.
t.Hours = 24;

// Retrieving the property causes the 'get' accessor to be called.
Console.WriteLine($"Time in hours: {t.Hours}");
// The example displays the following output:
//    Time in hours: 24

/*
===============================================================

	=>, value

===============================================================
*/
// Example 1
public class Person
{
    private string _firstName;
    private string _lastName;

    public Person(string first, string last)
    {
        _firstName = first;
        _lastName = last;
    }

    public string Name => $"{_firstName} {_lastName}";
}

// Example 2
public class SaleItem
{
    string _name;
    decimal _cost;

    public SaleItem(string name, decimal cost)
    {
        _name = name;
        _cost = cost;
    }

    public string Name
    {
        get => _name;
        set => _name = value;
    }

    public decimal Price
    {
        get => _cost;
        set => _cost = value;
    }
}

/*
===============================================================

	Auto-implemented properties

===============================================================
*/
public class SaleItem
{
    public string Name
    { get; set; }

    public decimal Price
    { get; set; }
}

// Access Modifiers
public int Foo {get; protected set;}

/*
===============================================================

	Required properties (C# 11)
	
	Beginning with C# 11, you can add the required member to force client code to initialize any property or field:

===============================================================
*/
public class SaleItem
{
    public required string Name
    { get; set; }

    public required decimal Price
    { get; set; }
}

// Example
var item = new SaleItem { Name = "Shoes", Price = 19.95m };
Console.WriteLine($"{item.Name}: sells for {item.Price:C2}");