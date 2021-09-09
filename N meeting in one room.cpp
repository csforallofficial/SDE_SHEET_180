/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105
*/


//1st approach - Intialize a count variable = 0. First traverse through the provided arrays and put them into a data structure. The data structure would contain, start time, end time and 1-based index 
//of the meetings. Sort the data structure in ascending order. Now go through each pair, note the ending time of the first pair as 'lastend' and increase count by 1.
//If the starting time of the next pair is more than the 'lastend', then we can count that pair as the next meeting and the process will continue. If the starting time
//is less than the 'lastend', that pair won't be considered for the next meeting and we will move to the next meeting.
//Time - O(N) for filling the data structure, O(NlogN) for sorting the data structure, and O(N) for traversing through the data structure and finding the meeting pairs.
//Space - O(N) for the data structure.

    struct meeting{
        int start;
        int end;
        int pos;
    };
    static bool comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        else    return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i = 0; i < n; i++)
            meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i+1;
        sort(meet,meet+n,comparator);
        int count = 1;
        int limit = meet[0].end;
        for(int i = 1; i < n; i++){
            if(meet[i].start > limit){
                count++;
                limit = meet[i].end;
            }
        }
        return count;
    }
