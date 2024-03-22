#include <cstdio>

#define Maxsize 50
typedef int Elemtype;

typedef struct {
    Elemtype data[Maxsize];
    int length;
}SqList;

//在第site位添加
bool insert(SqList &list,Elemtype value,int site){
    if (site >= Maxsize || site < 1)
        return false;
    if (site > list.length+1)
        return false;
    for (int i = list.length; i >= site ; i--) {
        list.data[i] = list.data[i-1];
    }
    list.data[site-1] = value;
    list.length++;
    return true;
}

//删除第site位的元素
bool delList(SqList &list,int site){
    if (site > list.length || site < 1 || site > Maxsize)
        return false;
    for (int i = site-1; i < list.length ; i++) {
        list.data[i] = list.data[i+1];
    }
    list.length--;
    return true;
}

//查询元素在第几位
int searchList(SqList list,Elemtype e){
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == e)
            return i+1;
    }
    return 0;
}
void printList(SqList L){
    for (int i = 0; i < L.length; i++) {
        printf("%5d",L.data[i]);
    }
    printf("\n");
}
int main(){
    SqList L;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 10;
    L.data[3] = 2;
    L.length = 4;
    printList(L);
    bool ret1,ret2;
    ret1 = insert(L,9,5);
    if (!ret1)
        printf("insert failed");
    else
        printf("insert success");
    printList(L);
    ret2 = delList(L,1);
    if (!ret2)
        printf("delete failed");
    else
        printf("delete success");
    printList(L);

    int a;
    a = searchList(L,9);
    if (a==0)
        printf("null");
    else
        printf("the number site is:%d",a);
}