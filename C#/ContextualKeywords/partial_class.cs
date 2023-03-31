// Partial type definitions allow for the definition of a class, struct, interface, or record to be split into multiple files.

// In File1.cs:
namespace PC
{
    partial class A
    {
        int num = 0;
        void MethodA() { }
        partial void MethodC();
    }
}

// In File2.cs the declaration:
namespace PC
{
    partial class A
    {
        void MethodB() { }
        partial void MethodC() { }
    }
}