/**
 * 本实验每个树都有一个首结点
 * 且首节点的左孩子和右孩子均指向该树的根结点
 * 函数中传入的值一般是根结点的左孩子(或右孩子)，即根结点
 */

/**
 * 当树未创建时，不能销毁树
 * 当树创建时，销毁树
 *  1.单树时，单树成为未初始化状态
 *  2.多树时，将舍弃多树中的此树
 * 未创建和已创建的条件下均可以通过exit退出当前树
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

#define BEF 0 //先序序列输入
#define MID 1 //中序序列输入
#define AFT 2 //后序序列输入
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
    int moro = 0;//判断是多树还是单树
    int choice = 1;//判断用户的选择
    int where = 0;//确定多树的位置
    int *how;//用来保存每个树的状态 0:未初始化 1：初始化 2：已创建 3：已舍弃 4：已保存
    int Isinit = 0;//用来判断树是否初始化
    int number = 0;
    int definition;
    RooTree * T = (RooTree *)malloc(sizeof(RooTree));;
    RooTree * TS = nullptr;//顺序表来存储多树的指针
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
            cout << "当前操作的为树 " << where << endl;
        cout << "    请选择你的操作[0~25]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:{
                if(Isinit == 1){
                    cout << "当前已初始化树!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 2){
                    cout << "当前树已创建!无法再次初始化，若要初始化树，请先销毁树!" << endl;
                    system("pause");
                    break;
                }
                if(InitBiTree(T)) {
                    cout << "初始化树成功!" << endl;
                    Change(&Isinit,moro,where,& how,INIT);
                }
                else
                    cout << "初始化树失败!" << endl;
                Isinit = 1;
                system("pause");
                break;
            }
            case 2:{
                if(Isinit == 0){
                    cout << "树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                else if (Isinit == 1){
                    cout << "树未创建，无法清空树，请重新选择你的操作!" << endl;
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
                    cout << "树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if (Isinit == 2){
                    cout << "当前树已创建，无法再次创建树!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 3 && moro == 1){
                    cout << "当前树已被舍弃，无法再次创建!" << endl;
                    system("pause");
                    break;
                }
                cout << "先序输入:0    中序输入:1    后序输入:2" << endl;
                cout << "请选择你的操作!" << endl;
                while(cin >> definition){
                    if(definition == 0 || definition == 1 || definition == 2)
                        break;
                    else{
                        cout << "输入的值不合法，请重新输入!" << endl;
                        continue;
                    }
                }
                cout << "学号输入#代表当前结点为空结点" << endl;
                CreateBiTree(&(*T) -> child,definition);
                if((*T) -> child != nullptr) {
                    Change(&Isinit, moro, where, &how, CREATE);
                    cout << "创建树成功!" << endl;
                } else{
                    cout << "根结点为空，故树未创建!" << endl;
                }
                system("pause");
                break;
            }
            case 4:{
                if(Isinit == 0){
                    cout << "树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 1){
                    cout << "当前树已初始化，但未被创建，因此无法清空树!" << endl;
                    system("pause");
                    break;
                }
                else if(Isinit == 3 && moro == 1){
                    cout << "当前树已被舍弃，无法再次创建!" << endl;
                    system("pause");
                    break;
                }
                else if(Isinit == 2){
                    ClearBiTree(&(*T) -> child);
                    Change(&Isinit,moro,where,& how,INIT);
                    cout << "清空树成功!" << endl;
                }
                system("pause");
                break;
            }
            case 5:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTreeEmpty((*T) -> child);
                system("pause");
                break;
            }
            case 6:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                int deepth = BiTreeDepth((*T) -> child);
                cout << "树的高度为" << deepth << endl;
                system("pause");
                break;
            }
            case 7:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                Root((*T) -> child);
                system("pause");
                break;
            }
            case 8:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTNode e;
                e.elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入你要查找的学生学号:" << endl;
                cin >> e.elem -> id;
                Value((*T) -> child,e);
                free(e.elem);
                system("pause");
                break;
            }
            case 9:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTNode e;
                ElemType value;
                e.elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入目标学生的学号" << endl;
                cin >> e.elem -> id;
                cout << "请依次输入改变后的学号，姓名以及手机号码" << endl;
                cin >> value.id >> value.name >> value.phone;
                if(Assign(&(*T) -> child,e,value)){
                    cout << "操作成功!" << endl;
                } else{
                    cout << "操作失败!" << endl;
                }
                free(e.elem);
                system("pause");
                break;
            }
            case 10:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入要查询结点的子结点的学号" << endl;
                cin >> e -> elem -> id;
                Parent((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 11:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入父亲结点的学号:" << endl;
                cin >> e -> elem -> id;
                LeftChild((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 12:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入父亲结点的学号:" << endl;
                cin >> e -> elem -> id;
                RightChild((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 13:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入目标结点的学号:" << endl;
                cin >> e -> elem -> id;
                LeftSibling((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 14:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                BiTree e;
                e = (BiTree)malloc(sizeof(BiTNode));
                e -> elem = (ElemType *)malloc(sizeof(ElemType));
                cout << "请输入目标结点的学号:" << endl;
                cin >> e -> elem -> id;
                RightSibling((*T) -> child,e);
                free(e -> elem);
                free(e);
                system("pause");
                break;
            }
            case 15:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "请输入插入结点的学号:" << endl;
                BiTree p;
                p = (BiTree)malloc(sizeof(BiTNode));
                p -> elem = (ElemType*)malloc(sizeof(ElemType));
                cin >> p -> elem -> id;
                cout << "请选择你插入的结点的孩子类型: 左孩子:0   右孩子:1" << endl;
                int LR;
                while(cin >> LR){
                    if(LR == 0 || LR == 1)
                        break;
                    else
                        cout << "输入的值不合法，请重新选择孩子类型: 左孩子:0   右孩子:1" << endl;
                }
                if(InsertChildBiTNode(&(*T) -> child,p,LR))
                    cout << "插入成功!" << endl;
                else
                    cout << "插入失败!" << endl;
                system("pause");
                break;
            }
            case 16:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                cout << "请输入要删除结点的父结点的学号:" << endl;
                BiTree p;
                p = (BiTree)malloc(sizeof(BiTNode));
                p -> elem = (ElemType*)malloc(sizeof(ElemType));
                cin >> p -> elem -> id;
                cout << "请选择你要删除的孩子类型: 左孩子:0   右孩子:1" << endl;
                int LR;
                while(cin >> LR){
                    if(LR == 0 || LR == 1)
                        break;
                    else
                        cout << "输入的值不合法，请重新选择孩子类型: 左孩子:0   右孩子:1" << endl;
                }
                DeleteChild(&(*T) -> child,p,LR);
                system("pause");
                break;
            }
            case 17:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                PreOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 18:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                InOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 19:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                PostOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 20:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                LevelOrderTraverse((*T) -> child,VisitElem);
                system("pause");
                break;
            }
            case 21:{
                if(Isinit == 0){
                    cout << "当前树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }else if(Isinit == 1){
                    cout << "当前树未创建，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else if(Isinit == 3){
                    cout << "当前树已被舍弃，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                if(WriteToFile((*T) -> child))
                    cout << "存储文件成功!" << endl;
                system("pause");
                break;
            }
            case 22:{
                if(Isinit == 0){
                    cout << "树未初始化，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                }
                if(Isinit == 2){
                    if(ReadFromFile(&(*T) -> child)) {
                        cout << "读取文件成功" << endl;
                        Change(&Isinit, moro, where, &how, CREATE);
                    }
                }else{
                    if(ReadFromFile(&(*T) -> child)) {
                        cout << "读取文件成功" << endl;
                        Change(&Isinit, moro, where, &how, CREATE);
                    }
                }
                system("pause");
                break;
            }
            case 23:{
                if(moro == 1){
                    cout << "当前已创建多树。无需再次创建!" << endl;
                    system("pause");
                    break;
                }else if(moro == 0 && Isinit == 2){
                    cout << "是否保存当前单树，若不保存，则视为丢弃!" << endl;
                    cout << "是: 1   否: 0" << endl;
                    int a;
                    cin >> a;
                    if(a == 1)
                        WriteToFile((*T) -> child);
                }
                cout << "请输入你要创建的多树数目:" << endl;
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
                    cout << "多树创建成功!" << endl;
                    cout << "当前操作的树为树 1" << endl;
                } else{
                    cout << "输入的值必须大于0，请重新选择你的操作!" << endl;
                }
                system("pause");
                break;
            }
            case 24:{
                if( moro == 0){
                    cout << "不存在多树！" << endl;
                    system("pause");
                    break;
                }
                //切换树的时候询问上一个树是否保存，若不保存，后面退出的时候可以选择保存
                if(moro == 1)
                    Isinit = how[where - 1];
                if(Isinit == 2){
                    cout << "是否要保存(若不保存，退出程序时可再次选择是否保存)上一个树?是：1   否：0" << endl;
                    int i;
                    cin >> i;
                    if (i) {
                        WriteToFile((*T) -> child);
                    }
                }
                cout << "请输入被切换到树的序号(输入数字0退出切树功能)" << endl;
                int a;
                while(true){
                    cin >> a;
                    if( a == 0)
                        break;
                    if( how[a - 1] == 3 && a <= number && a > 0){
                        cout << "此树已被舍弃！无法切换到该树！请重新输入！" << endl;
                        continue;
                    }
                    if(a > 0 && a <= number) {
                        where = a ;
                        Isinit = how[where - 1];
                        T = &TS[where - 1];
                        break;
                    }
                    cout << "输入的树序不存在，请在1--" << number << "选择输入" << endl;
                }
                system("pause");
                break;
            }
            case 25:{
                cout << "树形如下: " << '\n' << endl;
                PrintAsTree((*T) -> child,VisitElem);
                break;
            }
            case 0:{
                int i;
                if(moro == 1)//让Isinit为多表中被操作表的状态
                    Isinit = how[where - 1];
                if (Isinit != 2 && moro == 0) {
                        cout << "此树未被创建或已被舍弃！" << endl;
                        cout << "即将退出本程序!" << endl;
                }
                else{
                        DestroyBiTree(&T,moro,&where,&Isinit,&how,&TS,&choice,number);
                }
                //判断是否所有的树被保存，
                //若没有，则切换到未保存的树。
                if(moro == 1) {
                    for (i = 0; i < number; i++) {
                        if(how[i] != 3){
                            Isinit = how[i];
                            T = &TS[i];
                            where = i + 1;
                            choice = 100;//只是为了再次进入循环，而不是具体的操作命令
                            cout << "当前操作的树为树" << where << endl;
                            break;
                        }
                    }
                }
                if(moro == 1 && how[where] == 3)
                    cout << "即将退出程序!" << endl;
                system("pause");
                break;
            }
            default :{
                cout << "指令不存在，请重新输入!" << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
/*--------------------------------------------*/

