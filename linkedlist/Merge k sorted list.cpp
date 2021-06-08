class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL && l2==NULL) return NULL;
        if(l1 && !l2) return l1;
        if(l2 && !l1) return l2;
        if(l1->val<l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
        //return NULL;
    }
    ListNode* mergelists(vector<ListNode*>& lists,int start,int end){
        if(start==end) return lists[start];             //both equal one ist so return it for left or right
        int mid=start+(end-start)/2;
        ListNode* left=mergelists(lists,start,mid);
        ListNode* right=mergelists(lists,mid+1,end);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergelists(lists,0,lists.size()-1);
    }
};
