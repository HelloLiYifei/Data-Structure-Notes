#define MAXSIZE 100
typedef struct {
    SElemType *base;    // 栈底指针
    SElemType *top;     // 栈顶指针
    int stacksize;      // 栈可用最大容量
}SqStack;

Status InitStack(SqStack &S) {
    S.base = new SElemType[MAXSIZE];    // S.base = (SElemType *)malloc(MAXSIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);        // 存储分配失败
    S.top = S.base;                     // 栈顶指针等于栈底指针
    S.stacksize = MAXSIZE;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.top == S.base) { return TRUE; }
    return FALSE;
}

int StackLength(SqStack S) {
    return S.top - S.base;
}

Status ClearStack(SqStack &S) {
    if (S.base) S.top = S.base;
    return OK;
}

Status DestoryStack(SqStack &S) {
    if (S.base) {
        delete[] S.base;
        S.base = S.top = NULL;
        S.stacksize = 0;
    }
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) { return ERROR; }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) { return ERROR; }
    e = *--S.top;
    return OK;
}

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;
LinkStack S;

void InitStack(LinkStack &S) {
    S=NULL;
    return OK;
}

Status StackEmpty(LinkStack S) {
    if (S == NULL) return TRUE;
    else return FALSE;
}

Status Push(LinkStack &S, SElemType e) {
    p=new StackNode;    //生成新结点p
    p->data=e;          //将新结点数据域置为e
    p->next=S;          //将新结点插入栈顶
    S=p;                //修改栈顶指针
    return OK;
}

Status Pop (LinkStack &S, SElemType &e) {
    if (S==NULL) return ERROR;
    e = s->data;
    p = s;
    S = s->next;
    delete p;
    return OK;
}

SElemtype GetTop(LinkStack S) {
    if (S != NULL) {
        return S->data;
    }
}

