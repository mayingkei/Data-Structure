#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read() {
    List L = (List)malloc(sizeof(struct Node));
    List ptr = L;
    int num = 0;
    scanf("%d", &num);
    ElementType value;
    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->Element = value;
        ptr->Next = tmp;
        ptr = ptr->Next;
    }
    ptr->Next = NULL;
    return L;
}
void Print(List L) {
    List ptr = L;
    while (ptr->Next != NULL) {
        printf("%d ", ptr->Next->Element);
        ptr = ptr->Next;
    }
    printf("\n");
}

List Reverse(List L) {
    //Copy the list
    List copy = (List)malloc(sizeof(struct Node));
    List p1 = L->Next, p2 = copy;
    while (p1 != NULL) {
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->Element = p1->Element;
        p2->Next = tmp;
        p2 = p2->Next;
        p1 = p1->Next;
    }

    //reverse the copied list
    List next = NULL, last = NULL, current = copy->Next;
    while (current != NULL) {
        next = current->Next;
        current->Next = last;
        last = current;
        current = next;
    }

    List L2 = (List)malloc(sizeof(struct Node));
    L2->Next = last;

    return L2;
}

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */
