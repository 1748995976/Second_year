//
// Created by wzc-1748995976 on 2019/3/4.
//

#include <mem.h>
#include <malloc.h>
#include <time.h>
#include "sudoku.h"
#include "dpll.h"

FILE *fp_1 = NULL;

bool Read_sudo(Sudo *sudo){
    char file_name[60];
    char file_type[] = ".cnf";
    while (true) {
        printf("����������CNF�ļ�����(.cnf)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        strcat(file_name, file_type);
        fp_1 = fopen(file_name, "r");
        if (!fp_1)
            printf("������ļ������ڣ�����������!\n");
        else {
            printf("�ļ��򿪳ɹ�!\n");
            break;
        }
    }
    char a;
    for (int x = 0; x < ROW; ++x) {
        for (int y = 0; y < COL; ++y) {
            fscanf(fp_1,"%c",&a);
            sudo->matrix[x][y] = a - '0';
        }
        fscanf(fp_1,"%c",&a);
    }
    fclose(fp_1);
    fp_1 = NULL;
    return true;
}

bool Trans_sudo_to_cnf(Sudo *sudo){
    char file_name[60] = "qsx.cnf\0";
    fp_1 = fopen(file_name, "w");
    if (!fp_1)
        exit(0);
    int bool_number = 729;
    int clause_number = 8829;
    //ͳ���Ӿ�����
    for (int x = 0; x < ROW; ++x) {
        for (int y = 0; y < COL; ++y) {
            if (sudo->matrix[x][y] != 0) {
                clause_number++;
            }
        }
    }
    fprintf(fp_1,"p cnf %d %d\n",bool_number,clause_number);
    //single clause
    for (int x = 0; x < ROW; ++x) {
        for (int y = 0; y < COL; ++y) {
            if (sudo->matrix[x][y] != 0) {
                fprintf(fp_1, "%d %d\n", x * 81 + y * 9 + sudo->matrix[x][y], 0);
                clause_number++;
            }
        }
    }
    //There is at least one number in each entry(������):
    for (int x = 0; x <= 8; ++x) {
        for (int y = 0; y <= 8; ++y) {
            for (int z = 1; z <= 9; ++z)
                fprintf(fp_1,"%d ",x * 81 + y * 9+ z);
            fprintf(fp_1,"%d\n",0);
        }
    }
    //Each number appears at most once in each row(������):
    for (int y = 0; y <= 8; ++y) {
        for (int z = 1; z <= 9; ++z)
            for (int x = 0; x <= 7; ++x)
                for (int i = x+1; i <= 8; ++i)
                    fprintf(fp_1,"%d %d %d\n",0 - (y*81 + x*9 + z),0 - (y*81 + i*9 + z),0);
    }
    //Each number appears at most once in each column(������):
    for (int x = 0; x <= 8; ++x) {
        for (int z = 1; z <=9 ; ++z)
            for (int y = 0; y <= 7; ++y)
                for (int i = y+1; i <= 8; ++i)
                    fprintf(fp_1,"%d %d %d\n",0-(y*81 + x*9 + z),0-(i*81 + x*9 + z),0);
    }
    //Each number appears at most once in each 3x3 sub-grid(�Ź�������):
    for (int z = 1; z <= 9 ; ++z) {
        for (int i = 0; i <=2 ; ++i)
            for (int j = 0; j <=2 ; ++j)
                for (int x = 1; x <= 3 ; ++x)
                    for (int y = 1; y <= 2; ++y)
                        for (int k = y+1; k <= 3; ++k)
                            fprintf(fp_1,"%d %d %d\n",0 - (((3*i+x)-1)*81 + ((3*j+y)-1)*9 + z),0-(((3*i+x)-1)*81 + ((3*j+k)-1)*9 + z),0);
    }
    for (int z = 1; z <= 9; z++) {
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                for (int x = 1; x <= 2; x++)
                    for (int y = 1; y <= 3; y++)
                        for (int k = x + 1; k <= 3; k++)
                            for (int l = 1; l <= 3; l++)
                                fprintf(fp_1,"%d %d %d\n",0 - (((3*i+x)-1)*81 + ((3*j+y)-1)*9 + z),0 - (((3*i+k)-1)*81 + ((3*j+l)-1)*9 + z),0);
    }
    fclose(fp_1);
    return true;
}

ClauseLink *Read_sudo_cnf(int *bool_number){
    fp_1 = fopen("qsx.cnf","r");
    ClauseLink *lastClauseLink;
    ClauseLink *headClauseLink;
    ClauseLink *clauseLink;
    Clause *headclause;
    char words[100];
    char first_word;
    while (true) {//����cnf��ʽ�ļ��Ŀ�ͷ����
        fscanf(fp_1, "%c", &first_word);
        if (first_word == 'c') {
            fgets(words, 99, fp_1);//��ȡ��������ע�Ͳ��ֵ�һ���У��������ַ���Ŀ����99��ѭ����ִ��else����
        } else if (first_word == 'p') {
            fscanf(fp_1, "%s", words);
            break;//��ʼ����������Ϣ����
        } else
            fgets(words, 99, fp_1);
    }
    *bool_number = 0;
    fscanf(fp_1, "%d", bool_number);
    int clause_number = 0;
    int word = 0;
    fscanf(fp_1, "%d", &clause_number);
    clauseLink = lastClauseLink = headClauseLink = (ClauseLink *) malloc(sizeof(ClauseLink));
    clauseLink -> last_clause = NULL;
    //���η���ÿ���Ӿ�
    for (int i = 0;; i++) {
        int a;//������Ŀ
        int b;//��������Ŀ
        if (i == clause_number) {
            free(headClauseLink);
            lastClauseLink->next_clause = NULL;
            fclose(fp_1);
            fp_1 = NULL;
            return clauseLink;
        }
        //Ϊ�˷���������ѭ�����ȡ��һ������
        fscanf(fp_1, "%d", &word);
        //Ϊ�˷���������ѭ�������һ�οռ�
        headclause = headClauseLink->present_clause = (Clause *) malloc(sizeof(Clause));
        //��ȡ�Ӿ��е�����
        for (a = 1, b = 0;; a++) {
            headclause->word = word;
            if (word > 0)
                b++;
            //��ȡ��һ������
            fscanf(fp_1, "%d", &word);
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
//����cnf�Ľⶼ�洢��һ��һά������
bool Trans_cnf_to_sudo(Sudo *sudo, int *word_positive_value,int bool_number){
    int result[ROW * COL];
    for (int j = 0; j < bool_number; ++j) {
        if(word_positive_value[j] == 0)
            word_positive_value[j] = -(j+1);
        else if(word_positive_value[j] == 1)
            word_positive_value[j] = j + 1;
        else if(word_positive_value[j] == -1)
            return false;
    }
    for (int i = 0,a = 0; i < bool_number; ++i) {
        if (word_positive_value[i] > 0) {
            result[a] = word_positive_value[i] % 9;
            if (!result[a])
                result[a] = 9;
            a++;
        }
    }
    for(int row = 0;row < ROW;++row){
        for (int col = 0; col < COL; ++col) {
            sudo->matrix[row][col] = result[9*row + col];
        }
    }
    return true;
}

bool Produce_sudo(Sudo *sudo){
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            sudo->matrix[row][col] = 0;
        }
    }
    srand((unsigned)time(NULL));
    //������11����
    for (int i = 0; i < 11; i++) {
        int keyword = rand() % 729;
        int row = keyword / 81;
        int col = (keyword % 81) / 9;
        int data = keyword % 9 + 1;
        sudo->matrix[row][col] = data;
    }
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            if(sudo->matrix[row][col] != 0){
                for (int j = 0; j < COL; ++j) {
                    if(sudo->matrix[row][col] == sudo->matrix[row][j] && j != col)
                        return false;
                }
                for (int i = 0; i < ROW; ++i) {
                    if(sudo->matrix[row][col] == sudo->matrix[i][col] && i != row)
                        return false;
                }
                for (int i = (row/3)*3; i < (row/3)*3 + 3; ++i) {
                    for (int j = (col/3)*3; j < (col/3)*3 + 3; ++j) {
                        if(sudo->matrix[row][col] == sudo->matrix[i][j] && (i != row || j != col))
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Judge_sudo(Sudo *sudo,int row,int col){
    if(sudo->matrix[row][col] != 0){
        for (int j = 0; j < COL; ++j) {
            if(sudo->matrix[row][col] == sudo->matrix[row][j] && j != col)
                return false;
        }
        for (int i = 0; i < ROW; ++i) {
            if(sudo->matrix[row][col] == sudo->matrix[i][col] && i != row)
                return false;
        }
        for (int i = (row/3)*3; i < (row/3)*3 + 3; ++i) {
            for (int j = (col/3)*3; j < (col/3)*3 + 3; ++j) {
                if(sudo->matrix[row][col] == sudo->matrix[i][j] && (i != row || j != col))
                    return false;
            }
        }
    }
    return true;
}

//�ڶ�����������
bool Generate_sudo(Sudo *sudo){
    Sudo *sudo1 = (Sudo*)malloc(sizeof(Sudo));
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            sudo1->matrix[row][col] = sudo->matrix[row][col];
        }
    }
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            int i = 1;
            for (; i <= 9 ; ++i) {
                if(i != sudo->matrix[row][col]){
                    sudo1->matrix[row][col] = i;
                    //���ж��Ƿ�������������Ҫ��
                    if(!Judge_sudo(sudo1,row,col))
                        continue;
                    //�жϽ���
                    //�ж��Ƿ��н�
                    Trans_sudo_to_cnf(sudo1);
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
                    for (int p = 0; p < bool_number; ++p) {
                        word_positive_value[p] = -1;//��ʼ������
                    }
                    if (DPLL(&clauseLink,word_positive_value,&stack,degree,bool_number))
                        break;
                    else
                        continue;
                }
            }
            if (i == 10)
                sudo1->matrix[row][col] = 0;
            else
                sudo1->matrix[row][col] = sudo->matrix[row][col];
        }
    }
    //��ӡ������Ϸ
    printf("������ϷΪ:\n");
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            printf("%d ",sudo1->matrix[row][col]);
            if(col == 2 || col == 5)
                printf("|");
        }
        printf("\n");
        if(row == 2 || row == 5)
            printf("- - - - - - - - - - -\n");
    }
    free(sudo1);
    return true;
}

bool Read_result(Sudo *sudo){
    printf("��ӵ�һ�е�һ����ʼ����������Ĵ�:\n");
    int result[ROW][COL];
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            scanf("%d",&(result[row][col]));
        }
    }
    setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            if(sudo->matrix[row][col] != result[row][col]) {
                printf("�𰸴���!\n");
                return false;
            }
        }
    }
    printf("����ȷ!\n");
    return true;
}