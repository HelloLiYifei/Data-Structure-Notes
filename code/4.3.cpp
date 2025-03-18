#include <iostream>


#define MAXLEN 255
typedef struct {
    char ch[MAXLEN + 1]; // 存储串的一维数组
    int length;          // 串的当前长度
}SString;

#define CHUNKSIZE 80
typedef struct CHUNK{
    char ch[CHUNKSIZE];
    struct CHUNK *next;
}Chunk;

typedef struct {
    Chunk *head;
    Chunk *tail;
    int curlen;
}LString;

int Index_BF(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {   // 主串和子串依次匹配下一个字符
            ++i;
            ++j;
        } else {                    // 主串、子串指针回溯重新开始下一次匹配
            i = i - j + 2;
            j = 1;
        }
    }
    if (j >= T.length) return i - T.length; // 返回匹配的第一个字符的下标
    else return 0;
}

int Index_KMP(SString S, SString T, int pos) {
    int i = pos, j = 1;
    int next[T.length + 1];
    get_next(T, next);
    while (i < S.length && j < T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if (j >= T.length) return i - T.length;
    else return 0;
}

void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}