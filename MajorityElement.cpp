// Question: 

// Majority Element

// Moore Voting Algorithm : Works only for majority condition (occurence more than half) 
// Keep track of ans and count
// Reset ans if count = 0 -> ans = curr_ele
// Increment count if found ans
// decrement if found anything else

// Complexity T-> O(n)   S-> O(1)


int majorityElement(int a[], int size)
    {
        int ans, count = 0;
        for (int i = 0; i < size; i ++) {
            if (count == 0) {
                count ++;
                ans =  a[i];
            }
            else if ( a[i] == ans) count ++;
            else count --;
        }
        count = 0;
        // your code here
        for (int i = 0; i < size; i ++) {
            if (a[i] == ans) count ++;
        }
        if (count > size/2) return ans;
        return -1;
        
    }
