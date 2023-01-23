class Solution {
    fun solution(weightsInit: IntArray): Long {
        var answer: Long = 0
        val spots = arrayOf(2, 4, 3)
        val dirs = arrayOf(1, 3, 2)
        
        val weights = HashSet<Int>()
        val weightsAppearCount = HashMap<Int, Int>()
        for (i in weightsInit) {
            weights.add(i)
            if (!weightsAppearCount.containsKey(i)) {
                weightsAppearCount[i] = 1
            }
            else {
                weightsAppearCount.replace(i, weightsAppearCount[i]!! + 1)
            }
        }
        
        for (i in weights) {
            var weightSize: Long = weightsAppearCount[i]!!.toLong()
            answer += (weightSize * (weightSize - 1)) / 2
            
            for (j in 0 until dirs.size) {
                if (i % dirs[j] != 0) continue
                
                val calcWeight = (i / dirs[j]) * spots[j]
                val size: Long = 
                if(weightsAppearCount.containsKey(calcWeight)) {
                    weightsAppearCount[calcWeight]!!.toLong()
                }
                else 0

                answer += weightSize * size
            }
            
        }
        
        return answer
    }
}