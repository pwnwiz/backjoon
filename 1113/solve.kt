// https://www.acmicpc.net/problem/1113
// 수영장 만들기
// Written in Kotlin
// 2021. 04. 17.
// Wizley

import java.util.*
import kotlin.math.max

var n: Int = 0
var m: Int = 0
var result: Int = 0
const val arrSize = 52
val arr = Array(arrSize) { IntArray(arrSize) { 0 } }
fun main() = with(Scanner(System.`in`)) {
    n = nextInt()
    m = nextInt()
    var maxHeight = 0

    for (i in 1..n) {
        val line = next()
        for (j in 0 until m) {
            arr[i][j + 1] = line[j] - '0'
            maxHeight = max(maxHeight, arr[i][j+1])
        }
    }

    for(height in 1..maxHeight){
        bfs(height)
        result += calcSpace(height)
    }

    println(result)
}

fun calcSpace(height: Int): Int{
    var spaceCnt = 0
    for(i in 1..n){
        for(j in 1..m){
            if(arr[i][j] < height){
                arr[i][j]++
                spaceCnt++
            }
        }
    }
    return spaceCnt
}

val dx = arrayOf(0, 0, -1, 1)
val dy = arrayOf(-1, 1, 0, 0)
fun bfs(height: Int) {
    val visited = Array(arrSize) { BooleanArray(arrSize) { false } }

    val que: Queue<Pair<Int, Int>> = LinkedList()
    arr[0][0] = height
    que.add(0 to 0)
    visited[0][0] = true

    while (que.isNotEmpty()) {
        val x = que.peek().first
        val y = que.peek().second
        que.poll()

        for (i in dx.indices) {
            val nx = x + dx[i]
            val ny = y + dy[i]

            if (nx < 0 || ny < 0 || nx >= n+2 || ny >= m+2) continue
            if (visited[nx][ny]) continue
            if (arr[nx][ny] >= height) continue

            arr[nx][ny]++
            que.add(nx to ny)
            visited[nx][ny] = true
        }
    }
}

