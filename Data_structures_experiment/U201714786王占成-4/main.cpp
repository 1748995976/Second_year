#include <iostream>
#include <cstring>
#include <fstream>

#define MAXCHARLENGTH 20
#define OK 1
#define FALSE 0
#define MAX 100

using namespace std;

typedef int Status;

typedef struct ElemNext {
    ElemNext *next_elem;
    int current;
} ElemNext;

typedef struct ElemType {
    char id[MAXCHARLENGTH];
    char name[MAXCHARLENGTH];
    char birth[MAXCHARLENGTH];
    ElemNext *next_elem;
} ElemType;

typedef struct Graph {
    struct ElemType *elemtype;
    int number;
} Graph, *Graphptr;

typedef struct {
    int *base;
    int front;
    int rear;
} LinkQueue;

int visited[MAX];

Status (*VisitFunc)(ElemType *e);

Status CreateVex(ElemType **pElemType,Graphptr *G);

Status CreateArc(ElemNext **pElemNext,int number,ElemType *elemType);

Status CreateGraph(Graphptr *G,ElemType *V,ElemNext *VR);

Status DestroyGraph(Graphptr *G);

Status LocateVex(Graphptr G, ElemType example);

Status GetVex(Graphptr G, ElemType example);

Status PutVex(Graphptr *G, ElemType example, ElemType value);

Status FirstAdjVex(Graphptr G, ElemType example);

Status NextAdjVex(Graphptr G, ElemType example, ElemType w);

Status InsertVex(Graphptr *G, ElemType value);

Status DeleteVex(Graphptr *G, ElemType example);

Status InsertArc(Graphptr *G, ElemType example, ElemType example_to);

Status DeleteArc(Graphptr *G, ElemType example, ElemType example_to);

Status WriteToFile(Graphptr G);

Status ReadFromFile(Graphptr *G);

void DFS(Graphptr G, int v);

Status DFSTraverse(Graphptr G, Status(*Visit)(ElemType *e));

Status BFSTraverse(Graphptr G, Status(*Visit)(ElemType *e));

Status VisitElem(ElemType *e);

Status InitQueue(LinkQueue &Q);

Status DestroyQueue(LinkQueue &Q);

Status EnQueue(LinkQueue &Q, int v);

Status DeQueue(LinkQueue &Q, int &w);

