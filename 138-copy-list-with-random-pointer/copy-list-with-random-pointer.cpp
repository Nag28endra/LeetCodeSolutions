/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* cloneOfLL(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp){
                res->next = temp->next;
                res = res->next;
                temp->next = temp->next->next;
                temp = temp->next;
        }   
        return dummyNode->next;
    }
    void giveRandomConnections(Node* head){
        Node* temp = head;

        while(temp){
            Node* copyNode = temp->next;
            if(temp->random)copyNode->random = temp->random->next;
            else copyNode->random = nullptr;
            temp = temp->next->next;
        }
    }
    void insertCopyNodes(Node* head){
        Node * temp = head;

        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // first insert copynodes in between the linked list
        insertCopyNodes(head);

        // give random conections to the copy nodes.
        giveRandomConnections(head);

        // remove the connections of original linked lists to copy nodes and return them.
        return cloneOfLL(head);
    }
};