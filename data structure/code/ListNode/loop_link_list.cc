#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

using ElemType = int;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == nullptr) {
        return false;
    }
    L->next = L;
    return true;
}

bool Empty(LinkList L) { return L->next == L; }

bool isTail(LinkList L, LNode *p) { return p->next == L; }