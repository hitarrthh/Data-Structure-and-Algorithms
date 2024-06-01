#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

char operatorStack[MAX];
int operatorTop = -1;

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

void pushOperator(char value) {
    if (operatorTop < MAX - 1) {
        operatorStack[++operatorTop] = value;
    } else {
        printf("Operator stack overflow!\n");
        exit(1);
    }
}

char popOperator() {
    if (operatorTop >= 0) {
        return operatorStack[operatorTop--];
    } else {
        printf("Operator stack underflow!\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 0;
    }
}

int evaluateInfix(char* infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isspace(infix[i])) {
            // Skip whitespaces
            continue;
        } else if (isdigit(infix[i])) {
            int operand = 0;
            while (isdigit(infix[i])) {
                operand = operand * 10 + (infix[i] - '0');
                i++;
            }
            i--; // Move back one position after the loop
            push(operand);
        } else if (isOperator(infix[i])) {
            while (operatorTop >= 0 && precedence(operatorStack[operatorTop]) >= precedence(infix[i])) {
                int operand2 = pop();
                int operand1 = pop();
                switch (popOperator()) {
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
            pushOperator(infix[i]);
        } else if (infix[i] == '(') {
            pushOperator(infix[i]);
        } else if (infix[i] == ')') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(') {
                int operand2 = pop();
                int operand1 = pop();
                switch (popOperator()) {
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
            if (operatorTop >= 0 && operatorStack[operatorTop] == '(') {
                popOperator(); // Pop '('
            } else {
                printf("Invalid infix expression!\n");
                exit(1);
            }
        } else {
            printf("Invalid character in infix expression: %c\n", infix[i]);
            exit(1);
        }
    }

    while (operatorTop >= 0) {
        int operand2 = pop();
        int operand1 = pop();
        switch (popOperator()) {
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

    return pop();
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: \n");
    scanf(" %99[^\n]s", infix);

    int result = evaluateInfix(infix);
    printf("Result: %d\n", result);

    return 0;
}
