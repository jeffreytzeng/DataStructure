#ifndef LINKED_LIST
#define LINKED_LIST

template<class T>
class Node
{
	public:
		Node(T data):
			data_(data),
			next_(nullptr)
		{}
		~Node() {
			delete next_;
		}

		T GetData() { return data_;}
		Node *GetNext() { return next_;}
		void SetData(T data) { data_ = data;}
		void SetNext(Node<T> *node) { next_ = node;}

	private:
		T data_;
		Node<T> *next_;
};

template<class T>
class LinkedList
{
	public:
		LinkedList():
			head_(nullptr)
		{}
		~LinkedList();

		void Display();
		void Insert(T data);
	private:
		Node<T> *head_;
};

#endif