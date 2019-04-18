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


#endif //GAMEBASEONSAT_READANDSELECT_H
