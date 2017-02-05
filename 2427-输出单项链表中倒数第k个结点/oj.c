/*
输入一个单向链表，输出该链表中倒数第k个结点，
链表的倒数第0个结点为链表的尾指针。

链表结点定义如下：

struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
};

详细描述：

接口说明

原型：

ListNode* FindKthToTail(ListNode* pListHead, unsignedint k);

输入参数：

    ListNode* pListHead  单向链表
    unsigned int k  倒数第k个结点

输出参数（指针指向的内存区域保证有效）：

    无

返回值：

        正常返回倒数第k个结点指针，异常返回空指针

 */

#include <stdio.h>
#include <stdlib.h>



//  调试开关
//#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG


typedef struct ListNode
{
      int               m_nKey;
      struct ListNode   *m_pNext;
}ListNode;



//  根据输入的结点信息创建并初始化链表结点
ListNode* InputList(int length);

//  输出单向链表的信息
void OutputList(ListNode *pListHead);

//  删除单向链表的空间
void DeleteList(ListNode *pListHead);

//  查找链表pListHead的倒数第K个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);


int main( )
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int         n, k;
    struct ListNode *pListHead = NULL;
    struct ListNode *pNode = NULL;

    while(scanf("%d", &n) != EOF)
    {
        if((pListHead = InputList(n)) == NULL)
        {
            exit(-1);
        }
#ifdef DEBUG
        OutputList(pListHead);
#endif

        scanf("%d", &k);

        if((pNode = FindKthToTail(pListHead, k)) == NULL)
        {
            exit(0);
        }
        printf("%d\n", pNode->m_nKey);
        DeleteList(pListHead);
    }

    return 0;
}


//  根据输入的结点信息创建并初始化链表结点
ListNode* InputList(int length)
{
    struct ListNode *pListHead  = NULL;
    struct ListNode *pCurrNode  = NULL;
    struct ListNode *pLastNode  = NULL;
    int         key;

    if(length == 0)
    {
        return NULL;
    }
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &key);
        if((pCurrNode = (struct ListNode *)malloc(sizeof(struct ListNode))) == NULL)
        {
            perror("no memory");
            exit(-1);
        }
        pCurrNode->m_nKey = key;
        pCurrNode->m_pNext = NULL;

        if(pListHead == NULL)
        {
            pListHead = pCurrNode;
        }
        if(pLastNode != NULL)
        {
            pLastNode->m_pNext = pCurrNode;
        }

        pLastNode = pCurrNode;
    }

    return pListHead;
}

//  输出单向链表的信息
void OutputList(ListNode *pListHead)
{
    if(pListHead == NULL)
    {
        return ;
    }
    printf("%d", pListHead->m_nKey);
    ListNode *pNode = pListHead->m_pNext;
    while(pNode != NULL)
    {
        printf(" -=> %d", pNode->m_nKey);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

//  删除单向链表的空间
void DeleteList(ListNode *pListHead)
{
    ListNode *pNode = pListHead;
    ListNode *pNextNode = NULL;
    while(pNode != NULL)
    {
        pNextNode = pNode->m_pNext;

        free(pNode);
        pNode = pNextNode;
    }
}

//  查找链表pListHead的倒数第K个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    ListNode *pFirstNode = pListHead;
    ListNode *pSecondNode = pListHead;
    if(pListHead == NULL || k == 0)
    {
        return NULL;
    }
    //  第一个指针先走K-1步
    for(int i = 0;
        i < k && pFirstNode != NULL;
        i++)
    {
        pFirstNode = pFirstNode->m_pNext;
    }

    if(pFirstNode == NULL)
    {
        return NULL;
    }

    while(pFirstNode->m_pNext != NULL) /*  最后一个节点为倒数第0个, 其前一个节点为倒数第1个*/
    {
        pFirstNode = pFirstNode->m_pNext;
        pSecondNode = pSecondNode->m_pNext;
    }

    return pSecondNode;
}
