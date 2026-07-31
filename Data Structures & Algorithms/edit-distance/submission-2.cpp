class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base case: "" -> word2
        for (int j = 0; j <= m; j++)
            prev[j] = j;

        for (int i = 1; i <= n; i++) {

            // Base case: word1 -> ""
            curr[0] = i;

            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    curr[j] = 1 + min({
                        prev[j],      // Delete
                        curr[j - 1],  // Insert
                        prev[j - 1]   // Replace
                    });
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};