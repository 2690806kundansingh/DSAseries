#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second) {
        int carry = 0;

        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0) {
            int val1 = (first != NULL) ? first->data : 0;
            int val2 = (second != NULL) ? second->data : 0;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (first) first = first->next;
            if (second) second = second->next;
        }

        return ansHead;
    }

public:
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1: Reverse both lists
        first = reverse(first);
        second = reverse(second);

        // Step 2: Add both numbers
        Node* ans = add(first, second);

        // Step 3: Reverse the result to get final answer
        ans = reverse(ans);
        return ans;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Number 1: 243 (stored as 2 -> 4 -> 3)
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(3);

    // Number 2: 564 (stored as 5 -> 6 -> 4)
    Node* second = new Node(5);
    second->next = new Node(6);
    second->next->next = new Node(4);

    Solution sol;
    Node* result = sol.addTwoLists(first, second); // should give 807 as 8 -> 0 -> 7

    cout << "Result: ";
    printList(result);  // Output: 8 -> 0 -> 7

    return 0;
}
