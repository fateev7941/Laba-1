#pragma once
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	class Node
	{
	public:
		Node* next_ptr;
		Node* prev_ptr;
		T data;
	};

	size_t _size = 0;
	Node* first = nullptr;
	Node* last = nullptr;

public:
	List();
	List(const List<T>& other);		// ����������� �����������
	~List();						// ����������
	bool empty();

	size_t size();

	void push_back(T new_data);
	T pop_front();
	T pop(size_t i);

	List<T>& operator= (const List<T>& other); // �������� ������������

	T& operator[] (size_t const& i);

	template<class U>
	friend std::ostream& operator<< (std::ostream& out, const List<U>& other); // ��������� ������� ����� �� �����

	template<class U>
	friend std::istream& operator>> (std::istream& in, List<U>& V);
};
#include "List.inl"
