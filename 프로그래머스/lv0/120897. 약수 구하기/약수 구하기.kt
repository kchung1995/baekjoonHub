class Solution {
    fun solution(n: Int): IntArray {
        var answer: IntArray = intArrayOf()
        
        val answerSet = HashSet<Int>()
        
        for (i in 1 .. n) {
            if (n % i == 0) {
                answerSet.add(i)
                answerSet.add(n / i)
            }
        }
        for (i in answerSet) {
            answer += i
        }
        answer.sort()
        
        return answer
    }
}