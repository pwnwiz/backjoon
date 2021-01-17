// https://www.acmicpc.net/problem/2132
// 나무 위의 벌레
// Written in Kotlin
// 2021. 01. 17.
// Wizley

import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashSet

var n: Int = 0
lateinit var nodes: IntArray
lateinit var visited: BooleanArray
val edge = ArrayList<HashSet<Int>>()
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    n = nextInt()

    nodes = IntArray(n+1)
    visited = BooleanArray(n+1){false}
    for(i in 1..n){
        nodes[i] = nextInt()
    }

    for(i in 0..n){
        edge.add(HashSet())
    }

    for(i in 0 until n-1){
        val a = nextInt()
        val b = nextInt()
        edge[a].add(b)
        edge[b].add(a)
    }

    dfs(1, nodes[1])

    length = -1
    for(start in u){
        visited = BooleanArray(n+1){false}
        dfsReverse(start, nodes[start], start)
    }
    v.sort()

    println("$length ${v[0]}")
}

var length: Int = 0
var u = HashSet<Int>()
fun dfs(c: Int, w: Int){
    visited[c] = true

    if(length < w){
        length = w

        u.clear()
        u.add(c)
    } else if(length == w){
        u.add(c)
    }

    for(next in edge[c]){
        if(visited[next]) continue
        dfs(next, w+nodes[next])
    }
}

var v = ArrayList<Int>()
fun dfsReverse(c:Int, w:Int, s:Int){
    visited[c] = true

    if(length < w){
        length = w

        v.clear()
        v.add(s)

        v.add(c)
    } else if(length == w){
        v.add(c)
    }

    for(next in edge[c]){
        if(visited[next]) continue
        dfsReverse(next, w+nodes[next], s)
    }
}
