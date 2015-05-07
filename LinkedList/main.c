//
//  main.c
//  LinkedList
//
//  Created by Jeremy Petter on 2015-05-06.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int value;
    Node* next;
};

void printListFromStartingNode(Node *thisNode);
Node* searchListForIntFromStartingNode(int *query, Node *thisNode);
void insertNodeAtEndOfList(Node* thisNode, Node* head);
void removeNodeByPointer(Node* target, Node* head);
Node* newNodeWithValue (int value);

int main(int argc, const char * argv[]) {
    
    Node* node1 = newNodeWithValue(1);
    Node* head = node1;
    Node* node2 = newNodeWithValue(2);
    insertNodeAtEndOfList(node2,head);
    Node* node3 = newNodeWithValue(3);
    insertNodeAtEndOfList(node3,head);
    printListFromStartingNode(head);
    removeNodeByPointer(node1,head);
    printListFromStartingNode(head);
    
    
    return 0;
}

void printListFromStartingNode(Node *thisNode){
    while(thisNode != NULL){
        printf("%d\n", thisNode->value);
        thisNode = thisNode->next;
    }
}

Node* searchListForIntFromStartingNode(int *query, Node *thisNode){
    if (thisNode->value == *query){
        return thisNode;
    } else if (thisNode->next){
        return searchListForIntFromStartingNode(query, thisNode->next);
    } else {
        return NULL;
    }
}

void insertNodeAtEndOfList(Node* thisNode, Node* head){
    Node* query = head;
    while (query->next != NULL){
        query = query->next;
    }
        query->next = thisNode;
}

void removeNodeByPointer(Node* target, Node* head){
    if (target == head){
        head = head->next;
        free(target);
    } else {
        Node * query = head;
        while (query->next != target){
            query = query->next;
        }
        query->next = query->next->next;
        free(target);
    }
}

Node* newNodeWithValue (int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    return node;
}