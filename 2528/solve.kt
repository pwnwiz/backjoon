// https://www.acmicpc.net/problem/2528
// 사다리
// Written in Kotlin
// 2021. 01. 11.
// Wizley

import java.util.*
import kotlin.collections.ArrayList

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val n = nextInt()
    val l = nextInt()

    val arrayList = ArrayList<Stick>()
    for(idx in 0 until n){
        val len = nextInt()
        val direction = nextInt()

        // LEFT to RIGHT
        if(direction == 0){
            arrayList.add(Stick(len, direction, 0))
        } else {
            arrayList.add(Stick(len, direction, l-len))
        }
    }
    var currentStage = 0
    var time = 0
    while(currentStage < n-1){
        var s = arrayList[currentStage].pos
        var e = s + arrayList[currentStage].len

        for(idx in currentStage+1 until n){
            val next_s = arrayList[idx].pos
            val next_e = next_s + arrayList[idx].len

            // 올라 갈 수 있는 경우
            if(s <= next_e && next_s <= e){
                currentStage++
                s = next_s
                e = next_e
            } else {
                break
            }
        }

        for(idx in currentStage until n){
            val dir = arrayList[idx].direction
            val pos = arrayList[idx].pos
            val len = arrayList[idx].len
            when(dir){
                // LEFT to RIGHT
                0 -> {
                    if(pos + len == l){
                        arrayList[idx].direction = 0
                        arrayList[idx].pos -= 1
                    } else {
                        arrayList[idx].pos += 1
                    }
                }
                // RIGHT to LEFT
                1 -> {
                    if(pos == 0){
                        arrayList[idx].direction = 0
                        arrayList[idx].pos += 1
                    } else {
                        arrayList[idx].pos -= 1
                    }
                }
            }
        }

        if(currentStage == n-1) break
        time++
    }
    println(time)
}

data class Stick(val len: Int, var direction: Int, var pos: Int)
