#pragma once
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

namespace my
{
template <class T>
class vec
{
public:
	vec<T>() : head(new T), _size(0), max_size(1) {}
	vec<T>(const std::initializer_list<T> &v) : vec<T>()
	{
		*this = v;
	}
	vec<T>(const vec<T> &v) : vec<T>()
	{
		*this = v;
	}
	int size() const
	{
		return _size;
	}
	int capacity() const
	{
		return max_size;
	}
	void push_back(const T &a)
	{
		if (_size == max_size)
		{
			T *temp = new T[max_size << 1];
			memcpy(temp, head, sizeof(T) * max_size);
			delete[] head;
			head = temp;
			max_size <<= 1;
		}
		head[_size++] = a;
	}
	void pop_back()
	{
		try
		{
			if (_size == 0)
				throw "Error: \npop when empty!\nthe operation is invalid\n";
			else
				_size--;
		}
		catch (const char *str)
		{
			std::cerr << str << std::endl;
		}
	}
	void insert(const int &pos, const T &v)
	{
		// 0 1 2 3 4 5 4
		push_back(v);
		for (int i = _size - 1; i >= pos; i--)
			head[i] = head[i - 1];
		head[pos] = v;
	}
	void erase(const int &pos)
	{
		for (int i = pos; i < _size; i++)
			head[i] = head[i + 1];
		pop_back();
	}
	void clear()
	{
		delete[] head;
		max_size = 1;
		_size = 0;
		head = new T;
	}
	T back() const
	{
		return head[_size - 1];
	}
	T &operator[](const int &a) const
	{
		static T err;
		try
		{
			if (std::abs(a) >= _size)
				throw "Error: \nout of the index !\nthe operation is invalid\n";
		}
		catch (const char *str)
		{
			std::cerr << str << std::endl;
			return err;
		}
		return a >= 0 ? head[a] : head[_size - a];
	}
	T *begin() const
	{
		return head;
	}
	T *end() const
	{
		return head + _size;
	}
	vec<T> &operator=(const vec<T> &a)
	{
		clear();
		max_size = a.capacity();
		_size = a.size();
		delete[] head;
		head = new T[max_size];
		memcpy(head, a.begin(), sizeof(T) * max_size);
		return *this;
	}
	vec<T> &operator=(const std::initializer_list<T> &v)
	{
		clear();
		for (auto c : v)
			push_back(c);
		return *this;
	}
	bool operator==(const vec<T> &a)
	{
		if (size() != a.size())
			return 0;
		for (int i = 0; i < size(); i++)
			if (head[i] != a[i])
				return 0;
		return 1;
	}
	bool operator!=(const vec<T> &a)
	{
		return !operator==(a);
	}
	~vec<T>()
	{
		delete[] head;
	}
	virtual std::istream &ipt(std::istream &in) = 0;
	virtual std::ostream &opt(std::ostream &out) const = 0;

protected:
	T *head;
	int _size = 0, max_size = 1;
};
} // namespace my