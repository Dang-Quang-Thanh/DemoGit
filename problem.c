#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROBLEMS 10

typedef struct {
    int num1;
    int num2;
    char op;
    int answer;
} Problem;

Problem queue[MAX_PROBLEMS]; 
int front = 0, rear = 0;


Problem generateProblem() {
    Problem p;
    int operators[] = {'+', '-', '*', '/'};
    
    p.num1 = rand() % 100 + 1; 
    p.num2 = rand() % 100 + 1;
    p.op = operators[rand() % 4]; 
    
    
    switch (p.op) {
        case '+': p.answer = p.num1 + p.num2; break;
        case '-': p.answer = p.num1 - p.num2; break;
        case '*': p.answer = p.num1 * p.num2; break;
        case '/': p.answer = p.num2 != 0 ? p.num1 / p.num2 : 0; break;
    }
    return p;
}


void enqueue(Problem p) {
    if (rear < MAX_PROBLEMS) {
        queue[rear++] = p;
    }
}


void askProblem(Problem p) {
    int userAnswer;
    printf("Solve: %d %c %d = ?\n", p.num1, p.op, p.num2);
    scanf("%d", &userAnswer);

    if (userAnswer == p.answer) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
}

void solve() {
    int n;
    printf("Enter number of problems: ");
    scanf("%d", &n);

    srand(time(NULL)); 

    for (int i = 0; i < n; i++) {
        Problem p = generateProblem();
        askProblem(p);
        enqueue(p);
    }

    printf("\nRevisiting stored problems:\n");
    for (int i = front; i < rear; i++) {
        askProblem(queue[i]);
    }
}

int main() {
    solve();
    return 0;
}