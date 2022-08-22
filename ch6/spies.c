/*
 * @author 刘昂林 
 * @date 2022/8/22
 * @brief 间谍检测系统
 * 实现二叉树数据结构
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 每个节点包括一个问题
 * 回答 yes 或者 no
 * 每个答案对应一个子节点
 */
typedef struct node {
    char *question;
    struct node *no;
    struct node *yes;
} node;

/**
 * 获取问题答案
 * @param question 问题字符串指针
 * @return 输入答案第一个字母与 'y' 字符是否相等
 */
int yes_or_no(const char *question) {
    char answer[3];
    printf("%s (y/n) : ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

/**
 * 创建 node 实例
 * @param question 问题形参
 * @return 初始化的 node 节点
 */
node* create(const char *question) {
    // 初始化内存空间,创建指针变量指向分配的内存空间
    node *n = malloc(sizeof(node));
    // 拷贝问题字符串
    n->question = strdup(question);
    n->no = NULL; // 初始化两个引用的 node 指针为 NULL
    n->yes = NULL;
    return n;
}

/**
 * 递归释放内存空间
 * @param n 节点
 */
void release(node *n) {
    if (n){
        if (n->no)
            release(n->no);
        if (n->yes)
            release(n->yes);
        if (n->question)
            free(n->question);
        free(n);
    }
}

int main() {
    char question[80];
    char suspect[20];

    /*
     * 初始化问题
     * 和两个嫌犯节点
     */
    node  *start_node = create("嫌犯有没有胡子？");
    start_node->yes = create("张三");
    start_node->no = create("李四");

    node *current;

    do {
        /*
         * 循环开始
         * 将当前节点设置为 start node
         */
        current = start_node;

        while (1) {
            if (yes_or_no(current->question)) {
                if (current->yes){
                    /*
                     * 问题答案为 y
                     * 并且 yes_node 不为空
                     * 则将当前节点设定为 yes_node
                     */
                    current = current->yes;
                } else {
                    /*
                     * 问题答案为 y
                     * yes_node 为空
                     * 则确认烦人
                     */
                    printf("嫌犯确认\n");
                    break;
                }
            } else if (current->no){
                /*
                 * 问题答案为 n
                 * 并且 no_node 不为空
                 * 将当前节点设置为 no_node
                 */
                current = current->no;
            }
            else {
                /*
                 * 问题答案为 no
                 * 并且 no_node 为空
                 * 从 stdin 获取新的嫌疑犯名字
                 */
                printf("谁是嫌疑犯？");
                fgets(suspect, 20, stdin);

                /*
                 * 使用获取到的嫌犯名字创建新的 node
                 * 将 yes_node 设置为新创建的 node
                 */
                node *yes_node = create(suspect);
                current->yes = yes_node;

                /*
                 * 使用当前 node 的 question 创建新的 node
                 * 将 no_node 设置为创建的 node
                 */
                node *no_node = create(current->question);
                current->no = no_node;

                /*
                 * 从 stdin 获取新的问题
                 * 将当前 node 的问题设置为获取到的问题
                 */
                printf("给我一个问题，对于 %s 为真，对于 %s 为假。",
                       suspect, current->question);
                fgets(question, 80, stdin);
                printf("收到问题：%s\n", question);
                free(current->question);
                current->question = strdup(question);
            }
        }
    } while (yes_or_no("再来一次？"));
    printf("嫌疑犯%s\n", suspect);
    release(start_node);
    return 0;
}