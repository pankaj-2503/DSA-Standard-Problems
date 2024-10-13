// Given an array consisting of only 0,1,2 sort it in time complexity of O(N) -> below algo is dutch-national-flag-algo
// Time complexity - O(N)

void sort012(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


//  use this approach which is simple
void countSort012(vector<int>& arr) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Step 1: Count the occurrences of 0, 1, and 2
    for (int num : arr) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else count2++;
    }

    // Step 2: Refill the array based on the counts
    int i = 0;

    // Fill all 0's
    while (count0--) {
        arr[i++] = 0;
    }
    
    // Fill all 1's
    while (count1--) {
        arr[i++] = 1;
    }
    
    // Fill all 2's
    while (count2--) {
        arr[i++] = 2;
    }
}