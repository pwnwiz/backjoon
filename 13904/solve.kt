// https://www.acmicpc.net/problem/13904
// 과제
// Written in Kotlin
// 2021. 04. 24.
// Wizley

import java.util.*
import kotlin.math.max

var n: Int = 0
fun main() = with(Scanner(System.`in`)) {
    n = nextInt()

    val arr = mutableListOf<HomeWork>()
    var lastDay = 0
    for (i in 0 until n) {
        arr.add(HomeWork(d = nextInt(), w = nextInt())
                .also {
                    lastDay = max(lastDay, it.d)
                }
        )
    }

    var result = 0
    for (day in lastDay downTo 1) {
        val candidates = arr.filter { it.d >= day }

        if (candidates.isEmpty()) continue

        candidates
                .sortedWith(compareByDescending(HomeWork::w))
                .first()
                .let {
                    result += it.w

                    val idx = arr.indexOfFirst { value ->
                        value == it
                    }

                    arr.removeAt(idx)
                }
    }

    println(result)
}

data class HomeWork(val d: Int, val w: Int)
