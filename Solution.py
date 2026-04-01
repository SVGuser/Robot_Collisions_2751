from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        idx = list(range(n))
        idx.sort(key=lambda i: positions[i])

        stack = []
        alive = [True] * n

        for i in idx:
            if directions[i] == 'R':
                stack.append(i)
            else:  # 'L'
                while stack and healths[i] > 0:
                    j = stack[-1]
                    if healths[j] < healths[i]:
                        alive[j] = False
                        stack.pop()
                        healths[i] -= 1
                    elif healths[j] == healths[i]:
                        alive[j] = False
                        alive[i] = False
                        stack.pop()
                        healths[i] = 0
                        break
                    else:
                        healths[j] -= 1
                        alive[i] = False
                        healths[i] = 0
                        break

        return [healths[i] for i in range(n) if alive[i] and healths[i] > 0]