Status InitStack(BiStack &S){
    //构造一个空栈
    S.base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));
    if(!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(BiStack &S,BiTree t){
    //插入e元素为新的栈顶元素
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
    //若栈不为空，则删除S的栈顶元素，并用e返回其值，并且返回OK；否则返回ERROR
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
        if(moro == 1)//让Isinit为多表中被操作表的状态
            *Isinit = (*how)[*where - 1];
        if(moro == 0){
            cout << "是否保存当前树?是：1   否：0" << endl;
            cin >> i;
            if(i) {
                WriteToFile((**T)->child);
                cout << "保存文件成功!" << endl;
            }
            ClearBiTree(&(**T) -> child );
            Change(Isinit,moro,*where,how,NOTINIT);
            if(*choice == 0)
                cout << "即将退出本程序!" << endl;
            return OK;
        }
        else if(moro == 1 && *Isinit == 2){
            cout << "是否要保存当前树?是：1   否：0" << endl;
            cin >> i;
            if (i) {
                WriteToFile((**T) -> child);
                cout << "保存文件成功!" << endl;
                (*how)[*where - 1] = 3;
                ClearBiTree(&(**T)->child);
                Change(Isinit, moro, *where, how, ABANDON);
                cout << "销毁树成功!" << endl;
            } else {
                //将多树中改变不保存的状态，即删除该树的存在；单树视为清空
                ClearBiTree(&(**T)->child);
                Change(Isinit, moro, *where, how, ABANDON);
                cout << "销毁树成功!" << endl;
            }
        }
        //判断是否所有的树被保存，
        //若没有，则切换到未保存的树。
        if(moro == 1) {
            for (i = 0; i < number; i++) {
                if((*how)[i] != 3){
                    *Isinit = (*how)[i];
                    *T = &((*TS)[i]);
                    *where = i + 1;
                    *choice = 100;//只是为了再次进入循环，而不是具体的操作命令
                    cout << "当前操作的树为树" << *where << endl;
                    break;
                }
            }
            if(i == number) {
                cout << "剩余的树已保存或被舍弃，即将退出程序！" << endl;
                *choice = 0;
            }
        }
        return OK;
    }else {
        if(*choice != 0)
            cout << "树未创建，无法销毁!" << endl;
        else if(moro == 1)
            cout << "删除当前树成功!" << endl;
        Change(Isinit,moro,*where,how,ABANDON);
        return FALSE;
    }
}

