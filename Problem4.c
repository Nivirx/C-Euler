#include <stdlib.h>
#include <stdio.h>

struct list {
	struct node* root;
	unsigned int count;
};

struct node {
	struct node* next;
	unsigned int value;
};

unsigned int reverseInt(unsigned int number) {
	int rem = 0;
	int result = 0;
 	while (number > 0) {
		rem = number % 10;
		number = number / 10;
		result = (result * 10) + rem;
	}
	return result;
}

int main (void) {
  unsigned int pali_min = 100*100;
  unsigned int pali_max = 999*999;
  struct list* p = (struct list*)malloc(sizeof(struct list));
  p->root  = 0;
  p->count = 0;
  struct node* current = 0;

  for(unsigned int i = pali_max; i > pali_min; i--){
	if(i == reverseInt(i)){
		if(p->root != 0) {
			current->next = (struct node*)malloc(sizeof(struct node));
			current->next->next = 0;
			p->count++;
			current = current->next;

			current->value = i;
		} else {
			p->root = (struct node*)malloc(sizeof(struct node));
			p->count++;
			current = p->root;
			current->value = i;
		}
	}
  }
  struct node* prev = 0;
  current = p->root;
  printf("Total Palidromes: %d \n", p->count);

  
  for(unsigned int i = p->count; i != 0; i--){
    if(current->next != 0){
	  prev = current;
	  current = current->next;
	  free(prev);
	  p->count--;
    }
  }
  //TODO: factor each palindrome and make sure its the product of 2 three-digit numbers
  free(current);
  free(p);
  return 0;
}
