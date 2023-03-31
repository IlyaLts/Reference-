/*
Provides a convenient syntax that ensures the correct use of IDisposable objects. Beginning in C# 8.0,
the using statement ensures the correct use of IAsyncDisposable objects.
*/
string manyLines = @"This is line one
This is line two
Here is line three
The penultimate line is line four
This is the final, fifth line.";

using (var reader = new StringReader(manyLines))
{
    string? item;
    do
    {
        item = reader.ReadLine();
        Console.WriteLine(item);
    } while (item != null);
}

/*The using declaration, which was introduced in C# 8.0, doesn't require braces:*/
string manyLines = @"This is line one
This is line two
Here is line three
The penultimate line is line four
This is the final, fifth line.";

using var reader = new StringReader(manyLines);
string? item;
do
{
    item = reader.ReadLine();
    Console.WriteLine(item);
} while (item != null);