Status CreateBiTree(BiTree *T,int definition){
    //按照先序次序输入二叉树结点的值
    if(definition == BEF){
        ElemType e;
        cout << "请输入学生的学号" << endl;
        cin >> e.id;
        if(!strcmp(e.id,"#")) {
            cout << "当前结点为空结点，请输入下一个学生的学号" << endl;
            (*T) = nullptr;
        }
        else{
            cout << "请输入学生的姓名以及联系方式" << endl;
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

//此函数在case实例中在后面不会删除首结点
Status ClearBiTree (BiTree *T){
    if(*T){
        ClearBiTree(&(*T) -> lchild);
        ClearBiTree(&(*T) -> rchild);
        //释放树结点中的所有变量
        free((*T) -> elem);
        free((*T));
        (*T) = nullptr;
    }else
        return OK;
}

Status BiTreeEmpty(BiTree T){
    if(!T || !(T -> elem))
        cout << "树为空!" << endl;
    else
        cout << "树非空!" << endl;
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
        cout << "树根节点的信息为:" << endl;
        cout << "name:" << T -> elem -> id << endl;
        cout << "age:" << T -> elem -> name << endl;
        cout << "phone:" << T -> elem -> phone << endl;
        return OK;
    }
    else
        cout << "树为空!" << endl;
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
                cout << "目标学生的信息为:" << endl;
                cout << "id: " << T -> elem -> id << endl;
                cout << "name: " << T -> elem -> name << endl;
                cout << "phone: " << T -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            T = T -> rchild;
        }
    }
    cout << "目标学生不存在!" << endl;
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
                cout << "目标学生的信息为:" << endl;
                cout << "name: " << (*T) -> elem -> id << endl;
                cout << "name: " << (*T) -> elem -> name << endl;
                cout << "name: " << (*T) -> elem -> phone << endl;
                *((*T) -> elem) = value;
                cout << "修改后的学生信息为:" << endl;
                cout << "name: " << (*T) -> elem -> id << endl;
                cout << "name: " << (*T) -> elem -> name << endl;
                cout << "name: " << (*T) -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            (*T) = (*T) -> rchild;
        }
    }
    cout << "目标学生不存在!" << endl;
    free(S.base);
    return FALSE;
}

