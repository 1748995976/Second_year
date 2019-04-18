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
    int positive_number;//һ���Ӿ�����������Ŀ
    int number;//һ���Ӿ������ֵ���Ŀ
    int isnew;//�Ӿ��ǲ����´�����
    Clause * present_clause;
    struct ClauseLink * next_clause;
    struct ClauseLink * last_clause;
}ClauseLink;

typedef struct Stack{
    int word;
    int degree;
    int wdorsen;//0:����  :�Ӿ�
    struct Stack *highstack;
    ClauseLink *delorchang;
}Stack;

//��cnf�ļ��ж�ȡ
ClauseLink * ReadFromFile(int *bool_number);

//�����Ӿ�
bool HandleClause(ClauseLink *TempCL,Stack **stack,int word,ClauseLink **clauseLink,int degree);

//�ָ��Ӿ��״̬
bool FlashBack(ClauseLink **clauseLink,Stack **stack,int degree,int *word_positive_value);

//ѡȡ���߱���
int Selectword(ClauseLink *clauseLink,int *word_positive_value,int bool_number);

//�����߱��������Ӿ伯
bool MergeWord(ClauseLink **clauseLink,int word);

//DPLL�㷨����
bool DPLL(ClauseLink **clauseLink,int *word_positive_value,Stack **stack,int degree,int bool_number);

//����н�Ľ��
bool Print_yes_result(int *word_positive_value, int bool_number, double time);

//����޽�Ľ��
bool Print_no_result(double time);

//��ӡ�ļ������Լ����
bool OutPutClause(int *word_positive_value,int *bool_number);

//��ȡ�����ļ�
bool Read_sudo(Sudo *sudo);

//������ת��Ϊcnf�ļ�
bool Trans_sudo_to_cnf(Sudo *sudo);

//��ȡ����cnf�ļ�
ClauseLink *Read_sudo_cnf(int *bool_number);

//��cnf�ļ�ת��Ϊ����
bool Trans_cnf_to_sudo(Sudo *sudo, int *word_positive_value, int bool_number);

//�������11���յ�����
bool Produce_sudo(Sudo *sudo);

//�жϵ�ǰ�����Ƿ����������Ļ���Ҫ��
bool Judge_sudo(Sudo *sudo,int row,int col);

//�ڶ�������������Ϸ
bool Generate_sudo(Sudo *sudo);

//��ȡ�û��𰸲����ж�����
bool Read_result(Sudo *sudo);

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

bool HandleClause(ClauseLink *TempCL,Stack **stack,int word,ClauseLink **clauseLink,int degree){
    if(TempCL->isnew == 0) {
        Clause *lastclause = TempCL -> present_clause;
        for (Clause *clause = TempCL->present_clause; clause != NULL;lastclause = clause, clause = clause->next_word) {
            //��������
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
                //�����Ƿ�λ����λ
                if(clause == TempCL->present_clause){
                    TempCL->present_clause = clause-> next_word;
                    //�пռ�ɢ��
                } else{
                    lastclause->next_word = clause-> next_word;
                    free(clause);
                    clause =lastclause;
                }
                continue;
            }
            //�����Ӿ�
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
        if((*stack)->wdorsen == 1){//�ָ���ɾ�����Ӿ�
            (*stack)->delorchang ->next_clause = *clauseLink;
            (*stack)->delorchang->last_clause = NULL;
            (*clauseLink) -> last_clause = (*stack)->delorchang;
            (*clauseLink) = (*stack)->delorchang;
            Stack *stack1 = *stack;
            (*stack) = (*stack)->highstack;
            free(stack1);
        }else if((*stack)->wdorsen == 0){//�ָ���ɾ��������
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
    if (word == 0) {//û��������Ӿ�ʱ��ֵ
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
    //����ֵ��������Ϊ��Ԫ�Ӿ������Ӿ伯��
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
    //����
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
        //�����ָ�ֵ
        if(word > 0)
            word_positive_value[word - 1] = 1;
        else
            word_positive_value[abs(word) - 1] = 0;
        //��ֵ����
        //���Ӿ����
        for(ClauseLink *TempCL = *clauseLink;TempCL != NULL;TempCL = TempCL -> next_clause){
            HandleClause(TempCL,stack,word,clauseLink,degree);
        }
        //�ж�
        if(!(*clauseLink))
            return true;//�ҵ��˽�
        else{
            for(ClauseLink *TempCL = *clauseLink;TempCL != NULL;TempCL = TempCL -> next_clause){
                if(TempCL-> number == 0) {
                    return false;//��ǰ�޽�
                }
            }
        }
    }
    word = Selectword(*clauseLink,word_positive_value,bool_number);//ѡȡ����
    MergeWord(clauseLink,word);//�����������Ӿ伯
    if(DPLL(clauseLink,word_positive_value,stack,degree+1,bool_number))
        return true;
    word = -word;
    while ((*stack)->degree > degree)
        FlashBack(clauseLink,stack,(*stack)->degree,word_positive_value);
    MergeWord(clauseLink,word);//�����������Ӿ伯
    return DPLL(clauseLink,word_positive_value,stack,degree+1,bool_number);
}

bool Print_yes_result(int *word_positive_value, int bool_number, double time){
    FILE *fp;
    char file_name[60];
    char file_type[] = ".res";
    while (true) {
        printf("�����봴�����ɵ�CNF�ļ�����(.res)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        strcat(file_name, file_type);
        fp = fopen(file_name, "w");
        if (!fp)
            printf("�����ļ�ʧ��!\n");
        else {
            printf("�����ļ��ɹ�!\n");
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
        printf("�����봴�����ɵ�CNF�ļ�����(.res)\n");
        scanf("%s", file_name);
        setbuf(stdin, NULL);//ʹstdin��������Ĭ�ϻ�����תΪ�޻�����
        strcat(file_name, file_type);
        fp = fopen(file_name, "w");
        if (!fp)
            printf("�����ļ�ʧ��!\n");
        else {
            printf("�����ļ��ɹ�!\n");
            break;
        }
    }
    fprintf(fp,"s: 0\nv: \nt: %f",time);
    fclose(fp);
    return true;
}

bool OutPutClause(int *word_positive_value,int *bool_number){
    printf("��ӡCNF�Ӿ���Ҫ�ٴ�����һ���ļ������밴����ʾ����!\n");
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