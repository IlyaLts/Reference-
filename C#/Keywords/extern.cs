/*
The extern modifier is used to declare a method that is implemented externally.
A common use of the extern modifier is with the DllImport attribute when
you are using Interop services to call into unmanaged code. In this case,
the method must also be declared as static, as shown in the following example:
*/

class ExternTest
{
    [DllImport("User32.dll", CharSet=CharSet.Unicode)]
    public static extern int MessageBox(IntPtr h, string m, string c, int type);

    static int Main()
    {
        string myString;
        Console.Write("Enter your message: ");
        myString = Console.ReadLine();
        return MessageBox((IntPtr)0, myString, "My Message Box", 0);
    }
}