#include "String.h"
#include "list.h"
#include "vector.h"
#include <vector>

using namespace my;
using std::cin;
using std::cout;
using std::endl;
#define ps system("pause")

int main()
{
    list<vector<int>> q;
    vector<int> v1{1, 2, 3};
    vector<int> *v2 = new vector<int>{2, 3};
    cout << v1 << endl
         << *v2 << endl;
    cout << v1 + *v2 << endl;
    delete v2 ;
    return 0;
}
