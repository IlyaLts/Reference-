/*
===================
// Before C++17
===================
*/
namespace Game
{
    namespace Graphics
	{
        namespace Physics
		{
           class 2D
		   {
              // ...
           };
        }
    }
}

/*
===================
Since C++17
===================
*/
namespace Game::Graphics::Physics
{
    class 2D
	{
       // ...
    };
}
