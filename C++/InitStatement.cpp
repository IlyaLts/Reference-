// Requires C++ 17, 20

//=========================================================
// C++17 - If Init Statement
//=========================================================
if (init; condition) 

// Example
if (auto a = get_value(); a > 0)
   std::cout << "processing A " << a << '\n';
else if(auto b = get_another_value(); b > 0)
   std::cout << "processing B " << b << '\n';

//=========================================================
// C++17 - Switch Init Statement
//=========================================================
switch (init; condition)

// Example
switch (auto option = get_option(); option)
{
   case 'a': /* add */   break;
   case 'd': /* del */   break;
   case 'l': /* list */  break;
   case 'q': /* quit */  break;
   default:  /* error */ break;
}

//=========================================================
// C++20 - For Init Statement
//=========================================================
for (init; declaration : initializer)

// Example
for (auto const& values = get_values(); auto const& v : values)
   std::cout << v << '\n';
