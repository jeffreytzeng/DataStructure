#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
	int data;
	struct NodeStruct *next;
} Node;

typedef struct LinkedListStruct {
	Node *head;
	void (*Display)(Node *head);
	Node *(*Insert)(Node *head, int data);
} LinkedList;

void DisplayData(Node *head) {
	Node *current = head;

	while (current->next != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("%d", current->data);
}

void FreeLinkedList(LinkedList *llist) {
	while (llist->head != NULL) {
		Node *current = llist->head;
		Node *previous = current;

		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}

		free(current);

		// Stop looping when previous points to head.
		if (previous->next != NULL) {
			previous->next = NULL;
		} else {
			break;
		}
	}
}

Node *InsertData(Node *head, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	} else {
		Node *current = head;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = node;
	}
	return head;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	LinkedList llist = {.head = NULL, .Insert = InsertData, .Display = DisplayData};

	for (int i = 0; i < n; i++) {
		int data = 0;
		scanf("%d", &data);
		llist.head = llist.Insert(llist.head, data);
	}

	llist.Display(llist.head);
	FreeLinkedList(&llist);
	return 0;
}
	




