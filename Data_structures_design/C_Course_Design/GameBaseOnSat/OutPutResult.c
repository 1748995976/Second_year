//
// Created by wzc-1748995976 on 2019/3/4.
//
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include "OutPutResult.h"

bool Print_yes_result(int *word_positive_value, int bool_number, double time){
    FILE *fp;
    char file_name[60];
    char file_type[] = ".res";
    while (true) {
        printf("请输入创建生成的CNF文件名称(.res)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
        strcat(file_name, file_type);
        fp = fopen(file_name, "w");
        if (!fp)
            printf("创建文件失败!\n");
        else {
            printf("创建文件成功!\n");
            break;
        }
    }
    fprintf(fp,"s: 1\nv: ");
    for (int i = 1; i <= bool_number; i++) {
        if (word_positive_value[i - 1] == -1)
            fprintf(fp,"*%d ", i);
        else if (word_positive_value[i - 1] == 0)
            fprintf(fp,"-%d ", i);
        else if (word_positive_value[i - 1] == 1)
            fprintf(fp,"%d ", i);
    }
    fprintf(fp,"\nt: %f",time);
    fclose(fp);
    return true;
}

bool Print_no_result(double time){
    FILE *fp;
    char file_name[60];
    char file_type[] = ".res";
    while (true) {
        printf("请输入创建生成的CNF文件名称(.res)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
        strcat(file_name, file_type);
        fp = fopen(file_name, "w");
        if (!fp)
            printf("创建文件失败!\n");
        else {
            printf("创建文件成功!\n");
            break;
        }
    }
    fprintf(fp,"s: 0\nv: \nt: %f",time);
    fclose(fp);
    return true;
}

bool OutPutClause(int *word_positive_value,int *bool_number){
    printf("打印CNF子句需要再次输入一次文件名，请按照提示进行!\n");
    ClauseLink *clauseLink = ReadFromFile(bool_number);
    for (ClauseLink *TemporaryCL = clauseLink;TemporaryCL != NULL;TemporaryCL = TemporaryCL -> next_clause) {
        int a = 0;
        for (Clause *clause = TemporaryCL -> present_clause;clause != NULL; clause = clause -> next_word) {
            printf("%d(",clause->word);
            if(word_positive_value[abs(clause -> word) - 1] == -1){
                printf("*) ");
            }else if(clause -> word > 0){
                printf("%d) ",word_positive_value[clause -> word - 1]);
                if(word_positive_value[clause -> word - 1] == 1)
                    a = 1;
            }else if(clause -> word < 0){
                printf("%d) ",1 - word_positive_value[abs(clause -> word) - 1]);
                if(word_positive_value[abs(clause->word) - 1] == 0)
                    a = 1;
            }
        }
        if(a == 1)
            printf("  ---true");
        else
            printf("  ---false");
        printf("\n");
    }
    return true;
}