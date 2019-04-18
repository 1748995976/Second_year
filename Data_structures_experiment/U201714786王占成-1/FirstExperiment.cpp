/**
 * 本次代码实现的原理如下：
 * 开辟一段连续的内存空间来储存指针
 * 每个指针指向不同的学生
 * 每个学生信息的储存均为一段连续的内存空间
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define EVERY 20

typedef int status; //数据元素类型定义

typedef struct {
    char id[EVERY];
    char name[EVERY];
    float score;
} ElemType;

typedef struct {  //顺序表的定义
    ElemType *elem = nullptr;
    int length;
    int listsize;
} SqList;



status IntiaList(SqList *L);

status DestroyList(SqList *L);

status ClearList(SqList *L);

status ListEmpty(SqList L);

int ListLength(SqList L);

status GetElem(SqList L, char *stu, ElemType *e);

status LocateElem(SqList L, ElemType e,int &a);

status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

status ListInsert(SqList *L, int i, ElemType e);

status ListDelete(SqList *L, ElemType st, ElemType *e);

status ListTrabverse(SqList L);

status ReadFromFile(SqList *L, int moro, int *Isinit, int *hw, int wh);

status WriteToFile(SqList *L);

/*--------------------------------------------*/
int main(void) {
    SqList Q;
    SqList * L = &Q;
    int choice = 1;
    int Isinit = 0;
    int hm = 0;//用来保存多表的数目
    int wh = 0;//定位当前表在多表中哪一个表
    int moro = 0;//判断是多表操作还是单表操作
    SqList * multilist = nullptr;
    int *hw = nullptr;//保存表的状态 0：未初始化 1：初始化 2：已保存 3：不保存
    while (choice) {
        cout << "\n\n" << endl;
        cout <<"      Menu for Linear Table On Sequence Structure \n" << endl;
        cout <<"-------------------------------------------------\n" << endl;
        cout <<"    	  1. IntiaList        9. NextElem\n" << endl;
        cout <<"    	  2. DestroyList      10. ListInsert\n" << endl;
        cout <<"    	  3. ClearList        11. ListDelete\n" << endl;
        cout <<"    	  4. ListEmpty        12. ListTrabverse\n" << endl;
        cout <<"    	  5. ListLength       13. ReadFromFile\n" << endl;
        cout <<"    	  6. GetElem          14. MultiList\n" << endl;
        cout <<"    	  7. LocateElem       15. SwitchList\n" << endl;
        cout <<"          8. PriorElem        16. SaveList\n" << endl;
        cout <<"          0. Exit\n" << endl;
        cout <<"-------------------------------------------------\n" << endl;
        if(moro == 1)
            cout << "当前操作的为表 " << wh << endl;
        cout <<"    请选择你的操作[0~15]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                if(moro == 1){
                    Isinit = hw[wh - 1];
                }
                if(Isinit == 1){
                    cout << "当前已初始化表!" << endl;
                    break;
                }
                if (IntiaList(L)) {
                    if(moro == 1) {
                        hw[wh - 1] = 1;
                        Isinit = hw[wh - 1];
                    }
                    else
                        Isinit = 1;
                    int number;
                    cout << "线性表创建成功！" << endl;
                    cout << "输入学生的信息，依次输入学号、姓名、得分(学生的个数不大于" << LIST_INIT_SIZE << ")，学号中输入符号#结束输入" << endl;
                    for (number = 0; number <= LIST_INIT_SIZE; number++) {
                        cout << "请输入第" << number + 1 << "个学生的信息" << endl;
                        cin.sync();
                        cin >> (*L).elem[number].id;
                        if (number == LIST_INIT_SIZE && strcmp((*L).elem[number].id,"#") != 0) {
                            cout << "超出范围!" << endl;
                            break;
                        }
                        if (strcmp((*L).elem[number].id,"#") == 0)
                            break;
                        cin >> (*L).elem[number].name;
                        cin >> (*L).elem[number].score;
                        (*L).length++;
                    }
                } else
                    cout << "线性表创建失败！" << endl;
                system("pause");
                break;
            }
            case 2: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    break;
                }
                if (DestroyList(L)) {
                    cout << "销毁顺序表成功" << endl;
                    Isinit = 0;
                    if(moro == 1){
                        hw[wh - 1] = 3;
                    }
                }
                system("pause");
                break;
            }
            case 3: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                if (ClearList(L))
                    cout << "清空顺序表成功" << endl;
                system("pause");
                break;
            }
            case 4: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                if (ListEmpty(*L))
                    cout << "顺序表为空" << endl;
                else {
                    cout << "顺序表不为空" << endl;
                }
                system("pause");
                break;
            }
            case 5: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "顺序表的长度为 " << ListLength(*L) << endl;
                system("pause");
                break;
            }
            case 6: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                char stu[EVERY];
                ElemType s;
                ElemType *e = &s;
                cout << "请输入目标学生的学号:" << endl;
                cin >> stu;
                if (GetElem(Q, stu, e)) {
                    cout << "学号: " << stu << " 学生的信息为:\n"
                         << "ID:" << (*e).id << "\n"
                         << "Name:" << (*e).name << "\n"
                         << "Score:" << (*e).score << endl;
                } else {
                    cout << "查无此人" << endl;
                }
                system("pause");
                break;
            }
            case 7:{
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                ElemType s;
                cout << "请输入定位学生的学号:" << endl;
                cin >> s.id;
                int a = 0;
                int &b = a;
                if (LocateElem(Q,s,b))
                    cout <<"目标学生成绩表中的位序为" << b <<endl;
                else
                    cout << "查无此人" << endl;
                system("pause");
                break;
            }
            case 8: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "输入成绩表中被查找学生的下面学生的学号" << endl;
                ElemType cur_e;
                ElemType s;
                ElemType *pre_e = &s;
                cin >> cur_e.id;
                if (PriorElem(Q, cur_e, pre_e)) {
                    cout << "存在你所查找的学生:\n"
                         << "ID:" << (*pre_e).id << "\n"
                         << "Name:" << (*pre_e).name << "\n"
                         << "Score:" << (*pre_e).score << endl;
                } else
                    cout << "不存在被查找学生" << endl;
                system("pause");
                break;
            }
            case 9: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout <<"输入成绩表中被查找学生的上面学生的学号" << endl;
                ElemType cur_e;
                ElemType s;
                ElemType *next_e = &s;
                cin >> cur_e.id;
                if (NextElem(Q, cur_e, next_e)) {
                    cout << "存在你所查找的学生:\n"
                         << "ID:" << (*next_e).id << "\n"
                         << "Name:" << (*next_e).name << "\n"
                         << "Score:" << (*next_e).score << endl;
                } else
                    cout << "不存在被查找学生" << endl;
                system("pause");
                break;
            }
            case 10: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "输入你想插入的位置：" << endl;
                int i;
                cin >> i;
                cout << "输入你想插入的学生的学生信息：" << endl;
                ElemType s;
                cin >> s.id >> s.name >> s.score;
                if (ListInsert(L, i, s))
                    cout << "插入成功!" << endl;
                else
                    cout << "输入的位序不合法，请重新输入" << endl;
                system("pause");
                break;
            }
            case 11:{
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "请输入你想删除的学生的学号：" << endl;
                ElemType s;
                cin >> s.id;
                ElemType ds;
                ElemType *e1 = &ds;
                if (ListDelete(L, s, e1)) {
                    cout << "你删除的学生的信息为："
                        << "ID:" << (*e1).id << "\n"
                        << "Name:" << (*e1).name << "\n"
                        << "Score:" << (*e1).score << endl;
                    cout << "删除成功！" << endl;
                } else
                    cout << "不存在此学生" << endl;
                system("pause");
                break;
            }
            case 12: {
                if (Isinit != 1) {
                    cout << "线性表未创建!" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                if (!ListTrabverse(*L))
                    cout << "线性表是空表！" << endl;
                system("pause");
                break;
            }
            case 13: {
                cout << "请输入你想读取的文件名" << endl;
                ReadFromFile(L,moro,&Isinit,hw,wh);//表已经被初始化
                system("pause");
                break;
            }
            case 14: {
                if(moro == 0 && Isinit == 1){
                    cout << "是否保存(若不保存，则单表中的内容将被清空)当前的单表? 是：1    否：0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile(L);
                    } else
                        DestroyList(L);
                }
                if(moro == 1){
                    cout << "当前已创建多表，无需再创建!" << endl;
                    system("pause");
                    break;
                }
                cout << "请输入同时操作表的数目" << endl;
                int a;
                cin >> hm;
                if(hm > 0) {
                    moro = 1;
                    multilist = (SqList * )malloc( hm * sizeof(SqList));
                    hw = (int *)malloc( hm * sizeof(int));
                    for (a = 0; a < hm; a++) {
                        hw[a] = 0;
                    }
                    wh = 1;
                    L = &(multilist[0]);
                    Isinit = hw[0];
                    cout << "操作成功！当前操作的表为表 1" << endl;
                }else{
                    cout << "输入的数目不合法，将退出本功能！" << endl;
                }
                system("pause");
                break;
            }
            case 15: {
                if( hm == 0){
                    cout << "不存在多表！" << endl;
                    system("pause");
                    break;
                }
                //切换表的时候询问上一个表是否保存，若不保存，后面退出的时候可以选择保存
                if(moro == 1)
                    Isinit = hw[wh - 1];
                if(Isinit == 1){
                    cout << "是否要保存(若不保存，退出程序时可再次选择是否保存)上一个表?是：1   否：0" << endl;
                    int i;
                    cin >> i;
                    if (i) {//若文件已经被保存，则切换表的时候无法再次切换到该表
                        char filename[20];
                        cout << "输入文件名称（不超过20个字符）:" << endl;
                        cin >> filename;
                        strcat(filename,".txt");
                        ofstream outile;
                        outile.open(filename,std::ios::out);
                        if(outile){
                            if(moro == 1)
                                hw[wh -1] = 2;
                            int number;
                            for(number = 0;number < (*L).length;number++) {
                                outile << (*L).elem[number].id << endl;
                                outile << (*L).elem[number].name << endl;
                                outile << (*L).elem[number].score << endl;
                            }
                            outile.close();
                        } else
                            cout << "创建文件失败!" << endl;
                    }
                }
                cout << "请输入被切换到表的序号(输入数字0退出切表功能)" << endl;
                int a;
                while(true){
                    cin >> a;
                    if( a == 0)
                        break;
                    if( hw[a - 1] == 2 && a <= hm && a > 0){
                        cout << "此表已被保存！无法切换到该表！请重新输入！" << endl;
                    }
                    if( hw[a - 1] == 3 && a <= hm && a > 0){
                        cout << "此表已被舍弃！无法切换到该表！请重新输入！" << endl;
                    }
                    if(a > 0 && a <= hm && hw[a - 1] != 2) {
                        wh = a;
                        Isinit = hw[wh - 1];
                        L = &(multilist[wh - 1]);
                        break;
                    }
                    cout << "输入的表序不存在，请在1--" << hm << "选择输入" << endl;
                }
                system("pause");
                break;
            }
            case 16: {
                int i;
                cout << "是否要保存当前表?是：1   否：0" << endl;
                cin >> i;
                if (i) {
                    WriteToFile(L);
                }
                system("pause");
                break;
            }
            case 0: {
                int i;
                if(moro == 1)//让Isinit为多表中被操作表的状态
                    Isinit = hw[wh - 1];
                if (Isinit != 1) {
                    if(Isinit == 2)
                        cout << "此表已保存！" << endl;
                    else if(Isinit == 0){
                        cout << "线性表未初始化！" << endl;
                        cout << "即将退出本功能!" << endl;
                        if(moro == 1)
                            hw[ wh -1 ] = 3;
                    }
                }
                else{
                    cout << "是否要保存当前表?是：1   否：0" << endl;
                    cin >> i;
                    if (i) {
                        if (moro == 1)
                            hw[wh - 1] = 2;
                        WriteToFile(L);
                    } else{
                        //将表改变不保存的状态，即删除该表的存在
                        if (moro == 1)
                            hw[wh - 1] = 3;
                    }
                }
                //判断是否所有的表被保存，
                //若没有，则切换到未保存的表。
                if(moro == 1) {
                    for (i = 0; i < hm; i++) {
                        if(hw[i] == 1 || hw[i] == 0){
                            Isinit = hw[i];
                            L = &multilist[i];
                            wh = i + 1;
                            choice = 17;//只是为了再次进入循环，而不是具体的操作命令
                            break;
                        }
                    }
                    if(choice == 0){
                        cout << "剩余的表均被舍弃(退出)，即将退出程序！" << endl;
                    }
                }
                system("pause");
                break;
            }
            default:
                cout << "指令不存在，请重新输入！" << endl;
        }//end of switch
    }//end of while
    cout << "欢迎下次再使用本系统!" << endl;
    return 1;
}//end of main()

