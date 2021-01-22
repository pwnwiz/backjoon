// https://www.acmicpc.net/problem/2842
// 집배원 한상덕
// Written in Kotlin
// 2021. 01. 22.
// Wizley

import java.util.*
import kotlin.math.min

val directionX = arrayOf(-1, -1, -1, 0, 0, 1, 1, 1)
val directionY = arrayOf(-1, 0, 1, -1, 1, -1, 0, 1)

lateinit var villages: Array<Array<Char>>
lateinit var altitudes: Array<Array<Int>>
lateinit var postOffice: Pair<Int,Int>

val altitudeSet: MutableSet<Int> = mutableSetOf()
var houses: Int = 0

var n = 0
var from = 0
var to = 0

var res: Int = Int.MAX_VALUE

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    n = nextInt()

    villages = Array<Array<Char>>(51) { Array<Char>(51) { '0' } }
    altitudes = Array<Array<Int>>(51){ Array<Int>(51) { 0 } }

    for(i in 0 until n){
        val input = next()
        for(j in 0 until n){
            villages[i][j] = input[j]
            if(villages[i][j] == 'P') postOffice = Pair(i,j)
            else if(villages[i][j] == 'K') houses++
        }
    }

    for(i in 0 until n){
        for(j in 0 until n){
            altitudes[i][j] = nextInt()
            altitudeSet.add(altitudes[i][j])
        }
    }

    val twoPointerList = altitudeSet.sorted().toList()
    from = 0
    to = 0

    while(from < twoPointerList.size && to < twoPointerList.size){
        if(from > to) to = from

        if(bfs(twoPointerList[from], twoPointerList[to])){
            val diff = twoPointerList[to] - twoPointerList[from]
            res = min(res, diff)
            from++
        }

        else {
            to++
        }
    }

    println(res)
}

fun bfs(left:Int, right:Int): Boolean{
    if(altitudes[postOffice.first][postOffice.second] !in left..right) return false

    val visited:Array<Array<Boolean>> = Array<Array<Boolean>>(51) { Array<Boolean>(51) { false } }
    var count: Int = 0
    visited[postOffice.first][postOffice.second] = true

    val que: Queue<Pair<Int,Int>> = LinkedList()
    que.add(postOffice)

    while(que.isNotEmpty()){
        val x = que.peek().first
        val y = que.peek().second
        que.poll()

        if(count == houses){
            return true
        }

        for(i in 0 until 8){
            val nx = x + directionX[i]
            val ny = y + directionY[i]

            if(nx<0 || ny<0 || nx>=n || ny>=n) continue
            if(visited[nx][ny]) continue

            if(altitudes[nx][ny] in left..right){
                visited[nx][ny] = true
                que.add(Pair(nx,ny))

                if(villages[nx][ny] == 'K') count++
            }
        }
    }
    return false
}

