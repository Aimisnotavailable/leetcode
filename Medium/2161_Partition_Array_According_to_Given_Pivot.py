class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        
        gt = []
        lt = []

        tp = nums.count(pivot)
        eq = [pivot for i in range(tp)]

        for num in nums:

            if num < pivot:
                lt.append(num)
            elif num > pivot:
                gt.append(num)

        return lt + eq + gt    
