#include<malloc.h>
#include<stdio.h>

struct node {
	int data;
	struct node *next;
}*head, *temp, *temp2;

void display() {
	temp = head;
	while (temp != 0) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void insert(int i) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
	
    if (head == NULL) {
		temp = new_node;
		temp->data = i;
		temp->next = NULL;
		
		struct node* head = (struct node*) malloc(sizeof(struct node));
		head->next = temp;
	} else {
	    temp = head;
	    while (1) {
	        if (temp->next == NULL) {
        		temp2 = new_node;
        		temp2->data = i;
        		temp2->next = NULL;

        		temp->next = temp2;
        		break;
	        }
	        temp = temp->next;
	    }
	}
}

void insertAtBeginning(int i) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    temp = head->next;
	temp2 = new_node;
	temp2->data = i;
	temp2->next = temp;
	head->next = temp2;
}

void delete() {
	temp2 = head;
	temp = head;

	while (temp != NULL) {
		if (temp->next == NULL) {
			temp2->next = NULL;
			free(temp);
		}
		temp2 = temp;
		temp = temp->next;
	}
}

void deleteFromBeginning() {

}

void main() {
	head = NULL;

	int a, i;
	while (1) {
		printf("1 - insert at end\n2 - insert at beginning\n3 - delete from end\n4 - delete from beginning\n5 - display\nother - exit\n");
		scanf("%d", &a);
		if (a == 1) {
			printf("Enter value : ");
			scanf("%d", &i);
			insert(i);
		} else if (a == 2) {
			printf("Enter value : ");
			scanf("%d", &i);
			insertAtBeginning(i);
		} else if (a == 3) {
			delete();
		} else if (a == 4) {
			deleteFromBeginning();
		} else if (a == 5) {
			display();
		} else {
			break;
		}
	}
}
