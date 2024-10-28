/*
=============================================================================================
The fixed statement prevents the garbage collector from relocating a movable variable.
The fixed statement is only permitted in an unsafe context.
You can also use the fixed keyword to create fixed size buffers.

The fixed statement sets a pointer to a managed variable and "pins" that
variable during the execution of the statement.
Pointers to movable managed variables are useful only in a fixed context.
Without a fixed context, garbage collection could relocate the variables unpredictably.
The C# compiler only lets you assign a pointer to a managed variable in a fixed statement.
=============================================================================================
*/
class Point
{
    public int x;
    public int y;
}

unsafe private static void ModifyFixedStorage()
{
    // Variable pt is a managed variable, subject to garbage collection.
    Point pt = new Point();

    // Using fixed allows the address of pt members to be taken,
    // and "pins" pt so that it is not relocated.

    fixed (int* p = &pt.x)
    {
        *p = 1;
    }
}