import java.util.Scanner;

class Node {
	private int data;
	private Node next;

	Node() {
		this(0);
	}

	Node(int data) {
		this(data, null);
	}

	Node(int data, Node next) {
		this.data = data;
		this.next = next;
	}

	int GetData() {
		return data;
	}

	Node GetNext() {
		return next;
	}

	void SetData(int data) {
		this.data = data;
	}

	void SetNext(Node next) {
		this.next = next;
	}
}

public class MyLinkedList {
	private Node head;
	private int count;

	public MyLinkedList() {
		this(null);
		count = 0;
	}

	public MyLinkedList(Node node) {
		if (head == null) {
			if (node != null) {
				head = node;
				count = 1;
			}
		}
	}

	public void Add(int data) {
		Node temp = new Node(data);
		Node current = head;

		if (head == null) {
			head = temp;
			count++;
		} else {
			while (current.GetNext() != null) {
				current = current.GetNext();
			}
			current.SetNext(temp);
			count++;
		}
	}

	public int GetData(int index) {
		Node current = head;
		for (int i = 0; i <= index; i++) {
			current = current.GetNext();
		}
		return current.GetData();
	}

	public int GetSize() {
		return count;
	}

	public boolean IsEmpty() {
		return GetSize() == 0;
	}

	public void Pop() {
		Node current = head;
		Node previous = head;

		if (head == null) {
			return;
		} else {
			while (current.GetNext() != null) {
				previous = current;
				current = current.GetNext();
			}
			previous.SetNext(null);
			count--;
		}
	}

	public void Display() {
		Node current = head;

		while (current != null) {
			System.out.print(current.GetData() + " ");
			current = current.GetNext();
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int total_cases = input.nextInt();
		MyLinkedList list = new MyLinkedList();

		for (int i = 0; i < total_cases; i++) {
			list.Add(input.nextInt());
		}

		list.Display();
		list.Pop();
		list.Display();
	}
}