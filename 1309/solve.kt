// https://www.acmicpc.net/problem/1309
// 동물원
// Written in Kotlin
// 2021. 04. 08.
// Wizley

import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val n = nextInt()
    val dp = LongArray(100001){0}

    // 하나도 없는 경우
    dp[0] = 1

    // xx ox xo
    dp[1] = 3
    // xx -> ox xx xo , ox -> xo xx, xo -> xx ox
    dp[2] = 7

    for(i in 3..n){
        dp[i] = (dp[i-2] + dp[i-1] * 2) % 9901
    }
    println(dp[n])
}
