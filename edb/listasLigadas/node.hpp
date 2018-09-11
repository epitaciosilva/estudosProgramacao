#ifndef _NODE_HPP_
#define _NODE_HPP_

template <typename T>
class Node {
	public:
		T dado;
		Node<T> *next;
		Node<T> *previous;

		Node(){}
		~Node(){}
};

#endif