Status Parent(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "目标结点为根结点，不存在父结点，请重新选择你的操作!" << endl;
        return FALSE;
    }
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                cout << "目标结点的双亲的信息为:" << endl;
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
                cout << "目标结点的双亲的信息为:" << endl;
                cout << "name: " << T -> elem -> id << endl;
                cout << "name: " << T -> elem -> name << endl;
                cout << "name: " << T -> elem -> phone << endl;
                free(S.base);
                return OK;
            }
            T = T -> rchild;
        }
    }
    cout << "目标学生不存在!故其双亲不存在!" << endl;
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
                    cout << "目标结点的左孩子信息为:" << endl;
                    cout << "name: " << T -> lchild -> elem -> id << endl;
                    cout << "age: " << T -> lchild -> elem -> name << endl;
                    cout << "phone: " << T -> lchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }else{
                    cout << "目标结点不存在左孩子!" << endl;
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
    cout << "目标结点不存在，请重新选择你的操作!" << endl;
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
                    cout << "目标结点的右孩子信息为:" << endl;
                    cout << "name: " << T -> rchild -> elem -> id << endl;
                    cout << "age: " << T -> rchild -> elem -> name << endl;
                    cout << "phone: " << T -> rchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }else{
                    cout << "目标结点不存在右孩子!" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            T = T -> rchild;
        }
    }
    free(S.base);
    cout << "目标结点不存在，请重新选择你的操作!" << endl;
    return FALSE;
}

Status LeftSibling(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "目标结点为根结点，不存在左兄弟，请重新选择你的操作!" << endl;
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
                    cout << "目标结点的左兄弟信息为:" << endl;
                    cout << "name: " << T -> lchild -> elem -> id << endl;
                    cout << "age: " << T -> lchild -> elem -> name << endl;
                    cout << "phone: " << T -> lchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }
                else{
                    cout << "目标结点不存在左兄弟" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            else if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                free(S.base);
                cout << "目标结点不存在左兄弟!" << endl;
                return FALSE;
            }
            T = T -> rchild;
        }
    }
    free(S.base);
    cout << "目标结点不存在!" << endl;
    return FALSE;
}

