// https://www.acmicpc.net/problem/10800
// 컬러볼
// Written in Kotlin
// 2021. 02. 28.
// Wizley

import java.util.*

var n: Int = 0
val pq = PriorityQueue<Ball>(compareBy<Ball>({ it.size }, { it.color }))
val ballCount = IntArray(200001) { 0 }
val sameSize = IntArray(2001){0}
val result = IntArray(200001) { 0 }
fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    n = nextInt()

    for (i in 0 until n) {
        pq.add(Ball(nextInt(), nextInt(), i))
    }

    var totalCount = 0
    var prevSize = 0
    var prevColor = 0
    var prevResult = 0
    while (pq.isNotEmpty()) {
        val ball = pq.poll()

        ballCount[ball.color] += ball.size
        sameSize[ball.size] += ball.size
        totalCount += ball.size

        if(prevSize == ball.size && prevColor == ball.color){
            result[ball.idx] = prevResult
        } else {
            result[ball.idx] = totalCount - ballCount[ball.color] - sameSize[ball.size] + ball.size
        }

        prevSize = ball.size
        prevColor = ball.color
        prevResult = result[ball.idx]
    }

    for (i in 0 until n) {
        print("${result[i]}\n")
    }
}

data class Ball(val color: Int, val size: Int, val idx: Int)
