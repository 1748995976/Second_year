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
        printf("请输入数独CNF文件名称(.cnf)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
        strcat(file_name, file_type);
        fp_1 = fopen(file_name, "r");
        if (!fp_1)
            printf("输入的文件不存在，请重新输入!\n");
        else {
            printf("文件打开成功!\n");
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
    //统计子句数量
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
    //There is at least one number in each entry(格限制):
    for (int x = 0; x <= 8; ++x) {
        for (int y = 0; y <= 8; ++y) {
            for (int z = 1; z <= 9; ++z)
                fprintf(fp_1,"%d ",x * 81 + y * 9+ z);
            fprintf(fp_1,"%d\n",0);
        }
    }
    //Each number appears at most once in each row(行限制):
    for (int y = 0; y <= 8; ++y) {
        for (int z = 1; z <= 9; ++z)
            for (int x = 0; x <= 7; ++x)
                for (int i = x+1; i <= 8; ++i)
                    fprintf(fp_1,"%d %d %d\n",0 - (y*81 + x*9 + z),0 - (y*81 + i*9 + z),0);
    }
    //Each number appears at most once in each column(列限制):
    for (int x = 0; x <= 8; ++x) {
        for (int z = 1; z <=9 ; ++z)
            for (int y = 0; y <= 7; ++y)
                for (int i = y+1; i <= 8; ++i)
                    fprintf(fp_1,"%d %d %d\n",0-(y*81 + x*9 + z),0-(i*81 + x*9 + z),0);
    }
    //Each number appears at most once in each 3x3 sub-grid(九宫格限制):
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
    while (true) {//跳过cnf格式文件的开头部分
        fscanf(fp_1, "%c", &first_word);
        if (first_word == 'c') {
            fgets(words, 99, fp_1);//读取（跳过）注释部分的一整行，若此行字符数目超过99，循环后执行else部分
        } else if (first_word == 'p') {
            fscanf(fp_1, "%s", words);
            break;//开始进入正文信息部分
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
    //依次访问每个子句
    for (int i = 0;; i++) {
        int a;//文字数目
        int b;//正文字数目
        if (i == clause_number) {
            free(headClauseLink);
            lastClauseLink->next_clause = NULL;
            fclose(fp_1);
            fp_1 = NULL;
            return clauseLink;
        }
        //为了方便首先在循环外读取第一个文字
        fscanf(fp_1, "%d", &word);
        //为了方便首先在循环外分配一次空间
        headclause = headClauseLink->present_clause = (Clause *) malloc(sizeof(Clause));
        //读取子句中的文字
        for (a = 1, b = 0;; a++) {
            headclause->word = word;
            if (word > 0)
                b++;
            //读取下一个文字
            fscanf(fp_1, "%d", &word);
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
//数独cnf的解都存储在一个一维数组中
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
    //随机填充11个空
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

//挖洞法产生数独
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
                    //先判断是否满足数独基本要求
                    if(!Judge_sudo(sudo1,row,col))
                        continue;
                    //判断结束
                    //判断是否有解
                    Trans_sudo_to_cnf(sudo1);
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
                    for (int p = 0; p < bool_number; ++p) {
                        word_positive_value[p] = -1;//初始化数组
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
    //打印数独游戏
    printf("数独游戏为:\n");
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
    printf("请从第一行第一个开始按行输入你的答案:\n");
    int result[ROW][COL];
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            scanf("%d",&(result[row][col]));
        }
    }
    setbuf(stdin, NULL);//使stdin输入流由默认缓冲区转为无缓冲区
    for (int row = 0; row < ROW; ++row) {
        for (int col = 0; col < COL; ++col) {
            if(sudo->matrix[row][col] != result[row][col]) {
                printf("答案错误!\n");
                return false;
            }
        }
    }
    printf("答案正确!\n");
    return true;
}