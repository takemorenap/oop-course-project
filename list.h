#pragma once

#include <iostream>

namespace my
{
template <class T>
class Node
{
public:
	Node() : data(T()), pre(nullptr), next(nullptr) {}
	Node(const T &v) : data(v), pre(nullptr), next(nullptr) {}
	Node(const Node<T> &v) : data(v.data), pre(v.pre), next(v.next) {}
	T data;
	Node<T> *pre, *next;
};
template <class T>
class itrator
{
#define self itrator<T>
public:
	itrator(Node<T> *v) : node(v) {}
	T &operator*()
	{
		return node->data;
	}
	T *operator->()
	{
		return &(operator*());
	}
	self &operator++()
	{
		node = node->next;
		return *this;
	}
	self operator++(int)
	{
		self temp(*this);
		node = node->next;
		return temp;
	}
	self &operator--()
	{
		node = node->pre;
		return *this;
	}
	self operator--(int)
	{
		self temp(*this);
		node = node->pre;
		return temp;
	}
	bool operator==(const self &v) const
	{
		return node == v.node;
	}
	bool operator!=(const self &v) const
	{
		return !operator==(v);
	}
	Node<T> *node;
};
#undef self
template <class T>
class list
{
	using it = itrator<T>;

public:
	list()
	{
		//cout << "!"<<endl;
		head = new Node<T>();
		head->next = head;
		head->pre = head;
	}
	list(const std::initializer_list<T> &v) : list()
	{
		for (auto c : v)
			push_back(c);
	}
	~list()
	{
		auto pre = begin(), now = pre;
		while (now != end())
		{
			now++;
			erase(pre);
			pre = now;
		}
	}
	list<T> &operator=(const list<T> &v)
	{
		clear();
		for (auto c : v)
			push_back(c);
	}
	void clear()
	{
		auto pre = begin(), now = pre;
		while (now != end())
		{
			now++;
			erase(pre);
			pre = now;
		}
	}
	it begin()
	{
		return it(head->next);
	}
	it end()
	{
		return it(head);
	}
	void push_back(const T &v)
	{
		insert(end(), v);
	}
	void pop_back()
	{
		erase(--end());
	}
	void push_front(const T &v)
	{
		insert(begin(), v);
	}
	void pop_front()
	{
		erase(begin());
	}
	it erase(it pos)
	{
		Node<T> *now = pos.node;
		now->pre->next = now->next;
		now->next->pre = now->pre;
		Node<T> *nxt = now->next;
		delete now;
		return it(nxt);
	}
	void insert(it pos, const T &v)
	{
		Node<T> *newnode = new Node<T>(v);
		Node<T> *now = pos.node;
		Node<T> *pre = now->pre;
		pre->next = newnode;
		newnode->pre = pre;
		newnode->next = now;
		now->pre = newnode;
	}
	it find(const T &v)
	{
		for (auto i = begin(); i != end(); i++)
			if (*i == v)
				return i;
		return end();
	}
	it emplace(it pos, const T &v)
	{
		pos.node->data = v;
		return pos;
	}
	it emplace(const T &a, const T &b)
	{
		it pos = find(a);
		if (pos != end())
			return emplace(pos, b);
	}
	size_t size()
	{
		size_t cnt = 0;
		for (auto c : *this)
			cnt++;
		return cnt;
	}
	void show_list()
	{
		for (auto c : *this)
			std::cout << c;
		std::cout << "\n-------------------------------------\n";
	}

private:
	Node<T> *head;
};
} // namespace my
