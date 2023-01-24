class Solution {
    fun solution(s: String): Int {
        var answer: Int = 0
        
        var front: Int = 0
        var other: Int = 0
        var frontChar: Char = '.'
        for (i in 0 until s.length) {     
            if (frontChar == '.') {
                frontChar = s[i]
                println(frontChar)
                front++
            }
            else {
                println(s[i])
                if (s[i] == frontChar) {
                    front++
                }
                else {
                    other++
                    if (front == other) {
                        answer++
                        front = 0
                        other = 0
                        frontChar = '.'
                    }
                }
            }
            println(frontChar)
        }
        
        if (front != 0) answer++
        return answer
    }
}