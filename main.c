#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *previous;
} node;

typedef struct linkedlist {
    node *head;
    node *tail;
    int num;
} linkedlist;

node* createNode(int value) {
    node *new_node = (node *) malloc(sizeof(node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = NULL;

    return new_node;
}

linkedlist* createLinkedList(void) {
    linkedlist *newLinkedList = (linkedlist *) malloc(sizeof(linkedlist));
    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;
    newLinkedList->num = 0;
    return newLinkedList;
}

// insert head to linked list
void insert_into_head(linkedlist* llist, int val) {
    node *new_node = createNode(val);
    // First node map with linked
    if (llist->head == NULL) {
        llist->head = new_node;
        llist->tail = new_node;
    } else {
        // insert the firt node and move the old node to sec one
        node *ori_node;
        ori_node = llist->head;
        llist->head = new_node;
        new_node->next = ori_node;
        ori_node->previous = new_node;
    }
    llist->num++;
}

// insert tail to linked list
void insert_into_tail(linkedlist* llist, int val) {
    node *new_node = createNode(val);
    // First node map with linked
    if (llist->tail == NULL) {
        llist->head = new_node;
        llist->tail = new_node;
    } else {
        // insert the firt node and move the old node to sec one
        node *ori_node;
        ori_node = llist->tail;
        llist->tail = new_node;
        new_node->previous = ori_node;
        ori_node->next = new_node;
    }
    llist->num++;
}


// Display from head
void display_value_from_head(linkedlist* llist) {
    node *nodeVale = NULL;
    nodeVale = llist->head;
    int i = 0;

    // print from the head
    while (nodeVale != NULL) {
        printf("Node[%d] : %d\n", i, nodeVale->value);
        i++;
        nodeVale = nodeVale->next;
    }

    if(i == 0) {
        printf("No value in the linkedlist\n");
    }
}

// Display from tail
void display_value_from_tail(linkedlist* llist) {
    node *nodeVale = NULL;
    int i = 1;
    nodeVale = llist->tail;

    // print from the head
    while (nodeVale != NULL) {
        printf("Node[%d] : %d\n", (llist->num - i), nodeVale->value);
        i++;
        nodeVale = nodeVale->previous;
    }

    if(i == 0) {
        printf("No data in the linkedlist\n");
    }
}

//remove from head

//remote from tail

// Find the node

// insert node to specific num

int main(int argc, const char *argv[]) {
    // init value
    linkedlist *LinkedList = createLinkedList();
    insert_into_head(LinkedList, 1);
    insert_into_head(LinkedList, 2);
    insert_into_head(LinkedList, 3);
    insert_into_tail(LinkedList, 1);
    insert_into_tail(LinkedList, 2);
    insert_into_tail(LinkedList, 3);

    printf("There are %d node in the linkedlist\n", LinkedList->num);
    display_value_from_head(LinkedList);
    display_value_from_tail(LinkedList);
    printf("end of linked list sample \n");
    return 0;
}

