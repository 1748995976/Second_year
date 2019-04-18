//
// Created by wzc-1748995976 on 2019/2/28.
//

#ifndef GAMEBASEONSAT_READANDSELECT_H
#define GAMEBASEONSAT_READANDSELECT_H

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


#endif //GAMEBASEONSAT_READANDSELECT_H
