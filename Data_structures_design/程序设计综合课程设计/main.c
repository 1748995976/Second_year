#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mem.h>

#define ROW 9
#define COL 9

typedef struct Sudo{
    int matrix[ROW][COL];
}Sudo;

typedef struct Clause{
    struct Clause * next_word;
    int word;
}Clause;

typedef struct ClauseLink{
    int positive_number;//一行子句中正文字数目
    int number;//一行子句中文字的数目
    int isnew;//子句是不是新创建的
    Clause * present_clause;
    struct ClauseLink * next_clause;
    struct ClauseLink * last_clause;
}ClauseLink;

typedef struct Stack{
    int word;
    int degree;
    int wdorsen;//0:文字  :子句
    struct Stack *highstack;
    ClauseLink *delorchang;
}Stack;

//从cnf文件中读取
ClauseLink * ReadFromFile(int *bool_number);

//处理子句
bool HandleClause(ClauseLink *TempCL,Stack **stack,int word,ClauseLink **clauseLink,int degree);

//恢复子句的状态
bool FlashBack(ClauseLink **clauseLink,Stack **stack,int degree,int *word_positive_value);

//选取决策变量
int Selectword(ClauseLink *clauseLink,int *word_positive_value,int bool_number);

//将决策变量并入子句集
bool MergeWord(ClauseLink **clauseLink,int word);

//DPLL算法核心
bool DPLL(ClauseLink **clauseLink,int *word_positive_value,Stack **stack,int degree,int bool_number);

//输出有解的结果
bool Print_yes_result(int *word_positive_value, int bool_number, double time);

//输出无解的结果
bool Print_no_result(double time);

//打印文件内容以及结果
bool OutPutClause(int *word_positive_value,int *bool_number);

//读取数独文件
bool Read_sudo(Sudo *sudo);

//将数独转换为cnf文件
bool Trans_sudo_to_cnf(Sudo *sudo);

//读取数独cnf文件
ClauseLink *Read_sudo_cnf(int *bool_number);

//将cnf文件转化为数独
bool Trans_cnf_to_sudo(Sudo *sudo, int *word_positive_value, int bool_number);

//产生填充11个空的数独
bool Produce_sudo(Sudo *sudo);

//判断当前数独是否满足数独的基本要求
bool Judge_sudo(Sudo *sudo,int row,int col);

//挖洞法产生数独游戏
bool Generate_sudo(Sudo *sudo);

//读取用户答案并且判断正误
bool Read_result(Sudo *sudo);

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

bool HandleClause(ClauseLink *TempCL,Stack **stack,int word,ClauseLink **clauseLink,int degree){
    if(TempCL->isnew == 0) {
        Clause *lastclause = TempCL -> present_clause;
        for (Clause *clause = TempCL->present_clause; clause != NULL;lastclause = clause, clause = clause->next_word) {
            //消除文字
            if(clause->word + word == 0){
                Stack *stack1 = (Stack*)malloc(sizeof(Stack));
                stack1->delorchang = TempCL;
                stack1->wdorsen = 0;
                stack1->word = word;
                stack1->degree = degree;
                stack1->highstack = *stack;
                *stack = stack1;
                TempCL->number--;
                if(clause->word > 0)
                    TempCL->positive_number--;
                //文字是否位于首位
                if(clause == TempCL->present_clause){
                    TempCL->present_clause = clause-> next_word;
                    //有空间散落
                } else{
                    lastclause->next_word = clause-> next_word;
                    free(clause);
                    clause =lastclause;
                }
                continue;
            }
            //消除子句
            if(clause-> word == word){
                Stack *stack1 = (Stack*)malloc(sizeof(Stack));
                stack1->delorchang = TempCL;
                stack1->wdorsen = 1;
                stack1->word = word;
                stack1->degree = degree;
                stack1->highstack = *stack;
                *stack = stack1;
                if(TempCL -> last_clause == NULL) {
                    *clauseLink = TempCL->next_clause;
                    if(!(*clauseLink))
                        return true;
                    else
                        (*clauseLink)->last_clause = NULL;
                } else {
                    TempCL->last_clause->next_clause = TempCL->next_clause;
                    if(TempCL->next_clause)
                        TempCL->next_clause->last_clause = TempCL->last_clause;
                }
            }
        }
    } else{
        *clauseLink = TempCL-> next_clause;
        if(TempCL->next_clause != NULL)
            (*clauseLink)->last_clause = NULL;
    }
    return true;
}

