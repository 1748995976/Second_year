#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "readandselect.h"
#include "dpll.h"
#include "sudoku.h"
#include "OutPutResult.h"


int main() {
    while (true) {
        char a;
        while (true) {
            //用户选择要进行的操作
            printf("请选择你要进行的操作：\n");
            printf("\n");
            printf("      Menu  \n");
            printf("-------------------------------------------------\n");
            printf("    	  0. SAT求解\n");
            printf("    	  1. 标准数独文件求解\n");
            printf("    	  2. 数独游戏\n");
            printf("    	  #. 退出程序\n");
            printf("-------------------------------------------------\n");
            scanf("%c", &a);
            setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
            if (a != '0' && a != '1' && a != '#' && a != '2') {
                printf("输入的选择不合法，回到菜单!\n");
                continue;
            } else
                break;
        }
        //根据用户的选择执行不同的模块
        switch (a) {
            case '0': {
                int bool_number;//布尔变量数量
                int degree = 1;//所在的层
                clock_t start, finish;
                ClauseLink *clauseLink;//子句链表头
                clauseLink = ReadFromFile(&bool_number);
                int word_positive_value[bool_number];//正文字的赋值数组
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                start = clock();
                for (int i = 0; i < bool_number; ++i) {
                    word_positive_value[i] = -1;//初始化数组
                }
                if (DPLL(&clauseLink,word_positive_value,&stack,degree,bool_number)) {
                    printf("1\n");
                    for (int i = 1; i <= bool_number; i++) {
                        if (word_positive_value[i - 1] == -1)
                            printf("*%d ", i);
                        else if (word_positive_value[i - 1] == 0)
                            printf("-%d ", i);
                        else if (word_positive_value[i - 1] == 1)
                            printf("%d ", i);
                    }
                    finish = clock();
                    printf("\nDPLL算法的执行时间为%f毫秒\n", (double) (finish - start) / CLOCKS_PER_SEC*1000);
                    system("pause");
                    printf("是否打印CNF结果?   是：1  否：0\n");
                    char choice;
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
                        if (choice == '1') {
                            Print_yes_result(word_positive_value,bool_number, (double) (finish - start) / CLOCKS_PER_SEC*1000);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("输入的指令不合法，请重新输入!\n");
                    }
                    //人工判断
                    printf("是否人工判断CNF结果?   是(需要再次输入文件名)：1  否：0\n");
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
                        if (choice == '1') {
                            OutPutClause(word_positive_value,&bool_number);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("输入的指令不合法，请重新输入!\n");
                    }
                    system("pause");
                } else {
                    printf("该SAT问题无解!\n");
                    finish = clock();
                    printf("\nDPLL算法的执行时间为%f毫秒\n", (double) (finish - start) / CLOCKS_PER_SEC*1000);
                    system("pause");
                    printf("是否打印CNF结果?   是：1  否：0\n");
                    char choice;
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
                        if (choice == '1') {
                            Print_no_result((double) (finish - start) / CLOCKS_PER_SEC*1000);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("输入的指令不合法，请重新输入!\n");
                    }
                    system("pause");
                }
                //释放多余空间
                free(stack);
                break;
            }
            case '1': {
                Sudo *sudo = (Sudo*)malloc(sizeof(Sudo));
                Read_sudo(sudo);
                Trans_sudo_to_cnf(sudo);
                int bool_number;//布尔变量数量
                int degree = 1;//所在的层
                ClauseLink *clauseLink;//子句链表头
                clauseLink = Read_sudo_cnf(&bool_number);
                int word_positive_value[bool_number];//正文字的赋值数组
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                for (int i = 0; i < bool_number; ++i) {
                    word_positive_value[i] = -1;//初始化数组
                }
                if (DPLL(&clauseLink,word_positive_value,&stack,degree,bool_number)){
                    Trans_cnf_to_sudo(sudo,word_positive_value,bool_number);
                    printf("数独游戏答案为:\n");
                    for (int row = 0; row < ROW; ++row) {
                        for (int col = 0; col < COL; ++col) {
                            printf("%d ",sudo->matrix[row][col]);
                            if(col == 2 || col == 5)
                                printf("|");
                        }
                        printf("\n");
                        if(row == 2 || row == 5)
                            printf("- - - - - - - - - - -\n");
                    }
                }else {
                    printf("数独无解!\n");
                }
                system("pause");
                //释放多余空间
                free(stack);
                break;
            }
            case '2': {
                printf("正在随机生成数独游戏......\n");
                Sudo *sudo = (Sudo*)malloc(sizeof(Sudo));
                int bool_number = 729;//布尔变量数量
                int degree = 1;//所在的层
                ClauseLink *clauseLink;//子句链表头
                int word_positive_value[729];//正文字的赋值数组
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                for (int i = 0; i < 729; ++i) {
                    word_positive_value[i] = -1;//初始化数组
                }
                while(true) {
                    if(Produce_sudo(sudo) && Trans_sudo_to_cnf(sudo)){
                        clauseLink = Read_sudo_cnf(&bool_number);
                        if(!DPLL(&clauseLink,word_positive_value,&stack,degree,bool_number))
                            continue;
                        Trans_cnf_to_sudo(sudo,word_positive_value,bool_number);
                        break;
                    }
                }
                //挖洞法产生
                Generate_sudo(sudo);
                system("pause");
                //读取用户输入并且判断正误
                char c;
                while (true){
                    printf("请选择你的操作: 0: 输入你的答案(需输入完整的数独，格之间用空格隔开) 1: 查看答案\n");
                    scanf("%c",&c);
                    setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
                    if(c == '0'){
                        if(Read_result(sudo))
                            break;
                    } else if(c == '1'){
                        printf("数独游戏答案为:\n");
                        for (int row = 0; row < ROW; ++row) {
                            for (int col = 0; col < COL; ++col) {
                                printf("%d ",sudo->matrix[row][col]);
                                if(col == 2 || col == 5)
                                    printf("|");
                            }
                            printf("\n");
                            if(row == 2 || row == 5)
                                printf("- - - - - - - - - - -\n");
                        }
                        break;
                    } else
                        printf("输入的指令不合法，请重新输入!\n");
                }
                system("pause");
                //释放多余空间
                free(stack);
                break;
            }
            case '#': {
                printf("即将退出程序!感谢您的使用!\n");
                return 0;
            }
        }
    }
}