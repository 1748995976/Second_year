/**
 * ��ʵ��ÿ��������һ���׽��
 * ���׽ڵ�����Ӻ��Һ��Ӿ�ָ������ĸ����
 * �����д����ֵһ���Ǹ���������(���Һ���)���������
 */

/**
 * ����δ����ʱ������������
 * ��������ʱ��������
 *  1.����ʱ��������Ϊδ��ʼ��״̬
 *  2.����ʱ�������������еĴ���
 * δ�������Ѵ����������¾�����ͨ��exit�˳���ǰ��
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

#define BEF 0 //������������
#define MID 1 //������������
#define AFT 2 //������������
#define FALSE 0
#define OK 1
#define ERROR 0
#define EVERY 20
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXQSIZE 100
#define NOTINIT 0
#define INIT 1
#define CREATE 2
#define ABANDON 3

typedef int Status;



typedef struct{
    char id[EVERY];
    char name[EVERY];
    char phone[EVERY];
} ElemType;

typedef struct BiTNode{
    ElemType *elem;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
} BiTNode, * BiTree;

typedef struct RooTNode{
    BiTree child;
}RooTNode,* RooTree;

typedef struct {
    BiTree *base;
    BiTree *top;
    int stacksize;
} BiStack;

typedef struct {
    BiTree * base;
    int front;
    int rear;
}LinkQueue;

Status InitStack(BiStack &S);

Status Push(BiStack &S,BiTree t);

Status Pop(BiStack &S,BiTree &t);

Status InitQueue(LinkQueue &Q);

Status DestroyQueue(LinkQueue &Q);

Status EnQueue(LinkQueue &Q,BiTree N);

Status DeQueue(LinkQueue &Q,BiTree &N);

Status InitBiTree(RooTree *T);

Status DestroyBiTree(RooTree **T,int moro,int *where,int *Isinit,int **how,RooTree **TS,int *choice,int number);

Status CreateBiTree(BiTree *T,int definition);

Status ClearBiTree (BiTree *T);

Status BiTreeEmpty(BiTree T);

int BiTreeDepth(BiTree T);

Status Root(BiTree T);

Status Value(BiTree T,BiTNode e);

Status Assign(BiTree *T,BiTNode &e,ElemType value);

Status Parent(BiTree T,BiTree e);

Status LeftChild(BiTree T,BiTree e);

Status RightChild(BiTree T,BiTree e);

Status LeftSibling(BiTree T,BiTree e);

Status RightSibling(BiTree T,BiTree e);

Status InsertChildBiTNode (BiTree *T,BiTree p,int LR);

Status DeleteChild(BiTree *T,BiTree p,int LR);

Status PreOrderTraverse(BiTree T,Status(* Visit)(ElemType *e));

Status InOrderTraverse(BiTree T,Status(* Visit)(ElemType *e));

Status PostOrderTraverse(BiTree T,Status(* Visit)(ElemType *e));

Status LevelOrderTraverse(BiTree T,Status(* Visit)(ElemType *e));

Status Write(BiTree T,ofstream &outfile);

Status WriteToFile(BiTree T);

Status Read(BiTree *T,ifstream &infile);

Status ReadFromFile(BiTree *T);

Status Change(int *Inisinit,int moro,int where,int * *how, int state);

Status PrintAsTree(BiTree T,Status (* Visit)(ElemType *e));

Status PrintElem(ElemType *e);

Status VisitElem(ElemType *e);


/*--------------------------------------------*/
int main(void) {
    int moro = 0;//�ж��Ƕ������ǵ���
    int choice = 1;//�ж��û���ѡ��
    int where = 0;//ȷ��������λ��
    int *how;//��������ÿ������״̬ 0:δ��ʼ�� 1����ʼ�� 2���Ѵ��� 3�������� 4���ѱ���
    int Isinit = 0;//�����ж����Ƿ��ʼ��
    int number = 0;
    int definition;
    RooTree * T = (RooTree *)malloc(sizeof(RooTree));;
    RooTree * TS = nullptr;//˳������洢������ָ��
    while (choice) {
        cout << "\n\n" << endl;
        cout << "      Menu for Linear Table On Sequence Structure \n" << endl;
        cout << "-------------------------------------------------\n" << endl;
        cout << "    	  1. InitBiTree        13. LeftSibling\n" << endl;
        cout << "    	  2. DestroyBiTree     14. RightSibling\n" << endl;
        cout << "    	  3. CreateBiTree      15. InsertChildBiTNode\n" << endl;
        cout << "    	  4. ClearBiTree       16. DeleteChild\n" << endl;
        cout << "    	  5. BiTreeEmpty       17. PreOrderTraverse\n" << endl;
        cout << "    	  6. BiTreeDepth       18. InOrderTraverse\n" << endl;
        cout << "    	  7. Root              19. PostOrderTraverse\n" << endl;
        cout << "         8. Value             20. LevelOrderTraverse\n" << endl;
        cout << "         9. Assign            21. WriteToFile\n" << endl;
        cout << "         10. Parent           22. ReadFromFile \n" << endl;
        cout << "         11. LeftChild        23. MultiTrees\n" << endl;
        cout << "         12. RightChild       24. SwitchTree\n" << endl;
        cout << "         0. Exit              25. PrintAsTree\n" << endl;
        cout << "-------------------------------------------------\n" << endl;
        if (moro == 1)
            cout << "��ǰ������Ϊ�� " << where << endl;
        cout << "    ��ѡ����Ĳ���[0~25]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:{
                if(Isinit == 1){
                    cout << "��ǰ�ѳ�ʼ����!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 2){
                    cout << "��ǰ���Ѵ���!�޷��ٴγ�ʼ������Ҫ��ʼ����������������!" << endl;
                    system("pause");
                    break;
                }
                if(InitBiTree(T)) {
                    cout << "��ʼ�����ɹ�!" << endl;
                    Change(&Isinit,moro,where,& how,INIT);
                }
                else
                    cout << "��ʼ����ʧ��!" << endl;
                Isinit = 1;
                system("pause");
                break;
            }
            case 2:{
                if(Isinit == 0){
                    cout << "��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                else if (Isinit == 1){
                    cout << "��δ�������޷��������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                else{
                    DestroyBiTree(&T,moro,&where,&Isinit,&how,&TS,&choice,number);
                    system("pause");
                    break;
                }
            }
            case 3:{
                if(Isinit == 0){
                    cout << "��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if (Isinit == 2){
                    cout << "��ǰ���Ѵ������޷��ٴδ�����!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 3 && moro == 1){
                    cout << "��ǰ���ѱ��������޷��ٴδ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "��������:0    ��������:1    ��������:2" << endl;
                cout << "��ѡ����Ĳ���!" << endl;
                while(cin >> definition){
                    if(definition == 0 || definition == 1 || definition == 2)
                        break;
                    else{
                        cout << "�����ֵ���Ϸ�������������!" << endl;
                        continue;
                    }
                }
                cout << "ѧ������#����ǰ���Ϊ�ս��" << endl;
                CreateBiTree(&(*T) -> child,definition);
                if((*T) -> child != nullptr) {
                    Change(&Isinit, moro, where, &how, CREATE);
                    cout << "�������ɹ�!" << endl;
                } else{
                    cout << "�����Ϊ�գ�����δ����!" << endl;
                }
                system("pause");
                break;
            }
            case 4:{
                if(Isinit == 0){
                    cout << "��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 1){
                    cout << "��ǰ���ѳ�ʼ������δ������������޷������!" << endl;
                    system("pause");
                    break;
                }
                else if(Isinit == 3 && moro == 1){
                    cout << "��ǰ���ѱ��������޷��ٴδ���!" << endl;
                    system("pause");
                    break;
                }
                else if(Isinit == 2){
                    ClearBiTree(&(*T) -> child);
                    Change(&Isinit,moro,where,& how,INIT);
                    cout << "������ɹ�!" << endl;
                }
                system("pause");
                break;
            }
            case 5:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTreeEmpty((*T) -> child);
                system("pause");
                break;
            }
            case 6:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                int deepth = BiTreeDepth((*T) -> child);
                cout << "���ĸ߶�Ϊ" << deepth << endl;
                system("pause");
                break;
            }
            case 7:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                Root((*T) -> child);
                system("pause");
                break;
            }
            case 8:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTNode e;
                e.elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "��������Ҫ���ҵ�ѧ��ѧ��:" << endl;
                cin >> e.elem -> id;
                Value((*T) -> child,e);
                free(e.elem);
                system("pause");
                break;
            }
            case 9:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTNode e;
                ElemType value;
                e.elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "������Ŀ��ѧ����ѧ��" << endl;
                cin >> e.elem -> id;
                cout << "����������ı���ѧ�ţ������Լ��ֻ�����" << endl;
                cin >> value.id >> value.name >> value.phone;
                if(Assign(&(*T) -> child,e,value)){
                    cout << "�����ɹ�!" << endl;
                } else{
                    cout << "����ʧ��!" << endl;
                }
                free(e.elem);
                system("pause");
                break;
            }
            case 10:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "������Ҫ��ѯ�����ӽ���ѧ��" << endl;
                cin >> e -> elem -> id;
                Parent((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 11:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "�����븸�׽���ѧ��:" << endl;
                cin >> e -> elem -> id;
                LeftChild((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 12:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "�����븸�׽���ѧ��:" << endl;
                cin >> e -> elem -> id;
                RightChild((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 13:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "������Ŀ�����ѧ��:" << endl;
                cin >> e -> elem -> id;
                LeftSibling((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 14:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "������Ŀ�����ѧ��:" << endl;
                cin >> e -> elem -> id;
                RightSibling((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 15:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "������������ѧ��:" << endl;
                BiTree p;
                p = (BiTree)malloc(sizeof(BiTNode));
                p -> elem = (ElemType*)malloc(sizeof(ElemType));
                cin >> p -> elem -> id;
                cout << "��ѡ�������Ľ��ĺ�������: ����:0   �Һ���:1" << endl;
                int LR;
                while(cin >> LR){
                    if(LR == 0 || LR == 1)
                        break;
                    else
                        cout << "�����ֵ���Ϸ���������ѡ��������: ����:0   �Һ���:1" << endl;
                }
                if(InsertChildBiTNode(&(*T) -> child,p,LR))
                    cout << "����ɹ�!" << endl;
                else
                    cout << "����ʧ��!" << endl;
                system("pause");
                break;
            }
            case 16:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                cout << "������Ҫɾ�����ĸ�����ѧ��:" << endl;
                BiTree p;
                p = (BiTree)malloc(sizeof(BiTNode));
                p -> elem = (ElemType*)malloc(sizeof(ElemType));
                cin >> p -> elem -> id;
                cout << "��ѡ����Ҫɾ���ĺ�������: ����:0   �Һ���:1" << endl;
                int LR;
                while(cin >> LR){
                    if(LR == 0 || LR == 1)
                        break;
                    else
                        cout << "�����ֵ���Ϸ���������ѡ��������: ����:0   �Һ���:1" << endl;
                }
                DeleteChild(&(*T) -> child,p,LR);
                system("pause");
                break;
            }
            case 17:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                PreOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 18:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                InOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 19:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                PostOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 20:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                LevelOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 21:{
                if(Isinit == 0){
                    cout << "��ǰ��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "��ǰ��δ������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "��ǰ���ѱ�������������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if(WriteToFile((*T) -> child))
                    cout << "�洢�ļ��ɹ�!" << endl;
                system("pause");
                break;
            }
            case 22:{
                if(Isinit == 0){
                    cout << "��δ��ʼ����������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                }
                if(Isinit == 2){
                    if(ReadFromFile(&(*T) -> child)) {
                        cout << "��ȡ�ļ��ɹ�" << endl;
                        Change(&Isinit, moro, where, &how, CREATE);
                    }
                }else{
                    if(ReadFromFile(&(*T) -> child)) {
                        cout << "��ȡ�ļ��ɹ�" << endl;
                        Change(&Isinit, moro, where, &how, CREATE);
                    }
                }
                system("pause");
                break;
            }
            case 23:{
                if(moro == 1){
                    cout << "��ǰ�Ѵ��������������ٴδ���!" << endl;
                    system("pause");
                    break;
                }else if(moro == 0 && Isinit == 2){
                    cout << "�Ƿ񱣴浱ǰ�������������棬����Ϊ����!" << endl;
                    cout << "��: 1   ��: 0" << endl;
                    int a;
                    cin >> a;
                    if(a == 1)
                        WriteToFile((*T) -> child);
                }
                cout << "��������Ҫ�����Ķ�����Ŀ:" << endl;
                cin >> number;
                if(number > 0) {
                    TS = (RooTree *) malloc(number * sizeof(RooTree));
                    how = (int *) malloc(number * sizeof(int));
                    for (int i = 0; i < number; i++) {
                        how[i] = 0;
                    }
                    moro = 1;
                    where = 1;
                    T = &TS[where - 1];
                    Change(&Isinit, moro, where, &how, NOTINIT);
                    cout << "���������ɹ�!" << endl;
                    cout << "��ǰ��������Ϊ�� 1" << endl;
                } else{
                    cout << "�����ֵ�������0��������ѡ����Ĳ���!" << endl;
                }
                system("pause");
                break;
            }
            case 24:{
                if( moro == 0){
                    cout << "�����ڶ�����" << endl;
                    system("pause");
                    break;
                }
                //�л�����ʱ��ѯ����һ�����Ƿ񱣴棬�������棬�����˳���ʱ�����ѡ�񱣴�
                if(moro == 1)
                    Isinit = how[where - 1];
                if(Isinit == 2){
                    cout << "�Ƿ�Ҫ����(�������棬�˳�����ʱ���ٴ�ѡ���Ƿ񱣴�)��һ����?�ǣ�1   ��0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile((*T) -> child);
                    }
                }
                cout << "�����뱻�л����������(��������0�˳���������)" << endl;
                int a;
                while(true){
                    cin >> a;
                    if( a == 0)
                        break;
                    if( how[a - 1] == 3 && a <= number && a > 0){
                        cout << "�����ѱ��������޷��л������������������룡" << endl;
                        continue;
                    }
                    if(a > 0 && a <= number) {
                        where = a ;
                        Isinit = how[where - 1];
                        T = &TS[where - 1];
                        break;
                    }
                    cout << "��������򲻴��ڣ�����1--" << number << "ѡ������" << endl;
                }
                system("pause");
                break;
            }
            case 25:{
                cout << "��������: " << '\n' << endl;
                PrintAsTree((*T) -> child,VisitElem);
                break;
            }
            case 0:{
                int i;
                if(moro == 1)//��IsinitΪ����б��������״̬
                    Isinit = how[where - 1];
                if (Isinit != 2 && moro == 0) {
                        cout << "����δ���������ѱ�������" << endl;
                        cout << "�����˳�������!" << endl;
                }
                else{
                        DestroyBiTree(&T,moro,&where,&Isinit,&how,&TS,&choice,number);
                }
                //�ж��Ƿ����е��������棬
                //��û�У����л���δ���������
                if(moro == 1) {
                    for (i = 0; i < number; i++) {
                        if(how[i] != 3){
                            Isinit = how[i];
                            T = &TS[i];
                            where = i + 1;
                            choice = 100;//ֻ��Ϊ���ٴν���ѭ���������Ǿ���Ĳ�������
                            cout << "��ǰ��������Ϊ��" << where << endl;
                            break;
                        }
                    }
                }
                if(moro == 1 && how[where] == 3)
                    cout << "�����˳�����!" << endl;
                system("pause");
                break;
            }
            default :{
                cout << "ָ����ڣ�����������!" << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
/*--------------------------------------------*/

Status InitStack(BiStack &S){
    //����һ����ջ
    S.base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));
    if(!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(BiStack &S,BiTree t){
    //����eԪ��Ϊ�µ�ջ��Ԫ��
    if(S.top - S.base >= S.stacksize){
        S.base = (BiTree *)realloc(S.base,(S.stacksize + STACKINCREMENT) *sizeof(BiTree));
        if(!S.base)
            exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    * (S.top) = t;
    S.top ++;
    return OK;
}

Status Pop(BiStack &S,BiTree &T){
    //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ�����e������ֵ�����ҷ���OK�����򷵻�ERROR
    if(S.top == S.base)
        return ERROR;
    T = *(--S.top);
    return OK;
}

Status InitQueue(LinkQueue &Q){
    Q.base = (BiTree*)malloc(MAXQSIZE * sizeof(BiTree));
    if(!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(LinkQueue &Q){
    free(Q.base);
    return OK;
}

Status EnQueue(LinkQueue &Q,BiTree N){
    if((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = N;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(LinkQueue &Q, BiTree &N){
    if(Q.front == Q.rear)
        return ERROR;
    N = Q.base[Q.front];
    Q.front = (Q.front + 1 ) % MAXQSIZE;
    return OK;
}

Status InitBiTree(RooTree *T){
    (*T) = (RooTree)malloc(sizeof(RooTNode));
    (*T) -> child = nullptr;
    if(!(*T))
        return OVERFLOW;
    else{
        return OK;
    }
}


Status DestroyBiTree(RooTree **T,int moro,int *where,int *Isinit,int **how,RooTree **TS,int *choice,int number){
    if(*Isinit != 0 && (**T) -> child){
        int i;
        if(moro == 1)//��IsinitΪ����б��������״̬
            *Isinit = (*how)[*where - 1];
        if(moro == 0){
            cout << "�Ƿ񱣴浱ǰ��?�ǣ�1   ��0" << endl;
            cin >> i;
            if(i) {
                WriteToFile((**T)->child);
                cout << "�����ļ��ɹ�!" << endl;
            }
            ClearBiTree(&(**T) -> child );
            Change(Isinit,moro,*where,how,NOTINIT);
            if(*choice == 0)
                cout << "�����˳�������!" << endl;
            return OK;
        }
        else if(moro == 1 && *Isinit == 2){
            cout << "�Ƿ�Ҫ���浱ǰ��?�ǣ�1   ��0" << endl;
            cin >> i;
            if (i) {
                WriteToFile((**T) -> child);
                cout << "�����ļ��ɹ�!" << endl;
                (*how)[*where - 1] = 3;
                ClearBiTree(&(**T)->child);
                Change(Isinit, moro, *where, how, ABANDON);
                cout << "�������ɹ�!" << endl;
            } else {
                //�������иı䲻�����״̬����ɾ�������Ĵ��ڣ�������Ϊ���
                ClearBiTree(&(**T)->child);
                Change(Isinit, moro, *where, how, ABANDON);
                cout << "�������ɹ�!" << endl;
            }
        }
        //�ж��Ƿ����е��������棬
        //��û�У����л���δ���������
        if(moro == 1) {
            for (i = 0; i < number; i++) {
                if((*how)[i] != 3){
                    *Isinit = (*how)[i];
                    *T = &((*TS)[i]);
                    *where = i + 1;
                    *choice = 100;//ֻ��Ϊ���ٴν���ѭ���������Ǿ���Ĳ�������
                    cout << "��ǰ��������Ϊ��" << *where << endl;
                    break;
                }
            }
            if(i == number) {
                cout << "ʣ������ѱ���������������˳�����" << endl;
                *choice = 0;
            }
        }
        return OK;
    }else {
        if(*choice != 0)
            cout << "��δ�������޷�����!" << endl;
        else if(moro == 1)
            cout << "ɾ����ǰ���ɹ�!" << endl;
        Change(Isinit,moro,*where,how,ABANDON);
        return FALSE;
    }
}

Status CreateBiTree(BiTree *T,int definition){
    //������������������������ֵ
    if(definition == BEF){
        ElemType e;
        cout << "������ѧ����ѧ��" << endl;
        cin >> e.id;
        if(!strcmp(e.id,"#")) {
            cout << "��ǰ���Ϊ�ս�㣬��������һ��ѧ����ѧ��" << endl;
            (*T) = nullptr;
        }
        else{
            cout << "������ѧ���������Լ���ϵ��ʽ" << endl;
            cin >> e.name >> e.phone;
            if(!((*T) = (BiTree)malloc(sizeof(BiTNode))))
                exit(OVERFLOW);
            (*T) -> elem = nullptr;
            if (!((*T)->elem = (ElemType *) malloc(sizeof(ElemType))))
                exit(OVERFLOW);
            (*T) -> lchild = nullptr;
            (*T) -> rchild = nullptr;
            *((*T) -> elem) = e;
            CreateBiTree(&(*T) -> lchild,definition);
            CreateBiTree(&(*T) -> rchild,definition);
        }
        return OK;
    }
    else if(definition == MID){
        ElemType e;
        cin >> e.id;
        if(!strcmp(e.id,"#"))
            (*T) = nullptr;
        else{
            cin >> e.name >> e.phone;
            if(!((*T) = (BiTree)malloc(sizeof(BiTNode))))
                    exit(OVERFLOW);
            (*T) -> elem = nullptr;
            if (!((*T)->elem = (ElemType *) malloc(sizeof(ElemType))))
                exit(OVERFLOW);
            (*T) -> lchild = nullptr;
            (*T) -> rchild = nullptr;
            CreateBiTree(&(*T) -> lchild,definition);
            *((*T) -> elem) = e;
            CreateBiTree(&(*T) -> rchild,definition);
        }
        return OK;
    }
    else if(definition == AFT){
        ElemType e;
        cin >> e.id;
        if(!strcmp(e.id,"#"))
            (*T) = nullptr;
        else{
            cin >> e.name >> e.phone;
            if(!((*T) = (BiTree)malloc(sizeof(BiTNode))))
                exit(OVERFLOW);
            (*T) -> elem = nullptr;
            if (!((*T)->elem = (ElemType *) malloc(sizeof(ElemType))))
                exit(OVERFLOW);
            (*T) -> lchild = nullptr;
            (*T) -> rchild = nullptr;
            CreateBiTree(&(*T) -> lchild,definition);
            CreateBiTree(&(*T) -> rchild,definition);
            *((*T) -> elem) = e;
        }
        return OK;
    }
    return OK;
}

//�˺�����caseʵ�����ں��治��ɾ���׽��
Status ClearBiTree (BiTree *T){
    if(*T){
        ClearBiTree(&(*T) -> lchild);
        ClearBiTree(&(*T) -> rchild);
        //�ͷ�������е����б���
        free((*T) -> elem);
        free((*T));
        (*T) = nullptr;
    }else
        return OK;
}

Status BiTreeEmpty(BiTree T){
    if(!T || !(T -> elem))
        cout << "��Ϊ��!" << endl;
    else
        cout << "���ǿ�!" << endl;
    return OK;
}

int BiTreeDepth(BiTree T){
    int hl,hr,max;
    if(T){
        hl = BiTreeDepth(T -> lchild);
        hr = BiTreeDepth(T -> rchild);
        max = (hl > hr) ? hl : hr;
        return (max + 1);
    }
    else
        return 0;
}

Status Root(BiTree T){
    if(T){
        cout << "�����ڵ����ϢΪ:" << endl;
        cout << "name:" << T -> elem -> id << endl;
        cout << "age:" << T -> elem -> name << endl;
        cout << "phone:" << T -> elem -> phone << endl;
        return OK;
    }
    else
        cout << "��Ϊ��!" << endl;
    return FALSE;
}

Status Value(BiTree T,BiTNode e){
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            Push(S,T);
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            if(!strcmp(e.elem -> id, T -> elem -> id)){
                cout << "Ŀ��ѧ������ϢΪ:" << endl;
                cout << "id: " << T -> elem -> id << endl;
                cout << "name: " << T -> elem -> name << endl;
                cout << "phone: " << T -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            T = T -> rchild;
        }
    }
    cout << "Ŀ��ѧ��������!" << endl;
    free(S.base);
    return FALSE;
}

Status Assign(BiTree *T,BiTNode &e,ElemType value){
    BiStack S;
    InitStack(S);
    while ((*T) || S.top != S.base){
        while ((*T)){
            Push(S,(*T));
            (*T) = (*T) -> lchild;
        }
        if(S.base != S.top){
            Pop(S,(*T));
            if(!strcmp(e.elem -> id,(*T) -> elem -> id)){
                cout << "Ŀ��ѧ������ϢΪ:" << endl;
                cout << "name: " << (*T) -> elem -> id << endl;
                cout << "name: " << (*T) -> elem -> name << endl;
                cout << "name: " << (*T) -> elem -> phone << endl;
                *((*T) -> elem) = value;
                cout << "�޸ĺ��ѧ����ϢΪ:" << endl;
                cout << "name: " << (*T) -> elem -> id << endl;
                cout << "name: " << (*T) -> elem -> name << endl;
                cout << "name: " << (*T) -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            (*T) = (*T) -> rchild;
        }
    }
    cout << "Ŀ��ѧ��������!" << endl;
    free(S.base);
    return FALSE;
}

Status Parent(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "Ŀ����Ϊ����㣬�����ڸ���㣬������ѡ����Ĳ���!" << endl;
        return FALSE;
    }
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                cout << "Ŀ�����˫�׵���ϢΪ:" << endl;
                cout << "name: " << T -> elem -> id << endl;
                cout << "name: " << T -> elem -> name << endl;
                cout << "name: " << T -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            Push(S,T);
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            if(T -> rchild && !strcmp(T -> rchild -> elem -> id,e -> elem -> id)){
                cout << "Ŀ�����˫�׵���ϢΪ:" << endl;
                cout << "name: " << T -> elem -> id << endl;
                cout << "name: " << T -> elem -> name << endl;
                cout << "name: " << T -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            T = T -> rchild;
        }
    }
    cout << "Ŀ��ѧ��������!����˫�ײ�����!" << endl;
    free(S.base);
    return FALSE;
}

Status LeftChild(BiTree T,BiTree e){
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            if(!strcmp(T -> elem -> id,e -> elem -> id)){
                if(T -> lchild){
                    cout << "Ŀ�����������ϢΪ:" << endl;
                    cout << "name: " << T -> lchild -> elem -> id << endl;
                    cout << "age: " << T -> lchild -> elem -> name << endl;
                    cout << "phone: " << T -> lchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }else{
                    cout << "Ŀ���㲻��������!" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            Push(S,T);
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            T = T -> rchild;
        }
    }
    free(S.base);
    cout << "Ŀ���㲻���ڣ�������ѡ����Ĳ���!" << endl;
    return FALSE;
}

Status RightChild(BiTree T,BiTree e){
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            Push(S,T);
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            if(!strcmp(T -> elem -> id,e -> elem -> id)){
                if(T -> rchild){
                    cout << "Ŀ������Һ�����ϢΪ:" << endl;
                    cout << "name: " << T -> rchild -> elem -> id << endl;
                    cout << "age: " << T -> rchild -> elem -> name << endl;
                    cout << "phone: " << T -> rchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }else{
                    cout << "Ŀ���㲻�����Һ���!" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            T = T -> rchild;
        }
    }
    free(S.base);
    cout << "Ŀ���㲻���ڣ�������ѡ����Ĳ���!" << endl;
    return FALSE;
}

Status LeftSibling(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "Ŀ����Ϊ����㣬���������ֵܣ�������ѡ����Ĳ���!" << endl;
        return FALSE;
    }
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            Push(S,T);
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            if(T -> rchild && !strcmp(T -> rchild -> elem -> id,e -> elem -> id)){
                if(T -> lchild){
                    cout << "Ŀ��������ֵ���ϢΪ:" << endl;
                    cout << "name: " << T -> lchild -> elem -> id << endl;
                    cout << "age: " << T -> lchild -> elem -> name << endl;
                    cout << "phone: " << T -> lchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }
                else{
                    cout << "Ŀ���㲻�������ֵ�" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            else if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                free(S.base);
                cout << "Ŀ���㲻�������ֵ�!" << endl;
                return FALSE;
            }
            T = T -> rchild;
        }
    }
    free(S.base);
    cout << "Ŀ���㲻����!" << endl;
    return FALSE;
}

Status RightSibling(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "Ŀ����Ϊ����㣬���������ֵܣ�������ѡ����Ĳ���!" << endl;
        return FALSE;
    }
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            Push(S,T);
            if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                if(T -> rchild){
                    cout << "Ŀ��������ֵ���ϢΪ:" << endl;
                    cout << "name: " << T -> rchild -> elem -> id << endl;
                    cout << "age: " << T -> rchild -> elem -> name << endl;
                    cout << "phone: " << T -> rchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }
                else{
                    cout << "Ŀ���㲻�������ֵ�" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            else if(T -> rchild && !strcmp(T -> rchild -> elem -> id,e -> elem -> id)){
                free(S.base);
                cout << "Ŀ���㲻�������ֵ�!" << endl;
                return FALSE;
            }
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            T = T -> rchild;
        }
    }
    cout << "Ŀ���㲻����!" << endl;
    free(S.base);
    return FALSE;
}

Status InsertChildBiTNode (BiTree *T,BiTree p,int LR){
    BiStack S;
    InitStack(S);
    BiTree G = *T;
    BiTree H = (BiTree)malloc(sizeof(BiTNode));
    int definition;
    cout << "��������:0    ��������:1    ��������:2" << endl;
    cout << "��ѡ����Ĳ���!" << endl;
    while(cin >> definition){
        if(definition == 0 || definition == 1 || definition == 2)
            break;
        else{
            cout << "�����ֵ���Ϸ�������������!" << endl;
            continue;
        }
    }
    cout << "ѧ������#����ǰ���Ϊ�ս��" << endl;
    cout << "������������������ڣ�����Ϊ��ȥ������!" << endl;
    CreateBiTree(&H,definition);
    while ((*T) || S.top != S.base){
        while ((*T)){
            Push(S,(*T));
            (*T) = (*T) -> lchild;
        }
        if(S.base != S.top){
            Pop(S,(*T));
            if(!strcmp((*T) -> elem -> id,p -> elem -> id)){
                p = (*T);
                if(LR == 0){
                    H -> rchild = p -> lchild;
                    (*T) -> lchild = H;
                }else{
                    H -> rchild = p -> rchild;
                    (*T) -> rchild = H;
                }
                *T = G;
                return OK;
            }
            (*T) = (*T) -> rchild;
        }
    }
    *T = G;
    cout << "������Ŀ����!" << endl;
    return FALSE;
}

Status DeleteChild(BiTree *T,BiTree p,int LR){
    BiTree H = (*T);
    BiStack S;
    InitStack(S);
    while (LR != 0 && LR != 1) {
        cout << "ѡ����������ָ��Ϸ�����ȷ����Ҫɾ������������(��:0  ��:1)" << endl;
        cin >> LR;
        if(LR == 0 || LR == 1)
            break;
    }
    while ((*T) || S.top != S.base){
        while ((*T)){
            Push(S,(*T));
            (*T) = (*T) -> lchild;
        }
        if(S.base != S.top){
            Pop(S,(*T));
            if(!strcmp((*T) -> elem -> id,p -> elem -> id)){
                if(LR == 0){
                    if((*T) -> lchild) {
                        cout << "ɾ�����ɹ�!" << endl;
                        (*T)->lchild = nullptr;
                    }
                    else
                        cout << "Ŀ���㲻�������������޷�ɾ��!" << endl;
                } else if(LR == 1){
                    if((*T) -> rchild) {
                        cout << "ɾ�����ɹ�!" << endl;
                        (*T)->rchild = nullptr;
                    }
                    else
                        cout << "Ŀ���㲻�������������޷�ɾ��!" << endl;
                }
                (*T) = H;
                return OK;
            }
            (*T) = (*T) -> rchild;
        }
    }
    (*T) = H;
    return OK;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(ElemType *e)){
    if(T) {
        if (Visit(T->elem)) {
            if (PreOrderTraverse(T->lchild,Visit))
                if (PreOrderTraverse(T->rchild,Visit))
                    return OK;
        }
        return ERROR;
    }
    else
        return OK;
}

Status InOrderTraverse(BiTree T,Status(* Visit)(ElemType *e)){
    if(T) {
        if (InOrderTraverse(T->lchild,Visit)) {
            if (Visit(T -> elem)) {
                if (InOrderTraverse(T->rchild,Visit))
                    return OK;
            }
            else
                return ERROR;
        }
    }
    else
        return OK;
}

Status PostOrderTraverse(BiTree T,Status(* Visit)(ElemType *e)){
    if(T) {
        if (PostOrderTraverse(T->lchild,Visit))
            if (PostOrderTraverse(T->rchild,Visit)){
                if(!Visit(T -> elem))
                    exit(ERROR);
            }
                return OK;
    }
    else
        return OK;
}

Status LevelOrderTraverse(BiTree T,Status(* Visit)(ElemType *e)){
    if(!T){
        cout << "��Ϊ����!" << endl;
        return OK;
    }
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    while(Q.front != Q.rear) {
        DeQueue(Q,T);
        if(!Visit(T -> elem))
            exit(ERROR);
        if(T -> lchild)
            EnQueue(Q,T -> lchild);
        if(T -> rchild)
            EnQueue(Q,T -> rchild);
    }
    DestroyQueue(Q);
    return OK;
}

Status Write(BiTree T,ofstream &outfile){
    if(T) {
        if (outfile << T -> elem -> id << '\n'
                << T -> elem -> name << '\n'
                << T -> elem -> phone << endl)
        {
            if (Write(T->lchild,outfile))
                if (Write(T->rchild,outfile))
                    return OK;
        }
        return ERROR;
    }
    else {
        outfile << "#" << endl;
        return OK;
    }
}

Status WriteToFile(BiTree T){
    char filename[20];
    cout << "�����ļ����ƣ�������20���ַ���:" << endl;
    cin >> filename;
    strcat(filename,".txt");
    ofstream outfile;
    outfile.open(filename,std::ios::out);
    if(outfile){
        Write(T,outfile);
        outfile.close();
        return OK;
    } else
        cout << "�����ļ�ʧ��!" << endl;
    return FALSE;
}

Status Read(BiTree *T,ifstream &infile){
    ElemType e;
    infile >> e.id;
    if(!strcmp(e.id,"#"))
        (*T) = nullptr;
    else{
        infile >> e.name >> e.phone;
        if(!((*T) = (BiTree)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        (*T) -> elem = nullptr;
        if (!((*T)->elem = (ElemType *) malloc(sizeof(ElemType))))
            exit(OVERFLOW);
        (*T) -> lchild = nullptr;
        (*T) -> rchild = nullptr;
        *((*T) -> elem) = e;
        Read(&(*T) -> lchild,infile);
        Read(&(*T) -> rchild,infile);
    }
    return OK;
}

Status ReadFromFile(BiTree *T){
    char filename[20];
    cout << "�����ȡ�ļ����ƣ�������20���ַ���:" << endl;
    cin >> filename;
    strcat(filename, ".txt");
    ifstream infile;
    infile.open(filename, std::ios::in);
    if(infile){
        ClearBiTree(T);
        Read(T,infile);
        infile.close();
        return OK;
    } else {
        cout << "�����ڴ��ļ�!" << endl;
        return ERROR;
    }
}

Status Change(int *Inisinit,int moro,int where,int * *how, int state){
    if(moro == 1){
        (*how)[where - 1] = state;
        *Inisinit = (*how)[where - 1];
    } else
        *Inisinit = state;
    return OK;
}

Status PrintAsTree(BiTree T,Status(* Visit)(ElemType *e)){
    if(!T){
        cout << "��Ϊ����!" << endl;
        return OK;
    }
    BiTree F = (BiTree)malloc(sizeof(BiTNode));//�䵱�ս��
    F -> elem = nullptr;
    F -> lchild = F -> rchild = nullptr;
    int length;
    length = strlen(T -> elem ->id);//id�ĳ���
    int height;
    height = BiTreeDepth(T);//���ĸ߶�
    int depth = 1;//��ǰ���ڵĲ���(������ӡ��״̬)
    int children = 1;//�Ѵ�ӡ��������(������ӡ���״̬)
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    //�����ǰ��ղ��ִ�ӡ
    for(int a = 0; a < length * (pow(2,height - depth) - 1);a++){
        printf(" ");
    }
    //������ӡ
    if(!PrintElem(T -> elem))
        exit(ERROR);
    //ʣ�����ӡ
    while(Q.front != Q.rear) {
        if(children == pow(2,depth) - 1) {//ÿһ��ǰ��Ŀղ���
            depth++;
            printf("\n");
            for (int a = 0; a < length * (pow(2,height - depth) - 1); a++) {
                printf(" ");
            }
        }
        if(children == pow(2,height) - 1)
            break;
        DeQueue(Q,T);
        if(T -> lchild) {
            EnQueue(Q, T->lchild);
            if(!PrintElem(T -> lchild -> elem))
                exit(ERROR);
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        } else{
            EnQueue(Q,F);
            for(int a = 0;a < length;a++)//�䵱���
                printf(" ");
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        }
        if(T -> rchild) {
            EnQueue(Q, T->rchild);
            if(!PrintElem(T -> rchild -> elem))//��ӡ���
                exit(ERROR);
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        }else{
            EnQueue(Q,F);
            for(int a = 0;a < length;a++)//�䵱���
                printf(" ");
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        }
    }
    DestroyQueue(Q);
    return OK;
}

Status VisitElem(ElemType *e){
    cout << "ID:" << e -> id << endl;
    cout << "Name:" << e -> name << endl;
    cout << "Phone:" << e -> phone << endl;
    return OK;
}


Status PrintElem(ElemType *e) {
    printf("%s",e -> id);
    return OK;
}