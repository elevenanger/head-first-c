/*
 * @author 刘昂林 
 * @date 2022/8/22
 * @brief 岛屿群
 * 链表结构
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 链表保存了一条数据和一个链向另一条数据的链接
 * 如果一个结构包含一个链向同种结构的链接
 * 这个结构就被成为递归结构
 */
typedef struct {
    char *name;
    struct island *next;
} island;

// 在 C 语言中 NULL 的值为0， NULL 专门用于将某个指针设为 0
island amity = {"Amity", NULL};
island craggy = {"Craggy", NULL};
island shutter = {"Shutter", NULL};
island skull = {"Skull", NULL};

void init_islands() {
    amity.next = &craggy;
    craggy.next = &shutter;
    // 在 amity 和 craggy 中插入 skull
    amity.next = &skull;
    skull.next = &craggy;
}

void display(island *start) {
    island *i = start;
    /*
     * 每次循环跳到下一座岛屿
     * 一直循环直到当前的 island 没有 next 值
     */
    for (; i != NULL ; i = i->next) {
        printf("Island Name : %s\n", i->name);
    }
}

/*
 * 创建 island 结构实例
 * 岛名以指针的形式传递
 */
island* create_island(char *name) {
    // malloc() 在堆内存上分配空间
    island *i = malloc(sizeof(island));
    /*
     * strdup() 在堆上创建空间将字符串拷贝到这个空间中
     * 拷贝 name 的一份副本
     */
    i->name = strdup(name);
    i->next = NULL;
    return i;
}

/*
 * 释放存储器
 */
void release(island *start) {
    island *i = start;
    island *next = NULL;
    for ( ; i->next != NULL; i = next) {
        next = i->next;
        // 首先释放 strdup() 创建的 name 字符串
        free(i->name);
        // 如果先释放 i 则再也找不到 name 去释放了
        free(i);
    }
}

/*
 * 从 stdin 读取数据
 * 创建 island 链表
 */
void create_island_chain() {

    island *start = NULL;
    island *i = NULL;
    island *next = NULL;

    char name[80];

    for (; fgets(name, 80, stdin) ; i = next ) {
        if (strstr(name, "quit"))
            break;
        next = create_island(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }

    display(start);
    release(start);
}


int main() {

    init_islands();

    display(&amity);
    display(&skull);

    create_island_chain();

    return 0;
}