#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 5          //최대 크기 설정

typedef int element;

typedef struct Stacktype {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* sptr) {
	sptr->top = -1;
}


int is_empty(StackType* sptr) {         //비었는지 확인
	return (sptr->top == -1);
}


int is_full(StackType* sptr) {         //가득찼는지 확인
	return (sptr->top == MAX_STACK_SIZE - 1);
}

void push(StackType* sptr, element item) {
	if (is_full(sptr)) {
		fprintf(stderr, "Stack Overflow\n");
		return;
	}
	else {
		sptr->data[++(sptr->top)] = item;
		printf("Push: %d\n", item);
		printf("Stack elements: ");
		for (int i = 0; i <= sptr->top; i++) {
			printf("%d ", sptr->data[i]);
		}
		printf("\n");
	}
}

element pop(StackType* sptr) {
	if (is_empty(sptr)) {
		fprintf(stderr, "스택이 비었습니다.\n");
		return -1;
	}
	else {
		element temp = sptr->data[(sptr->top)--];
		printf("Pop: %d\n", temp);
		printf("Stack elements: ");
		for (int i = 0; i <= sptr->top; i++) {
			printf("%d ", sptr->data[i]);
		}
		printf("\n");
		return temp;
	}
}

int main() {
	StackType s;
	int rand_num;

	srand(time(NULL));

	init(&s);

	for (int i = 0; i < 30; i++) {
		rand_num = rand() % 100 + 1;
		printf("\n");
		printf("Current rand_num: %d | %s\n", rand_num, (rand_num % 2 == 0) ? "Even" : "Odd");
		if ((rand_num % 2) == 0) {
			push(&s, rand_num);
		}
		else {
			pop(&s);
		}
	}

	return 0;
}
//스택이 push 된 순서대로 출력되며 공백 상태일 때 empty, 포화상태일 때 full이 발생한다.
