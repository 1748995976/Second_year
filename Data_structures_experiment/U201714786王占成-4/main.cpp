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
            cout << "��ǰ������Ϊͼ " << where + 1 << endl;
        cout << "    ��ѡ����Ĳ���[0~17]:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "���洴�����㼯!" << endl;
                system("pause");
                CreateVex(&pElemType,&G);
                cout << "���濪ʼ�����ڽӹ�ϵ:" << endl;
                system("pause");
                CreateArc(&pElemNext,G -> number,pElemType);
                CreateGraph(&G,pElemType,pElemNext);
                system("pause");
                break;
            }
            case 2: {
                DestroyGraph(&G);
                free(pElemNext);//�ͷ��ڽӶ���ǰ���ײ���ռ�õĿռ�
                system("pause");
                break;
            }
            case 3: {
                ElemType example;
                cout << "�����������Ҷ����ID" << endl;
                cin >> example.id;
                LocateVex(G, example);
                system("pause");
                break;
            }
            case 4: {
                ElemType example;
                cout << "�����������Ҷ����ID" << endl;
                cin >> example.id;
                GetVex(G, example);
                system("pause");
                break;
            }
            case 5: {
                ElemType example;
                cout << "������Ҫ�޸Ķ����ID" << endl;
                cin >> example.id;
                ElemType value;
                cout << "�������޸ĺ�Ķ�����Ϣ(�����Լ���������)" << endl;
                cin >> value.name >> value.birth;
                for(int a = 0;a < MAXCHARLENGTH;a++)
                    value.id[a] = example.id[a];
                PutVex(&G, example, value);
                system("pause");
                break;
            }
            case 6: {
                ElemType example;
                cout << "�����붥��ID" << endl;
                cin >> example.id;
                FirstAdjVex(G, example);
                system("pause");
                break;
            }
            case 7: {
                ElemType example;
                cout << "�����붥��ID" << endl;
                cin >> example.id;
                ElemType w;
                cout << "�������ڽӶ���ID" << endl;
                cin >> w.id;
                NextAdjVex(G, example, w);
                system("pause");
                break;
            }
            case 8: {
                ElemType value;
                cout << "��������붥����Ϣ(ѧ�š������Լ���������)" << endl;
                cin >> value.id >> value.name >> value.birth;
                InsertVex(&G, value);
                system("pause");
                break;
            }
            case 9: {
                ElemType example;
                cout << "�����붥��ID" << endl;
                cin >> example.id;
                DeleteVex(&G, example);
                system("pause");
                break;
            }
            case 10: {
                ElemType example;
                cout << "�����뻡β����ID" << endl;
                cin >> example.id;
                ElemType example_to;
                cout << "�����뻡ͷ����ID" << endl;
                cin >> example_to.id;
                InsertArc(&G, example, example_to);
                system("pause");
                break;
            }
            case 11: {
                ElemType example;
                cout << "�����뻡β����ID" << endl;
                cin >> example.id;
                ElemType example_to;
                cout << "�����뻡ͷ����ID" << endl;
                cin >> example_to.id;
                DeleteArc(&G, example, example_to);
                system("pause");
                break;
            }
            case 12: {
                if (moro == 1) {
                    cout << "��ǰ�Ѵ�����ͼ�������ٴδ���!" << endl;
                    system("pause");
                    break;
                } else {
                    cout << "�����뽨����ͼ����Ŀ!" << endl;
                    while (cin >> number) {
                        if (number > 0)
                            break;
                        else
                            cout << "��������ֲ��Ϸ�������������!" << endl;
                    }
                    //������ͼ
                    moro = 1;
                    GS = (Graphptr *) malloc(number * sizeof(Graphptr));
                    //��ÿ��ͼ��ʼ��
                    for (int i = 0; i < number; i++) {
                        GS[i] = (Graphptr) malloc(sizeof(Graph));
                        GS[i]->number = 0;
                    }
                    //�л�Ϊ��һ��ͼ
                    where = 0;
                    G = GS[where];
                    cout << "������ͼ�ɹ�!" << endl;
                    system("pause");
                    break;
                }
            }
            case 13: {
                if (moro == 0) {
                    cout << "�����ڶ�ͼ���޷��л���������ѡ����Ĳ���!" << endl;
                    system("pause");
                    break;
                } else {
                    cout << "������ͼ�����" << endl;
                    int c;
                    while (cin >> c) {
                        if (c >= 1 && c <= number)
                            break;
                        else
                            cout << "�������Ų��Ϸ�������������������!" << endl;
                    }
                    where = c - 1;
                    G = GS[where];
                    cout << "�л��ɹ�!" << endl;
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
                cout << "���������������:" << endl;
                DFSTraverse(G, VisitElem);
                system("pause");
                break;
            }
            case 17: {
                cout << "���������������:" << endl;
                BFSTraverse(G, VisitElem);
                system("pause");
                break;
            }
            case 0: {
                cout << "�����Ƴ�������!" << endl;
                cout << "��л����ʹ��!" << endl;
                system("pause");
                break;
            }
            default: {
                cout << "����ָ����ڣ�������ѡ����Ĳ���!" << endl;
                system("pause");
                break;
            }
        }
    }

}

