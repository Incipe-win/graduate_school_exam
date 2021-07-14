#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

void InitList(SqList *L) {
    for (int i = 0; i < MAXSIZE; ++i) {
        L->data[i] = 0;
    }
    L->length = 0;
}

void ListPrint(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
}

bool ListInsert(SqList *L, int index, int e) {
    if (index < 1 || index > L->length + 1) {
        return false;
    }
    if (L->length >= MAXSIZE) {
        return false;
    }
    for (int i = L->length; i >= index; --i) {
        L->data[i] = L->data[i - 1];
    }
    L->data[index - 1] = e;
    ++L->length;
    return true;
}

bool ListDelete(SqList *L, int index, int *e) {
    if (index < 1 || index > L->length) {
        return false;
    }
    *e = L->data[index - 1];
    for (int i = index; i < L->length; ++i) {
        L->data[i - 1] = L->data[i];
    }
    --L->length;
    return true;
}

ElemType GetElem(SqList L, int i) { return L.data[i - 1]; }

int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    SqList L;
    InitList(&L);

    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);

    ListPrint(L);

    int e = -1;
    if (ListDelete(&L, 2, &e)) {
        printf("已删除第2个元素, 删除元素的值为=%d\n", e);
    } else {
        printf("位序i不合法， 删除失败\n");
    }

    ListPrint(L);

    printf("第2个元素为=%d\n", GetElem(L, 2));

    int res = LocateElem(L, 3);
    if (res != -1) {
        printf("元素3的位序为=%d\n", res);
    } else {
        printf("没有找到这个元素\n");
    }

    return 0;
}