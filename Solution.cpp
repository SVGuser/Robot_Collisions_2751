class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0); // indices 0..n-1
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; // stack of indices of robots moving right
        vector<int> alive(n, 1);

        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else { // directions[i] == 'L'
                while (!st.empty() && healths[i] > 0) {
                    int j = st.top();
                    if (healths[j] < healths[i]) {
                        alive[j] = 0;
                        st.pop();
                        healths[i]--; // left robot loses 1 health
                    } else if (healths[j] == healths[i]) {
                        alive[j] = 0;
                        alive[i] = 0;
                        st.pop();
                        healths[i] = 0;
                        break;
                    } else { // healths[j] > healths[i]
                        healths[j]--;
                        alive[i] = 0;
                        healths[i] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> ans; 
        for (int i = 0; i < n; i++) {
            if (alive[i] && healths[i] > 0) ans.push_back(healths[i]);
        }
        return ans;
    }
};