Status CreateVex(ElemType **pElemType,Graphptr *G){
    if ((*G) -> number != 0) {
        cout << "��ǰͼ��Ϊ��ͼ�������ٺ��ٴ���!" << endl;
        return FALSE;
    }
    int number;
    cout << "�����붥�����Ŀ:" << endl;
    while (cin >> number) {
        if (number > 0)
            break;
        else
            cout << "������Ŀ���Ϸ�������������!" << endl;
    }
    int a;
    (*G) -> number = number;
    (*pElemType) = (ElemType *)malloc(number * sizeof(ElemType));
    ElemType e;
    e.next_elem = nullptr;
    for(int i = 0; i < number;i++)
        (*pElemType)[i].next_elem = nullptr;
    for (int i = 0; i < number; ++i) {
        cout << "�����������" << i + 1 << "�����ѧ��ѧ�š������Լ���������(ÿ����Ϣ������20���ַ�)" << endl;
        while(cin >> e.id >> e.name >> e.birth){
            for(a = 0;a <= i;a++){
                if(!strcmp(e.id,(*pElemType)[a].id)){
                    cout << "��ǰ���붥���ID�Ѵ��ڣ�����������ѧ����������Ϣ!" << endl;
                    break;//��������ͼ
                }
            }
            if(a == i + 1)
                break;//�����ظ�����
        }
        (*pElemType)[i] = e;
    }
    cout << "�������㼯�ɹ�!" << endl;
    return OK;
}

Status CreateArc(ElemNext **pElemNext,int number,ElemType* elemType){
    (*pElemNext) = (ElemNext*)malloc(number * sizeof(ElemNext));
    for(int i = 0;i < number;i++)
        (*pElemNext)[i].next_elem = nullptr;
    //ɾ��ԭ�й�ϵ
    cout << "����ǰͼ�Ķ����ѽ����ڽӹ�ϵ���ٴ�ִ�д˲����Ḳ�Ƕ���֮ǰ�������ڽӹ�ϵ!" << endl;
    cout << "�Ƿ����? �ǣ�1   ��0" << endl;
    int choice;
    if (cin >> choice && choice == 0)
        return OK;
    //�����µĹ�ϵ
    int a = 0;//��ǰ��������
    int b = 0;//��ָ���������
    cout << "���еĶ�����Ϣ����:" << endl;
    for (int i = 0; i < number; i++) {
        cout << i + 1 << ":  " << "\nID: " << elemType[i].id
             << "\nName:" << elemType[i].name
             << "\nBirth: " << elemType[i].birth
             << endl;
    }
    ElemType search;
    while (true) {
        cout << "������Ҫ������ϵ�Ķ����ѧ��(ѧ������ # ֹͣ������ϵ)" << endl;
        cin >> search.id;
        if (!strcmp("#", search.id))
            break;
        for (a = 0; a < number; a++) {
            if (!strcmp(search.id, elemType[a].id))
                break;
            if (a == number - 1)
                cout << "�޷��Ϲ�ϵ�Ķ���" << endl;
        }
        if (a == number) {
            cout << "����������Ҫ������ϵ�Ķ����ѧ��(ѧ������ # ֹͣ������ϵ)" << endl;
            continue;
        } else {
            ElemType e;
            while (true) {
                cout << "������ѧ��: " << elemType[a].id << "������ָ�򶥵��ѧ��(���� * ��������)" << endl;
                cin >> e.id;
                if (!strcmp(e.id, "*"))
                    break;
                for (b = 0; b < number; b++) {
                    if (!strcmp(e.id, elemType[b].id))
                        break;
                    if (b == number - 1)
                        cout << "�޷��Ϲ�ϵ�Ķ���" << endl;
                }
                if (b == number) {
                    cout << "����������ѧ��: " << elemType[a].id << "������ָ�����ѧ��(���� * ��������)" << endl;
                    continue;
                } else {
                    //ͷ�巨
                    ElemNext *elemNext = (*pElemNext)[a].next_elem;
                    while(elemNext){
                        if(elemNext -> current == b){
                            cout << "��ǰ���Ѵ��ڣ�����������!" << endl;
                            break;
                        }
                        elemNext = elemNext -> next_elem;
                    }
                    if(!elemNext) {
                        ElemNext *p = (*pElemNext)[a].next_elem;
                        (*pElemNext)[a].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                        (*pElemNext)[a].next_elem->next_elem = p;
                        (*pElemNext)[a].next_elem->current = b;
                    }//���뻡��ϵ
                }
            }
        }
    }
    cout << "������ϵ���ɹ�!" << endl;
    return OK;
}

