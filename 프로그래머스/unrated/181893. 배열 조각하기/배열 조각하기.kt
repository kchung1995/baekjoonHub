class Solution {
    fun solution(arr: IntArray, query: IntArray): IntArray {
        var result = arr
        for (i in 0 until query.size) {
            when (i % 2) {
                0 -> result = result.sliceArray(0 until query[i] + 1)
                1 -> result = result.sliceArray(query[i] until result.size)
            }
        }
        return result
    }
}