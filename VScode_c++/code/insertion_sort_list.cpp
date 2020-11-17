#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr|| !head->next){
            return head;
        }
        ListNode *dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode *prev =head;
        ListNode *node = head->next;
        while(node){
            if (node->val < prev->val){
                ListNode* temp = dummy_head;
                while(temp ->next->val < node->val){
                    temp = temp->next;
                }
                prev->next = node ->next;
                node->next = temp->next;
                temp->next = node;
                node = prev->next;
            }else{
                prev = prev->next;
                node=node->next;
            }
        }
        return dummy_head->next;

    }

    ListNode* markLinkedNode(int* numbers,int l){
        ListNode* dummy_head = new ListNode(-1);
        ListNode *node = dummy_head;
        for (int i = 0; i < l;i++){
            node->next = new ListNode(numbers[i]);
            node = node->next;
        }
        return dummy_head->next;
    }
};
int main(){
    cout << "hello world" << endl;
    Solution  solution = Solution();
    int numbers[] = {4, 2, 1, 3};
    int l = sizeof(numbers)/sizeof(numbers[0]);
    ListNode *input = solution.markLinkedNode(numbers,l);
    ListNode *result = solution.insertionSortList(input);

    while(result){
        cout << result->val << endl;
        result = result->next;
    }
    getchar();}