int main() {
    int number = 0;
    int moro = 0;
    int choice = 1;
    int where = 0;
    Graphptr G = (Graphptr) malloc(sizeof(Graph));
    ElemNext *pElemNext = nullptr;
    ElemType *pElemType = nullptr;
    G->number = 0;
    Graphptr *GS = nullptr;
    while (choice) {
        cout << "\n\n" << endl;
        cout << "      Menu for Linear Table On Sequence Structure \n" << endl;
        cout << "-------------------------------------------------\n" << endl;
        cout << "         1. CreateGraph        10.InsertArc\n" << endl;
        cout << "         2. DestroyGraph       11.DeleteArc\n" << endl;
        cout << "         3. LocateVex          12.MultiGraph\n" << endl;
        cout << "         4. GetVex             13.SwitchGraph\n" << endl;
        cout << "         5. PutVex             14.WriteToFile\n" << endl;
        cout << "         6. FirstAdjVex        15.ReadFromFile\n" << endl;
        cout << "         7. NextAdjVex         16.DFSTraverse\n" << endl;
        cout << "         8. InsertVex          17.BFSTraverse\n" << endl;
        cout << "         9. DeleteVex          0. Exit\n" << endl;
        cout << "-------------------------------------------------\n" << endl;
        if (moro == 1)
            cout << "当前操作的为图 " << where + 1 << endl;
        cout << "    请选择你的操作[0~17]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "下面创建顶点集!" << endl;
                system("pause");
                CreateVex(&pElemType,&G);
                cout << "下面开始建立邻接关系:" << endl;
                system("pause");
                CreateArc(&pElemNext,G -> number,pElemType);
                CreateGraph(&G,pElemType,pElemNext);
                system("pause");
                break;
            }
            case 2: {
                DestroyGraph(&G);
                free(pElemNext);//释放邻接顶点前的首部所占用的空间
                system("pause");
                break;
            }
            case 3: {
                ElemType example;
                cout << "请输入所查找顶点的ID" << endl;
                cin >> example.id;
                LocateVex(G, example);
                system("pause");
                break;
            }
            case 4: {
                ElemType example;
                cout << "请输入所查找顶点的ID" << endl;
                cin >> example.id;
                GetVex(G, example);
                system("pause");
                break;
            }
            case 5: {
                ElemType example;
                cout << "请输入要修改顶点的ID" << endl;
                cin >> example.id;
                ElemType value;
                cout << "请输入修改后的顶点信息(姓名以及出生日期)" << endl;
                cin >> value.name >> value.birth;
                for(int a = 0;a < MAXCHARLENGTH;a++)
                    value.id[a] = example.id[a];
                PutVex(&G, example, value);
                system("pause");
                break;
            }
            case 6: {
                ElemType example;
                cout << "请输入顶点ID" << endl;
                cin >> example.id;
                FirstAdjVex(G, example);
                system("pause");
                break;
            }
            case 7: {
                ElemType example;
                cout << "请输入顶点ID" << endl;
                cin >> example.id;
                ElemType w;
                cout << "请输入邻接顶点ID" << endl;
                cin >> w.id;
                NextAdjVex(G, example, w);
                system("pause");
                break;
            }
            case 8: {
                ElemType value;
                cout << "请输入插入顶点信息(学号、姓名以及出生日期)" << endl;
                cin >> value.id >> value.name >> value.birth;
                InsertVex(&G, value);
                system("pause");
                break;
            }
            case 9: {
                ElemType example;
                cout << "请输入顶点ID" << endl;
                cin >> example.id;
                DeleteVex(&G, example);
                system("pause");
                break;
            }
            case 10: {
                ElemType example;
                cout << "请输入弧尾顶点ID" << endl;
                cin >> example.id;
                ElemType example_to;
                cout << "请输入弧头顶点ID" << endl;
                cin >> example_to.id;
                InsertArc(&G, example, example_to);
                system("pause");
                break;
            }
            case 11: {
                ElemType example;
                cout << "请输入弧尾顶点ID" << endl;
                cin >> example.id;
                ElemType example_to;
                cout << "请输入弧头顶点ID" << endl;
                cin >> example_to.id;
                DeleteArc(&G, example, example_to);
                system("pause");
                break;
            }
            case 12: {
                if (moro == 1) {
                    cout << "当前已创建多图，无需再次创建!" << endl;
                    system("pause");
                    break;
                } else {
                    cout << "请输入建立多图的数目!" << endl;
                    while (cin >> number) {
                        if (number > 0)
                            break;
                        else
                            cout << "输入的数字不合法，请重新输入!" << endl;
                    }
                    //建立多图
                    moro = 1;
                    GS = (Graphptr *) malloc(number * sizeof(Graphptr));
                    //将每个图初始化
                    for (int i = 0; i < number; i++) {
                        GS[i] = (Graphptr) malloc(sizeof(Graph));
                        GS[i]->number = 0;
                    }
                    //切换为第一个图
                    where = 0;
                    G = GS[where];
                    cout << "创建多图成功!" << endl;
                    system("pause");
                    break;
                }
            }
            case 13: {
                if (moro == 0) {
                    cout << "不存在多图，无法切换，请重新选择你的操作!" << endl;
                    system("pause");
                    break;
                } else {
                    cout << "请输入图的序号" << endl;
                    int c;
                    while (cin >> c) {
                        if (c >= 1 && c <= number)
                            break;
                        else
                            cout << "输入的序号不合法，请重新输入你的序号!" << endl;
                    }
                    where = c - 1;
                    G = GS[where];
                    cout << "切换成功!" << endl;
                    system("pause");
                    break;
                }
            }
            case 14: {
                WriteToFile(G);
                system("pause");
                break;
            }
            case 15: {
                ReadFromFile(&G);
                system("pause");
                break;
            }
            case 16: {
                cout << "深度优先搜索如下:" << endl;
                DFSTraverse(G, VisitElem);
                system("pause");
                break;
            }
            case 17: {
                cout << "广度优先搜索如下:" << endl;
                BFSTraverse(G, VisitElem);
                system("pause");
                break;
            }
            case 0: {
                cout << "即将推出本程序!" << endl;
                cout << "感谢您的使用!" << endl;
                system("pause");
                break;
            }
            default: {
                cout << "输入指令不存在，请重新选择你的操作!" << endl;
                system("pause");
                break;
            }
        }
    }

}

