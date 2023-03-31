if constexpr(cond)
     statement1; // Discarded if cond is false
else
     statement2; // Discarded if cond is true
 
//==========================================================================

template <typename T> auto get_value(T t)
{
    if constexpr (std::is_pointer_v<T>)
        return *t;
    else
        return t;
}