Status RightSibling(BiTree T,BiTree e){
    if(!strcmp(T -> elem -> id,e ->elem -> id)){
        cout << "目标结点为根结点，不存在右兄弟，请重新选择你的操作!" << endl;
        return FALSE;
    }
    BiStack S;
    InitStack(S);
    while (T || S.top != S.base){
        while (T){
            Push(S,T);
            if(T -> lchild && !strcmp(T -> lchild -> elem -> id,e -> elem -> id)){
                if(T -> rchild){
                    cout << "目标结点的右兄弟信息为:" << endl;
                    cout << "name: " << T -> rchild -> elem -> id << endl;
                    cout << "age: " << T -> rchild -> elem -> name << endl;
                    cout << "phone: " << T -> rchild -> elem -> phone << endl;
                    free(S.base);
                    return OK;
                }
                else{
                    cout << "目标结点不存在右兄弟" << endl;
                    free(S.base);
                    return FALSE;
                }
            }
            else if(T -> rchild && !strcmp(T -> rchild -> elem -> id,e -> elem -> id)){
                free(S.base);
                cout << "目标结点不存在右兄弟!" << endl;
                return FALSE;
            }
            T = T -> lchild;
        }
        if(S.base != S.top){
            Pop(S,T);
            T = T -> rchild;
        }
    }
    cout << "目标结点不存在!" << endl;
    free(S.base);
    return FALSE;
}

Status InsertChildBiTNode (BiTree *T,BiTree p,int LR){
    BiStack S;
    InitStack(S);
    BiTree G = *T;
    BiTree H = (BiTree)malloc(sizeof(BiTNode));
    int definition;
    cout << "先序输入:0    中序输入:1    后序输入:2" << endl;
    cout << "请选择你的操作!" << endl;
    while(cin >> definition){
        if(definition == 0 || definition == 1 || definition == 2)
            break;
        else{
            cout << "输入的值不合法，请重新输入!" << endl;
            continue;
        }
    }
    cout << "学号输入#代表当前结点为空结点" << endl;
    cout << "若输入的树右子树存在，则视为舍去右子树!" << endl;
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
    cout << "不存在目标结点!" << endl;
    return FALSE;
}

Status DeleteChild(BiTree *T,BiTree p,int LR){
    BiTree H = (*T);
    BiStack S;
    InitStack(S);
    while (LR != 0 && LR != 1) {
        cout << "选择左右子树指令不合法，请确定你要删除的左右子树(左:0  右:1)" << endl;
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
                        cout << "删除结点成功!" << endl;
                        (*T)->lchild = nullptr;
                    }
                    else
                        cout << "目标结点不存在左子树，无法删除!" << endl;
                } else if(LR == 1){
                    if((*T) -> rchild) {
                        cout << "删除结点成功!" << endl;
                        (*T)->rchild = nullptr;
                    }
                    else
                        cout << "目标结点不存在右子树，无法删除!" << endl;
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
        cout << "树为空树!" << endl;
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
    cout << "输入文件名称（不超过20个字符）:" << endl;
    cin >> filename;
    strcat(filename,".txt");
    ofstream outfile;
    outfile.open(filename,std::ios::out);
    if(outfile){
        Write(T,outfile);
        outfile.close();
        return OK;
    } else
        cout << "创建文件失败!" << endl;
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
    cout << "输入读取文件名称（不超过20个字符）:" << endl;
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
        cout << "不存在此文件!" << endl;
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
        cout << "树为空树!" << endl;
        return OK;
    }
    BiTree F = (BiTree)malloc(sizeof(BiTNode));//充当空结点
    F -> elem = nullptr;
    F -> lchild = F -> rchild = nullptr;
    int length;
    length = strlen(T -> elem ->id);//id的长度
    int height;
    height = BiTreeDepth(T);//树的高度
    int depth = 1;//当前所在的层数(根结点打印后状态)
    int children = 1;//已打印结点的数量(根结点打印后的状态)
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    //根结点前面空部分打印
    for(int a = 0; a < length * (pow(2,height - depth) - 1);a++){
        printf(" ");
    }
    //根结点打印
    if(!PrintElem(T -> elem))
        exit(ERROR);
    //剩余结点打印
    while(Q.front != Q.rear) {
        if(children == pow(2,depth) - 1) {//每一层前面的空部分
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
            for(int a = 0;a < length;a++)//充当结点
                printf(" ");
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        }
        if(T -> rchild) {
            EnQueue(Q, T->rchild);
            if(!PrintElem(T -> rchild -> elem))//打印结点
                exit(ERROR);
            for(int a = 0;a < length * (pow(2,height - depth + 1) - 1);a++)
                printf(" ");
            children++;
        }else{
            EnQueue(Q,F);
            for(int a = 0;a < length;a++)//充当结点
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