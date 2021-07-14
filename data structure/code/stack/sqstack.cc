#include <iostream>

using namespace std;

using ElemType = int;

#define MAXSIZE 10

typedef struct SqStack {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack &S) { S.top = -1; }

bool StackEmpty(SqStack S) { return S.top == -1; }

bool Push(SqStack &S, ElemType x) {
    if (S.top == MAXSIZE - 1) {
        return false;
    }
    ++S.top;
    S.data[S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (StackEmpty(S)) {
        return false;
    }
    x = S.data[S.top];
    --S.top;
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (StackEmpty(S)) {
        return false;
    }
    x = S.data[S.top];
    return true;
}

void StackPrint(SqStack S) {
    int res = 0;
    while (!StackEmpty(S)) {
        Pop(S, res);
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < 10; ++i) {
        Push(S, i);
    }
    StackPrint(S);
    return 0;
}