Status CreateVex(ElemType **pElemType,Graphptr *G){
    if ((*G) -> number != 0) {
        cout << "当前图不为空图，请销毁后再创建!" << endl;
        return FALSE;
    }
    int number;
    cout << "请输入顶点的数目:" << endl;
    while (cin >> number) {
        if (number > 0)
            break;
        else
            cout << "顶点数目不合法，请重新输入!" << endl;
    }
    int a;
    (*G) -> number = number;
    (*pElemType) = (ElemType *)malloc(number * sizeof(ElemType));
    ElemType e;
    e.next_elem = nullptr;
    for(int i = 0; i < number;i++)
        (*pElemType)[i].next_elem = nullptr;
    for (int i = 0; i < number; ++i) {
        cout << "请依次输入第" << i + 1 << "顶点的学生学号、姓名以及出生日期(每条信息不超过20个字符)" << endl;
        while(cin >> e.id >> e.name >> e.birth){
            for(a = 0;a <= i;a++){
                if(!strcmp(e.id,(*pElemType)[a].id)){
                    cout << "当前输入顶点的ID已存在，请重新输入学生的所有信息!" << endl;
                    break;//跳出遍历图
                }
            }
            if(a == i + 1)
                break;//跳出重复输入
        }
        (*pElemType)[i] = e;
    }
    cout << "创建顶点集成功!" << endl;
    return OK;
}

Status CreateArc(ElemNext **pElemNext,int number,ElemType* elemType){
    (*pElemNext) = (ElemNext*)malloc(number * sizeof(ElemNext));
    for(int i = 0;i < number;i++)
        (*pElemNext)[i].next_elem = nullptr;
    //删除原有关系
    cout << "若当前图的顶点已建立邻接关系，再次执行此操作会覆盖顶点之前建立的邻接关系!" << endl;
    cout << "是否继续? 是：1   否：0" << endl;
    int choice;
    if (cin >> choice && choice == 0)
        return OK;
    //建立新的关系
    int a = 0;//当前顶点索引
    int b = 0;//被指顶点的索引
    cout << "所有的顶点信息如下:" << endl;
    for (int i = 0; i < number; i++) {
        cout << i + 1 << ":  " << "\nID: " << elemType[i].id
             << "\nName:" << elemType[i].name
             << "\nBirth: " << elemType[i].birth
             << endl;
    }
    ElemType search;
    while (true) {
        cout << "请输入要建立关系的顶点的学号(学号输入 # 停止建立关系)" << endl;
        cin >> search.id;
        if (!strcmp("#", search.id))
            break;
        for (a = 0; a < number; a++) {
            if (!strcmp(search.id, elemType[a].id))
                break;
            if (a == number - 1)
                cout << "无符合关系的顶点" << endl;
        }
        if (a == number) {
            cout << "请重新输入要建立关系的顶点的学号(学号输入 # 停止建立关系)" << endl;
            continue;
        } else {
            ElemType e;
            while (true) {
                cout << "请输入学号: " << elemType[a].id << "顶点所指向顶点的学号(输入 * 结束输入)" << endl;
                cin >> e.id;
                if (!strcmp(e.id, "*"))
                    break;
                for (b = 0; b < number; b++) {
                    if (!strcmp(e.id, elemType[b].id))
                        break;
                    if (b == number - 1)
                        cout << "无符合关系的顶点" << endl;
                }
                if (b == number) {
                    cout << "请重新输入学号: " << elemType[a].id << "顶点所指向结点的学号(输入 * 结束输入)" << endl;
                    continue;
                } else {
                    //头插法
                    ElemNext *elemNext = (*pElemNext)[a].next_elem;
                    while(elemNext){
                        if(elemNext -> current == b){
                            cout << "当前弧已存在，请重新输入!" << endl;
                            break;
                        }
                        elemNext = elemNext -> next_elem;
                    }
                    if(!elemNext) {
                        ElemNext *p = (*pElemNext)[a].next_elem;
                        (*pElemNext)[a].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                        (*pElemNext)[a].next_elem->next_elem = p;
                        (*pElemNext)[a].next_elem->current = b;
                    }//插入弧关系
                }
            }
        }
    }
    cout << "创建关系集成功!" << endl;
    return OK;
}

