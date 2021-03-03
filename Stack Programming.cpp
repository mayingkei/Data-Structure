#include <iostream>
#include "stdlib.h"

using namespace std;

typedef struct stackCDT* stackADT;
typedef int stackElementT;
stackADT EmptyStack();
void Push(stackADT stack, stackElementT element);
stackElementT Pop(stackADT stack);
int StackDepth(stackADT stack);
int StackIsEmpty(stackADT stack);

struct stackCDT {
	stackElementT* elements;
	int count;
	int size;
};

stackADT EmptyStack() {
	stackADT stack;
	stack = (stackADT)malloc(sizeof(struct stackCDT));
	stack->elements = (stackElementT*)
		malloc(10 * sizeof(stackElementT));
	stack->count = 0;
	stack->size = 10;
	return stack;
}

void Push(stackADT stack, stackElementT element) {
	if (stack->count == stack->size) {
		stack->size += 10;
		stack->elements = (stackElementT*)realloc(
			stack->elements,
			stack->size * sizeof(stackElementT));
	}
	stack->elements[stack->count] = element;
	(stack->count)++;
}

stackElementT Pop(stackADT stack) {
	(stack->count)--;
	return stack->elements[stack->count];
}
int StackDepth(stackADT stack) {
	return stack->count;
}
int StackIsEmpty(stackADT stack) {
	return (stack->count == 0);
}

int FindParentheses(string s) {
	stackADT stack;
	stack = EmptyStack();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			Push(stack, s[i]);
		else if (s[i] == ')' && !StackIsEmpty(stack))
			Pop(stack);
		else if (s[i] == 'T')
			break;
	}
	return StackDepth(stack);
}

int main(){
	string s = "(()()((T)))";
	int res = FindParentheses(s);
	cout << res;
}