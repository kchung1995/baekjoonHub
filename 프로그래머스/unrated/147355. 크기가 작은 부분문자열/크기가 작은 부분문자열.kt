class Solution {
    fun solution(t: String, p: String): Int {
        var answer: Int = 0
        val pInt = p.toLong()
        
        for (i in 0 .. (t.length - p.length)) {
            val compareString = t.substring(i, i + p.length)
            if (compareString.toLong() <= pInt) {
                answer++
            }
        }
        
        return answer
    }
}