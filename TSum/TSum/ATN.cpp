#include<iostream>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		//接下来的代码is O(n)
/*		ListNode*node = new ListNode(0), *curr = node;
		while (l1 != NULL && l2 != NULL) {
			//i'm sure l1->next and l2->next not null here
			curr->next = new ListNode(0);
			curr = curr->next;
			curr->val=((l1->val + l2->val) % 10);	
			if ((l1->val + l2->val) / 10 != 0) {
				if (l1->next != NULL)
					l1->next->val += ((l1->val + l2->val) / 10);
				if (l1->next == NULL)
					l1->next = new ListNode((l1->val + l2->val) / 10);
				if (l2->next == NULL)
					l2->next = new ListNode(0);	
			}
			else if (l1->next!=NULL || l2->next!=NULL){
				if (l1->next == NULL)
					l1->next = new ListNode(0);
				if (l2->next == NULL)
					l2->next = new ListNode(0);
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		// u cannot use delete to make it NULL
		//use node->next instead
//		delete curr;
		return node->next;*/

		// another solution
		ListNode*node = new ListNode(0), *curr = node;
		int jinwei = 0;
		while (l1 != NULL || l2 != NULL ) {
			//i'm sure l1->next and l2->next not null here
			curr->next = new ListNode(0);
			curr = curr->next;
			curr->val = (((l1?l1->val:0) + (l2?l2->val:0)))+jinwei;
			jinwei = (curr->val) / 10;
			curr->val = curr->val % 10;
			l1 = l1?l1->next:NULL;
			l2 = l2?l2->next:NULL;

		}
		if (jinwei)curr->next = new ListNode(jinwei);
		// u cannot use delete to make it NULL
		//use node->next instead
		//		delete curr;
		return node->next;
	}
};
int main() {
	int tmp;
	ListNode*l1 = new ListNode(0), *l11 = l1;
	ListNode*l2 = new ListNode(0), *l22 = l2;
	cin >> tmp;
	//do not use 10 as the terminal signal as it may be treate as 1
	while (tmp != -1) {
		l11->next = new ListNode(0);
		l11 = l11->next;
		l11->val = tmp;
		
		cin >> tmp;
	}
	cin >> tmp;
	while (tmp != -1) {
		l22->next = new ListNode(0);
		l22 = l22->next;
		l22->val = tmp;
		cin >> tmp;
	}

	Solution s;
	ListNode*ll=s.addTwoNumbers(l1->next, l2->next);
	while (ll != NULL) {
		cout << ll->val << " ";
		ll = ll->next;
	}
	cout << endl;
}