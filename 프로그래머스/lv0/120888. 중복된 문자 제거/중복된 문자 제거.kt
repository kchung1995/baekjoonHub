class Solution {
    fun solution(myString: String): String {
        val set = HashSet<Char>()
        val sb = StringBuilder()
        
        for (i in myString) {
            when (set.contains(i)) {
                true -> continue
                else -> {
                    set.add(i)
                    sb.append(i)
                }
            }
        }

        return sb.toString()
    }
}