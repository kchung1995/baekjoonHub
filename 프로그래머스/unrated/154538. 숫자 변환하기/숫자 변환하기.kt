class Solution {
    fun solution(x: Int, y: Int, n: Int): Int {
        var answer: Int = 0
        
        var current = HashSet<Int>()
        var next = HashSet<Int>()
        current.add(x)
        
        while (!current.isEmpty()) {
            if (current.contains(y)) {
                return answer
            }
            
            next = HashSet<Int>()
            for (i in current) {
                val plus = i + n
                val two = i * 2
                val three = i * 3
                
                if (plus <= y)
                    next.add(plus)
                if (two <= y)
                    next.add(two)
                if (three <= y)
                    next.add(three)
            }
            current = next
            answer++   
        }
        
        return -1
    }
}