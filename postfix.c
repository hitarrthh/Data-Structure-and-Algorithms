#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0'); 
        } else if (expression[i] == ' ' || expression[i] == '\t') {
            
        } else {
            int operand2 = pop();
            int operand1 = pop();
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '%':
                    push(operand1 % operand2);
                    break;
            }
        }
    }

    return pop();
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: \n");
    scanf(" %99[^\n]s", expression);
    getchar();  

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
