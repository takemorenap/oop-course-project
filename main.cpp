#include "list.h"
#include <algorithm>

using namespace my;
using std::cin;
using std::cout;
using std::endl;
#define ps system("pause")

int main()
{
    list<int> q;
    for (int i = 1; i <= 5; i++)
        q.push_back(i);
    auto it = std::find(q.begin(), q.end(), 2);
    cout << * it <<endl;
    return 0;
}
