// Expression lambda that has an expression as its body:
Func<int, int> square = x => x * x;
Console.WriteLine(square(5));
// Output:
// 25