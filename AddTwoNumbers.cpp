    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pHead = new ListNode(0);
        ListNode *pCur = pHead;
        int carry = 0;
        while(carry!=0 || l1 || l2){
            int il1 = 0;
            int il2 = 0;
            if(l1){
                il1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                il2 = l2->val;
                l2 = l2->next;
            }
            int sum = il1 + il2 + carry;
            carry = sum/10;
            ListNode *pNewNode = new ListNode(sum%10);
            pCur->next = pNewNode;
            pCur = pNewNode;
        }
        ListNode *pRes = pHead->next;
        delete pHead;
        return pRes;
    }