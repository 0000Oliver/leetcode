#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode * slow = head;
        ListNode * fast = head->next;
        while (fast!= nullptr  && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * mid = slow->next;
        slow->next = nullptr;
        ListNode * left = sortList(head);
        ListNode * right = sortList(mid);

        ListNode * dummy_head = new ListNode(0);
        ListNode * node  = dummy_head;
        while (left && right){
            if (left->val <right->val){
                node->next = left;
                left = left->next;
            }
            else{
                node->next =right;
                right = right->next; 
            }
            node = node->next;
        }
        if (left){
            node->next = left;
        }else{
            node->next= right;
        }
        return dummy_head->next;
    }
     ListNode* sortList2(ListNode* head) {

        ListNode * node  = head;
        int length = 0;
        int intv = 1;

        while (node){
            node = node->next;
            length+=1;
        }
        ListNode * dummy_head = new ListNode(0);
        dummy_head->next = head;

        while(intv < length){
            ListNode * pre = dummy_head;
            node = dummy_head->next;
            while(node){
                ListNode * h1 = node;
                int i = intv;
                while(node && i){
                    node = node->next;
                    i -=1;
                }
               
                if (i){
                    break;
                }
                ListNode *h2 = node;;
                i = intv;
                while(node && i){
                    node = node->next;
                    i -=1;
                }
                int c1  = intv;
                int c2 = intv-i;
                while (c1 && c2){
                    if (h1->val < h2->val){
                        
                        pre->next = h1;
                        h1 = h1->next;
                        c1 -=1;
                    }else{
                        pre->next = h2;
                        h2 = h2->next;
                        c2 -=1;
                    }
                    pre = pre->next;
                }
                pre->next = (c1)?h1:h2;
                while(c1>0 || c2>0){
                    pre = pre->next;
                    c1-=1;
                    c2-=1;
                }
                pre->next = node;
            }
            intv *=2;
        }
        return dummy_head->next;
    
    }
};
ListNode* markLinkedNode(int* numbers,int l){
    ListNode* dummy_head = new ListNode(-1);
    ListNode *node = dummy_head;
    for (int i = 0; i < l;i++){
        node->next = new ListNode(numbers[i]);
        node = node->next;
    }
    return dummy_head->next;
}
int main(){
    cout << "hello world" << endl;
    Solution  solution = Solution();
    int numbers[] = {4, 2, 1, 3};
    int l = sizeof(numbers)/sizeof(numbers[0]);
    ListNode *input = markLinkedNode(numbers,l);
    ListNode *result = solution.sortList(input);

    while(result){
        cout << result->val << endl;
        result = result->next;
    }
    getchar();}