Status CreateGraph(Graphptr *G,ElemType *V,ElemNext *VR){
    (*G) -> elemtype = V;
    for(int i = 0;i < (*G) -> number; i++)
        (*G) -> elemtype[i].next_elem = VR[i].next_elem;
    cout << "����ͼ�ɹ�!" << endl;
}

Status DestroyGraph(Graphptr *G) {
    if ((*G)->number == 0) {
        cout << "��ǰͼδ���������޷�����!" << endl;
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
    cout << "����ͼ�ɹ�!" << endl;
    return OK;
}

Status LocateVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            cout << "���Ҷ�������Ϊ:" << i + 1 << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
    }
    return OK;
}

Status GetVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            cout << "���Ҷ������ϢΪ:" << endl;
            cout << "Id: " << G->elemtype[i].id << endl;
            cout << "Name: " << G->elemtype[i].name << endl;
            cout << "Birth: " << G->elemtype[i].birth << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
    }
    return OK;
}

Status PutVex(Graphptr *G, ElemType example, ElemType value) {
    if(!(*G) -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            cout << "���Ķ����ԭ����ϢΪ:" << endl;
            cout << "Id: " << (*G)->elemtype[i].id << endl;
            cout << "Name: " << (*G)->elemtype[i].name << endl;
            cout << "Birth: " << (*G)->elemtype[i].birth << endl;
            value.next_elem = (*G)->elemtype[i].next_elem;
            (*G)->elemtype[i] = value;
            cout << "�޸ĺ�Ķ�����ϢΪ:" << endl;
            cout << "Id: " << (*G)->elemtype[i].id << endl;
            cout << "Name: " << (*G)->elemtype[i].name << endl;
            cout << "Birth: " << (*G)->elemtype[i].birth << endl;
            break;
        }
        if (i == (*G)->number - 1)
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
    }
    return OK;
}

Status FirstAdjVex(Graphptr G, ElemType example) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < G->number; i++) {
        if (!strcmp(G->elemtype[i].id, example.id)) {
            if (G->elemtype[i].next_elem != nullptr) {
                cout << "���Ҷ���ĵ�һ���ڽӶ�����ϢΪ:" << endl;
                cout << "Id: " << G->elemtype[G->elemtype[i].next_elem->current].id << endl;
                cout << "Name: " << G->elemtype[G->elemtype[i].next_elem->current].name << endl;
                cout << "Birth: " << G->elemtype[G->elemtype[i].next_elem->current].birth << endl;
            }else
                cout << "���Ҷ��㲻���ڵ�һ���ڽӶ���!" << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
    }
    return OK;
}

