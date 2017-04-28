#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* tmp) {
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


ListNode* add(vector<int> v) {
    if (v.size() < 1)
        return NULL;
    ListNode * head = new ListNode(v[0]);

    ListNode * iter = head;
    for (int i = 1; i < v.size(); ++i) {
        ListNode* tmp= new ListNode(v[i]);
        iter->next = tmp;
        iter = tmp;
    }
    printList(head);
    return head;
}

ListNode* merge_lists(ListNode* l1, ListNode * l2) {
    ListNode * current;
    if (l1 == NULL)
       return l2;
    if (l2 == NULL)
       return l1;
    // Set the HEAD
    if (l1->val > l2->val) {
        current = l2;
        l2 = l2->next;
    } else {
        current = l1;
        l1 = l1->next;
    }
    ListNode *head = current;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            current->next = l2;
            l2 = l2->next;
        } else {
            current->next = l1;
            l1 = l1->next;
        }
        current = current->next;
    }
    if (l1 != NULL)
        current->next = l1;
    if (l2 != NULL)
        current->next = l2;
     return head;
}

int main() {
    vector<int> a = {1,4,6};
    vector<int> b = {2,3,5,7,8,9,10};
    ListNode * l1 = add(a);
    ListNode * l2 = add(b);
    ListNode *h = merge_lists(l1, l2);
    printList(h);
}

