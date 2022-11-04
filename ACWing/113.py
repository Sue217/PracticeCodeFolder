# Forward declaration of compare API.
# def compare(a, b):
# @param a, b int
# @return bool
# return bool means whether a is less than b.

class Solution(object):
    def specialSort(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        ret = [1]
        for i in range(2, N + 1):
            low = 0
            high = len(ret) - 1
            while low < high:
                mid = (low + high + 1) / 2
                if compare(ret[mid], i):
                    low = mid
                else:
                    high = mid - 1
            ret.append(i)
            for j in range(len(ret) - 2, high, -1):
                ret[j], ret[j + 1] = ret[j + 1], ret[j]
            if compare(i, ret[high]):
                ret[high], ret[high + 1] = ret[high + 1], ret[high]

        return ret
