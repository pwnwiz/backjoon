// https://www.acmicpc.net/problem/16918
// 봄버맨
// Written in Kotlin
// 2021. 01. 25.
// Wizley

import java.util.*

val intMap = Array<IntArray>(201){IntArray(201){0}}

var r = 0
var c = 0
var n = 0

var time = 2
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    r = nextInt()
    c = nextInt()
    n = nextInt()

    for(i in 0 until r){
        val input = next()
        for(j in 0 until c){
            if(input[j] == 'O') intMap[i][j] = 3 else 0
        }
    }

    while(time <= n){
        when(time % 2) {
            0 -> addBomb()
            1 -> exploitBomb()
        }
        time++
    }

    for(i in 0 until r){
        for(j in 0 until c){
            if(intMap[i][j] == 0) print('.') else print('O')
        }
        println()
    }
}

val dx = arrayOf(-1,1,0,0)
val dy = arrayOf(0,0,-1,1)
fun exploitBomb(){
    val que : Queue<Pair<Int, Int>> = LinkedList()
    for(i in 0 until r){
        for(j in 0 until c){
            if(intMap[i][j] == time){
                que.add(Pair(i,j))

                for(k in 0 until 4){
                    val nx = i+dx[k]
                    val ny = j+dy[k]

                    if(nx<0 || ny<0 || nx>=r || ny>=c) continue

                    if(intMap[nx][ny] != time) intMap[nx][ny] = 0
                }
            }
        }
    }

    while(que.isNotEmpty()){
        intMap[que.peek().first][que.peek().second] = 0
        que.poll()
    }
}

fun addBomb(){
    for(i in 0 until r){
        for(j in 0 until c) {
            if(intMap[i][j] == 0) intMap[i][j] = time+3
        }
    }
}
