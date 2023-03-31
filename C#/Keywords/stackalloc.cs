/*
A stackalloc expression allocates a block of memory on the stack.
A stack allocated memory block created during the method execution is automatically discarded
when that method returns. You cannot explicitly free the memory allocated with stackalloc.
A stack allocated memory block is not subject to garbage collection
and doesn't have to be pinnedwith a fixed statement.
*/
int length = 3;
Span<int> numbers = stackalloc int[length];
for (var i = 0; i < length; i++)
{
    numbers[i] = i;
}