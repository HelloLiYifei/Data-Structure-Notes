#include <iostream>
#include <stdlib.h>

// using namespace std;

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
typedef struct {
    ElemType elem[LIST_INIT_SIZE];
    int length; // 当前长度
} SqList;

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

// InitList(&L);          // 初始化擦欧总，建立一个空的线性表L
// DestoryList(&L);       // 销毁已存在的线性表L
// ClearList(&L);         // 将线性表L重置为空表
// ListInsert(&L, i, e);  // 在线性表L中第i个位置插入新元素e
// ListDelete(&L, i, &e); // 删除线性表L中第i个位置元素，并用e返回其值
// IsEmpty(L);            // 若L为空表，则返回TRUE，否则返回FALSE
// ListLength(L);         // 返回L中元素个数
// LocateElem(L, e);      // L中查找给定值e相等的元素，若成功返回该元素在线性表中的序号，否则返回0
// GetElem(L, i, &e);     // 将线性表L中的第i个位置元素返回给e

Status InitList_Sq(SqList &L)
{                                       // 构造一个空的顺序表L
    L.elem = new ElemType[MAXSIZE];     // 为顺序表分配一个大小为MAXSIZE的数组空间
    if (!L.elem) { exit(OVERFLOW); }    // 存储分配失败退出
    L.length = 0;                       // 空表长度为0
    return OK;
}
void DestoryList(SqList &L){
    if(L.elem) delete L.elem; // 释放存储空间
}

void ClearList(SqList &L) {
    L.length = 0; // 将线性表的长度置为0 
}

int GetLength(SqList L) {
    return L.length; // 返回L中元素的个数
}

int IsEmpty(SqList L) {
    if(L.length == 0) return 1;
    else return 0;   
}

int GetElem(SqList L, int i, ElemType &e) {
   if( i < 1 || i > L.length) return ERROR;     // 判断i值是否合理，若不合理，返回ERROR
   e = L.elem[i-1];                             // 第i-1的单元存储着第i个数据
   return OK;
}

int LocateElem(SqList L, ElemType e) {
    // 在顺序表L中查找值为e的数据元素，返回其序号
    for(int i = 0; i < L.length; i++)
        if(L.elem[i] == e) return i+1; // 查找成功，返回序号
    return 0; // 查找失败，返回0
}

Status LinkInsert(SqList &L, int i, ElemType e) {
  if (i < 1 || i > L.length + 1) return ERROR; // i值不合法
  if (L.length == MAXSIZE) return ERROR; // 当前存储空间已满
  for (int j = L.length - 1; j >= i - 1; j--)
    L.elem[j + 1] = L.elem[j]; // 插入位置及之后的元素后移
  L.elem[i - 1] = e; // 新元素插入
  ++L.length; // 表长增1
  return OK;
}

Status LinkDelete_Sq(SqList &L, int i) {
    if (i < 1 || i > L.length) return ERROR; // i值不合法
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
    --L.length; // 表长减1
    return OK;
}