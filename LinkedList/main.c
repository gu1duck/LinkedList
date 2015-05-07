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

void printListFromStartingNode(Node *startingNode);

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
    
    
    return 0;
}

void printListFromStartingNode(Node *startingNode){
    printf("%d\n", startingNode->value);
    if (startingNode->next){
        printListFromStartingNode(startingNode->next);
    }
}
