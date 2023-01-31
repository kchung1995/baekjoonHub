class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        var answer: Int = 0
        
        val gouleMap = HashMap<Int, Int>()
        for (i in tangerine) {
            if (gouleMap.containsKey(i)) {
                gouleMap[i] = gouleMap[i]!! + 1
            }
            else {
                gouleMap.put(i, 1)
            }
        }
        
        val goule = mutableListOf<Pair<Int, Int>>()
        for ((num, count) in gouleMap) {
            goule.add(Pair(num, count))
        }
        
        goule.sortBy{ it.second }
        goule.reverse()
        
        var countSum = 0
        for ((num, count) in goule) {
            if (countSum < k) {
                countSum += count
                answer++
            }
            else {
                break
            }
        }
        
        return answer
    }
}