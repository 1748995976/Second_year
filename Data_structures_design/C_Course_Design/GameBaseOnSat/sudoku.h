//
// Created by wzc-1748995976 on 2019/3/4.
//

#ifndef GAMEBASEONSAT_SUDOKU_H
#define GAMEBASEONSAT_SUDOKU_H

#include <stdbool.h>
#include <stdio.h>
#include "readandselect.h"

#define ROW 9
#define COL 9

typedef struct Sudo{
    int matrix[ROW][COL];
}Sudo;
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

#endif //GAMEBASEONSAT_SUDOKU_H
