#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_


#include <iostream>
#include <assert.h>

namespace CP {

template <typename T1,typename T2>
class pair
{
  public:
    T1  first;
    T2  second;

    // default constructor, using list initialize
    pair() : first(), second() {}

    // custom constructor, using list initialize
    pair(const T1 &a,const T2 &b) : first(a), second(b) { }

    // we have no destructor

    // equality operator
    bool operator==(const pair<T1,T2> &other) {
      std::cout << "You cannot call operator==" << std::endl;
      assert(false);
    }

    bool operator!=(const pair<T1, T2> &other) {
        return (
        (first != other.first && second == other.second) || 
        (first == other.first && second != other.second) || 
        (first != other.first && second != other.second)
        );
    }
    // comparison operator
    bool operator<(const pair<T1, T2> &other) const { 
        return (
        (first < other.first) || 
        (first == other.first && second < other.second)
        );
    }

    bool operator>(const pair<T1, T2> &other) const { 
        return (
        (first > other.first) || 
        (first == other.first && second > other.second)
        );
    }
    bool operator>=(const pair<T1,T2>& other) const {
        return ((first > other.first)
            || (first == other.first && second > other.second)
            || (first == other.first && second == other.second)
            );
        return false;
    }
};


}

#endif

using namespace std;
int main() {
    CP::pair <int, int> p1(10, 20);
    CP::pair <int, int> p2(p1);
    CP::pair <int, int> q(10, 30);
    
    cout << (p1 == q) << endl;
    cout << (p1 != q) << endl;
    cout << (p1 < q) << endl;
    cout << (p1 > q) << endl;

    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cout << (p1 < p2) << endl;
    cout << (p1 > p2) << endl;

    // modify
    CP::pair <int, int> m(20,20);
    CP::pair <int, int> n(10,30);
    cout << (m < n) << endl;

}
