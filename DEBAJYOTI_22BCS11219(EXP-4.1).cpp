#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1};  
        while (result.size() < n) {
            vector<int> temp;
            // Generating odd numbers
            for (int num : result) {
                if (2 * num - 1 <= n) temp.push_back(2 * num - 1);
            }
            // Generating even numbers
            for (int num : result) {
                if (2 * num <= n) temp.push_back(2 * num);
            }
            result = temp;
        }
        return result;
    }
};
