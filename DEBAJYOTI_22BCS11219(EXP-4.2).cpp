#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;  

        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); // Start event
            events.emplace_back(b[1], b[2]);  // End event
        }

        sort(events.begin(), events.end());

        multiset<int> heights = {0};  // Max heap using multiset
        vector<vector<int>> result;
        int prevMaxHeight = 0;

        for (auto& e : events) {
            int x = e.first, h = e.second;

            if (h < 0) {  
                heights.insert(-h);
            } else {  
                heights.erase(heights.find(h));
            }

            int currentMaxHeight = *heights.rbegin();  

            if (currentMaxHeight != prevMaxHeight) {  
                result.push_back({x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }

        return result;
    }
};
