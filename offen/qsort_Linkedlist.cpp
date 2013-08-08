//单链表进行快速排序
//基本思想是遍历一遍将比head小的节点挖出来建立一个新的链表，然后将这个链表放在head之前
typedef struct Node
{
	int val;
	struct Node *next;
}LNode;

void partition(LNode** head, LNode** tail)
{
	if(*head == *tail)return;

	LNode *small_head, *small_tail, *big_head, *big_tail, *tp;
	LNode **cur = &((*head)->next);
	LNode *end = (*tail)->next;

	small_tail = small_head = NULL;
	while(*cur != end)
	{
		if((*cur)->val >= head->val)
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
				tp->next = NULL;
			}
		}
	}
	small_tail->next = *head;
	big_head = (*head)->next;

//注意这一段不能忘记，重新设置head和tail
	*head = small_head;
	*tail = big_tail;

	partition(head, &small_tail);
	partition(&big_head, tail);
}