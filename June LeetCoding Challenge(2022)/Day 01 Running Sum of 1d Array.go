func runningSum(nums []int) []int {
    var res []int
    res = append(res, nums[0])
    
    for i := 1; i<len(nums); i++{
        res = append(res, nums[i] + res[i-1])
    }
    return res
}
