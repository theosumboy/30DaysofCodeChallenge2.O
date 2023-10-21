from collections import deque

class Solution:
    def constrainedSubsetSum(self, nums, k):
        maxSum = nums[0]
        maxSumQueue = deque()

        for i in range(len(nums)):
            nums[i] += maxSumQueue[0] if maxSumQueue else 0
            maxSum = max(maxSum, nums[i])

            while maxSumQueue and nums[i] > maxSumQueue[-1]:
                maxSumQueue.pop()

            if nums[i] > 0:
                maxSumQueue.append(nums[i])

            if i >= k and maxSumQueue and maxSumQueue[0] == nums[i - k]:
                maxSumQueue.popleft()

        return maxSum
