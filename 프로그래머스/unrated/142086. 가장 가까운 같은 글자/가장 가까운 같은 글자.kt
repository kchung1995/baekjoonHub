class Solution {
    fun solution(s: String): IntArray {
        var answer: IntArray = intArrayOf()
        
        val wordmap = HashMap<Char, Int>()
        
        for(i in 0 until s.length) {
            if (wordmap.containsKey(s[i])) {
                answer += (i - wordmap[s[i]]!!)
            }
            else {
                answer += -1
            }
            wordmap[s[i]] = i
        }
        
        return answer
    }
}