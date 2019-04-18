//
// Created by wzc-1748995976 on 2019/2/28.
//

#include <windef.h>
#include <stdlib.h>
#include <stdio.h>
#include "dpll.h"

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
