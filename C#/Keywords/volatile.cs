/*
The volatile keyword indicates that a field might be modified by multiple threads
that are executing at the same time. The compiler, the runtime system, and even hardware
may rearrange reads and writes to memory locations for performance reasons.
Fields that are declared volatile are excluded from certain kinds of optimizations.
There is no guarantee of a single total ordering of volatile writes as seen from all threads of execution.
For more information, see the Volatile class.
*/
class VolatileTest
{
    public volatile int sharedStorage;

    public void Test(int i)
    {
        sharedStorage = i;
    }
}