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
    vector<int> t, t2;
    cin >> t;
    q.push_back(t);    // list增 vector默认构造
    t += t;            // vector+=
    cout << t << endl; // vector的 operator<<
    q.push_front(t);   //list增
    q.show_list();
    cin >> t2;
    q.emplace(t, t2); //list查 改  vector的operator=
    q.show_list();
    q.pop_back();                // list删
    q.push_back(*q.begin() * 2); //list增 vector的operator*(int)
    q.show_list();
    cout << *q.begin() * *--q.end() << endl; //list迭代器的--  vector的operator*(vector)
#define dbg cout << s1 << endl \
                 << s2 << endl \
                 << s3 << "\n---------------------------\n"
    string s1("s1"), s2(s1), s3; // string(char*) string(string) string()
    dbg;
    s3 = s2;      // operator=(string)
    cin >> s2;    //operator >>
    s1 = s2 + s3; // operator+(string)
    dbg;
    std::vector<string> a{s1, s2, s3};
    sort(a.begin(), a.end());
    for (auto c : a)
        cout << c << endl; // operator<(string)
#undef dbg
#define dbg cout << s1 << endl \
                 << "---------------------------\n"
    getline(cin, s1); // istream,string
    dbg;
    getline(cin, s1, 'a'); // istream ,string ,dlim
    dbg;
    getline(cin, s1, 5); // istream , string , maxsize
    dbg;
    getline(cin, s1, 5, 'a'); // istream ,string , maxsie ,dlim
    dbg;
    return 0;
}
