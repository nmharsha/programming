/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode* copyRandomList( RandomListNode * head ) {
        if ( head == NULL ) {
            return NULL;
        }
        RandomListNode* headRef = head;
        RandomListNode* copyHeadRef;
        while ( head != NULL ) {
            //cout << "Maybe" << endl;
            RandomListNode* copyHead = new RandomListNode( head->label );
            copyHead->next = head->next;
            head->next = copyHead;
            if ( head == headRef ) {
                copyHeadRef = copyHead;
            }
            head = copyHead->next;
        }
        head = headRef;
        while ( head != NULL ) {
            cout << "In here" << endl;
            if ( head->random == NULL) {
                head->next->random = NULL;
            } else {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        head = headRef;
        while ( head != NULL ) {
            RandomListNode* temp = head->next;
            head->next = temp->next;
            if ( temp->next != NULL ) {
                temp->next = temp->next->next;
            }
            head = head->next;
        }
        return copyHeadRef;
    }
};

