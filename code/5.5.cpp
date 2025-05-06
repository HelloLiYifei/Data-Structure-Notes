Status PreOrderTraverse(BiTree T) {
    if (T == NULL) return OK; //空二叉树
    else {
        Visit(T); //访问根结点
        PreOrderTraverse(T->lchild); //递归遍历左子树
        PreOrderTraverse(T->rchild); //递归遍历右子树
    }
}

Status InOrderTraverse(BiTree T) {
    if (T == NULL) return OK; //空二叉树
    else {
        InOrderTraverse(T->lchild); //递归遍历左子树
        Visit(T); //访问根节点
        InOrderTraverse(T->rchild); //递归遍历右子树
    }
}

Status PostOrderTraverse(BiTree T) {
    if (T == NULL) return OK; //空二叉树
    else {
        PostOrderTraverse(T->lchild); //递归遍历左子树
        PostOrderTraverse(T->rchild); //递归遍历右子树
        Visit(T); //访问根节点
    }
}

Status InOrderTraverse(BiTree T) {
    BiTree p; 
    InitStack(S);
    p = T;
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    return OK;
}

/**
 * 对二叉树进行层序遍历
 * 层序遍历是指从树的根节点开始，按照层次顺序依次访问每个节点
 * 
 * @param b 指向二叉树根节点的指针
 */
void LevelOrder(BTNode *b) {
    BTNode *p;  // 用于指向当前访问的节点
    SqQueue *qu;  // 创建一个队列用于存储待访问的节点
    InitQueue(qu);  // 初始化队列
    enQueue(qu, b);  // 将根节点入队
    while(!QueueEmpty(qu)) {
        deQueue(qu, p);  // 出队一个节点
        printf("%c", p->data);  // 访问当前节点的数据
        if (p->lchild) enQueue(qu, p->lchild);  // 如果当前节点有左孩子，则将左孩子入队
        if (p->rchild) enQueue(qu, p->rchild);  // 如果当前节点有右孩子，则将右孩子入队
    }
}

Status CreatBiTree(BiTree &T) {
    scanf(&ch); 
    if (ch == "#") T=NULL;
    else {
        if(!(T=BiTNode*)malloc(sizeof(BiTNode)))    //T = new BiTNode;
            exit(OVERFLOW); 
        T->data = ch;   //生成根节点
        CreatBiTree(T->lchild);   //生成左子树
        CreatBiTree(T->rchild);   //生成右子树
    }
    return OK;
}

int Copy(BiTree T, BiTree &NewT) {
    if (T == NULL) {  //空树返回0
        NewT = NULL;
        return 0;
    } else {
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}

int Depth(BiTree T) {
    if(T == NULL) return 0;
    else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if (m > n) return m + 1;
        else return n + 1;
    }
}

int NodeCount(BiTree T) {
    if (T == NULL) return 0;
    else reutrn NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int LeadCount(BiTree T) {
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL) return 1;
    else return LeadCount(T->lchild) + LeadCount(T->rchild);
}

typedef struct BiThrNode {
    int data;
    int ltag, rtag;
    struct BiThrNode *lchild, *rchild;
} BiThrNode, *BiThrTree;