// To check the run-time type of an expression, as the following example shows:
int i = 34;
object iBoxed = i;
int? jNullable = 42;
if (iBoxed is int a && jNullable is int b)
{
    Console.WriteLine(a + b);  // output 76
}

// To check for null, as the following example shows:
if (input is null)
{
    return;
}