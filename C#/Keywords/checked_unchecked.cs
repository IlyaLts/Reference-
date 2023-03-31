// The checked and unchecked statements specify the overflow-checking context
// for integral-type arithmetic operations and conversions, as the following example shows:

uint a = uint.MaxValue;

unchecked
{
    Console.WriteLine(a + 1);  // output: 0
}

try
{
    checked
    {
        Console.WriteLine(a + 1);
    }
}
catch (OverflowException e)
{
    Console.WriteLine(e.Message);  // output: Arithmetic operation resulted in an overflow.
}