#include <iostream>
#include "heap_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main()
{
    std::vector<int> vec;
    for(int i = 10;i > 0;i--)
    {
        vec.push_back(i);
    }
//    vec.push_back(2);
//    vec.push_back(1);
//    vec.push_back(4);
//    vec.push_back(6);
//    vec.push_back(5);
//    vec.push_back(3);
    quick_sort(vec);

    std::vector<int>::iterator it;
    for(it = vec.begin();it <vec.end();it++)
    {
        std::cout << *it << ' ';
    }
    return 0;
}
