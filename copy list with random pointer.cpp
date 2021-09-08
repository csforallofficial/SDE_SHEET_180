/*
*/

//1st approach - Create a hash map. Create deep copy of every node in the hashmap and then assign the next and random pointers of the deepcopies with respect to the original ones. 
// and then we return the head of the deep copied linked list
//Time - O(N) for first traversal while creating the deep copies && O(N) for traversing again while assiging the next and random pointers to the deep copies.
//Space - O(N) for the creating the Hash map

//2nd approach - 
//Create deepcopy of the original nodes, like connecting 1 --> 1' --> 2 --> 2' --> 3 --> 3' and so on.

        ListNode* iter = head;
        ListNode* front = head;
        while(iter!=NULL){
            front = iter->next;
            ListNode* copy = new ListNode(iter.val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
//Assign the random pointers of the deep copied nodes with respect to the original nodes

        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
//Seperate the original linked list from the deep copied linked list

        iter = head;
        Node* pseudohead = new Node(0);
        Node* copy = pseudohead;
        while(iter!=NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return pseudohead->next;
        
//Time - O(N) for 1st traversal while creating deep copied, O(N) for assigning random pointers and O(N) for seperating the original list from the deep copied list
//Space - O(1) since no extra spaced needed.



