//单链表进行快速排序
//基本思想是遍历一遍将比head小的节点挖出来建立一个新的链表，然后将这个链表放在head之前
//双向链表快排也可以用这种思路
typedef struct Node
{
	int val;
	struct Node *next;
}LLNode;

void partition(LLNode** phead, LLNode* tail)
{
	if(*phead == tail)return;

	LLNode *small_head, *big_head, *small_tail, *big_tail, *tp;
	LLNode **cur = &((*phead)->next);
	LLNode *end = tail->next;

	small_head = NULL;
	big_tail = NULL;
	small_head = NULL;
	small_tail = NULL;

	while(*cur != end)
	{
		if((*cur)->val >= (*phead)->val)
		{
			big_tail = *cur;
			cur = &((*cur)->next);
		}
		else{
			tp = *cur;
			*cur = (*cur)->next;
			if(small_head == NULL)
			{
				small_head = small_tail = tp;
				tp->next = NULL;
			}else
			{
				small_tail->next = tp;
				small_tail = tp;
				tp->next = NULL;
			}
		}
	}

	tp = *phead;
	if(small_tail != NULL)
	{
		small_tail->next = *phead;

		//注意这一段不能忘记，重新设置head和tail
		*phead = small_head;
	}else small_tail = *phead;

	if(big_tail != NULL)
		tail = big_tail;
	else tail = tp;

	partition(phead, small_tail);
	if(tail != tp)partition(&(tp->next), tail);
}



//双链表交换两节点
//需要考虑两个节点相同、相邻、在链表头尾
//可以想象成两次插入
typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}LNode;

void insertNode(LNode* cur, LNode *p)//将p插到cur之前
{
	;
}

void swapNode(LNode* a, LNode* b)
{
	if(a == NULL || b == NULL || a == b)return;
	LNode *pa = a;
	LNode *pb = b;
	LNode *pbn = b->right;
	LNode *pbp = b->left;
	
	insertNode(a, b);
	if(pbn != NULL)
		insertNode(pbn, a);
	else{

	}
}