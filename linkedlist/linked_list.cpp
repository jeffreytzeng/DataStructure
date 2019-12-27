#include <iostream>
#include "linked_list.hpp"

using namespace std;

template<class T>
LinkedList<T>::~LinkedList() {
	while (head_ != nullptr) {
		Node<T> *current = head_;
		Node<T> *previous = current;

		while (current->GetNext() != nullptr) {
			previous = current;
			current = current->GetNext();
		}

		delete current;

		if (previous->GetNext() != nullptr) {
			previous->SetNext(nullptr);
		} else {
			break;
		}
	}
}

template<class T>
void LinkedList<T>::Display() {
	Node<T> *current = head_;

	while (current != nullptr) {
		cout << current->GetData() << " ";
		current = current->GetNext();
	}
}

template <class T>
void LinkedList<T>::Insert(T data) {
	if (head_ == nullptr) {
		head_ = new Node<T>(data);
	} else {
		Node<T> *current = head_;

		while (current->GetNext() != nullptr) {
			current = current->GetNext();
		}

		current->SetNext(new Node<T>(data));
	}
}

int main()
{
	int n = 0;
	cin >> n;
	LinkedList<int> *llist = new LinkedList<int>;

	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		llist->Insert(num);
	}

	llist->Display();
	delete llist;
}
	