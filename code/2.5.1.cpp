#include <iostream>

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

typedef struct Lnode
{                       // 声明结点的类型和指向结点的指针类型
    ElemType data;      // 结点的数据域
    struct Lnode *next; // 结点的指针域
} Lnode, *LinkList;     // LinkList为指向结构体Lnode的指针类型

Status InitList_L(LinkList &L) {
    L = new Lnode; // 或者 L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    return OK;
}

int ListEmpty(LinkList L) { // 若L为空表，则返回1，否则返回0
    if (L->next)    // 非空
        return 0;
    else
        return 1; 
}

Status DestoryList_L(LinkList &L) { //销毁单链表L
    Lnode *p;
    while(L) {
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

Status ClearList(LinkList &L) { // 将单链表L重置为空表，并释放原链表的结点空间
    Lnode *p, *q;   // 或者 LinkList p, q;
    p = L->next;
    while(p) {   // 没到表尾
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL; // 头结点指针域为空
    return OK;
}

int ListLength(LinkList L) { // 返回L中数据元素个数
    LinkList p;
    p = L->next; // p指向第一个结点
    int i = 0;
    while(p) { // 遍历单链表，统计结点数
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e) { // 用e返回L中第i个数据元素的值
    LinkList p;
    p = L->next; // p指向第一个结点
    int j = 1; // j为计数器
    while(p && j < i) { // 顺链域向后扫描，直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if(!p || j > i) // 第i个元素不存在
        return ERROR;
    e = p->data; // 取第i个元素
    return OK;
}

Lnode *LocateElem(LinkList L, ElemType e) { // 返回L中值为e的数据元素的地址，查找失败返回NULL
    LinkList p;
    p = L->next; // p指向第一个结点
    while(p && p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
        p = p->next;
    return p; // 查找成功返回值为e的结点地址p，查找失败p为NULL
}

//在线性表L中查找值为e的数据元素的位置序号
int LocateElem_L(LinkList L, ElemType e) {
    LinkList p;
    p = L->next; // p指向第一个结点
    int j = 1; // j为计数器
    while(p && p->data != e) { // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
        p = p->next;
        ++j;
    }
    if(p) // 查找成功返回其逻辑序号j
        return j;
    else // 查找失败返回0
        return 0; 
}

Status ListInsert(LinkList &L, int i, ElemType e) {
    LinkList p = L;
    int j = 0;
    while(p && j < i-1) {
        p = p->next;
        ++j;     
    }
    if(!p || j > i-1) // 第i个位置不存在
        return ERROR;       // 插入失败
    Lnode *s = new Lnode;   // 或者 Lnode *s = (Lnode *)malloc(sizeof(Lnode));
    s->data = e;            // 插入结点s
    s->next = p->next;      // s插入在p之后
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    int j = 0;
    while(p->next && j < i-1) {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i-1) // 第i个位置不存在
        return ERROR;       // 删除失败
    Lnode *q = p->next;     // q指向待删除的结点
    p->next = q->next;
    e = q->data;            // 取出待删除结点的值
    delete q;
    return OK;
}

void CreateList_H(LinkList &L, int n) {
    L = new Lnode;
    L->next = NULL;  //建立一个带头结点的单链表
    for (int i = 0; i < n; ++i) {
        Lnode *s = new Lnode;   //生成新节点
        std::cin >> s->data;    //输入数据
        s->next = L->next;      //插入到表头
        L->next = s;            //L指向新节点
    }
}

void CreateList_R(LinkList &L, int n) {
    L = new Lnode;
    L->next = NULL;
    Lnode *r = L;
    for(int i = 0; i < n; ++i) {
        Lnode *s = new Lnode;   //生成新节点
        std::cin >> s->data;    //输入数据
        r->next = s;            //插入到表尾
        r = s;                  //r指向新节点
    }
}

LinkList Connect(LinkList Ta, LinkList Tb) {//假设Ta,Tb都是非空的单循环链表
    Lnode *p = Ta->next;        
    Ta->next = Tb->next->next;  //1o存表头结点
    delete Tb->next;            //2Tb表头连接Ta表尾
    Tb->next = p;               //3释放Tb表头结点
    return Tb;                  //4修改指针
}

int main(void) {

}