class Solution {
    public int search(int[] nums, int target) {

        int i = 0;
        int j = nums.length - 1;

        while (i <= j) {

            // Find the middle index without risking integer overflow
            int mid = i + (j - i) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Target is bigger than middle element,
            // so eliminate the entire left half including mid
            if (target > nums[mid]) {
                i = mid + 1;
            }

            // Target is smaller than middle element,
            // so eliminate the entire right half including mid
            else {
                j = mid - 1;
            }
        }

        // Target doesn't exist
        return -1;
    }
}