//
// Created by wzc-1748995976 on 2019/2/28.
//

#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>
#include "readandselect.h"

ClauseLink *ReadFromFile(int *bool_number) {//���ļ���ȡ��������
    FILE *fp = NULL;
    ClauseLink *lastClauseLink;
    ClauseLink *headClauseLink;
    ClauseLink *clauseLink;
    Clause *headclause;
    char file_name[60];
    char file_type[] = ".cnf";
    printf("�������ȡ�ļ�������(.cnf)\n");
    while (true) {
        scanf("%s", file_name);
        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        strcat(file_name, file_type);
        fp = fopen(file_name, "r");
        if (!fp)
            printf("������ļ������ڣ�����������!\n");
        else {
            printf("�ļ��򿪳ɹ�!\n");
            break;
        }
    }
    char words[100];
    char first_word;
    while (true) {//����cnf��ʽ�ļ��Ŀ�ͷ����
        fscanf(fp, "%c", &first_word);
        if (first_word == 'c') {
            fgets(words, 99, fp);//��ȡ��������ע�Ͳ��ֵ�һ���У��������ַ���Ŀ����99��ѭ����ִ��else����
        } else if (first_word == 'p') {
            fscanf(fp, "%s", words);
            break;//��ʼ����������Ϣ����
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
    //���η���ÿ���Ӿ�
    for (int i = 0;; i++) {
        int a;//������Ŀ
        int b;//��������Ŀ
        if (i == clause_number) {
            free(headClauseLink);
            lastClauseLink->next_clause = NULL;
            printf("�ļ���ȡ�ɹ���\n");
            fclose(fp);
            return clauseLink;
        }
        //Ϊ�˷���������ѭ�����ȡ��һ������
        fscanf(fp, "%d", &word);
        //Ϊ�˷���������ѭ�������һ�οռ�
        headclause = headClauseLink->present_clause = (Clause *) malloc(sizeof(Clause));
        //��ȡ�Ӿ��е�����
        for (a = 1, b = 0;; a++) {
            headclause->word = word;
            if (word > 0)
                b++;
            //��ȡ��һ������
            fscanf(fp, "%d", &word);
            //�жϸ��Ӿ��Ƿ�����һ������
            if (word == 0) {
                headclause->next_word = NULL;
                break;
            }
            headclause->next_word = (Clause *) malloc(sizeof(Clause));
            headclause = headclause->next_word;
        }
        //��ʼ��ÿ���Ӿ��״̬(�Ӿ����������Ŀ�Լ��Ƿ���Է���)
        headClauseLink->positive_number = b;
        headClauseLink->number = a;
        headClauseLink->isnew = 0;
        lastClauseLink = headClauseLink;
        headClauseLink->next_clause = (ClauseLink *) malloc(sizeof(ClauseLink));
        headClauseLink->next_clause->last_clause = lastClauseLink;
        headClauseLink = headClauseLink->next_clause;
    }
}