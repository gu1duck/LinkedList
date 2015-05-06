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

int main(int argc, const char * argv[]) {
    
    Node node0;
    node0.value = 1;
    
    Node node1;
    node1.value = 2;
    node0.next = &node0;
    
    Node node2;
    node2.value = 3;
    node2.next = &node1;
    
    
    return 0;
}
