class Solution {
    fun solution(storeyFirst: Int): Int {
        var answer: Int = 0
        var storey: Int = storeyFirst
        
        while(storey > 0) {
            val firstFloor = storey % 10
            when(firstFloor) {
                0, 1, 2, 3, 4 -> {
                    answer += firstFloor
                }
                6, 7, 8, 9 -> {
                    answer += (10 - firstFloor)
                    storey += 10
                }
                5 -> {
                    val tenthFloor = ((storey / 10) % 10)
                    answer += 5
                    if (tenthFloor >= 5) {
                        storey += 10
                    }
                }
            }
            
            storey /= 10
        }
        
        return answer
    }
}