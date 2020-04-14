#include <stdio.h>
#include <stdlib.h>
/**
 * AC time 85.22%
 *    mem  100  %
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* newNode()
{
	struct ListNode* new = malloc(sizeof(struct ListNode));
	return new;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int s1[10000]; // stack of l1
	int s2[10000]; // stack of l2
	int top1 = -1; // stack top1
	int top2 = -1; // stack top2
	struct ListNode* t1 = l1; // temp pointers
	struct ListNode* t2 = l2; 
	while (t1 != NULL) // push the vals to stack
	{
		s1[++top1] = t1->val;
		t1=t1->next;
	}
	while (t2 != NULL)
	{
		s2[++top2] = t2->val;
		t2=t2->next;
	}
	struct ListNode* result = NULL; // the result pointer
	int up = 0; // to add the part up 10 to pre loc
	while (top1>=0 || top2>=0) // calc every node val and insert to the head of list
	{
		printf("[%d:%d] - [%d:%d]\n", top1, (top1<0?0:s1[top1]), top2, (top2<0?0:s2[top2]));
		int cval = up + (top1<0?0:s1[top1--])+(top2<0?0:s2[top2--]);//pop vals from stack and calc the current value
		if (cval>=10)
		{
			up=1;
			cval-=10;
		}
		else
		{
			up = 0;
		}
		struct ListNode* temp=newNode(); // make a temp element
		temp->val = cval; // set the element
		temp->next = result; // insert to list
		result = temp;
	}
	if (up!=0)
	{
		struct ListNode* temp=newNode();
		temp->val=up;
		temp->next=result;
		result=temp;
	}
	return result;

}

int main()
{
	int in1[4] = {7,2,4,3};
	int in2[3] = {5,6,4};
	struct ListNode *l1=NULL; 
	for (int i = 3;i >= 0;i--)
	{
		struct ListNode *temp=newNode();
		temp->val=in1[i];
		temp->next=l1;
		l1=temp;
	}
	struct ListNode *l2 = NULL;
	for (int i = 2;i >= 0;i--)
	{
		struct ListNode *temp=newNode();
		temp->val=in2[i];
		temp->next=l2;
		l2=temp;
	}
	struct ListNode * result = addTwoNumbers(l1, l2);
	while (result != NULL)
	{
		printf("%d, ", result->val);
		result=result->next;
	}
	return 0;
}
