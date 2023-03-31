string name = "Mark";
var date = DateTime.Now;

// Composite formatting:
Console.WriteLine("Hello, {0}! Today is {1}, it's {2:HH:mm} now.", name, date.DayOfWeek, date);
// String interpolation:
Console.WriteLine($"Hello, {name}! Today is {date.DayOfWeek}, it's {date:HH:mm} now.");
// Both calls produce the same output that is similar to:
// Hello, Mark! Today is Wednesday, it's 19:40 now.


/*
=====================================
Beginning with C# 11, the interpolated expressions can include newlines.
The text between the { and } must be valid C#, therefore it can include newlines that improve readability.
The following example shows how newlines can improve the readability of an expression involving pattern matching:
=====================================
*/
string message = $"The usage policy for {safetyScore} is {
    safetyScore switch
    {
        > 90 => "Unlimited usage",
        > 80 => "General usage, with daily safety check",
        > 70 => "Issues must be addressed within 1 week",
        > 50 => "Issues must be addressed within 1 day",
        _ => "Issues must be addressed before continued use",
    }
    }";

//=====================================
//Also, beginning in C# 11, you can use a raw string literal for the format string:
//=====================================
int X = 2;
int Y = 3;

var pointMessage = $"""The point "{X}, {Y}" is {Math.Sqrt(X * X + Y * Y)} from the origin""";

Console.WriteLine(pointMessage);
// output:  The point "2, 3" is 3.605551275463989 from the origin.

//=====================================
//You can use multiple $ characters in an interpolated raw string literal to embed { and } characters in the output string without escaping them:
//=====================================
int X = 2;
int Y = 3;

var pointMessage = $$"""The point {{{X}}, {{Y}}} is {{Math.Sqrt(X * X + Y * Y)}} from the origin""";
Console.WriteLine(pointMessage);
// output:  The point {2, 3} is 3.605551275463989 from the origin.