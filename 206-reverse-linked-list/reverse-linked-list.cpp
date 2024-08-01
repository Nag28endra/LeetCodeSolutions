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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        stack<int> st;
    ListNode* current = head;
    while(current)
    {
        st.push(current->val);
        current = current->next;
    }
    current = head;
    while(current){
        current->val = st.top();
        st.pop();
        current = current->next;
    }
    return head;
    }
    
};