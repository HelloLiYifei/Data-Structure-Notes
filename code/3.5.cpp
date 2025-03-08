#include <iostream>

#define MAXQSIZE 100 // 队列最大长度
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

#define QElemType int

typedef struct {
    QElemType *base; // 初始化的动态分配储存空间
    int front;       // 队头指针
    int rear;        // 队尾指针
}SqQueue;

Status InitQueue(SqQueue &Q) {
    Q.base = new QElemType[MAXQSIZE]; //分配数组空间
    if(!Q.base) {exit(OVERFLOW);}     //分配失败
    Q.front = Q.rear = 0;             //初始化队头、队尾指针
    return OK;
}

int QueueLength(SqQueue Q) {
    return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE); 
}

Status EnQueue(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) { return ERROR; } //队满
    Q.base[Q.rear] = e;                                       //新元素加入队尾
    Q.rear = (Q.rear + 1) % MAXQSIZE;                         //队尾指针+1
    return OK;
}

// Status DeQueue(SqQueue &Q, QElemType &e) {
//     if (Q.front == Q.rear) { return ERROR; } //队空
//     e = Q.base[Q.front];                     //保存队头元素
//     Q.front = (Q.front + 1) % MAXQSIZE;      //队头指针+1
//     return OK;
// }

QElemType GetHead(SqQueue Q) {
    if (Q.front != Q.rear) { return Q.base[Q.front]; }
}

typedef struct Qnode {
    QElemType data;
    struct Qnode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    if (!Q.front) { exit(OVERFLOW); }
    Q.front->next = NULL;
    return OK;
}

Status DestoryQueue(LinkQueue &Q) {
    while(Q.front) {
        QueuePtr p = Q.front->next; 
        delete(Q.front);
        Q.front = p;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p = new QNode;
    if(!p) {exit(OVERFLOW);}
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) { Q.rear = Q.front; }
    delete(p);
    return OK;
}

Status GetHead(LinkQueue Q, QElemType &e) {
    if (Q.front == Q.rear) { return ERROR; }
    e = Q.front->next->data;
    return OK;
}



int main(void) {

    return 0;
}