// //merge short in Linklist
// #include<iostream>
// using namespace std;

// //middle function
// Node*findMid(Node*head){
//     Node*slow = head;
//     Node*fast = head;

//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// //merge function
// Node*merge(Node*left,Node*right){
//     if(left == NULL)
//        return right;
//     if(right == NULL)
//        return left;

//     Node*ans = new Node(-1)//creating dummy node
//     Node*temp = head;

//     while(left != NULL && right != NULL){
//         if(left->data < right->data){
//             temp->next = left;
//             temp = left;
//             left = left->next;
//         }
//         else{
//             temp->next = right;
//             temp = right;
//             right = right->next;
//         }
//     } 
//     while(left != NULL){
//         temp->next = left;
//         temp = left;
//         left = left->next;
//     } 
//     while(right != NULL){
//         temp->next = right;
//         temp = right;
//         right = right->next;
//     } 
//     ans = ans->next;
//     return ans;

// }

// Node*mergesort(Node*head){
//     //base case
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     //break into two halves after finding mid
//     Node*mid = findMid(head);

//     Node*left = head;
//     Node*right = mid->next;
//     mid->next = NULL;

//     //recursive call for sort both halves
//     left = mergesort(left);
//     right = mergesort(right);

//     //merge both right and left
//     Node*result = merge(left,right);

//     return result;


// }



#include<iostream>
using namespace std;

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
public:
    // Merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (left == NULL) return right;
        if (right == NULL) return left;

        Node* ans = new Node(-1); // Dummy node
        Node* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->data < right->data) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return ans->next;
    }

    // Find the middle of the linked list
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge sort function
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* middle = getMiddle(head);
        Node* left = head;
        Node* right = middle->next;
        middle->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Creating an unsorted linked list: 5 -> 1 -> 3 -> 2 -> 4
    Node* head = new Node(5);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}

// TC = NLOGN
// SC = LOGN