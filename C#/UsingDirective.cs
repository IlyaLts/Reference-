/*
The using directive allows you to use types defined in a namespace without specifying the fully qualified
namespace of that type. In its basic form, the using directive imports all the types from a single namespace,
as shown in the following example:
*/
using System.Text;
using Project = PC.MyCompany.Project;

/*
global modifier

Adding the global modifier to a using directive means that using is applied to all files in the compilation
(typically a project). The global using directive was added in C# 10. Its syntax is:
*/
global using <fully-qualified-namespace>;

/*
static modifier

using static imports only accessible static members and nested types declared
in the specified type. Inherited members aren't imported.
*/

using static System.Console;
using static System.Math;
class Program
{
    static void Main()
    {
        WriteLine(Sqrt(3*3 + 4*4));
    }
}

// with global too
global using static System.Math;
