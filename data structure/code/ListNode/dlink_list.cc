#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

using ElemType = int;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == nullptr) {
        return false;
    }
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

bool Empty(DLinkList L) { return L->next == nullptr; }

bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }
    s->next = p->next;
    if (p->next != nullptr) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode *p) {
    if (p == nullptr) {
        return false;
    }
    DNode *q = p->next;
    if (q == nullptr) {
        return false;
    }
    p->next = q->next;
    if (q->next != nullptr) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

void DestoryList(DLinkList &L) {
    while (L->next != nullptr) {
        DeleteNextDNode(L);
    }
    free(L);
    L = nullptr;
}

int main() {
    DLinkList L;
    InitDLinkList(L);
    return 0;
}