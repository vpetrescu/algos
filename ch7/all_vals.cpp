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

ListNode* removeElement(ListNode* head, int val) {
    // Skip head elements
    ListNode * iter = head;
    while (iter && iter->val == val) {
        ListNode * tmp = iter;
        iter = iter->next;
        delete tmp;
    }
    head = iter;
    // Skip other elements
    while (iter) {
        if (iter && iter->next && iter->next->val == val) {
            ListNode * tmp = iter->next;
            iter->next = iter->next->next;
            delete tmp;
        } else {
            iter = iter->next;
        }
    }
    return head;
}

int main() {
    vector<int> a = {6,6,6,1,2,6,6,3,6,6};
    ListNode * head = add(a);
    ListNode* h = removeElement(head, 6);
    printList(h);
}

