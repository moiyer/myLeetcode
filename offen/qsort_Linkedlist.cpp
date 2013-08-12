//单链表进行快速排序
//基本思想是遍历一遍将比head小的节点挖出来建立一个新的链表，然后将这个链表放在head之前
//双向链表快排也可以用这种思路
typedef struct Node
{
	int val;
	struct Node *next;
}LNode;

void partition(LNode** phead, LNode* tail)
{
	if(*phead == tail)return;

	LNode *small_head, *big_head, LNode *small_tail, *big_tail, *tp;
	LNode **cur = &((*phead)->next);
	LNode *end = tail->next;

	small_head = NULL;
	big_tail = tail;
	small_head = *phead;
	small_tail = phead;

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
	small_tail->next = *phead;

//注意这一段不能忘记，重新设置head和tail
	tp = *phead;
	*phead = small_head;
	tail = big_tail;

	partition(phead, small_tail);
	partition(&(tp->next), tail);
}