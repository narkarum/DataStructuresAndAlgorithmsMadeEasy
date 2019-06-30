# Copyright (c) Dec 22, 2014 CareerMonk Publications and others.
# E-Mail           		: info@careermonk.com 
# Creation Date    		: 2014-01-10 06:15:46 
# Last modification		: 2008-10-31 
#               by		: Narasimha Karumanchi 
# Book Title			: Data Structures And Algorithms Made Easy
# Warranty         		: This software is provided "as is" without any 
# 				   warranty; without even the implied warranty of 
# 				    merchantability or fitness for a particular purpose. 

#include <stdio.h>
#include <stdlib.h>

struct CLLNode{
	int data;
	struct CLLNode* next;
};

struct CLLNode *head = NULL;

//length of the list
int length(struct CLLNode *head) {
    struct CLLNode *current = head;
    int count = 0;
    if(head == NULL) 
        return 0;

    do {      
        current = current->next;
        count++;
    } while (current != head);

    return count;
}

// display list using iteration
void printList(struct CLLNode *head) {
    struct CLLNode *current = head;
    if(head == NULL) 
        return;

    do {      
        printf ("%d-->", current->data);
          current = current->next;
    } while(current != head);
}

// Insert at the beginning of the list 
void insertAtBeginInCLL (struct CLLNode **head, int data){
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *) (malloc(sizeof(struct CLLNode)));
    if(!newNode) { 
        printf("Memory Error"); 
        return;
    }
    newNode->data = data;
    newNode->next = newNode;
    if(current == NULL){
        *head = newNode;
        return;
    }
    
    while (current->next != *head) 
        current = current->next;
        
    newNode->next = *head;
    current->next = newNode;
    *head = newNode;
}

//insert item at the end of the list
void insert_item_at_end(struct CLLNode *head, int item){

	struct CLLNode *newNode;

	newNode = (struct CLLNode*)malloc(sizeof(struct CLLNode));
	newNode->data = item;
	newNode->next = newNode;

	if (head == NULL){

		head = newNode;
		newNode->next = head;
		printf("%d is added at the end of the list! \n", item);
		return;

	} else{
		struct CLLNode *ptr;

		ptr = head;

		while(ptr->next != head){
			ptr = ptr->next;
		}

		ptr->next = newNode;
		printf("%d is added at the end of the list! \n", item);

	}
}



int main(){
    struct CLLNode *head = NULL;
    printf("%d \n",length(head));
    insertAtBeginInCLL(&head, 30);
    insertAtBeginInCLL(&head, 20);
    insertAtBeginInCLL(&head, 10);
    printf("%d \n",length(head));
    printList(head);
    return 0;
}
