/*
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/


//optimal approach - We create a sum variable = 0, and count variable = 0. First we sort the array in descending order according to the profits. Then we find the maximum deadline. We create a dummy array of length = maximum
//We iterate through the sorted array pairs, and for each job id, we look for it's deadline, and check if the corresponding index is available in the dummy array. If yes,
//we fill the dummy array with that job id in that particular index. And we add the profit to the sum and increase count by 1. In case, the corresponding index is not available, we look for 
//the nearest empty slot left to it and place the id there. If not available, then that job can't be completed.
//Time - O(NlogN) + O(N*M), NlogN for sorting the array and N*M for iterating through each job id and placing them in the dummy array.
//Space - O(M)


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job j1, Job j2){
        return (j1.profit > j2.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> res;
        sort(arr,arr+n,comparator);
        int max1 = arr[0].dead;
        for(int i = 1; i < n; i++)
            max1 = max(max1,arr[i].dead);
        
        int count = 0, profit = 0;
        int arr2[max1+1];
        for(int i = 0; i <= max1; i++)
            arr2[i] = -1;
            
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(arr2[j] == -1){
                    arr2[j] = arr[i].dead;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        res.push_back(count);
        res.push_back(profit);
        return res;
    } 


