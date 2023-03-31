#include <iostream>
#include <cstring>

using namespace std;

// Range based loop calls begin() and end() methods that return iterator to an element

/*
=================================================================================

    FixedString

=================================================================================
*/
template<size_t S> class FixedString
{
public:
    
    FixedString() = default;
    FixedString(const char* str) { if(str) ::strncpy(str_, str, S); }

    const char* c_str() const { return str_; }
    size_t count() const { return ::strlen(str_); }
    const char& operator[](size_t i) const { return str_[i]; } 
    
    // default memberwise copies
    
    // Minimum required for range-for loop
    template<typename T> struct Iterator
    {
        T* p;
        T& operator*() { return *p; }
        bool operator != (const Iterator& rhs) { return p != rhs.p; }
        void operator ++() { ++p; }
    };

    // auto return requires C++14
    // const version
    auto begin() const
    { 
       return Iterator<const char>{str_};
    }

    // const version
    auto end() const 
    {
        return Iterator<const char>{str_+count()};
    }

private:
    
    char str_[S+1]{}; // '\0' everywhere
};

/*
=================================================================================

    Numbers

=================================================================================
*/
class Numbers
{
public:
    
    Numbers() = default;
    Numbers(int n) { len = n; p = new int[n]; for (int i  = 0; i < n; i++) { p[i] = i; } }
    
    // Minimum required for range-for loop
    template<typename T> struct Iterator
    {
        T* p;
        T& operator*() { return *p; }
        bool operator != (const Iterator& rhs) { return p != rhs.p; }
        void operator ++() { ++p; }
    };
    
    auto begin() const
    { 
       return Iterator<int>{p};
    }

    // const version
    auto end() const 
    {
        return Iterator<int>{p+len};
    }
    
    
private:

    int *p;
    int len;
};

//========================================
// main function
//========================================
int main()
{
    Numbers nums(10);
    FixedString<5> string("test!");

    for (auto &num : nums)
        cout << num;
    
    cout << endl;
    
    for (auto &letter : string)
        cout << letter;

    return 0;
}
