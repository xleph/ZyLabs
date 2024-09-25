#include <stdlib.h>
#include <stdio.h>

struct node {
double val;
int n;
struct node *next;
};

double randd() {
return rand() * 1.0 / 0x7FFFFFFF;
}

int main (int argc, char **argv) {
int nsize = sizeof(struct node);
srand((int)malloc(1));
int num = atoi(argv[1]);
int enjoyed = 1;
char found = 0;
struct node *ref, *walk;
struct node *head = malloc(nsize);
             head->val = -1;
             head->n   = -1;
             head->next = malloc(nsize);
                          head->next->val  = randd();
                          head->next->n    =   0;
                          head->next->next =   0;
	for (int i = 0; i < num; i++) {
		ref = malloc(nsize);
		ref->val = randd();
		ref->n = i + 1;
		walk = head;
		found = 0;
		if ((head->next->val) < (ref->val)) {
			enjoyed++;
			ref->next = head->next;
			head->next = ref;
		} else {
			while (walk->next!=0) {
				if ((walk->val) > (ref->val)&&(walk->next->val) < (ref->val)) {
					found |= 1;
					ref->next = walk->next;
					walk->next = ref;
				}
			walk = walk->next;
			}
			if (!found) {
			// printf("Adding to end");
			walk->next = ref;
			ref->next = 0;
			}

		}

	}
	walk = head;
	while (walk->next!=0) {
	printf("%f %d\n", walk->val, walk->n);
	walk = walk->next;
	}

	printf("%d / %d = %f", enjoyed, num, enjoyed * 1.0 / num);
}


/*	int i = 0;
double sum = 0.0;
	for (int i = 0; i < n; i++) {
	sum+=randd();
	}
	printf("%f\n", sum/n);

	while (i < 10000000) {
		if ( rand() * 1.0 / 0x7FFFFFFF < 0) {
		printf("negative encountered!");
		}
	i++;
	}*/
