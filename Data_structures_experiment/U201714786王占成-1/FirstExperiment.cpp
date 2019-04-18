/**
 * ���δ���ʵ�ֵ�ԭ�����£�
 * ����һ���������ڴ�ռ�������ָ��
 * ÿ��ָ��ָ��ͬ��ѧ��
 * ÿ��ѧ����Ϣ�Ĵ����Ϊһ���������ڴ�ռ�
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

typedef int status; //����Ԫ�����Ͷ���

typedef struct {
    char id[EVERY];
    char name[EVERY];
    float score;
} ElemType;

typedef struct {  //˳���Ķ���
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
    int hm = 0;//�������������Ŀ
    int wh = 0;//��λ��ǰ���ڶ������һ����
    int moro = 0;//�ж��Ƕ��������ǵ������
    SqList * multilist = nullptr;
    int *hw = nullptr;//������״̬ 0��δ��ʼ�� 1����ʼ�� 2���ѱ��� 3��������
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
            cout << "��ǰ������Ϊ�� " << wh << endl;
        cout <<"    ��ѡ����Ĳ���[0~15]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                if(moro == 1){
                    Isinit = hw[wh - 1];
                }
                if(Isinit == 1){
                    cout << "��ǰ�ѳ�ʼ����!" << endl;
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
                    cout << "���Ա����ɹ���" << endl;
                    cout << "����ѧ������Ϣ����������ѧ�š��������÷�(ѧ���ĸ���������" << LIST_INIT_SIZE << ")��ѧ�����������#��������" << endl;
                    for (number = 0; number <= LIST_INIT_SIZE; number++) {
                        cout << "�������" << number + 1 << "��ѧ������Ϣ" << endl;
                        cin.sync();
                        cin >> (*L).elem[number].id;
                        if (number == LIST_INIT_SIZE && strcmp((*L).elem[number].id,"#") != 0) {
                            cout << "������Χ!" << endl;
                            break;
                        }
                        if (strcmp((*L).elem[number].id,"#") == 0)
                            break;
                        cin >> (*L).elem[number].name;
                        cin >> (*L).elem[number].score;
                        (*L).length++;
                    }
                } else
                    cout << "���Ա���ʧ�ܣ�" << endl;
                system("pause");
                break;
            }
            case 2: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    break;
                }
                if (DestroyList(L)) {
                    cout << "����˳���ɹ�" << endl;
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
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if (ClearList(L))
                    cout << "���˳���ɹ�" << endl;
                system("pause");
                break;
            }
            case 4: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if (ListEmpty(*L))
                    cout << "˳���Ϊ��" << endl;
                else {
                    cout << "˳���Ϊ��" << endl;
                }
                system("pause");
                break;
            }
            case 5: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "˳���ĳ���Ϊ " << ListLength(*L) << endl;
                system("pause");
                break;
            }
            case 6: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                char stu[EVERY];
                ElemType s;
                ElemType *e = &s;
                cout << "������Ŀ��ѧ����ѧ��:" << endl;
                cin >> stu;
                if (GetElem(Q, stu, e)) {
                    cout << "ѧ��: " << stu << " ѧ������ϢΪ:\n"
                         << "ID:" << (*e).id << "\n"
                         << "Name:" << (*e).name << "\n"
                         << "Score:" << (*e).score << endl;
                } else {
                    cout << "���޴���" << endl;
                }
                system("pause");
                break;
            }
            case 7:{
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                ElemType s;
                cout << "�����붨λѧ����ѧ��:" << endl;
                cin >> s.id;
                int a = 0;
                int &b = a;
                if (LocateElem(Q,s,b))
                    cout <<"Ŀ��ѧ���ɼ����е�λ��Ϊ" << b <<endl;
                else
                    cout << "���޴���" << endl;
                system("pause");
                break;
            }
            case 8: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "����ɼ����б�����ѧ��������ѧ����ѧ��" << endl;
                ElemType cur_e;
                ElemType s;
                ElemType *pre_e = &s;
                cin >> cur_e.id;
                if (PriorElem(Q, cur_e, pre_e)) {
                    cout << "�����������ҵ�ѧ��:\n"
                         << "ID:" << (*pre_e).id << "\n"
                         << "Name:" << (*pre_e).name << "\n"
                         << "Score:" << (*pre_e).score << endl;
                } else
                    cout << "�����ڱ�����ѧ��" << endl;
                system("pause");
                break;
            }
            case 9: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout <<"����ɼ����б�����ѧ��������ѧ����ѧ��" << endl;
                ElemType cur_e;
                ElemType s;
                ElemType *next_e = &s;
                cin >> cur_e.id;
                if (NextElem(Q, cur_e, next_e)) {
                    cout << "�����������ҵ�ѧ��:\n"
                         << "ID:" << (*next_e).id << "\n"
                         << "Name:" << (*next_e).name << "\n"
                         << "Score:" << (*next_e).score << endl;
                } else
                    cout << "�����ڱ�����ѧ��" << endl;
                system("pause");
                break;
            }
            case 10: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "������������λ�ã�" << endl;
                int i;
                cin >> i;
                cout << "������������ѧ����ѧ����Ϣ��" << endl;
                ElemType s;
                cin >> s.id >> s.name >> s.score;
                if (ListInsert(L, i, s))
                    cout << "����ɹ�!" << endl;
                else
                    cout << "�����λ�򲻺Ϸ�������������" << endl;
                system("pause");
                break;
            }
            case 11:{
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "����������ɾ����ѧ����ѧ�ţ�" << endl;
                ElemType s;
                cin >> s.id;
                ElemType ds;
                ElemType *e1 = &ds;
                if (ListDelete(L, s, e1)) {
                    cout << "��ɾ����ѧ������ϢΪ��"
                        << "ID:" << (*e1).id << "\n"
                        << "Name:" << (*e1).name << "\n"
                        << "Score:" << (*e1).score << endl;
                    cout << "ɾ���ɹ���" << endl;
                } else
                    cout << "�����ڴ�ѧ��" << endl;
                system("pause");
                break;
            }
            case 12: {
                if (Isinit != 1) {
                    cout << "���Ա�δ����!" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if (!ListTrabverse(*L))
                    cout << "���Ա��ǿձ�" << endl;
                system("pause");
                break;
            }
            case 13: {
                cout << "�����������ȡ���ļ���" << endl;
                ReadFromFile(L,moro,&Isinit,hw,wh);//���Ѿ�����ʼ��
                system("pause");
                break;
            }
            case 14: {
                if(moro == 0 && Isinit == 1){
                    cout << "�Ƿ񱣴�(�������棬�򵥱��е����ݽ������)��ǰ�ĵ���? �ǣ�1    ��0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile(L);
                    } else
                        DestroyList(L);
                }
                if(moro == 1){
                    cout << "��ǰ�Ѵ�����������ٴ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "������ͬʱ���������Ŀ" << endl;
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
                    cout << "�����ɹ�����ǰ�����ı�Ϊ�� 1" << endl;
                }else{
                    cout << "�������Ŀ���Ϸ������˳������ܣ�" << endl;
                }
                system("pause");
                break;
            }
            case 15: {
                if( hm == 0){
                    cout << "�����ڶ��" << endl;
                    system("pause");
                    break;
                }
                //�л����ʱ��ѯ����һ�����Ƿ񱣴棬�������棬�����˳���ʱ�����ѡ�񱣴�
                if(moro == 1)
                    Isinit = hw[wh - 1];
                if(Isinit == 1){
                    cout << "�Ƿ�Ҫ����(�������棬�˳�����ʱ���ٴ�ѡ���Ƿ񱣴�)��һ����?�ǣ�1   ��0" << endl;
                    int i;
                    cin >> i;
                    if (i) {//���ļ��Ѿ������棬���л����ʱ���޷��ٴ��л����ñ�
                        char filename[20];
                        cout << "�����ļ����ƣ�������20���ַ���:" << endl;
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
                            cout << "�����ļ�ʧ��!" << endl;
                    }
                }
                cout << "�����뱻�л���������(��������0�˳��б���)" << endl;
                int a;
                while(true){
                    cin >> a;
                    if( a == 0)
                        break;
                    if( hw[a - 1] == 2 && a <= hm && a > 0){
                        cout << "�˱��ѱ����棡�޷��л����ñ����������룡" << endl;
                    }
                    if( hw[a - 1] == 3 && a <= hm && a > 0){
                        cout << "�˱��ѱ��������޷��л����ñ����������룡" << endl;
                    }
                    if(a > 0 && a <= hm && hw[a - 1] != 2) {
                        wh = a;
                        Isinit = hw[wh - 1];
                        L = &(multilist[wh - 1]);
                        break;
                    }
                    cout << "����ı��򲻴��ڣ�����1--" << hm << "ѡ������" << endl;
                }
                system("pause");
                break;
            }
            case 16: {
                int i;
                cout << "�Ƿ�Ҫ���浱ǰ��?�ǣ�1   ��0" << endl;
                cin >> i;
                if (i) {
                    WriteToFile(L);
                }
                system("pause");
                break;
            }
            case 0: {
                int i;
                if(moro == 1)//��IsinitΪ����б��������״̬
                    Isinit = hw[wh - 1];
                if (Isinit != 1) {
                    if(Isinit == 2)
                        cout << "�˱��ѱ��棡" << endl;
                    else if(Isinit == 0){
                        cout << "���Ա�δ��ʼ����" << endl;
                        cout << "�����˳�������!" << endl;
                        if(moro == 1)
                            hw[ wh -1 ] = 3;
                    }
                }
                else{
                    cout << "�Ƿ�Ҫ���浱ǰ��?�ǣ�1   ��0" << endl;
                    cin >> i;
                    if (i) {
                        if (moro == 1)
                            hw[wh - 1] = 2;
                        WriteToFile(L);
                    } else{
                        //����ı䲻�����״̬����ɾ���ñ�Ĵ���
                        if (moro == 1)
                            hw[wh - 1] = 3;
                    }
                }
                //�ж��Ƿ����еı����棬
                //��û�У����л���δ����ı�
                if(moro == 1) {
                    for (i = 0; i < hm; i++) {
                        if(hw[i] == 1 || hw[i] == 0){
                            Isinit = hw[i];
                            L = &multilist[i];
                            wh = i + 1;
                            choice = 17;//ֻ��Ϊ���ٴν���ѭ���������Ǿ���Ĳ�������
                            break;
                        }
                    }
                    if(choice == 0){
                        cout << "ʣ��ı��������(�˳�)�������˳�����" << endl;
                    }
                }
                system("pause");
                break;
            }
            default:
                cout << "ָ����ڣ����������룡" << endl;
        }//end of switch
    }//end of while
    cout << "��ӭ�´���ʹ�ñ�ϵͳ!" << endl;
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
        //�����Ƕ��������ǵ���������ı����ǵ�״̬��
        //�Ӷ���ǰ���ж��Ƿ񱻳�ʼ��
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
        cout << "�����ڴ��ļ�!" << endl;
    }
    infile.close();
    return  TRUE;
}

status WriteToFile(SqList *L) {
    char filename[20];
    cout << "�����ļ����ƣ�������20���ַ���:" << endl;
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
        cout << "�����ļ�ʧ��!" << endl;
    return TRUE;
}
