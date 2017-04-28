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

ListNode* removeNthElement(ListNode* head, int n) {
    ListNode *ahead = head;
    ListNode* current = head;
    for (int i = 0; i <= n; ++i) {
        // Deal with border case when one element is to be
        // deleted.
        if (!current)
            return ahead->next;
        current = current->next;
    }
    while (current) {
        current = current->next;
        ahead = ahead->next;
    }
    ListNode*tmp = ahead->next;
    if (ahead->next)
        ahead->next = ahead->next->next;
    delete tmp;
    return head;
}

int main() {
    vector<int> a = {1};
    ListNode * head = add(a);
    ListNode* h = removeNthElement(head, 1);
    // ListNode* h2 = removeNthElement(head, 1);
    printList(h);
}

