/*
===========================
Basic
===========================
*/
var fibNumbers = new List<int> { 0, 1, 1, 2, 3, 5, 8, 13 };
foreach (int element in fibNumbers)
{
    Console.Write($"{element} ");
}
// Output:
// 0 1 1 2 3 5 8 13

/*
===========================
By reference
===========================
*/
Span<int> storage = stackalloc int[10];
int num = 0;
foreach (ref int item in storage)
{
    item = num++;
}
foreach (ref readonly var item in storage)
{
    Console.Write($"{item} ");
}
// Output:
// 0 1 2 3 4 5 6 7 8 9

/*
===========================
await foreach
===========================
*/
await foreach (var item in GenerateSequenceAsync())
{
    Console.WriteLine(item);
}