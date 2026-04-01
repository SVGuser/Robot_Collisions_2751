import java.util.*;

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;

        Arrays.sort(idx, (a, b) -> positions[a] - positions[b]);

        Stack<Integer> st = new Stack<>();
        boolean[] alive = new boolean[n];
        Arrays.fill(alive, true);

        for (int i : idx) {
            if (directions.charAt(i) == 'R') {
                st.push(i);
            } else { // 'L'
                while (!st.isEmpty() && healths[i] > 0) {
                    int j = st.peek();
                    if (healths[j] < healths[i]) {
                        alive[j] = false;
                        st.pop();
                        healths[i]--;
                    } else if (healths[j] == healths[i]) {
                        alive[j] = false;
                        alive[i] = false;
                        st.pop();
                        healths[i] = 0;
                        break;
                    } else {
                        healths[j]--;
                        alive[i] = false;
                        healths[i] = 0;
                        break;
                    }
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (alive[i] && healths[i] > 0) ans.add(healths[i]);
        }
        return ans;
    }
}
