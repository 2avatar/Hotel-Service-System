#pragma once
#ifndef __TEMPLATE_NODE_H
#define __TEMPLATE_NODE_H

template <class T>
class Node
{
public:

	const T *data;
	Node *next;
	Node(const T& data) 
	{
		Node::data = &data;
		next = nullptr;
	};

	Node(const Node& other) 
	{
		Node::data = other.data;
		Node::next = other.next;
	}

	bool hasNext()
	{
		return next != nullptr;
	};



};

#endif // __TEMPLATE_NODE_H