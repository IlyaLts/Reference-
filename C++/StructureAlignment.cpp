#include <iostream>
#include <cstring>

using namespace std;

/*
Use:
    char c;
    char s;
    int x;
    double y;
    
instead of 

    char c;
    char s;
    double y;
    int x;

as its size is 16 bytes instead of 24 bytes
*/

struct Entry
{

};

struct Object : Entry
{
    char c;
    char s;
    int x;
    double y;
};

struct alignas(64) BigData
{
    int x;
    int y;
    int z;
};

// the array "cacheline" will be aligned to 64-byte boundary:
alignas(64) char cacheline[64];

//========================================
// main function
//========================================
int main()
{
    Entry entry;
    Object obj;
    BigData data;
    
    cout << "sizeof(entry) = " << sizeof(entry) << endl;
    cout << "alignof(entry) = " << alignof(entry) << endl;
    cout << "sizeof(obj) = " << sizeof(obj) << endl;
    cout << "alignof(obj) = " << alignof(obj) << endl;
    cout << "sizeof(data) = " << sizeof(data) << endl;
    cout << "alignof(data) = " << alignof(data) << endl;
    
    cout << "alignment_of<char> = " << alignment_of<char>() << endl;
    cout << "alignment_of<int> = " << alignment_of<int>() << endl;
    cout << "alignment_of<double> = " << alignment_of<double>() << endl;
    cout << "alignment_of<Entry> = " << alignment_of<Entry>() << endl;
    cout << "alignment_of<Object> = " << alignment_of<Object>() << endl;
    cout << "alignment_of<BigData> = " << alignment_of<BigData>() << endl;
    
    return 0;
}

/*
OUTPUT:

sizeof(entry) = 1
alignof(entry) = 1
sizeof(obj) = 16
alignof(obj) = 8
sizeof(data) = 64
alignof(data) = 64
alignment_of<char> = 1
alignment_of<int> = 4
alignment_of<double> = 8
alignment_of<Entry> = 1
alignment_of<Object> = 8
alignment_of<BigData> = 64
*/
