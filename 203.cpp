/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
            ListNode* now=head;
            ListNode* pre=nullptr;
            while(now){
                    //删中间节点
                    if(now->val == val){
                            if(pre != nullptr){
                            							pre->next = now->next;
                            							delete now;
                            							now = pre->next;
                            	}
                            	else{
                            	    ListNode* temp = now;
                            	    head = head->next;
                            	    now = head;
                            	    delete temp;
                            	}
                                               
                    }
                    else{
                            pre = now;
                            now =now->next;
                    }
            }
            return head;
	}
}
