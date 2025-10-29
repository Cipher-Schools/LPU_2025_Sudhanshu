/*
 Brief: Introduction to linked lists, types, and pros/cons vs arrays.

 This file contains short explanatory comments plus minimal C structs and
 tiny helper functions to illustrate singly and doubly linked lists.

 What is a linked list?
 - A linked list is a linear data structure where elements (nodes) hold
    data and one or more pointers (links) to other nodes.
 - Nodes are typically allocated dynamically and connected by pointers,
    forming a chain. The list head points to the first node.

 Common types of linked lists:
 - Singly linked list:
      Each node has data and a pointer to the next node.
      Traversal is forward only.
 - Doubly linked list:
      Each node has data, a next pointer, and a prev pointer.
      Supports forward and backward traversal.
 - Circular singly/doubly linked list:
      The last node links back to the first node, forming a ring.
      No NULL terminator; careful handling of stop condition needed.

 Advantages of linked lists over arrays:
 - Dynamic size: can easily grow/shrink at runtime (no need to reserve large blocks).
 - Efficient insertions/deletions: inserting or deleting at a known node is O(1)
    (only pointer updates), whereas arrays require shifting elements (O(n)).
 - No contiguous memory requirement: nodes can be scattered in memory.

 Disadvantages of linked lists vs arrays:
 - No constant-time random access: accessing the i-th element requires O(i) traversal.
 - Extra memory overhead: each node stores one or more pointers.
 - Poor cache performance: nodes may be scattered in memory, reducing locality.
 - More pointer manipulation bugs (dangling pointers, leaks) unless managed carefully.

 Minimal example: singly and doubly linked list node types and a few helpers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Singly linked list node */
typedef struct SNode {
    int data;
    struct SNode *next;
} SNode;

/* Allocate and initialize a new node with given value.
   Returns pointer to node or NULL on allocation failure. */
SNode* s_create_node(int value) {
    SNode *n = (SNode*)malloc(sizeof(SNode));
    if (!n) return NULL;
    n->data = value;
    n->next = NULL;
    return n;
}

/* Insert a new node at the head of the list.
   head: pointer to the list head pointer. */
void s_insert_head(SNode **head, int value) {
    SNode *n = s_create_node(value);
    if (!n) return;
    n->next = *head;
    *head = n;
}

/* Insert a new node at the tail of the list.
   If list is empty, new node becomes the head. */
void s_insert_tail(SNode **head, int value) {
    SNode *n = s_create_node(value);
    if (!n) return;
    if (!*head) {
        *head = n;
        return;
    }
    SNode *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

/* Insert a new node after the specified node.
   prev must not be NULL. Returns true on success. */
bool s_insert_after(SNode *prev, int value) {
    if (!prev) return false;
    SNode *n = s_create_node(value);
    if (!n) return false;
    n->next = prev->next;
    prev->next = n;
    return true;
}

/* Find first node with given value. Returns pointer or NULL if not found. */
SNode* s_find(SNode *head, int value) {
    for (SNode *cur = head; cur; cur = cur->next) {
        if (cur->data == value) return cur;
    }
    return NULL;
}

/* Delete the head node if present. Returns true if a node was deleted. */
bool s_delete_head(SNode **head) {
    if (!*head) return false;
    SNode *tmp = *head;
    *head = tmp->next;
    free(tmp);
    return true;
}

/* Delete first occurrence of value from the list.
   Returns true if a node was deleted. */
bool s_delete_value(SNode **head, int value) {
    if (!*head) return false;
    SNode *cur = *head;
    SNode *prev = NULL;
    while (cur && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) return false; /* not found */
    if (!prev) {
        /* deleting head */
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
    return true;
}

/* Reverse the list in-place. head is updated to new head. */
void s_reverse(SNode **head) {
    SNode *prev = NULL;
    SNode *cur = *head;
    while (cur) {
        SNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

/* Return number of nodes in the list. */
size_t s_length(SNode *head) {
    size_t n = 0;
    for (SNode *cur = head; cur; cur = cur->next) ++n;
    return n;
}

/* Print list contents in a readable format. */
void s_print(SNode *head) {
    printf("Singly: ");
    for (SNode *cur = head; cur; cur = cur->next) {
        printf("%d -> ", cur->data);
    }
    printf("NULL\n");
}

/* Free all nodes of the list. After this call head must not be used. */
void s_free(SNode *head) {
    while (head) {
        SNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* Small demonstration of singly linked list operations. */
int main(void) {
    SNode *head = NULL;

    s_insert_head(&head, 3);
    s_insert_head(&head, 2);
    s_insert_head(&head, 1); /* list: 1 -> 2 -> 3 */
    s_print(head);

    s_insert_tail(&head, 4); /* list: 1 -> 2 -> 3 -> 4 */
    s_print(head);

    SNode *found = s_find(head, 3);
    if (found) s_insert_after(found, 33); /* insert 33 after 3 */
    s_print(head);

    printf("Length: %zu\n", s_length(head));

    s_delete_value(&head, 2); /* remove first occurrence of 2 */
    s_print(head);

    s_reverse(&head);
    s_print(head); /* reversed */

    s_free(head);
    head = NULL;
    return 0;
}