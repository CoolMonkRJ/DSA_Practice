class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string word = q.front();
                q.pop();

                // If we reached endWord, return answer
                if (word == endWord)
                    return level;

                // Try changing each character
                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        // Skip generating the same word
                        if (ch == original)
                            continue;

                        word[i] = ch;

                        if (wordSet.find(word) != wordSet.end()) {

                            q.push(word);

                            // Mark visited immediately
                            wordSet.erase(word);
                        }
                    }

                    // Restore original character
                    word[i] = original;
                }
            }

            // One BFS level completed
            level++;
        }

        return 0;
    }
};