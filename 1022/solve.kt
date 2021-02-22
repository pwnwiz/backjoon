// https://www.acmicpc.net/problem/1022
// 소용돌이 예쁘게 출력하기
// Written in Kotlin
// 2021. 02. 22.
// Wizley

import java.util.*
import kotlin.math.max

val arr = Array(51){(IntArray(51){1})}
var r1=0
var c1=0
var r2=0
var c2=0

var cnt=0
var collected = 0

var interval = 0
var nx = 0
var ny = 0
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    r1 = nextInt()
    c1 = nextInt()
    r2 = nextInt()
    c2 = nextInt()

    cnt = (r2-r1+1)*(c2-c1+1)

    simulate()
    print()
}

var maxv = 0
val dx = arrayOf(0, -1, 0, 1)
val dy = arrayOf(1, 0, -1, 0)
fun simulate(){
    var current = 1

    if(nx in r1..r2 && ny in c1..c2){
        collected++
    }

    while(collected < cnt){

        for(i in 0 until 4){
            var used = 0

            if(i == 0 || i == 2) interval++

            while(used < interval){
                nx += dx[i]
                ny += dy[i]

                current++
                used++
                if(nx in r1..r2 && ny in c1..c2){
                    maxv = max(maxv, current)
                    arr[nx-r1][ny-c1] = current

                    collected++
                }
            }
        }
    }
}

fun print(){
    val digit = maxv.toString().length
    for(i in r1..r2){
        for(j in c1..c2){
            for(k in 0 until digit-arr[i-r1][j-c1].toString().length){
                print(" ")
            }
            print("${arr[i-r1][j-c1]} ")
        }
        println()
    }


}

