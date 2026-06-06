class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1

        left_sum = [0]
        right_sum = [0]
        for i in range(len(nums) - 1):
            left_sum.append(left_sum[-1] + nums[i])
        
        for i in range(len(nums) - 1, 0, -1):
            right_sum = [right_sum[0] + nums[i]] + right_sum

        answer = []
        for i in range(len(nums)):
            answer.append(abs(left_sum[i] - right_sum[i]))

        return answer
