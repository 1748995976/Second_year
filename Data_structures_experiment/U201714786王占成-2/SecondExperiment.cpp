/**
 * ���δ���ʵ�ֵ�ԭ�����£�
 * ����һ���������ڴ�ռ�������ָ��
 * ÿ��ָ��ָ��ͬ��ѧ������һ����㲻�洢�κ���Ϣ
 * ÿ��ѧ����Ϣ��Ϊ��ʽ�洢
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

typedef int status; //����Ԫ�����Ͷ���

typedef struct ElemType{//����Ԫ�صĶ��壬Ϊ��ʽ�洢
    char id[EVERY] = "";
    char name[EVERY] = "";
    float score = 0;
    struct ElemType *next = nullptr;
} ElemType;

typedef struct LNode{//ÿ�������Ϣ
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
    int hm = 0;//�������������Ŀ
    int wh = 0;//��λ��ǰ���ڶ������һ����
    int moro = 0;//�ж��Ƕ��������ǵ������
    LinkList  LinkLists;
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
        cout <<"          0.Exit\n" << endl;
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
                if (IntiaList(&L)) {
                    if(moro == 1) {
                        hw[wh - 1] = 1;
                        Isinit = hw[wh - 1];
                    }
                    else
                        Isinit = 1;
                    int number;
                    cout << "���Ա����ɹ���" << endl;
                    cout << "����ѧ������Ϣ����������ѧ�š��������÷�,ѧ�����������#��������" << endl;
                    ElemType *q = L -> elem;
                    ElemType *p = L -> elem -> next = (ElemType *)malloc(sizeof(ElemType));
                    for(number = 0;;number++) {
                        cout << "�������" << number + 1 << "��ѧ������Ϣ" << endl;
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
                    cout << "���Ա���ʧ�ܣ�" << endl;
                system("pause");
                break;
            }
            case 2: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if (DestroyList(&L)) {
                    cout << "�������Ա�ɹ�!" << endl;
                    Isinit = 0;
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
                if (ClearList(&L))
                    cout << "������Ա�ɹ�!" << endl;
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
                    cout << "���Ա�Ϊ��" << endl;
                else {
                    cout << "���Ա�Ϊ��" << endl;
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
                cout << "���Ա�ĳ���Ϊ " << ListLength(*L) << endl;
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
                ElemType *e = (ElemType *)malloc(sizeof(ElemType));
                cout << "������Ŀ��ѧ����ѧ��:" << endl;
                cin >> stu;
                if (GetElem(*L, stu, e)) {
                    cout << "ѧ��: " << stu << " ѧ������ϢΪ:\n"
                         << "ID:" << e -> id << "\n"
                         << "Name:" << e -> name << "\n"
                         << "Score:" << e -> score << endl;
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
                if (LocateElem(*L,s,b))
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
                ElemType *pre_e = (ElemType *)malloc(sizeof(ElemType));
                cin >> cur_e.id;
                if (PriorElem(*L, cur_e, pre_e)) {
                    cout << "�����������ҵ�ѧ��:\n"
                         << "ID:" << pre_e -> id << "\n"
                         << "Name:" << pre_e -> name << "\n"
                         << "Score:" << pre_e -> score << endl;
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
                ElemType *next_e = (ElemType *)malloc(sizeof(ElemType));//��һ��
                cin >> cur_e.id;
                if (NextElem(*L, cur_e, next_e)) {
                    cout << "�����������ҵ�ѧ��:\n"
                         << "ID:" << next_e -> id << "\n"
                         << "Name:" << next_e -> name << "\n"
                         << "Score:" << next_e -> score << endl;
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
                if (ListInsert(&L, i, s))
                    cout << "����ɹ�!" << endl;
                else
                    cout << "�����λ�򲻺Ϸ�" << endl;
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
                ElemType *e = (ElemType *)malloc(sizeof(ElemType));
                if (ListDelete(&L, s, e)) {
                    cout << "��ɾ����ѧ������ϢΪ��"
                        << "ID:" << e -> id << "\n"
                        << "Name:" << e -> name << "\n"
                        << "Score:" << e -> score << endl;
                    cout << "ɾ���ɹ���" << endl;
                }else{
                    cout << "Ŀ��ѧ��������!" << endl;
                }
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
                ReadFromFile(&L,moro,&Isinit,hw,wh);//���Ѿ�����ʼ��
                system("pause");
                break;
            }
            case 14: {
                if(moro == 0 && Isinit == 1){
                    cout << "�Ƿ񱣴�(�������棬�򵥱��е����ݽ������)��ǰ�ĵ���? �ǣ�1    ��0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile(&L);
                    } else
                        DestroyList(&L);
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
                    LinkLists = (LinkList)malloc( hm * sizeof(LNode));
                    hw = (int *)malloc( hm * sizeof(int));
                    for (a = 0; a < hm; a++) {
                        hw[a] = 0;
                    }
                    wh = 1;
                    L = &(LinkLists[0]);
                    Isinit = hw[0];
                    cout << "������ɹ�!" << endl;
                    cout << "��ǰ�����ı�Ϊ�� 1" << endl;
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
                            ElemType *p = L -> elem -> next;
                            while(p != nullptr) {
                                outile << p -> id << endl;
                                outile << p -> name << endl;
                                outile << p -> score << endl;
                                p = p -> next;
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
                    if( hw[a - 1] == 3 && a <= hm && a > 0){
                        cout << "�˱��ѱ��������޷��л����ñ����������룡" << endl;
                        continue;
                    }
                    if(a > 0 && a <= hm) {
                        wh = a;
                        Isinit = hw[wh - 1];
                        L = &(LinkLists[wh - 1]);
                        break;
                    }
                    cout << "����ı��򲻴��ڣ�����1--" << hm << "ѡ������" << endl;
                }
                system("pause");
                break;
            }
            case 16: {
                if (Isinit != 1) {
                    cout << "���Ա�δ������" << endl;
                    cout << "������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                int i;
                cout << "�Ƿ�Ҫ���浱ǰ��?�ǣ�1   ��0" << endl;
                cin >> i;
                if (i) {
                    WriteToFile(&L);
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
                            hw[wh - 1] = 3;
                    }
                }
                else{
                    cout << "�Ƿ�Ҫ���浱ǰ��?�ǣ�1   ��0" << endl;
                    cin >> i;
                    if (i) {
                        if (moro == 1)
                            hw[wh - 1] = 2;
                        WriteToFile(&L);
                    } else{
                        //����ı䲻�����״̬����ɾ���ñ�Ĵ���
                        if (moro == 1)
                            hw[wh - 1] = 3;
                        DestroyList(&L);
                    }
                }
                //�ж��Ƿ����еı����棬
                //��û�У����л���δ����ı�
                if(moro == 1) {
                    for (i = 0; i < hm; i++) {
                        if(hw[i] == 1 || hw[i] == 0){
                            Isinit = hw[i];
//                            L = &LinkLists[i];
                            L = &(LinkLists[i]);
                            wh = i + 1;
                            choice = 17;//ֻ��Ϊ���ٴν���ѭ���������Ǿ���Ĳ�������
                            cout << "��ǰ�����ı�Ϊ��" << wh << endl;
                            break;
                        }
                    }
                    if(choice == 0){
                        cout << "ʣ��ı��ѱ���������������˳�����" << endl;
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
        q = q -> next;//��i��λ�õ�Ԫ��
    for(a = 0;a < i - 1;a++)
        p = p -> next;//��(i-1)��λ�õ�Ԫ��
    p -> next = h;
    h -> next = q;
    ++((*L) -> length);
    return OK;
}

status ListDelete(LinkList *L, ElemType st, ElemType *e) {
    ElemType *m = (*L) -> elem;//��Ҫɾ����Ԫ��
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
        //�����Ƕ��������ǵ���������ı����ǵ�״̬��
        //�Ӷ���ǰ���ж��Ƿ񱻳�ʼ��
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
        cout << "��ȡ�ɹ�!" << endl;
        return OK;
    } else {
        cout << "�����ڴ��ļ�!" << endl;
        return  ERROR;
    }
}

status WriteToFile(LinkList *L) {
    char filename[20];
    cout << "�����ļ����ƣ�������20���ַ���:" << endl;
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
        cout << "�����ļ��ɹ�!" << endl;
        return OK;
    } else
        cout << "�����ļ�ʧ��!" << endl;
    return FALSE;
}
