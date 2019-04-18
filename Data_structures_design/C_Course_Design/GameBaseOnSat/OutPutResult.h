//
// Created by wzc-1748995976 on 2019/3/4.
//

#ifndef GAMEBASEONSAT_OUTPUTRESULT_H
#define GAMEBASEONSAT_OUTPUTRESULT_H

#include <stdbool.h>
#include "readandselect.h"

//输出有解的结果
bool Print_yes_result(int *word_positive_value, int bool_number, double time);

//输出无解的结果
bool Print_no_result(double time);

//打印文件内容以及结果
bool OutPutClause(int *word_positive_value,int *bool_number);

#endif //GAMEBASEONSAT_OUTPUTRESULT_H
