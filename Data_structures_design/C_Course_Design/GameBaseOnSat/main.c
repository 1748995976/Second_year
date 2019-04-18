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
            //�û�ѡ��Ҫ���еĲ���
            printf("��ѡ����Ҫ���еĲ�����\n");
            printf("\n");
            printf("      Menu  \n");
            printf("-------------------------------------------------\n");
            printf("    	  0. SAT���\n");
            printf("    	  1. ��׼�����ļ����\n");
            printf("    	  2. ������Ϸ\n");
            printf("    	  #. �˳�����\n");
            printf("-------------------------------------------------\n");
            scanf("%c", &a);
            setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
            if (a != '0' && a != '1' && a != '#' && a != '2') {
                printf("�����ѡ�񲻺Ϸ����ص��˵�!\n");
                continue;
            } else
                break;
        }
        //�����û���ѡ��ִ�в�ͬ��ģ��
        switch (a) {
            case '0': {
                int bool_number;//������������
                int degree = 1;//���ڵĲ�
                clock_t start, finish;
                ClauseLink *clauseLink;//�Ӿ�����ͷ
                clauseLink = ReadFromFile(&bool_number);
                int word_positive_value[bool_number];//�����ֵĸ�ֵ����
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                start = clock();
                for (int i = 0; i < bool_number; ++i) {
                    word_positive_value[i] = -1;//��ʼ������
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
                    printf("\nDPLL�㷨��ִ��ʱ��Ϊ%f����\n", (double) (finish - start) / CLOCKS_PER_SEC*1000);
                    system("pause");
                    printf("�Ƿ��ӡCNF���?   �ǣ�1  ��0\n");
                    char choice;
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
                        if (choice == '1') {
                            Print_yes_result(word_positive_value,bool_number, (double) (finish - start) / CLOCKS_PER_SEC*1000);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("�����ָ��Ϸ�������������!\n");
                    }
                    //�˹��ж�
                    printf("�Ƿ��˹��ж�CNF���?   ��(��Ҫ�ٴ������ļ���)��1  ��0\n");
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
                        if (choice == '1') {
                            OutPutClause(word_positive_value,&bool_number);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("�����ָ��Ϸ�������������!\n");
                    }
                    system("pause");
                } else {
                    printf("��SAT�����޽�!\n");
                    finish = clock();
                    printf("\nDPLL�㷨��ִ��ʱ��Ϊ%f����\n", (double) (finish - start) / CLOCKS_PER_SEC*1000);
                    system("pause");
                    printf("�Ƿ��ӡCNF���?   �ǣ�1  ��0\n");
                    char choice;
                    while (true) {
                        scanf("%c", &choice);
                        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
                        if (choice == '1') {
                            Print_no_result((double) (finish - start) / CLOCKS_PER_SEC*1000);
                            break;
                        } else if (choice == '0')
                            break;
                        else
                            printf("�����ָ��Ϸ�������������!\n");
                    }
                    system("pause");
                }
                //�ͷŶ���ռ�
                free(stack);
                break;
            }
            case '1': {
                Sudo *sudo = (Sudo*)malloc(sizeof(Sudo));
                Read_sudo(sudo);
                Trans_sudo_to_cnf(sudo);
                int bool_number;//������������
                int degree = 1;//���ڵĲ�
                ClauseLink *clauseLink;//�Ӿ�����ͷ
                clauseLink = Read_sudo_cnf(&bool_number);
                int word_positive_value[bool_number];//�����ֵĸ�ֵ����
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                for (int i = 0; i < bool_number; ++i) {
                    word_positive_value[i] = -1;//��ʼ������
                }
                if (DPLL(&clauseLink,word_positive_value,&stack,degree,bool_number)){
                    Trans_cnf_to_sudo(sudo,word_positive_value,bool_number);
                    printf("������Ϸ��Ϊ:\n");
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
                    printf("�����޽�!\n");
                }
                system("pause");
                //�ͷŶ���ռ�
                free(stack);
                break;
            }
            case '2': {
                printf("�����������������Ϸ......\n");
                Sudo *sudo = (Sudo*)malloc(sizeof(Sudo));
                int bool_number = 729;//������������
                int degree = 1;//���ڵĲ�
                ClauseLink *clauseLink;//�Ӿ�����ͷ
                int word_positive_value[729];//�����ֵĸ�ֵ����
                Stack *stack = (Stack*)malloc(sizeof(Stack));
                stack->degree = -1;
                stack->wdorsen = -1;
                stack->highstack = NULL;
                stack->word = 0;
                stack->delorchang = NULL;
                for (int i = 0; i < 729; ++i) {
                    word_positive_value[i] = -1;//��ʼ������
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
                //�ڶ�������
                Generate_sudo(sudo);
                system("pause");
                //��ȡ�û����벢���ж�����
                char c;
                while (true){
                    printf("��ѡ����Ĳ���: 0: ������Ĵ�(��������������������֮���ÿո����) 1: �鿴��\n");
                    scanf("%c",&c);
                    setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
                    if(c == '0'){
                        if(Read_result(sudo))
                            break;
                    } else if(c == '1'){
                        printf("������Ϸ��Ϊ:\n");
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
                        printf("�����ָ��Ϸ�������������!\n");
                }
                system("pause");
                //�ͷŶ���ռ�
                free(stack);
                break;
            }
            case '#': {
                printf("�����˳�����!��л����ʹ��!\n");
                return 0;
            }
        }
    }
}