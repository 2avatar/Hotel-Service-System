#pragma once
#ifndef __TEMPLATE_LINKED_LIST_H
#define __TEMPLATE_LINKED_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
private:
	Node<T> *head, *tail;
public:

	LinkedList()
	{
		head = tail = nullptr;
	}

	LinkedList(const LinkedList& other) 
	{
		LinkedList::head = other.head;
		LinkedList::tail = other.tail;
	}

	~LinkedList()
	{
		deleteHelper(*head);
		delete[] tail;
	}

	void deleteHelper(Node<T>& node)
	{
		if (node.next == nullptr)
			return;

		deleteHelper(*node.next);

		delete[] &node;
	}

	const LinkedList& operator+=(const T& node)
	{
		if (head != nullptr) {
			tail->next = new Node<T>(node);
			tail = tail->next;
		}
		else {
			head = new Node<T>(node);
			tail = head;
		}
		return *this;
	}

	const LinkedList& operator-=(const T& node)
	{
		Node<T> *previousIterator = head;
		Node<T> *currentIterator = head;
		while (currentIterator.hasNext() && currentIterator->data != node)
		{
			previousIterator = currentIterator;
			currentIterator = currentIterator->next;
		}
		prev->next = currentIterator->next
			delete[] currentIterator;

		return *this;
	}

	void deleteAll() 
	{
		deleteHelper(*head->next);
		head = tail = nullptr;
	}

	bool isExists(const T& node)
	{

		if (head == nullptr)
			return false;

		Node<T> *currentIterator = head;

		while (currentIterator->hasNext())
		{
			if (*currentIterator->data == node)
				return true;

			currentIterator = currentIterator->next;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const LinkedList& list)
	{
		if (list.head == nullptr)
			return os;

		Node<T> *currentIterator = list.head;
		while (currentIterator->hasNext()) 
		{
			os << *currentIterator->data << "\n";
			currentIterator = currentIterator->next;
		}
		os << *currentIterator->data;
		return os;
	}

};

#endif // __TEMPLATE_LINKED_LIST_H
