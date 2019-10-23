#pragma once

#include"base.h"
bool isblank(const char &c)
{
    return c=='\n';
}
namespace my
{
class string : public vec<char>
{
public:
    virtual std::istream & ipt(std::istream &in)
    {
        clear();
        static char ch;
        while (in.get(ch) && ch != EOF && isprint(ch) && !isblank(ch))
            push_back(ch);
        return in;
    }
    virtual std::ostream & opt(std::ostream &out) const
    {
        for (int i=0; i<size(); i++)
            out << head[i];
        return out;
    }
    string(const char * str)
    {
        _size = strlen(str);
        while (max_size < _size)
            max_size <<= 1;
        head = new char[max_size];
        memcpy(head, str, sizeof(char)*_size);
    }
    string() :vec<char>() {}
    string(std::initializer_list<char> &v) : vec<char>(v) {}
    string(const string &a)
    {
        this->_size = a.size();
        this->max_size = a.capacity();
        this->head = new char[max_size];
        memcpy(this->head, a.begin(), this->max_size * sizeof(char));
    }
    friend std::istream& operator >>(std::istream & in, string &s)
    {
        s.ipt(in);
        return in;
    }
    friend std::ostream& operator << (std::ostream& out,const string &s)
    {
        s.opt(out);
        return out;
    }
    friend string &operator +=(string &a, const string &b)
    {
        for (auto c : b)
            a.push_back(c);
        return a;
    }
    friend string operator+(const string &a, const string &b)
    {
        string res(a);
        res += b;
        return res;
    }
    friend bool operator<(const string &a, const string &b)
    {
        int sz = std::min(a.size(), b.size());
        for (int i = 0; i < sz; i++)
            if (a[i] != b[i])
                return a[i] < b[i];
        return a.size() < b.size();
    }
    friend bool operator>(string &a, const string &b)
    {
        return a != b && !(a < b);
    }

    string substr(int s, int n)
    {
        int sz = std::min(s + n, this->_size);
        static string temp;
        temp.clear();
        for (int i = s; i < sz; i++)
            temp.push_back(this->head[i]);
        return temp;
    }
    int find(const int &start, const int & end, const string &s)
    {
        if (end - start < s.size())
            return -1;
        for (int i = start; i + s.size() <= end; i++)
        {
            static string sub = substr(i, s.size());
            if (sub == s)
                return i;
        }
        return -1;
    }
    friend std::istream & getline(std::istream & in , string &s ,int n,const char & dlim)
    {
        s.clear();
        while(s.max_size<n)
            s.max_size<<=1;
        char *tp=new char[s.max_size];
        in.getline(tp,n,dlim);
        delete[] s.head;
        s.head = tp;
        s._size=strlen(tp);
        return in;
    }
    friend std::istream &getline(std::istream &in, string &s ,const char &dlim)
    {
        s.clear();
        static char ch;
        while (in.get(ch) && ch != EOF && ch!=dlim)
            s.push_back(ch);
        return in;
    }
    friend std::istream &getline(std::istream &in ,string &s,const int n)
    {
        s.clear();
        while(s.max_size<n)
            s.max_size<<=1;
        char *tp=new char[s.max_size];
        in.getline(tp,n);
        delete[] s.head;
        s.head = tp;
        s._size=strlen(tp);
        return in;
    }
    friend std::istream &getline(std::istream &in ,string &s)
    {
        s.clear();
        static char ch;
        while (in.get(ch) && ch != EOF && ch!='\n')
            s.push_back(ch);
        return in;
    }
};
}
