// https://www.acmicpc.net/problem/16235
// 나무 재테크
// Written in Kotlin
// 2021. 01. 31.
// Wizley

import java.util.*

var n:Int = 0
var m:Int = 0
var k:Int = 0
var robot = Array(101) { IntArray(101) { 0 } }
var sand = Array(101) { IntArray(101) { 5 } }
var trees = Array(101) { Array(101) { PriorityQueue<Int>() } }
var prospers = Array(101) { Array(101) { 0 } }
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    n = nextInt()
    m = nextInt()
    k = nextInt()

    for(i in 0 until n){
        for(j in 0 until n){
            robot[i][j] = nextInt()
        }
    }

    for(i in 0 until m){
        val x = nextInt()
        val y = nextInt()
        trees[x-1][y-1].add(nextInt())
    }

    for(year in 0 until k){
        springAndSummer()
        autumnAndWinter()
    }

    var result = 0
    for(i in 0 until n){
        for(j in 0 until n){
            result += trees[i][j].size
        }
    }

    println(result)
}

// 봄 : 자신의 나이만큼 양분을 먹고 나이가 1증가(하나의 칸에 여러개가 있으면 어린 순으로) -> 안되면 죽음
// 여름 : 봄에 죽은 나무가 양분이 됨(나무마다 나이를 2로 나눈 값이 양분으로 해당 칸에 추가)
fun springAndSummer(){
    for(i in 0 until n){
        for(j in 0 until n){
            prospers[i][j] = 0

            val tmp = PriorityQueue<Int>()
            var dead = 0
            while(trees[i][j].isNotEmpty()){
                val needs = trees[i][j].poll()
                if(needs <= sand[i][j]){
                    sand[i][j] -= needs
                    tmp.add(needs + 1)

                    if((needs + 1) % 5 == 0){
                        prospers[i][j] += 1
                    }
                } else {
                    dead += needs / 2
                }
            }
            trees[i][j] = tmp
            sand[i][j] += dead
        }
    }
}

// 가을 : 나무가 번식(나이가 5의 배수여야 됨 -> 인접한 8개 칸에 나이가 1인 나무가 생김)
// 겨울 : 로봇이 땅을 돌아다니며 양분을 추가함
var dx = intArrayOf(-1,-1,-1,0,0,1,1,1)
var dy = intArrayOf(-1,0,1,-1,1,-1,0,1)
fun autumnAndWinter(){
    for(i in 0 until n){
        for(j in 0 until n){
            sand[i][j] += robot[i][j]
            if(prospers[i][j]<1) continue

            for(k in 0 until 8){
                val nx = i + dx[k]
                val ny = j + dy[k]

                if(nx<0 || ny<0 || nx>=n || ny>=n) continue

                for(p in 0 until prospers[i][j]) {
                    trees[nx][ny].add(1)
                }
            }
        }
    }
}


