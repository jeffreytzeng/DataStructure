class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def Insert(self, data):
        if (self.head == None):
            self.head = Node(data)
        else:
            current = self.head

            while current.next != None:
                current = current.next

            current.next = Node(data)

    def Display(self):
        current = self.head

        while current != None:
            print(str(current.data) + ' ', end='')
            current = current.next

n = int(input())
llist = LinkedList()

for i in range(n):
    llist.Insert(int(input()))

llist.Display()