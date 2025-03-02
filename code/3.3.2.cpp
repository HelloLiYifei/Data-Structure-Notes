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