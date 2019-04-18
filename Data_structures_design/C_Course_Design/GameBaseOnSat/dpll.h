//
// Created by wzc-1748995976 on 2019/2/28.
//

#ifndef GAMEBASEONSAT_DPLL_H
#define GAMEBASEONSAT_DPLL_H

#include <stdbool.h>
#include "readandselect.h"

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



#endif //GAMEBASEONSAT_DPLL_H
