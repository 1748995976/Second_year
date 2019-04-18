/**
 * 本次代码实现的原理如下：
 * 开辟一段连续的内存空间来储存指针
 * 每个指针指向不同的学生，第一个结点不存储任何信息
 * 每个学生信息的为链式存储
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
#define EVERY 20

typedef int status; //数据元素类型定义

typedef struct ElemType{//数据元素的定义，为链式存储
    char id[EVERY] = "";
    char name[EVERY] = "";
    float score = 0;
    struct ElemType *next = nullptr;
} ElemType;

typedef struct LNode{//每个表的信息
    ElemType *elem = nullptr;
    int length = 0;
} LNode, *LinkList;

status IntiaList(LinkList *L);

status DestroyList(LinkList *L);

status ClearList(LinkList *L);

status ListEmpty(LNode L);

int ListLength(LNode L);

status GetElem(LNode L, char *stu, ElemType *e);

status LocateElem(LNode L, ElemType e,int &a);

status PriorElem(LNode L, ElemType cur_e, ElemType *pre_e);

status NextElem(LNode L, ElemType cur_e, ElemType *next_e);

status ListInsert(LinkList *L, int i, ElemType e);

status ListDelete(LinkList *L, ElemType st, ElemType *e);

status ListTrabverse(LNode L);

status ReadFromFile(LinkList *L, int moro, int *Isinit, int *hw, int wh);

status WriteToFile(LinkList *L);

/*--------------------------------------------*/
int main(void) {
    LNode Q;
    LinkList L = &Q;
    int choice = 1;
    int Isinit = 0;
    int hm = 0;//用来保存多表的数目
    int wh = 0;//定位当前表在多表中哪一个表
    int moro = 0;//判断是多表操作还是单表操作
    LinkList  LinkLists;
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
        cout <<"          0.Exit\n" << endl;
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
                if (IntiaList(&L)) {
                    if(moro == 1) {
                        hw[wh - 1] = 1;
                        Isinit = hw[wh - 1];
                    }
                    else
                        Isinit = 1;
                    int number;
                    cout << "线性表创建成功！" << endl;
                    cout << "输入学生的信息，依次输入学号、姓名、得分,学号中输入符号#结束输入" << endl;
                    ElemType *q = L -> elem;
                    ElemType *p = L -> elem -> next = (ElemType *)malloc(sizeof(ElemType));
                    for(number = 0;;number++) {
                        cout << "请输入第" << number + 1 << "个学生的信息" << endl;
                        cin.sync();
                        cin >> p -> id;
                        if (strcmp(p -> id,"#") == 0) {
                            free(p);
                            q -> next = nullptr;
                            break;
                        }
                        cin >> p -> name;
                        cin >> p -> score;
                        (*L).length++;
                        p -> next = (ElemType *)malloc(sizeof(ElemType));
                        q = p;
                        p = p -> next;
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
                    system("pause");
                    break;
                }
                if (DestroyList(&L)) {
                    cout << "销毁线性表成功!" << endl;
                    Isinit = 0;
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
                if (ClearList(&L))
                    cout << "清空线性表成功!" << endl;
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
                    cout << "线性表为空" << endl;
                else {
                    cout << "线性表不为空" << endl;
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
                cout << "线性表的长度为 " << ListLength(*L) << endl;
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
                ElemType *e = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入目标学生的学号:" << endl;
                cin >> stu;
                if (GetElem(*L, stu, e)) {
                    cout << "学号: " << stu << " 学生的信息为:\n"
                         << "ID:" << e -> id << "\n"
                         << "Name:" << e -> name << "\n"
                         << "Score:" << e -> score << endl;
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
                if (LocateElem(*L,s,b))
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
                ElemType *pre_e = (ElemType *)malloc(sizeof(ElemType));
                cin >> cur_e.id;
                if (PriorElem(*L, cur_e, pre_e)) {
                    cout << "存在你所查找的学生:\n"
                         << "ID:" << pre_e -> id << "\n"
                         << "Name:" << pre_e -> name << "\n"
                         << "Score:" << pre_e -> score << endl;
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
                ElemType *next_e = (ElemType *)malloc(sizeof(ElemType));//搜一下
                cin >> cur_e.id;
                if (NextElem(*L, cur_e, next_e)) {
                    cout << "存在你所查找的学生:\n"
                         << "ID:" << next_e -> id << "\n"
                         << "Name:" << next_e -> name << "\n"
                         << "Score:" << next_e -> score << endl;
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
                if (ListInsert(&L, i, s))
                    cout << "插入成功!" << endl;
                else
                    cout << "输入的位序不合法" << endl;
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
                ElemType *e = (ElemType *)malloc(sizeof(ElemType));
                if (ListDelete(&L, s, e)) {
                    cout << "你删除的学生的信息为："
                        << "ID:" << e -> id << "\n"
                        << "Name:" << e -> name << "\n"
                        << "Score:" << e -> score << endl;
                    cout << "删除成功！" << endl;
                }else{
                    cout << "目标学生不存在!" << endl;
                }
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
                ReadFromFile(&L,moro,&Isinit,hw,wh);//表已经被初始化
                system("pause");
                break;
            }
            case 14: {
                if(moro == 0 && Isinit == 1){
                    cout << "是否保存(若不保存，则单表中的内容将被清空)当前的单表? 是：1    否：0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile(&L);
                    } else
                        DestroyList(&L);
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
                    LinkLists = (LinkList)malloc( hm * sizeof(LNode));
                    hw = (int *)malloc( hm * sizeof(int));
                    for (a = 0; a < hm; a++) {
                        hw[a] = 0;
                    }
                    wh = 1;
                    L = &(LinkLists[0]);
                    Isinit = hw[0];
                    cout << "多表创建成功!" << endl;
                    cout << "当前操作的表为表 1" << endl;
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
                            ElemType *p = L -> elem -> next;
                            while(p != nullptr) {
                                outile << p -> id << endl;
                                outile << p -> name << endl;
                                outile << p -> score << endl;
                                p = p -> next;
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
                    if( hw[a - 1] == 3 && a <= hm && a > 0){
                        cout << "此表已被舍弃！无法切换到该表！请重新输入！" << endl;
                        continue;
                    }
                    if(a > 0 && a <= hm) {
                        wh = a;
                        Isinit = hw[wh - 1];
                        L = &(LinkLists[wh - 1]);
                        break;
                    }
                    cout << "输入的表序不存在，请在1--" << hm << "选择输入" << endl;
                }
                system("pause");
                break;
            }
            case 16: {
                if (Isinit != 1) {
                    cout << "线性表未创建！" << endl;
                    cout << "请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                int i;
                cout << "是否要保存当前表?是：1   否：0" << endl;
                cin >> i;
                if (i) {
                    WriteToFile(&L);
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
                            hw[wh - 1] = 3;
                    }
                }
                else{
                    cout << "是否要保存当前表?是：1   否：0" << endl;
                    cin >> i;
                    if (i) {
                        if (moro == 1)
                            hw[wh - 1] = 2;
                        WriteToFile(&L);
                    } else{
                        //将表改变不保存的状态，即删除该表的存在
                        if (moro == 1)
                            hw[wh - 1] = 3;
                        DestroyList(&L);
                    }
                }
                //判断是否所有的表被保存，
                //若没有，则切换到未保存的表。
                if(moro == 1) {
                    for (i = 0; i < hm; i++) {
                        if(hw[i] == 1 || hw[i] == 0){
                            Isinit = hw[i];
//                            L = &LinkLists[i];
                            L = &(LinkLists[i]);
                            wh = i + 1;
                            choice = 17;//只是为了再次进入循环，而不是具体的操作命令
                            cout << "当前操作的表为表" << wh << endl;
                            break;
                        }
                    }
                    if(choice == 0){
                        cout << "剩余的表已保存或被舍弃，即将退出程序！" << endl;
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

status IntiaList(LinkList *L) {
    (*L) -> elem = (ElemType *)malloc(sizeof(ElemType));
    (*L) -> elem -> next = nullptr;
    (*L) -> length = 0;
    return OK;
}

status DestroyList(LinkList *L) {
    ElemType *p = (*L) -> elem;
    ElemType *q;
    while(p != nullptr){
        q = p -> next;
        free(p);
        p = q;
    }
    return  TRUE;
}

status ClearList(LinkList *L) {
    (*L) -> length = 0;
    return TRUE;
}

status ListEmpty(LNode L) {
    if (L.length == 0 || L.elem ->next == nullptr)
        return TRUE;
    else
        return FALSE;
}

int ListLength(LNode L) {
    return L.length;
}

status GetElem(LNode L, char *stu, ElemType *e) {
    ElemType *p;
    p = L.elem;
    while(p -> next != nullptr) {
        if (strcmp(stu,p -> id) == 0) {
            *e = *p;
            return OK;
        }
        p = p -> next;
    }
    return FALSE;
}

status LocateElem(LNode L, ElemType e,int &a) {
    int i;
    ElemType *p = L.elem;
    for (i = 0;p -> next != nullptr; i++) {
        if (strcmp(p -> id,e.id) == 0) {
            a = i;
            return TRUE;
        }
        p = p -> next;
    }
    return FALSE;
}

status PriorElem(LNode L, ElemType cur_e, ElemType *pre_e) {
    int i;
    ElemType *p = L.elem -> next;
    ElemType *q;
    for (i = 0; i < L.length && p != nullptr; i++) {
        if (strcmp(p -> id,cur_e.id) == 0 && i != 0) {
            *pre_e = *q;
            return TRUE;
        }
        q = p;
        p = p -> next;
    }
    return FALSE;
}

status NextElem(LNode L, ElemType cur_e, ElemType *next_e) {
    int i;
    ElemType *p = L.elem -> next;
    cout << L.length << endl;
    for (i = 0; i < L.length && p ->next != nullptr; i++) {
        if (strcmp(p -> id,cur_e.id) == 0 && i != (L.length - 1)) {
            *next_e = *(p -> next);
            return TRUE;
        }
        p = p -> next;
    }
    return ERROR;
}

status ListInsert(LinkList *L, int i, ElemType e) {
    int a = 0;
    if (i < 1 || i > (*L) -> length + 1)
        return ERROR;
    ElemType *p = (*L) -> elem;
    ElemType *q = (*L) -> elem;
    ElemType *h = (ElemType*)malloc(sizeof(ElemType));
    *h = e;
    for(a = 0;a < i;a++)
        q = q -> next;//第i个位置的元素
    for(a = 0;a < i - 1;a++)
        p = p -> next;//第(i-1)个位置的元素
    p -> next = h;
    h -> next = q;
    ++((*L) -> length);
    return OK;
}

status ListDelete(LinkList *L, ElemType st, ElemType *e) {
    ElemType *m = (*L) -> elem;//所要删除的元素
    ElemType *n = nullptr;
    while(m -> next != nullptr) {
        if (strcmp(m -> id,st.id) == 0) {
            break;
        }
        n = m;
        m = m -> next;
    }
    if(m -> next == nullptr)
        return FALSE;
    *e = *m;
    n -> next = m -> next;
    --((*L) -> length);
    return OK;
}

status ListTrabverse(LNode L) {
    if (!L.elem || L.length == 0)
        return ERROR;
    ElemType *p = L.elem -> next;
    while (p != nullptr) {
        cout << "ID:"<< p -> id << "\n"
        << "Name:" << p -> name << "\n"
        << "Score:" << p -> score << "\n" << endl;
        p = p -> next;
    }
    return TRUE;
}

status ReadFromFile(LinkList *L, int moro, int *Isinit, int *hw, int wh) {
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
            DestroyList(L);
            *Isinit = 0;
        }
        if(*Isinit == 0 && moro == 1) {
            IntiaList(L);
            *Isinit = hw[wh - 1] = 1;
        } else if(*Isinit == 0 && moro == 0){
            IntiaList(L);
            *Isinit = 1;
        }
        int a;
        ElemType *q;
        ElemType *p = (*L) -> elem -> next = (ElemType *)malloc(sizeof(ElemType));
        for (a = 0;; a++) {
            infile >> p -> id >> p -> name >> p -> score;
            if(infile.peek() == EOF) {
                free(p);
                q -> next = nullptr;
                break;
            }
            ++((*L) -> length);
            p -> next = (ElemType *)malloc(sizeof(ElemType));
            q = p;
            p = p -> next;
        }
        infile.close();
        cout << "读取成功!" << endl;
        return OK;
    } else {
        cout << "不存在此文件!" << endl;
        return  ERROR;
    }
}

status WriteToFile(LinkList *L) {
    char filename[20];
    cout << "输入文件名称（不超过20个字符）:" << endl;
    cin.sync();
    cin >> filename;
    cin.sync();
    strcat(filename,".txt");
    ofstream outfile;
    outfile.open(filename,std::ios::out);
    if(outfile){
        ElemType *p = (*L) -> elem -> next;
        while(p != nullptr) {
            outfile << p -> id << endl;
            outfile << p -> name << endl;
            outfile << p -> score << endl;
            p = p -> next;
        }
        outfile.close();
        cout << "创建文件成功!" << endl;
        return OK;
    } else
        cout << "创建文件失败!" << endl;
    return FALSE;
}
