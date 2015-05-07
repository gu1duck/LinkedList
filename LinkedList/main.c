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

int main(int argc, const char * argv[]) {
    
    Node node0;
    node0.value = 1;
    
    Node node1;
    node1.value = 2;
    node0.next = &node1;
    
    Node node2;
    node2.value = 3;
    node1.next = &node2;
    
    printListFromStartingNode(&node0);
    
    newNodeAtEndOfListDefinedByNode(&node0, 4);
    
    int query = 4;
    Node* searchResult = searchListForIntFromStartingNode(&query, &node0);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.");
    }
    
    newNodeAtEndOfListDefinedByNode(&node0, 5);
    
    query = 5;
    searchResult = searchListForIntFromStartingNode(&query, &node0);
    if (searchResult){
        printf("Search result is at list index: %d\n",(searchResult->value-1));
    } else{
        printf("Query is not present.");
    }

    
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