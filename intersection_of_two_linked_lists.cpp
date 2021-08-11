/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, 
then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; 
There are 3 nodes before the intersected node in B.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; 
There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, 
while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
0 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 

Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?
*/


/*
1st approach- 
Traverse through nodes of any of the linked lists. For each node, check if there's an identical node present in the other linked list. If it's present, return the node.
Time - O(m*n) || m -> size of linked list 1; n -> size of linked list 2;
Space - O(1)


2nd approach-
Build a Hash table. Traverse through any of the linked lists. Push the nodes of the linked list into the hash table. Now traverse through nodes of the other linked list.
If the node is already present in the Hash table, return the node.
Time - O(m+n) 
Space - O(1)

3rd approach-
Traverse through both the Linked Lists and count their length. Create dummy nodes each pointing to the head of two linked lists. Count the difference in length. Move the dummy
node of the bigger linked list by (m-n) steps. ( m -> size of bigger linked list; n -> size of smaller linked list;) Now move both the dummy nodes of the two linked lists 
simultaneously. Return the node where both the dummy nodes are equal.
Time - O(2m)
Space - O(1)

4th approach-
Create dummy nodes each pointing to the head of the two linked lists. Move both the dummy nodes simultaneosly until both dummy nodes are equal. If any of the dummy node of a 
particular linked list reaches null, place it at the head of the other linked list and continue the traversal. Return the node where both the dummy nodes are equal. 
Time - O(2m)
Space - O(1)

*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            a = a == NULL?headB:a->next;
            b = b == NULL?headA:b->next;
        }
        return b;
    }
};
