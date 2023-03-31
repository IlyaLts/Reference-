/*
If you are using Visual Studio, aliases can be provided in similar way.

Add reference of grid.dll and grid20.dll to your project in Visual Studio.
Open a property tab and change the Aliases from global to GridV1 and GridV2 respectively.
*/

/*
CommandLine
   - Program.cs
DepOne
    - MyType.cs (Namespace: Dep)
DepTwo
    - MyType.cs (Namespace: Dep)
*/

extern alias DepOneAlias;
extern alias DepTwoAlias;

namespace CommandLine
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var instanceOne = new DepOneAlias::Dep.MyType();
            var instanceTwo = new DepTwoAlias::Dep.MyType();
			var instanceOne = new MyType(); // Error
            var instanceTwo = new MyType(); // Error
        }
    }
}