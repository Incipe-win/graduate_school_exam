/**
 * 带头结点
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == nullptr) {
        return false;
    }
    L->next = nullptr;
    return true;
}

bool Empty(LinkList L) { return L->next == nullptr; }

LNode *GetElem(LinkList L, int index) {
    if (index < 0) {
        return nullptr;
    }
    LNode *p;
    int i = 0;
    p = L;
    while (p != nullptr && i < index) {
        p = p->next;
        ++i;
    }
    return p;
}

// 在p结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == nullptr) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == nullptr) {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert(LinkList &L, int index, ElemType e) {
    if (index < 1) {
        return false;
    }
    // LNode *p;
    // int i = 0;
    // p = L;
    // while (p != nullptr && i < index - 1) {
    //     p = p->next;
    //     ++i;
    // }
    LNode *p = GetElem(L, index - 1);
    // if (p == nullptr) {
    //     return false;
    // }
    // LNode *s = (LNode *)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // p->next = s;
    // return true;
    return InsertNextNode(p, e);
}

// 前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e) {
    if (p == nullptr) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == nullptr) {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 前插操作：在p结点之前插入结点s
bool InsertPriorNode(LNode *p, LNode *s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }
    s->next = p->next;
    p->next = s;
    ElemType temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

bool ListDelete(LinkList &L, int index, ElemType &e) {
    if (index < 1) {
        return false;
    }
    // LNode *p;
    // int i = 0;
    // p = L;
    // while (p != nullptr && i < index - 1) {
    //     p = p->next;
    //     ++i;
    // }
    LNode *p = GetElem(L, index - 1);
    if (p == nullptr) {
        return false;
    }
    if (p->next == nullptr) {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 有bug，如果p结点是最后一个节点，则会出错！
bool DeleteNode(LNode *p) {
    if (p == nullptr) {
        return false;
    }
    LNode *q = p->next;
    p->data = p->next->data; // bug
    p->next = q->next;
    free(q);
    return true;
}

LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}

int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != nullptr) {
        p = p->next;
        ++len;
    }
    return len;
}

LinkList ListTailInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = nullptr;
    return L;
}

LinkList ListHeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

int main() {
    LinkList L;
    InitList(L);
    return 0;
}