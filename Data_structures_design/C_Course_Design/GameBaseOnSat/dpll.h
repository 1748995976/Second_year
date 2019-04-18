//
// Created by wzc-1748995976 on 2019/2/28.
//

#ifndef GAMEBASEONSAT_DPLL_H
#define GAMEBASEONSAT_DPLL_H

#include <stdbool.h>
#include "readandselect.h"

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



#endif //GAMEBASEONSAT_DPLL_H
