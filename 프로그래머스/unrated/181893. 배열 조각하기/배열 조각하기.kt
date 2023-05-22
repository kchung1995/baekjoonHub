class Solution {
    fun solution(arr: IntArray, query: IntArray): IntArray {
        var list = arr.toList()
        
        for (i in 0 until query.size) {
            when (i % 2) {
                0 -> list = list.slice(0 until query[i] + 1)
                1 -> list = list.slice(query[i] until list.size)
            }
        }
        
        return list.toIntArray()
    }
}