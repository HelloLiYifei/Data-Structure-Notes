#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
// Status 函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;


typedef struct
{            // 多项式非零项的定义
    float p; // 系数
    int e;   // 指数
} Polynomial;

typedef struct
{
    Polynomial *elem; // 存储空间的基地址
    int length;       // 多项式当前长度
} SqList;             // 多项式的顺序存储结构为SqList
void union(List &La, List &Lb) {
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for (int i = 1; i <= Lb_len; i ++) {
        GetElem(Lb, i, e);
        if (!LocateElem(La, e)) ListInsert(&La, ++La_len, e);
    }
}

void MergeList_Sq(SqList &La, SqList &Lb, SqList &Lc) {
    pa = La.elem;
    pb = Lb.elem;
    Lc.length = La.length + Lb.length;
    Lc.elem = new ElemType[Lc.length];
    pc = Lc.elem;
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) { *pc++ = *pa++; }
        else { *pc++ = *pb++; }
    }
    while (pa <= pa_last) { *pc++ = *pa++; }
    while (pb <= pb_last) { *pc++ = *pb++; }
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) { 
            pc->next = pa;
            pc = pa;
            pa = pa->next; 
        }
        else { 
            pc->next = pb;
            pc = pb;
            pb = pb->next; 
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
}