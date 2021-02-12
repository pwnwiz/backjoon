// https://www.acmicpc.net/problem/2174
// 로봇 시뮬레이션
// Written in Kotlin
// 2021. 02. 12.
// Wizley

import java.util.*
import kotlin.system.exitProcess

var land = Array(101) { IntArray(101) { 0 } }
var robotList = ArrayList<Robot>()
var a = 0
var b = 0
var n = 0
var m = 0
fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    a = nextInt()
    b = nextInt()

    n = nextInt()
    m = nextInt()

    robotList.add(Robot(0, 0, 0, ""))

    var robotNum = 1
    for (i in 0 until n) {
        val y = nextInt()
        val x = nextInt()
        val c = next()

        robotList.add(Robot(robotNum, b - x, y - 1, c))
        land[b - x][y - 1] = robotNum++
    }

    for (j in 0 until m) {
        val rob = nextInt()
        val command = next()
        val count = nextInt()

        for (l in 0 until count) {
            val cur = robotList[rob]

            when (command) {
                "L" -> {
                    doCommandL(cur)
                }
                "R" -> {
                    doCommandR(cur)
                }
                "F" -> {
                    doCommandF(cur)
                }
            }
        }
    }

    println("OK")
}

fun crashIntoWall(robotNum: Int) {
    println("Robot $robotNum crashes into the wall")
}

fun crashIntoRobot(robotNum: Int, robotNum2: Int) {
    println("Robot $robotNum crashes into robot $robotNum2")
}

fun doCommandL(rob: Robot){
    rob.direction = when (rob.direction) {
        "N" -> "W"
        "W" -> "S"
        "E" -> "N"
        "S" -> "E"
        else -> "X"
    }
    robotList[rob.no] = rob
}

fun doCommandR(rob: Robot) {
    rob.direction =  when (rob.direction) {
        "N" -> "E"
        "W" -> "N"
        "E" -> "S"
        "S" -> "W"
        else -> "X"
    }
    robotList[rob.no] = rob
}

fun doCommandF(cur: Robot) {
    land[cur.x][cur.y] = 0
    when (cur.direction) {
        "N" -> cur.x -= 1
        "W" -> cur.y -= 1
        "S" -> cur.x += 1
        "E" -> cur.y += 1
    }

    if (cur.x < 0 || cur.x >= b || cur.y < 0 || cur.y >= a) {
        crashIntoWall(cur.no)
        exitProcess(0)
    } else if (land[cur.x][cur.y] != 0) {
        crashIntoRobot(cur.no, land[cur.x][cur.y])
        exitProcess(0)
    }

    robotList[cur.no] = cur
    land[cur.x][cur.y] = cur.no
}

data class Robot(var no: Int, var x: Int, var y: Int, var direction: String)