Status NextAdjVex(Graphptr G, ElemType example, ElemType w) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
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
                        cout << "���������Ķ�����ϢΪ:" << endl;
                        cout << "Id: " << G->elemtype[e->next_elem->current].id << endl;
                        cout << "Name: " << G->elemtype[e->next_elem->current].name << endl;
                        cout << "Birth: " << G->elemtype[e->next_elem->current].birth << endl;
                        return OK;
                    } else {
                        cout << "�����ڽӶ������һ���ڽӶ���Ϊ��!" << endl;
                        return FALSE;
                    }
                }
                e = e->next_elem;
            }
            if (!e)
                cout << "���������Ҷ�����ڽӶ���" << endl;
            break;
        }
        if (i == G->number - 1)
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
    }
    return FALSE;
}

Status InsertVex(Graphptr *G, ElemType value) {
    if(!(*G) -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    for(int i = 0;i < (*G) -> number;i++){
        if(!strcmp(value.id,(*G) -> elemtype[i].id)){
            cout << "��ǰ����ID�Ѵ��ڣ�������ѡ����Ĳ���!" << endl;
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
    cout << "���붥��ɹ�!" << endl;
    return OK;
}

Status DeleteVex(Graphptr *G, ElemType example) {
    if(!(*G) -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
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
            cout << "���������Ҷ��㣬������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
    for(int i = 0;i < (*G) -> number;i++){
        ElemNext *h = (*G) -> elemtype[i].next_elem;
        ElemNext *k = h;
        ElemNext *m;
        while(h){
            m = h -> next_elem;//��hδ���ͷŵ���ʱ��ȡh����һ���ڽӶ���
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
    }//ɾ��������ɾ�������йصĻ���ϵ
    for (int i = 0; i < (*G)->number - 1; ++i) {
        GNew->elemtype[i].next_elem = nullptr;
        if (i < a)
            GNew->elemtype[i] = (*G)->elemtype[i];
        else
            GNew->elemtype[i] = (*G)->elemtype[i + 1];
    }//����ͼ
    ElemNext *elemNext = (*G) -> elemtype[a].next_elem;
    ElemNext *p;
    while(elemNext){
        p = elemNext -> next_elem;
        free(elemNext);
        elemNext = p;
    }//�ͷŶ���洢���е��ڽӶ���ռ�õ������ռ�
    free((*G) -> elemtype);
    *G = GNew;
    cout << "ɾ������ɹ�!" << endl;
    return OK;
}

Status InsertArc(Graphptr *G, ElemType example, ElemType example_to) {
    if(!(*G) -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            break;
        }
        if (i == (*G)->number - 1) {
            cout << "���������һ�β���㣬������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
    int l;
    for (l = 0; l < (*G)->number; l++) {
        if (!strcmp((*G)->elemtype[l].id, example_to.id)) {
            break;
        }
        if (l == (*G)->number - 1) {
            cout << "���������һ�ͷ���㣬������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
    ElemNext *H = (*G)->elemtype[i].next_elem;
    if (H == nullptr) {
        (*G)->elemtype[i].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
        (*G)->elemtype[i].next_elem->current = l;
        (*G)->elemtype[i].next_elem->next_elem = nullptr;
        cout << "���뻡�ɹ�!" << endl;
        return OK;
    }
    while (H->next_elem) {
        if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
            cout << "��ǰ����ϵ�Ѵ��ڣ�������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
        H = H->next_elem;
    }
    //ͷ�巨
    H = (ElemNext *) malloc(sizeof(ElemNext));
    H -> current = l;
    H -> next_elem = (*G) -> elemtype[i].next_elem;
    (*G) -> elemtype[i].next_elem = H;
    cout << "���뻡�ɹ�!" << endl;
    return OK;
}

Status DeleteArc(Graphptr *G, ElemType example, ElemType example_to) {
    if(!(*G) -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    int i;
    for (i = 0; i < (*G)->number; i++) {
        if (!strcmp((*G)->elemtype[i].id, example.id)) {
            break;
        }
        if (i == (*G)->number - 1) {
            cout << "���������һ�β���㣬������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
    int l;
    for (l = 0; l < (*G)->number; l++) {
        if (!strcmp((*G)->elemtype[l].id, example_to.id)) {
            break;
        }
        if (l == (*G)->number - 1) {
            cout << "���������һ�ͷ���㣬������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
    ElemNext *H = (*G)->elemtype[i].next_elem;
    ElemNext *P = H;
    if (H == nullptr) {
        cout << "���Ҷ��㲻�����ڽӶ��㣬������ѡ����Ĳ���!" << endl;
        return FALSE;
    } else if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
        //��һ���ڽӶ����������
        (*G)->elemtype[i].next_elem = H->next_elem;
        free(H);
        cout << "ɾ�����ɹ�!" << endl;
        return OK;
    } else {
        while (H) {
            if (!strcmp((*G)->elemtype[H->current].id, (*G)->elemtype[l].id)) {
                P -> next_elem = H -> next_elem;
                cout << "ɾ�����ɹ�!" << endl;
                free(H);
                return OK;
            }
            P = H;
            H = H->next_elem;
        }
        if (!H) {
            cout << "���������һ���ϵ��������ѡ����Ĳ���!" << endl;
            return FALSE;
        }
    }
}

Status WriteToFile(Graphptr G) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    char filename[20];
    cout << "�����ļ����ƣ�������20���ַ���:" << endl;
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
        cout << "�����ļ��ɹ�!" << endl;
        return OK;
    } else
        cout << "�����ļ�ʧ��!" << endl;
    return FALSE;
}

Status ReadFromFile(Graphptr *G) {
    if((*G) -> number != 0){
        cout << "��ǰͼ��Ϊ�գ�������ͼ���ٶ�ȡ�ļ�!" << endl;
        return FALSE;
    }
    char filename[20];
    cout << "�����ļ����ƣ�������20���ַ���:" << endl;
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
            //�����һ���ڽӶ���
            if (infile >> elemNext.current && elemNext.current != -1) {
                (*G)->elemtype[i].next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                (*G)->elemtype[i].next_elem->current = elemNext.current;
                (*G)->elemtype[i].next_elem->next_elem = nullptr;
            } else
                continue;
            //�����������ڽӶ���
            ElemNext *e = (*G)->elemtype[i].next_elem;
            while (infile >> elemNext.current && elemNext.current != -1) {
                e->next_elem = (ElemNext *) malloc(sizeof(ElemNext));
                e = e->next_elem;
                e->current = elemNext.current;
                e->next_elem = nullptr;
            }
        }
        infile.close();
        cout << "��ȡ�ɹ�!" << endl;
        return OK;
    } else {
        cout << "�����ڴ��ļ�!" << endl;
        return FALSE;
    }
}


void DFS(Graphptr G, int v) {
    //�˴��ı��־���״̬
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
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    for (int i = 0; i < G->number; i++) {
        visited[i] = 0;
    }//��־�����ʼ��
    VisitFunc = Visit;
    int v;
    for (v = 0; v < G->number; v++)
        if (!visited[v])
            DFS(G, v);
}

Status BFSTraverse(Graphptr G, Status(*Visit)(ElemType *e)) {
    if(!G -> number){
        cout << "��ǰͼΪ�գ�������ѡ����Ĳ���!" << endl;
        return OK;
    }
    for (int i = 0; i < G->number; i++) {
        visited[i] = 0;
    }//��־�����ʼ��
    LinkQueue Q;
    InitQueue(Q);
    int v;
    int w = -1;
    ElemNext *elemNext;
    for (v = 0; v < G->number; v++) {
        if (!visited[v]) {
            //���ʶ���
            EnQueue(Q, v);
            visited[v] = 1;
            Visit(&(G->elemtype[v]));
            //�����ڽӶ���
            while (Q.front != Q.rear) {//�ж϶����Ƿ�Ϊ��
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
        return -2;//���пռ���
    Q.base[Q.rear] = v;
    Q.rear = (Q.rear + 1) % MAX;
    return OK;
}

Status DeQueue(LinkQueue &Q, int &w) {
    if (Q.front == Q.rear)
        return -2;//���пռ���
    w = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX;
    return OK;
}