bool FlashBack(ClauseLink **clauseLink,Stack **stack,int degree,int *word_positive_value){
    while((*stack)->degree == degree){
        word_positive_value[abs((*stack)->word) - 1] = -1;
        if((*stack)->wdorsen == 1){//恢复被删除的子句
            (*stack)->delorchang ->next_clause = *clauseLink;
            (*stack)->delorchang->last_clause = NULL;
            (*clauseLink) -> last_clause = (*stack)->delorchang;
            (*clauseLink) = (*stack)->delorchang;
            Stack *stack1 = *stack;
            (*stack) = (*stack)->highstack;
            free(stack1);
        }else if((*stack)->wdorsen == 0){//恢复被删除的文字
            Clause *clause = (Clause *)malloc(sizeof(Clause));
            clause->word = 0 - (*stack)->word;
            clause->next_word = (*stack)->delorchang->present_clause;
            (*stack)->delorchang ->present_clause = clause;
            (*stack)->delorchang->number++;
            if(clause->word > 0)
                (*stack)->delorchang->positive_number++;
            Stack *stack1 = *stack;
            (*stack) = (*stack)->highstack;
            free(stack1);
        }
    }
    return true;
}

int Selectword(ClauseLink *clauseLink,int *word_positive_value,int bool_number){
    int word = 0;
    for (ClauseLink *temp = clauseLink;temp!= NULL;temp = temp -> next_clause) {
        if(temp->number == temp->positive_number && temp->number != 0){
            word = temp->present_clause->word ;
            break;
        }
    }
    if (word == 0) {//没有最短正子句时赋值
        for (int i = 0; i < bool_number; ++i) {
            if (word_positive_value[i] == -1) {
                word = i + 1;
                break;
            }
        }
    }
    return word;
}

bool MergeWord(ClauseLink **clauseLink,int word){
    //将赋值的文字作为单元子句置于子句集首
    ClauseLink *newclauseLink = (ClauseLink *) malloc(sizeof(ClauseLink));
    newclauseLink->number = 1;
    newclauseLink->isnew = 1;
    if(word > 0)
        newclauseLink -> positive_number = 1;
    else if(word < 0)
        newclauseLink -> positive_number = 0;
    newclauseLink->present_clause = (Clause *) malloc(sizeof(Clause));
    newclauseLink->present_clause->word = word;
    newclauseLink->present_clause->next_word = NULL;
    newclauseLink->next_clause = *clauseLink;
    newclauseLink->last_clause = NULL;
    if(*clauseLink != NULL)
        (*clauseLink)->last_clause = newclauseLink;
    *clauseLink = newclauseLink;
    //结束
    return true;
}

bool DPLL(ClauseLink **clauseLink,int *word_positive_value,Stack **stack,int degree,int bool_number){
    int word;
    while (true){
        word = 0;
        for(ClauseLink *TempCL = *clauseLink;TempCL != NULL;TempCL = TempCL -> next_clause){
            if(TempCL -> number == 1){
                word = TempCL -> present_clause -> word;
                break;
            }
        }
        if(!word)
            break;
        //给文字赋值
        if(word > 0)
            word_positive_value[word - 1] = 1;
        else
            word_positive_value[abs(word) - 1] = 0;
        //赋值结束
        //单子句规则
        for(ClauseLink *TempCL = *clauseLink;TempCL != NULL;TempCL = TempCL -> next_clause){
            HandleClause(TempCL,stack,word,clauseLink,degree);
        }
        //判断
        if(!(*clauseLink))
            return true;//找到了解
        else{
            for(ClauseLink *TempCL = *clauseLink;TempCL != NULL;TempCL = TempCL -> next_clause){
                if(TempCL-> number == 0) {
                    return false;//当前无解
                }
            }
        }
    }
    word = Selectword(*clauseLink,word_positive_value,bool_number);//选取变量
    MergeWord(clauseLink,word);//将变量并入子句集
    if(DPLL(clauseLink,word_positive_value,stack,degree+1,bool_number))
        return true;
    word = -word;
    while ((*stack)->degree > degree)
        FlashBack(clauseLink,stack,(*stack)->degree,word_positive_value);
    MergeWord(clauseLink,word);//将变量并入子句集
    return DPLL(clauseLink,word_positive_value,stack,degree+1,bool_number);
}

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