#define MAXSIZE 1000 // 多项式可能达到的最大长度

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