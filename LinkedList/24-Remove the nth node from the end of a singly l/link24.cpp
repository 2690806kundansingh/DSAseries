class Solution{
    public:
    Node*removeFromEnd(Node*head,int n){
        //step 1 create a dummy node
        Node*dummy = new Node(0);
        dummy->next = head;

        //step 2 use two pointers
        Node*fast = dummy;
        Node*slow = dummy;

        //step 3 move fast pointer n steps ahead
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        //step4 Move fast one more step so the gap is n+1
        fast = fast->next;

        //step 5 Move both pointer untils fast reaches the end
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        //step 6 Delete the nth node from the end
        Node*todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;

        //Return the new head
        Node*newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
