// Count occurrences of each element using an unordered_map<int, int>.

// Store the frequencies in an unordered_set<int>.

// If the size of the set equals the number of unique elements, return true; otherwise, return false.

class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> freq; // Stores occurrences of elements
            unordered_set<int> seenFreq;  // Stores unique frequencies
    
            // Step 1: Count occurrences
            for (int num : arr) {
                freq[num]++;
            }
    
            // Step 2: Check if frequencies are unique
            for (auto it : freq) {
                if (seenFreq.find(it.second) != seenFreq.end()) {
                    return false; // If frequency already exists, return false
                }
                seenFreq.insert(it.second); // Store frequency in the set
            }
    
            return true; // Return true if all frequencies are unique
        }
    };