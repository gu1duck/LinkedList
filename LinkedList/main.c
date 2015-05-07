//
//  main.c
//  LinkedList
//
//  Created by Jeremy Petter on 2015-05-06.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>

typedef struct Node Node;
struct Node {
    int value;
    Node* next;
};

void printListFromStartingNode(Node *thisNode);
Node* searchListForIntFromStartingNode(int *query, Node *thisNode);

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
    
    int query = 3;
    Node* searchResult = searchListForIntFromStartingNode(&query, &node0);
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