Status CreateGraph(Graphptr *G,ElemType *V,ElemNext *VR){
    (*G) -> elemtype = V;
    for(int i = 0;i < (*G) -> number; i++)
        (*G) -> elemtype[i].next_elem = VR[i].next_elem;
    cout << "创建图成功!" << endl;
}

Status DestroyGraph(Graphptr *G) {
    if ((*G)->number == 0) {
        cout << "当前图未创建，故无法销毁!" << endl;
        return FALSE;
    }
    ElemNext *H;
    ElemNext *P;
    for (int i = 0; i < (*G)->number; i++) {
        H = (*G)->elemtype[i].next_elem;
        while (H) {
            P = H -> next_elem;
            free(H);
            H = P;
        }
    }
    free((*G)->elemtype);
    (*G)->number = 0;
    cout << "销毁图成功!" << endl;
    return OK;
}

Status LocateVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            cout << "所找顶点的序号为:" << i + 1 << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
    }
    return OK;
}

Status GetVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            cout << "所找顶点的信息为:" << endl;
            cout << "Id: " << G->elemtype[i].id << endl;
            cout << "Name: " << G->elemtype[i].name << endl;
            cout << "Birth: " << G->elemtype[i].birth << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
    }
    return OK;
}

Status PutVex(Graphptr *G, ElemType example, ElemType value) {
    if(!(*G) -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            cout << "所改顶点的原有信息为:" << endl;
            cout << "Id: " << (*G)->elemtype[i].id << endl;
            cout << "Name: " << (*G)->elemtype[i].name << endl;
            cout << "Birth: " << (*G)->elemtype[i].birth << endl;
            value.next_elem = (*G)->elemtype[i].next_elem;
            (*G)->elemtype[i] = value;
            cout << "修改后的顶点信息为:" << endl;
            cout << "Id: " << (*G)->elemtype[i].id << endl;
            cout << "Name: " << (*G)->elemtype[i].name << endl;
            cout << "Birth: " << (*G)->elemtype[i].birth << endl;
            break;
        }
        if (i == (*G)->number - 1)
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
    }
    return OK;
}

Status FirstAdjVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            if (G->elemtype[i].next_elem != nullptr) {
                cout << "所找顶点的第一个邻接顶点信息为:" << endl;
                cout << "Id: " << G->elemtype[G->elemtype[i].next_elem->current].id << endl;
                cout << "Name: " << G->elemtype[G->elemtype[i].next_elem->current].name << endl;
                cout << "Birth: " << G->elemtype[G->elemtype[i].next_elem->current].birth << endl;
            }else
                cout << "所找顶点不存在第一个邻接顶点!" << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
    }
    return OK;
}

