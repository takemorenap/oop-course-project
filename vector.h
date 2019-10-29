#pragma once

#include "base.h"

namespace my
{
template <class T>
class vector : vec<T>
{
public:
    vector<T>() : vec<T>() {}
    vector<T>(const std::initializer_list<T> &v) : vec<T>(v) {}
    vector<T>(const vector<T> &v)
    {
        this->max_size = v.max_size;
        this->_size = v._size;
        this->head = new T[this->max_size];
        memcpy(this->head, v.head, sizeof(T) * this->_size);
    }
    virtual std::istream &ipt(std::istream &in)
    {
        this->clear();
        static int temp, num;
        in >> num;
        for (int i = 1; i <= num; i++)
        {
            in >> temp;
            this->push_back(temp);
        }
        return in;
    }
    virtual std::ostream &opt(std::ostream &out) const
    {
        out << "dim is :" << this->_size << '\n'
            << '(';
        for (int i = 0; i < this->_size - 1; i++)
            out << this->head[i] << ',';
        if (this->_size > 0)
            out << this->back();
        else
            out << ' ';
        out << ')' << '\n';
        return out;
    }
    bool operator==(const vector<T> &v) const
    {
        if (this->size() != v.size())
            return 0;
        for (int i = 0; i < v.size(); i++)
            if (this->head[i] != v[i])
                return 0;
        return 1;
    }
    friend std::istream &operator>>(std::istream &in, vector<T> &s)
    {
        s.ipt(in);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const vector<T> &s)
    {
        s.opt(out);
        return out;
    }
    friend vector<T> operator+(const vector<T> &a, const vector<T> &b)
    {
        static vector<int> temp;
        temp.clear();
        try
        {
            if (a.size() == b.size())
            {
                for (int i = 0; i < a.size(); i++)
                    temp.push_back(a[i] + b[i]);
                return temp;
            }
            else
                throw "Error!\nThe dimension of two vector is different.\nThe operation is invalid!\n";
        }
        catch (const char *str)
        {
            std::cerr << str << '\n';
            return temp;
        }
    }
    vector<T> &operator+=(const vector<T> &a)
    {
        static vector<int> err;
        try
        {
            if (this->size() == a.size())
            {
                for (int i = 0; i < a.size(); i++)
                    this->head[i] += a[i];
                return *this;
            }
            else
                throw "Error!\nThe dimension of two vector is different.\nThe operation is invalid!\n";
        }
        catch (const char *str)
        {
            std::cerr << str << '\n';
            return err;
        }
    }
    friend vector<T> operator-(const vector<T> &a, const vector<T> &b)
    {
        static vector<int> temp;
        temp.clear();
        try
        {
            if (a.size() == b.size())
            {
                for (int i = 0; i < a.size(); i++)
                    temp.push_back(a[i] - b[i]);
                return temp;
            }
            else
                throw "Error!\nThe dimension of two vector is different.\nThe operation is invalid!\n";
        }
        catch (const char *str)
        {
            std::cerr << str << '\n';
            return temp;
        }
    }
    vector<T> &operator-=(const vector<T> &a)
    {
        static vector<int> err;
        try
        {
            if (this->size() == a.size())
            {
                for (int i = 0; i < a.size(); i++)
                    this->head[i] -= a[i];
                return *this;
            }
            else
                throw "Error!\nThe dimension of two vector is different.\nThe operation is invalid!\n";
        }
        catch (const char *str)
        {
            std::cerr << str << '\n';
            return err;
        }
    }
    vector<T> &operator*=(const int &v)
    {
        for (auto &c : *this)
            c *= v;
        return *this;
    }
    vector<T> operator*(const int &v)
    {
        vector<T> temp(*this);
        temp *= v;
        return temp;
    }
    int operator*(const vector<T> &v)
    {
        int temp = 0;
        try
        {
            if (this->size() == v.size())
            {
                for (int i = 0; i < v.size(); i++)
                    temp += this->head[i] * v[i];
                return temp;
            }
            else
                throw "Error!\nThe dimension of two vector is different.\nThe operation is invalid!\n";
        }
        catch (const char *str)
        {
            std::cerr << str << '\n';
            return -1;
        }
    }
};
} // namespace my
