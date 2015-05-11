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

void printListFromStartingNode();
Node* searchListForIntFromStartingNode(int *target);
void insertNodeAtEndOfList(Node* thisNode);
void removeNodeByPointer(Node* target);
Node* newNodeWithValue (int value);
void deallocateList ();
int getIndexFromPointer (Node* target);

Node* head;

int main(int argc, const char * argv[]) {
    
    Node* node1 = newNodeWithValue(1);
    insertNodeAtEndOfList(node1);
    Node* node2 = newNodeWithValue(2);
    insertNodeAtEndOfList(node2);
    Node* node3 = newNodeWithValue(3);
    insertNodeAtEndOfList(node3);
    printListFromStartingNode();
    
    int target = 2;
    int queryResult = getIndexFromPointer(searchListForIntFromStartingNode(&target));
    printf("Found target %d at index %d\n", target, queryResult);
    
    removeNodeByPointer(node2);
    printListFromStartingNode();
    
    queryResult = getIndexFromPointer(searchListForIntFromStartingNode(&target));
    printf("Found target %d at index %d\n", target, queryResult);
    
    deallocateList();
    printListFromStartingNode();
    
    return 0;
}

void printListFromStartingNode(){
    Node* query = head;
    if (query == NULL){
        printf("NO LIST");
    }
    while(query != NULL){
        printf("%d\n", query->value);
        query = query->next;
    }
}

Node* searchListForIntFromStartingNode(int *target){
    Node* query = head;
    while (query->value != *target){
        if (query->next == NULL){
            return NULL;
        }else{
            query = query->next;
        }
    }
    return query;
}

void insertNodeAtEndOfList(Node* thisNode){
    if (head == NULL){
        head = thisNode;
    } else {
        Node* query = head;
        while (query->next != NULL){
            query = query->next;
        }
        query->next = thisNode;
    }
}

void removeNodeByPointer(Node* target){
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

void deallocateList (){
    while(head != NULL){
        removeNodeByPointer(head);
    }
}

int getIndexFromPointer (Node* target){
    Node * query = head;
    int count = 0;
    while (query != target){
        if (query->next == NULL){
            return -1;
        } else {
            count++;
            query = query->next;
        }
    }
    return count;
}