Status NextAdjVex(Graphptr G, ElemType example, ElemType w) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    ElemNext *e;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            e = G->elemtype[i].next_elem;
            while (e != nullptr) {
                if (!strcmp(G->elemtype[e->current].id, w.id)) {
                    if (e->next_elem != nullptr) {
                        cout << "符合条件的顶点信息为:" << endl;
                        cout << "Id: " << G->elemtype[e->next_elem->current].id << endl;
                        cout << "Name: " << G->elemtype[e->next_elem->current].name << endl;
                        cout << "Birth: " << G->elemtype[e->next_elem->current].birth << endl;
                        return OK;
                    } else {
                        cout << "所找邻接顶点的下一个邻接顶点为空!" << endl;
                        return FALSE;
                    }
                }
                e = e->next_elem;
            }
            if (!e)
                cout << "不存在所找顶点的邻接顶点" << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
    }
    return FALSE;
}

Status InsertVex(Graphptr *G, ElemType value) {
    if(!(*G) -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    for(int i = 0;i < (*G) -> number;i++){
        if(!strcmp(value.id,(*G) -> elemtype[i].id)){
            cout << "当前顶点ID已存在，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    value.next_elem = nullptr;
    Graphptr GNew = (Graphptr) malloc(sizeof(Graph));
    GNew -> elemtype = (ElemType *) malloc(((*G)->number + 1) * sizeof(ElemType));
    GNew -> number = ((*G)->number + 1);
    for (int i = 0; i < ((*G)->number + 1); ++i) {
        GNew->elemtype[i].next_elem = nullptr;
        if (i == (*G)->number)
            GNew->elemtype[i] = value;
        else
            GNew->elemtype[i] = (*G)->elemtype[i];
    }
    free((*G) -> elemtype);
    *G = GNew;
    cout << "插入顶点成功!" << endl;
    return OK;
}

Status DeleteVex(Graphptr *G, ElemType example) {
    if(!(*G) -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int a;
    Graphptr GNew = (Graphptr) malloc(sizeof(Graph));
    GNew -> elemtype = (ElemType *) malloc(((*G)->number - 1) * sizeof(ElemType));
    GNew -> number = ((*G)->number - 1);
    for (a = 0; a < (*G)->number; a++) {
        if (!strcmp((*G)->elemtype[a].id, example.id))
            break;
        if (a == (*G)->number - 1) {
            cout << "不存在所找顶点，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    for(int i = 0;i < (*G) -> number;i++){
        ElemNext *h = (*G) -> elemtype[i].next_elem;
        ElemNext *k = h;
        ElemNext *m;
        while(h){
            m = h -> next_elem;//在h未被释放掉的时候取h的下一个邻接顶点
            if(h -> current == a)
            {
                if((*G) -> elemtype[i].next_elem -> current == h -> current){
                    ElemNext *q = (*G) -> elemtype[i].next_elem;
                    (*G) -> elemtype[i].next_elem = q -> next_elem;
                    free(q);
                }
                else{
                    k -> next_elem = h -> next_elem;
                    free(h);
                }
            }
            else if(h -> current > a)
                --(h -> current);
            k = h;
            h = m;
        }
    }//删除所有与删除顶点有关的弧关系
    for (int i = 0; i < (*G)->number - 1; ++i) {
        GNew->elemtype[i].next_elem = nullptr;
        if (i < a)
            GNew->elemtype[i] = (*G)->elemtype[i];
        else
            GNew->elemtype[i] = (*G)->elemtype[i + 1];
    }//复制图
    ElemNext *elemNext = (*G) -> elemtype[a].next_elem;
    ElemNext *p;
    while(elemNext){
        p = elemNext -> next_elem;
        free(elemNext);
        elemNext = p;
    }//释放顶点存储所有的邻接顶点占用的连续空间
    free((*G) -> elemtype);
    *G = GNew;
    cout << "删除顶点成功!" << endl;
    return OK;
}

Status InsertArc(Graphptr *G, ElemType example, ElemType example_to) {
    if(!(*G) -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            break;
        }
        if (i == (*G)->number - 1) {
            cout << "不存在所找弧尾顶点，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    int l;
    for (l = 0; l < (*G)->number; l++) {
        if (!strcmp((*G)->elemtype[l].id, example_to.id)) {
            break;
        }
        if (l == (*G)->number - 1) {
            cout << "不存在所找弧头顶点，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    ElemNext *H = (*G)->elemtype[i].next_elem;
    if (H == nullptr) {
        (*G)->elemtype[i].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
        (*G)->elemtype[i].next_elem->current = l;
        (*G)->elemtype[i].next_elem->next_elem = nullptr;
        cout << "插入弧成功!" << endl;
        return OK;
    }
    while (H->next_elem) {
        if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
            cout << "当前弧关系已存在，请重新选择你的操作!" << endl;
            return FALSE;
        }
        H = H->next_elem;
    }
    //头插法
    H = (ElemNext *) malloc(sizeof(ElemNext));
    H -> current = l;
    H -> next_elem = (*G) -> elemtype[i].next_elem;
    (*G) -> elemtype[i].next_elem = H;
    cout << "插入弧成功!" << endl;
    return OK;
}

Status DeleteArc(Graphptr *G, ElemType example, ElemType example_to) {
    if(!(*G) -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            break;
        }
        if (i == (*G)->number - 1) {
            cout << "不存在所找弧尾顶点，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    int l;
    for (l = 0; l < (*G)->number; l++) {
        if (!strcmp((*G)->elemtype[l].id, example_to.id)) {
            break;
        }
        if (l == (*G)->number - 1) {
            cout << "不存在所找弧头顶点，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
    ElemNext *H = (*G)->elemtype[i].next_elem;
    ElemNext *P = H;
    if (H == nullptr) {
        cout << "所找顶点不存在邻接顶点，请重新选择你的操作!" << endl;
        return FALSE;
    } else if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
        //第一个邻接顶点符合条件
        (*G)->elemtype[i].next_elem = H->next_elem;
        free(H);
        cout << "删除弧成功!" << endl;
        return OK;
    } else {
        while (H) {
            if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
                P -> next_elem = H -> next_elem;
                cout << "删除弧成功!" << endl;
                free(H);
                return OK;
            }
            P = H;
            H = H->next_elem;
        }
        if (!H) {
            cout << "不存在所找弧关系，请重新选择你的操作!" << endl;
            return FALSE;
        }
    }
}

Status WriteToFile(Graphptr G) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    char filename[20];
    cout << "输入文件名称（不超过20个字符）:" << endl;
    cin >> filename;
    strcat(filename, ".txt");
    ofstream outfile;
    outfile.open(filename, std::ios::out);
    if (outfile) {
        outfile << G->number << endl;
        for (int i = 0; i < G->number; i++) {
            outfile << G->elemtype[i].id << endl;
            outfile << G->elemtype[i].name << endl;
            outfile << G->elemtype[i].birth << endl;
            ElemNext *elemNext = G->elemtype[i].next_elem;
            while (elemNext) {
                outfile << elemNext->current << endl;
                elemNext = elemNext->next_elem;
            }
            outfile << "-1" << endl;
        }
        outfile.close();
        cout << "创建文件成功!" << endl;
        return OK;
    } else
        cout << "创建文件失败!" << endl;
    return FALSE;
}

Status ReadFromFile(Graphptr *G) {
    if((*G) -> number != 0){
        cout << "当前图不为空，请销毁图后再读取文件!" << endl;
        return FALSE;
    }
    char filename[20];
    cout << "输入文件名称（不超过20个字符）:" << endl;
    cin >> filename;
    strcat(filename, ".txt");
    ifstream infile;
    infile.open(filename, std::ios::in);
    if (infile) {
        infile >> (*G)->number;
        (*G)->elemtype = (ElemType *) malloc((*G)->number * sizeof(ElemType));
        ElemType elemType;
        for (int i = 0; i < (*G)->number; ++i) {
            (*G)->elemtype[i].next_elem = nullptr;
            infile >> elemType.id >> elemType.name >> elemType.birth;
            elemType.next_elem = nullptr;
            (*G)->elemtype[i] = elemType;
            ElemNext elemNext;
            //处理第一个邻接顶点
            if (infile >> elemNext.current && elemNext.current != -1) {
                (*G)->elemtype[i].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                (*G)->elemtype[i].next_elem->current = elemNext.current;
                (*G)->elemtype[i].next_elem->next_elem = nullptr;
            } else
                continue;
            //处理其他的邻接顶点
            ElemNext *e = (*G)->elemtype[i].next_elem;
            while (infile >> elemNext.current && elemNext.current != -1) {
                e->next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                e = e->next_elem;
                e->current = elemNext.current;
                e->next_elem = nullptr;
            }
        }
        infile.close();
        cout << "读取成功!" << endl;
        return OK;
    } else {
        cout << "不存在此文件!" << endl;
        return FALSE;
    }
}


void DFS(Graphptr G, int v) {
    //此处改变标志组的状态
    visited[v] = 1;
    VisitFunc(&(G->elemtype[v]));
    ElemNext *elemNext = G->elemtype[v].next_elem;
    while (elemNext) {
        if (!visited[elemNext->current])
            DFS(G, elemNext->current);
        elemNext = elemNext->next_elem;
    }
}

Status DFSTraverse(Graphptr G, Status(*Visit)(ElemType *e)) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    for (int i = 0; i < G->number; i++) {
        visited[i] = 0;
    }//标志数组初始化
    VisitFunc = Visit;
    int v;
    for (v = 0; v < G->number; v++)
        if (!visited[v])
            DFS(G, v);
}

Status BFSTraverse(Graphptr G, Status(*Visit)(ElemType *e)) {
    if(!G -> number){
        cout << "当前图为空，请重新选择你的操作!" << endl;
        return OK;
    }
    for (int i = 0; i < G->number; i++) {
        visited[i] = 0;
    }//标志数组初始化
    LinkQueue Q;
    InitQueue(Q);
    int v;
    int w = -1;
    ElemNext *elemNext;
    for (v = 0; v < G->number; v++) {
        if (!visited[v]) {
            //访问顶点
            EnQueue(Q, v);
            visited[v] = 1;
            Visit(&(G->elemtype[v]));
            //访问邻接顶点
            while (Q.front != Q.rear) {//判断队列是否为空
                DeQueue(Q, w);
                elemNext = G->elemtype[w].next_elem;
                while (elemNext) {
                    if (!visited[elemNext->current]) {
                        Visit(&(G->elemtype[elemNext->current]));
                        EnQueue(Q, elemNext->current);
                        visited[elemNext->current] = 1;
                    }
                    elemNext = elemNext->next_elem;
                }
            }

        }
    }
    DestroyQueue(Q);
    return OK;

}

Status VisitElem(ElemType *e) {
    cout << "ID:" << e->id << endl;
    cout << "Name:" << e->name << endl;
    cout << "Birth:" << e->birth << endl;
    cout << endl;
    return OK;
}

Status InitQueue(LinkQueue &Q) {
    Q.base = (int *) malloc(MAX * sizeof(int));
    if (!Q.base)
        exit(-1);
    Q.front = Q.rear = 0;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    free(Q.base);
    return OK;
}

Status EnQueue(LinkQueue &Q, int v) {
    if ((Q.rear + 1) % MAX == Q.front)
        return -2;//队列空间满
    Q.base[Q.rear] = v;
    Q.rear = (Q.rear + 1) % MAX;
    return OK;
}

Status DeQueue(LinkQueue &Q, int &w) {
    if (Q.front == Q.rear)
        return -2;//队列空间满
    w = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX;
    return OK;
}