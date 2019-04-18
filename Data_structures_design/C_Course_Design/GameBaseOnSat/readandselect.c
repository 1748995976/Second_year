//
// Created by wzc-1748995976 on 2019/2/28.
//

#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>
#include "readandselect.h"

ClauseLink *ReadFromFile(int *bool_number) {//将文件读取到链表中
    FILE *fp = NULL;
    ClauseLink *lastClauseLink;
    ClauseLink *headClauseLink;
    ClauseLink *clauseLink;
    Clause *headclause;
    char file_name[60];
    char file_type[] = ".cnf";
    printf("请输入读取文件的名称(.cnf)\n");
    while (true) {
        scanf("%s", file_name);
        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
        strcat(file_name, file_type);
        fp = fopen(file_name, "r");
        if (!fp)
            printf("输入的文件不存在，请重新输入!\n");
        else {
            printf("文件打开成功!\n");
            break;
        }
    }
    char words[100];
    char first_word;
    while (true) {//跳过cnf格式文件的开头部分
        fscanf(fp, "%c", &first_word);
        if (first_word == 'c') {
            fgets(words, 99, fp);//读取（跳过）注释部分的一整行，若此行字符数目超过99，循环后执行else部分
        } else if (first_word == 'p') {
            fscanf(fp, "%s", words);
            break;//开始进入正文信息部分
        } else
            fgets(words, 99, fp);
    }
    *bool_number = 0;
    fscanf(fp, "%d", bool_number);
    int clause_number = 0;
    int word = 0;
    fscanf(fp, "%d", &clause_number);
    clauseLink = lastClauseLink = headClauseLink = (ClauseLink *) malloc(sizeof(ClauseLink));
    clauseLink -> last_clause = NULL;
    //依次访问每个子句
    for (int i = 0;; i++) {
        int a;//文字数目
        int b;//正文字数目
        if (i == clause_number) {
            free(headClauseLink);
            lastClauseLink->next_clause = NULL;
            printf("文件读取成功！\n");
            fclose(fp);
            return clauseLink;
        }
        //为了方便首先在循环外读取第一个文字
        fscanf(fp, "%d", &word);
        //为了方便首先在循环外分配一次空间
        headclause = headClauseLink->present_clause = (Clause *) malloc(sizeof(Clause));
        //读取子句中的文字
        for (a = 1, b = 0;; a++) {
            headclause->word = word;
            if (word > 0)
                b++;
            //读取下一个文字
            fscanf(fp, "%d", &word);
            //判断该子句是否还有下一个文字
            if (word == 0) {
                headclause->next_word = NULL;
                break;
            }
            headclause->next_word = (Clause *) malloc(sizeof(Clause));
            headclause = headclause->next_word;
        }
        //初始化每个从句的状态(从句的正文字数目以及是否可以访问)
        headClauseLink->positive_number = b;
        headClauseLink->number = a;
        headClauseLink->isnew = 0;
        lastClauseLink = headClauseLink;
        headClauseLink->next_clause = (ClauseLink *) malloc(sizeof(ClauseLink));
        headClauseLink->next_clause->last_clause = lastClauseLink;
        headClauseLink = headClauseLink->next_clause;
    }
}