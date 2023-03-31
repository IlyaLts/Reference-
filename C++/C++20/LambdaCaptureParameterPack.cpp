/*
=============================
Capture parameter packs by value:
=============================
*/

template <typename... Args> auto f(Args&&... args)
{
    // By value:
    return [...args = std::forward<Args>(args)]
	{
        // ...
    };
}

// Capture parameter packs by reference:

template <typename... Args> auto f(Args&&... args
{
    // By reference:
    return [&...args = std::forward<Args>(args)]
	{
        // ...
    };
}
