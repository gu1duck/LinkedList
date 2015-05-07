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
void newNodeAtEndOfListDefinedByNode(Node* thisNode, int value);
void removeNodeByPointer(Node* target, Node* head);

int main(int argc, const char * argv[]) {
    
    Node node0;
    node0.value = 1;
    
    //Node* head = &node0;
    
    Node node1;
    node1.value = 2;
    node0.next = &node1;
    
    Node node2;
    node2.value = 3;
    node1.next = &node2;
    
    Node* head = &node0;
    
    printListFromStartingNode(head);
    
    newNodeAtEndOfListDefinedByNode(head, 4);
    
    int query = 4;
    Node* searchResult = searchListForIntFromStartingNode(&query, head);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.\n");
    }
    printListFromStartingNode(head);
    
    newNodeAtEndOfListDefinedByNode(head, 5);
    
    query = 5;
    searchResult = searchListForIntFromStartingNode(&query, head);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.\n");
    }
    printListFromStartingNode(head);
    
    removeNodeByPointer(node2.next, head);
    
    query = 5;
    searchResult = searchListForIntFromStartingNode(&query, head);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.\n");
    }
    printListFromStartingNode(head);
    
    removeNodeByPointer(node2.next, head);
    
    query = 5;
    searchResult = searchListForIntFromStartingNode(&query, head);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.\n");
    }
    printListFromStartingNode(head);

    
    return 0;
}

void printListFromStartingNode(Node *thisNode){
    printf("%d\n", thisNode->value);
    if (thisNode->next){
        printListFromStartingNode(thisNode->next);
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

void newNodeAtEndOfListDefinedByNode(Node* thisNode, int value){
    if (thisNode->next){
        newNodeAtEndOfListDefinedByNode(thisNode->next, value);
    } else {
        thisNode->next = malloc(sizeof(Node));
        thisNode->next->value = value;
    }
    
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