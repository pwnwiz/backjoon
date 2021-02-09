// https://www.acmicpc.net/problem/17144
// 미세먼지 안녕!
// Written in Kotlin
// 2021. 02. 09.
// Wizley

import java.util.*

enum class CleanerStatus {
    UP,
    DOWN,
    LEFT,
    RIGHT
}

var r: Int = 0
var c: Int = 0
var t: Int = 0
var room = Array(51) { IntArray(51) { 0 } }
var airCleaner = ArrayList<Pair<Int, Int>>()
var airCleanerFirstLocation = ArrayList<Pair<Int, Int>>()
var TopAirCleanerStatus = CleanerStatus.RIGHT
var BottomAirCleanerStatus = CleanerStatus.RIGHT
fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    r = nextInt()
    c = nextInt()
    t = nextInt()

    for (i in 0 until r) {
        for (j in 0 until c) {
            room[i][j] = nextInt()
            if (room[i][j] == -1) {
                airCleanerFirstLocation.add(Pair(i, j))
                airCleaner.add(Pair(i, j))
            }
        }
    }

    for (time in 0 until t) {
        expandDusts()
        cleanDusts()
    }
    println(getSum())
}

val dx = arrayOf(-1, 1, 0, 0)
val dy = arrayOf(0, 0, -1, 1)
fun expandDusts() {
    val nextDust = Array(51) { IntArray(51) { 0 } }

    for (x in 0 until r) {
        for (y in 0 until c) {
            if (room[x][y] <= 0) continue

            var cnt = 0
            val expandDustValue = room[x][y] / 5
            for (k in 0 until 4) {
                val nx = x + dx[k]
                val ny = y + dy[k]

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue
                if (room[nx][ny] == -1) continue

                nextDust[nx][ny] += expandDustValue
                cnt++
            }

            room[x][y] -= expandDustValue * cnt
        }
    }

    for (x in 0 until r) {
        for (y in 0 until c) {
            room[x][y] += nextDust[x][y]
        }
    }
}

fun cleanDusts() {
    val moved = Array(51) { IntArray(51) { -1 } }
    while (true) {
        val value = room[airCleaner[0].first][airCleaner[0].second]
        var needToStop = false
        when (TopAirCleanerStatus) {
            CleanerStatus.UP -> {
                if (airCleaner[0].first - 1 < 0) {
                    TopAirCleanerStatus = CleanerStatus.LEFT
                    airCleaner[0] = Pair(airCleaner[0].first, airCleaner[0].second - 1)
                } else {
                    airCleaner[0] = Pair(airCleaner[0].first - 1, airCleaner[0].second)
                }
            }
            CleanerStatus.DOWN -> {
                if (airCleaner[0].first + 1 >= airCleanerFirstLocation[0].first) {
                    TopAirCleanerStatus = CleanerStatus.RIGHT
                    airCleaner[0] = Pair(airCleaner[0].first + 1, airCleaner[0].second + 1)
                    needToStop = true
                } else {
                    airCleaner[0] = Pair(airCleaner[0].first + 1, airCleaner[0].second)
                }
            }
            CleanerStatus.LEFT -> {
                if (airCleaner[0].second - 1 < 0) {
                    TopAirCleanerStatus = CleanerStatus.DOWN
                    airCleaner[0] = Pair(airCleaner[0].first + 1, airCleaner[0].second)
                } else {
                    airCleaner[0] = Pair(airCleaner[0].first, airCleaner[0].second - 1)
                }
            }
            CleanerStatus.RIGHT -> {
                if (airCleaner[0].second + 1 >= c) {
                    TopAirCleanerStatus = CleanerStatus.UP
                    airCleaner[0] = Pair(airCleaner[0].first - 1, airCleaner[0].second)
                } else {
                    airCleaner[0] = Pair(airCleaner[0].first, airCleaner[0].second + 1)
                }
            }
        }
        if (needToStop) {
            break
        }
        moved[airCleaner[0].first][airCleaner[0].second] = value
    }

    while (true) {
        val value = room[airCleaner[1].first][airCleaner[1].second]
        var needToStop = false
        when (BottomAirCleanerStatus) {
            CleanerStatus.UP -> {
                if (airCleaner[1].first - 1 <= airCleanerFirstLocation[1].first) {
                    BottomAirCleanerStatus = CleanerStatus.RIGHT
                    airCleaner[1] = Pair(airCleaner[1].first - 1, airCleaner[1].second + 1)
                    needToStop = true
                } else {
                    airCleaner[1] = Pair(airCleaner[1].first - 1, airCleaner[1].second)
                }
            }
            CleanerStatus.DOWN -> {
                if (airCleaner[1].first + 1 >= r) {
                    BottomAirCleanerStatus = CleanerStatus.LEFT
                    airCleaner[1] = Pair(airCleaner[1].first, airCleaner[1].second - 1)
                } else {
                    airCleaner[1] = Pair(airCleaner[1].first + 1, airCleaner[1].second)
                }
            }
            CleanerStatus.LEFT -> {
                if (airCleaner[1].second - 1 < 0) {
                    BottomAirCleanerStatus = CleanerStatus.UP
                    airCleaner[1] = Pair(airCleaner[1].first - 1, airCleaner[1].second)
                } else {
                    airCleaner[1] = Pair(airCleaner[1].first, airCleaner[1].second - 1)
                }
            }
            CleanerStatus.RIGHT -> {
                if (airCleaner[1].second + 1 >= c) {
                    BottomAirCleanerStatus = CleanerStatus.DOWN
                    airCleaner[1] = Pair(airCleaner[1].first + 1, airCleaner[1].second)
                } else {
                    airCleaner[1] = Pair(airCleaner[1].first, airCleaner[1].second + 1)
                }
            }
        }
        if (needToStop) {
            break
        }
        moved[airCleaner[1].first][airCleaner[1].second] = value
    }

    room[airCleanerFirstLocation[0].first][airCleanerFirstLocation[0].second+1] = 0
    room[airCleanerFirstLocation[1].first][airCleanerFirstLocation[1].second+1] = 0

    for (i in 0 until r) {
        for (j in 0 until c) {
            if(moved[i][j]>=0){
                room[i][j] = moved[i][j]
            }
        }
    }
}

fun getSum(): Long {
    var sum = 0L
    for (x in 0 until r) {
        for (y in 0 until c) {
            if (room[x][y] > 0) sum += room[x][y]
        }
    }
    return sum
}

