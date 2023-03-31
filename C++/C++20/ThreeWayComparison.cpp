#include <iostream>

using namespace std;

/*
=================================
operator <=> returns std::strong_ordering
=================================
*/

struct S2
{
    int a;
    int b;
};

struct S1
{
    // Support homogeneous comparisons
    auto operator <=>(const S1&) const = default;
	
    // This is required because there's operator ==(const S2&) which prevents implicit declaration of defaulted operator ==()
    bool operator ==(const S1&) const = default;

    // Support heterogeneous comparisons
    std::strong_ordering operator <=>(const S2& other) const
    {
        if (auto cmp = x <=> other.a; cmp != 0)
            return cmp;
		
        return y <=> other.b;
    }

    bool operator ==(const S2& other) const
    {
        return (*this <=> other) == 0;
    }

    int x;
    int y;
};

int main()
{
	int a = (7 <=> 7) > 0;
	cout << "7 <=> 7 = " << ((7 <=> 7) == 0) << endl;
	cout << "7 <=> 5 = " << ((7 <=> 5) > 0) << endl;
	cout << "5 <=> 7 = " << ((5 <=> 7) < 0) << endl;
	
	S1 a2{3, 6};
	S2 b2{3, 6};
	cout << ((a2 <=> b2) == 0) << endl;
	
	return 0;
}

/*
=============================
Returns:

7 <=> 7 = 1
7 <=> 5 = 1
5 <=> 7 = 1
1
=============================
*/
