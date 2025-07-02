// Explicacao do exercicio: https://www.hackerrank.com/contests/monitoria-ip/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = create_singly_linked_list_node(data);

    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* current = llist;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return llist;
}