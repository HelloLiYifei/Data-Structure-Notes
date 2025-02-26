// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
// Status 函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

#define MAXSIZE 100 // 顺序表可能达到的最大长度


typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;


Status ListInsert_DuL(DuLinkList &L, int i, ElemType e) {
    DuLNode *p;
    if (!(p = GetElem_DuL(L, i))) { return ERROR; }
    DuLNode *s = new DuLNode;
    s->data = e;
    s->next = p->next;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
    DuLNode *p;
    if (!(p = GetElem_DuL(L, i))) { return ERROR; }
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return OK;
}