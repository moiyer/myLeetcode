#include <iostream>

using namespace std;

typedef struct _Node
{
	int val;
	struct _Node* next;
}Node;

bool IsExitLoop(Node* head)
{
	Node* fast = head, *slow = head;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)return true;
	}

	return false;
}

Node* GetFirstCommonNode(Node* aHead, Node* bHead)
{
	if(aHead == NULL || bHead == NULL)return NULL;

	bool aExitLoop = IsExitLoop(aHead);
	bool bExitLoop = IsExitLoop(bHead);
	if(aExitLoop == false && bExitLoop == false)
	{
		int aLength = 1;
		int bLength = 1;
		Node* aCur = aHead;
		Node* bCur = bHead;
		while(aCur->next != NULL)
		{
			aCur = aCur->next;
			aLength++;
		}
		while(bCur->next != NULL)
		{
			bCur = bCur->next;
			bLength++;
		}
		if(aLength < bLength)
		{
			swap(aLength, bLength);
			swap(aHead, bHead);
		}
		int gap = aLength - bLength;
		aCur = aHead;
		bCur = bHead;
		for(int i = 0; i < gap; ++i)
			aCur = aCur->next;
		while(aCur != NULL && aCur != bCur)
		{
			aCur = aCur->next;
			bCur = bCur->next;
		}
		if(aCur == NULL)return NULL;
		else return aCur;
	}else if(aExitLoop ^ bExitLoop == 1)
	{
		return NULL;
	}else if(aExitLoop == true && bExitLoop == true)
	{
		//¶Ï¿ª»·
	}
}

int main()
{
	system("pause");
	return 0;
}

