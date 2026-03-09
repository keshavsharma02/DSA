import numpy as np

class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        if n <= 0: return []
        
        i, j = np.indices((n, n))
        
        k = np.minimum(np.minimum(i, j), np.minimum(n - 1 - i, n - 1 - j))
        
        offset = 4 * k * (n - k)
        
        res = np.zeros((n, n), dtype=int)
        
        m = n - 2 * k
        
        top    = (i == k) & (j >= k) & (j < n - k)
        right  = (j == n - 1 - k) & (i > k) & (i < n - k)
        bottom = (i == n - 1 - k) & (j >= k) & (j < n - 1 - k)
        left   = (j == k) & (i > k) & (i < n - 1 - k)
        
        res[top]    = offset[top] + (j[top] - k[top] + 1)
        res[right]  = offset[right] + m[right] + (i[right] - k[right])
        res[bottom] = offset[bottom] + 2 * m[bottom] + (n - 2 - k[bottom] - j[bottom])
        res[left] = offset[left] + 3 * m[left] - 1 + (n - 2 - k[left] - i[left])
        
        return res.tolist()