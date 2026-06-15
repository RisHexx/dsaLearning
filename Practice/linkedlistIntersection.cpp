#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode {
  int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int size1 = 0;
        int size2 = 0;
        ListNode* tempA = headA;
        while (tempA != nullptr) {
            size1++;
            tempA = tempA->next;
        }
        ListNode* tempB = headB;
        while (tempB != nullptr) {
            size2++;
            tempB = tempB->next;
        }
        int diff = abs(size1 - size2);
        if (size1 > size2) {
            tempA = headA;
            while (diff--) {
                tempA = tempA->next;
            }
            tempB = headB;
        } else {
            tempB = headB;
            while (diff--) {
                tempB = tempB->next;
            }
            tempA = headA;
        }
        while (tempA != nullptr && tempB != nullptr) {
            if (tempA == tempB) {
                return tempA;
            } else {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};