#include <iostream>

// 二叉树顺序存储表示
#define MAXSIZE 100
typedef int Telemtype;
typedef Telemtype SqBiTree[MAXSIZE];
SqBiTree bt;


//二叉链表存储结构
typedef struct BiNode {
    Telemtype data;
    struct BiNode *lchild, *rchild; // 左右孩子指针
}BiNode, *BiTree;

//三叉链表
typedef struct TriTNode {
    Telemtype data;
    struct TriTNode *Ichild, *parent, *rchild;
}TriTNode, *TriTree;

int main(void) {
    return 0;
}