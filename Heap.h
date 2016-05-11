#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

template<class T>
class Heap
{
public:
	Heap()
	{}
	Heap(const T* a, size_t size)
	{
		assert(a);
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		//建堆(从第一个非叶子节点(n-1)/2)
		for (int i = (_a.size() - 2) / 2; i >= 0; --i) //先-1求下表
		{
			_AdjustDown(i);
		}
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1); //向上调整
	}
	void Pop() //删除最大元素（与最后一个元素交换，在pop，最后向下调整）
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}
protected:
	void _AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < _a.size())
		{
			if ((child+1<_a.size())&&(_a[child] < _a[child + 1]))
			{
				child++;
			}
			if (_a[parent] < _a[child])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	void _AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

protected:
	vector<T> _a;
};

void test()
{
	int a[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int> h1(a, sizeof(a) / sizeof(a[0]));
	h1.Push(30);
	h1.Pop();
}

