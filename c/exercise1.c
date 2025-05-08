#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct node{
	char* value;
	struct node* next;
	struct node* previous;
};

int checkCompilerStatus(){
	printf("Clang seems fine to me!\n");
	return 0;
}

struct node* createDoubleLinkedListNode(char* value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->previous = NULL;
	return newNode;
}

void insertNodeDoubleLinkedList(struct node* head,struct node* newNode){
	assert(head != NULL);
	while(head->next != NULL){
		head = head->next;	
	}
	head->next = newNode;
	newNode->previous = head;
}

struct node* deleteNodeDoubleLinkedList(struct node* head, char* value){
	assert(head != NULL);
	while(head->next != NULL){
		if(strcmp(head->value,value) == 0){
			struct node* toRemove = head;
			if(toRemove->next != NULL){
				toRemove->next->previous = toRemove->previous;
			}
			if(toRemove->previous != NULL){
				toRemove->previous->next = toRemove->next;
			}
			return toRemove;
		}
		head = head->next;
	}
	return NULL;
}

struct node* findNodeDoubleLinkedList(struct node* head, char* value){
	assert(head != NULL);
	while(head->next != NULL){
		if(strcmp(head->value,value) == 0){
			return head;
		}
		head = head->next;
	}
	return NULL;
}


void testDoubleLinkedList(){
	struct node* head = createDoubleLinkedListNode("head");
	assert(strcmp("head",head->value) == 0);
	assert(head->next == NULL);
	assert(head->previous == NULL);

	struct node* newNodeOne = createDoubleLinkedListNode("1");
	insertNodeDoubleLinkedList(head,newNodeOne);
	assert(head->next == newNodeOne);
	assert(newNodeOne->previous == head);
	assert(strcmp(head->next->value,"1") == 0);


	struct node* newNodeTwo = createDoubleLinkedListNode("2");
	insertNodeDoubleLinkedList(head,newNodeTwo);
	deleteNodeDoubleLinkedList(head,"1");
	assert(head->next == newNodeTwo);
	assert(newNodeTwo->previous == head);
	assert(strcmp(head->next->value,"2") == 0);

	assert(strcmp(findNodeDoubleLinkedList(head,"head")->value,"head") == 0);
}

int main(){
	checkCompilerStatus();
	testDoubleLinkedList();
}