status IntiaList(SqList *L) {
    (*L).elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!(*L).elem)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList *L) {
    if ((*L).elem != nullptr) {
        free((*L).elem);
        return TRUE;
    } else {
        return ERROR;
    }
}

status ClearList(SqList *L) {
    (*L).length = 0;
    return TRUE;
}

status ListEmpty(SqList L) {
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L) {
    return L.length;
}

status GetElem(SqList L, char *stu, ElemType *e) {
    int a;
    for(a = 0;a < L.length;a++) {
        if (strcmp(stu,L.elem[a].id) == 0) {
            *e = L.elem[a];
            return OK;
        }
    }
    return FALSE;
}

status LocateElem(SqList L, ElemType e,int &a) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (strcmp(L.elem[i].id,e.id) == 0) {
            a = i + 1;
            return TRUE;
        }
    }
    return FALSE;
}

status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (strcmp(L.elem[i].id,cur_e.id) == 0 && i != 0) {
            *pre_e = L.elem[i - 1];
            return TRUE;
        }
    }
    return FALSE;
}

status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (strcmp(L.elem[i].id,cur_e.id) == 0 && i != (L.length - 1)) {
            *next_e = L.elem[i + 1];
            return TRUE;
        }
    }
    return ERROR;
}

status ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > (*L).length + 1)
        return ERROR;
    if ((*L).length >= (*L).listsize) {
        ElemType *newbase;
        newbase = (ElemType *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    ElemType *q, *p;
    q = &((*L).elem[i - 1]);
    p = &((*L).elem[(*L).length - 1]);
    for (; p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++((*L).length);
    return OK;
}

status ListDelete(SqList *L, ElemType st, ElemType *e) {
    int i;
    for(i = 0; i < (*L).length;i++){
        if(strcmp(st.id,(*L).elem[i].id) == 0)
            break;
    }
    if((*L).length == i)
        return FALSE;
    ElemType *p, *q;
    p = &((*L).elem[i]);
    *e = *p;
    q = &((*L).elem[(*L).length - 1]);
    for (++p; p <= q; p++)
        *(p - 1) = *p;
    --((*L).length);
    return OK;
}

status ListTrabverse(SqList L) {
    if (!L.elem || L.length == 0)
        return ERROR;
    int i;
    for (i = 0; i < L.length; i++) {
        cout << "ID:"<< L.elem[i].id << "\n"
        << "Name:" << L.elem[i].name << "\n"
        << "Score:" << L.elem[i].score << "\n" << endl;
    }
    return TRUE;
}

status ReadFromFile(SqList *L, int moro, int *Isinit, int *hw, int wh) {
    char filename[20];
    cin >> filename;
    strcat(filename, ".txt");
    ifstream infile;
    infile.open(filename, std::ios::in);
    if (infile) {
        //根据是多表操作还是单表操作来改变它们的状态，
        //从而在前面判断是否被初始化
        if(moro == 1)
            *Isinit = hw[wh - 1];
        if(*Isinit == 1){
            ClearList(L);
        }
        if(*Isinit == 0 && moro == 1) {
            IntiaList(L);
            *Isinit = hw[wh - 1] = 1;
        } else if(*Isinit == 0 && moro == 0){
            IntiaList(L);
            *Isinit = 1;
        }
        int a;
        for (a = 0;; a++) {
            infile >> (*L).elem[a].id >> (*L).elem[a].name >> (*L).elem[a].score;
            if(infile.peek() == EOF )
                break;
            ++((*L).length);
            if ((*L).length >= (*L).listsize) {
                ElemType *newbase;
                newbase = (ElemType *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
                if (!newbase)
                    exit(OVERFLOW);
                (*L).elem = newbase;
                (*L).listsize += LISTINCREMENT;
            }
        }
    } else {
        cout << "不存在此文件!" << endl;
    }
    infile.close();
    return  TRUE;
}

status WriteToFile(SqList *L) {
    char filename[20];
    cout << "输入文件名称（不超过20个字符）:" << endl;
    cin >> filename;
    strcat(filename,".txt");
    ofstream outile;
    outile.open(filename,std::ios::out);
    if(outile){
        int number;
        for(number = 0;number < (*L).length;number++) {
            outile << (*L).elem[number].id << endl;
            outile << (*L).elem[number].name << endl;
            outile << (*L).elem[number].score << endl;
        }
        outile.close();
    } else
        cout << "创建文件失败!" << endl;
    return TRUE;
}
