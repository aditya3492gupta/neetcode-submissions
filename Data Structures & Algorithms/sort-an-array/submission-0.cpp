class Solution {
public:
    void merge(vector<int> &arr, int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;
        vector<int> t1(n1), t2(n2);
        for (int i = 0; i < n1; i++)
            t1[i] = arr[start + i];
        for (int j = 0; j < n2; j++)
            t2[j] = arr[mid + 1 + j];
        int i = 0, j = 0;
        int k = start;
        while (i < n1 && j < n2) {
            if (t1[i] <= t2[j]) {
                arr[k] = t1[i];
                i++;
            }
            else {
                arr[k] = t2[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = t1[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = t2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int> &nums, int start, int end){
        if(end <= start)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};