#include <stdio.h>
#include <stdlib.h>
/*
 * 42．（10 分）请设计一个队列，要求满足：①初始时队列为空；②入队时，允许增加
队列占用空间；③出队后，出队元素所占用的空间可重复使用，即整个队列所占用的空间只
增不减；④入队操作和出队操作的时间复杂度始终保持为 O(1)。请回答下列问题：
（1）该队列是应选择链式存储结构，还是应选择顺序存储结构？
（2）画出队列的初始状态，并给出判断队空和队满的条件。
（3）画出第一个元素入队后的队列状态。
（4）给出入队操作和出队操作的基本过程。
 * */
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;


void EnQueue(LinkList front,LinkList &rear,ElemType x){
    LinkList  pNew;
    if(rear->next==front){//队满，申请一个结点的空间，放入队列
        pNew=(LinkList) malloc(sizeof(LNode));
        rear->data=x;//把入队元素放入rear指向结点
        rear->next=pNew;//放入了一个结点，相当于做了分割
        pNew->next=front;//形成循环队列
        rear=pNew;//队尾始终指向新的结点
    }else{//如果队列不满，直接放值，让rear后移一个结点
        rear->data=x;
        rear=rear->next;
    }
}

void DeQueue(LinkList &front,LinkList rear){
    if(front==rear){
        printf("queue is empty\n");
    }else{
        printf("deQueue value is %d\n",front->data);
        front=front->next;
    }
}

void CircleQueue(LinkList &front,LinkList &rear){
    //队列头和队列尾都指向一个结点，此时队列是空的，也是满的
    front=(LinkList) malloc(sizeof(LNode));
    rear=front;
    rear->next=front;
    //入队
    EnQueue(front,rear,3);
    EnQueue(front,rear,4);
    //出队
    DeQueue(front,rear);
    DeQueue(front,rear);
    DeQueue(front,rear);
}
int main() {
    LinkList front,rear;
    CircleQueue(front,rear);
    return 0;
}
