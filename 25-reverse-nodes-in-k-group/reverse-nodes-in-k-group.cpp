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
    ListNode* findKthNode(ListNode* temp, int k ){
        k -= 1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseLinkedList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLinkedList(head->next);
        ListNode* frontNode = head->next;
        frontNode->next = head;
        head->next = NULL;

        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp){
            ListNode* kthNode = findKthNode(temp,k);

            if(kthNode == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp);

            if(temp == head) head = kthNode;
            else prevNode->next = kthNode;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};