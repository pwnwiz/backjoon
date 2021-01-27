// https://www.acmicpc.net/problem/16939
// 2x2x2 큐브
// Written in Kotlin
// 2021. 01. 27.
// Wizley

import java.util.*

val cube = IntArray(25){0}
var result: Boolean = false
fun main(args: Array<String>) = with(Scanner(System.`in`)){

    for(i in 1..24){
        cube[i] = nextInt()
    }

    if(checkLeftUp()) result = true
    if(checkLeftDown()) result = true
    if(checkRightUp()) result = true
    if(checkRightDown()) result = true
    if(checkFrontDownLeft()) result = true
    if(checkFrontDownRight()) result = true
    if(checkBackDownLeft()) result = true
    if(checkBackDownRight()) result = true
    if(checkTopLeft()) result = true
    if(checkTopRight()) result = true
    if(checkDownLeft()) result = true
    if(checkDownRight()) result = true

    if(result) println("1") else println("0")
}

fun checkLeftUp(): Boolean {
    val tmpCube = cube.clone()
    tmpCube[1] = cube[5]
    tmpCube[3] = cube[7]

    tmpCube[5] = cube[9]
    tmpCube[7] = cube[11]

    tmpCube[9] = cube[24]
    tmpCube[11] = cube[22]

    tmpCube[22] = cube[3]
    tmpCube[24] = cube[1]

    tmpCube[13] = cube[14]
    tmpCube[14] = cube[16]
    tmpCube[15] = cube[13]
    tmpCube[16] = cube[15]

    return checkColor(tmpCube)
}

fun checkLeftDown(): Boolean {
    val tmpCube = cube.clone()
    tmpCube[1] = cube[24]
    tmpCube[3] = cube[22]

    tmpCube[5] = cube[1]
    tmpCube[7] = cube[3]

    tmpCube[9] = cube[5]
    tmpCube[11] = cube[7]

    tmpCube[22] = cube[11]
    tmpCube[24] = cube[9]

    tmpCube[13] = cube[15]
    tmpCube[14] = cube[13]
    tmpCube[15] = cube[16]
    tmpCube[16] = cube[14]

    return checkColor(tmpCube)
}

fun checkRightUp(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[2] = cube[6]
    tmpCube[4] = cube[8]

    tmpCube[6] = cube[10]
    tmpCube[8] = cube[12]

    tmpCube[10] = cube[23]
    tmpCube[12] = cube[21]

    tmpCube[23] = cube[2]
    tmpCube[21] = cube[4]

    tmpCube[17] = cube[19]
    tmpCube[18] = cube[17]
    tmpCube[19] = cube[20]
    tmpCube[20] = cube[18]

    return checkColor(tmpCube)
}

fun checkRightDown(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[2] = cube[23]
    tmpCube[4] = cube[21]

    tmpCube[6] = cube[2]
    tmpCube[8] = cube[4]

    tmpCube[10] = cube[6]
    tmpCube[12] = cube[8]

    tmpCube[23] = cube[10]
    tmpCube[21] = cube[12]

    tmpCube[17] = cube[18]
    tmpCube[18] = cube[20]
    tmpCube[19] = cube[17]
    tmpCube[20] = cube[19]

    return checkColor(tmpCube)
}

fun checkFrontDownLeft(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[3] = cube[17]
    tmpCube[4] = cube[19]

    tmpCube[17] = cube[10]
    tmpCube[19] = cube[9]

    tmpCube[10] = cube[16]
    tmpCube[9] = cube[14]

    tmpCube[16] = cube[3]
    tmpCube[14] = cube[4]

    tmpCube[5] = cube[6]
    tmpCube[6] = cube[8]
    tmpCube[7] = cube[5]
    tmpCube[8] = cube[7]

    return checkColor(tmpCube)
}

fun checkFrontDownRight(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[3] = cube[16]
    tmpCube[4] = cube[14]

    tmpCube[17] = cube[3]
    tmpCube[19] = cube[4]

    tmpCube[10] = cube[17]
    tmpCube[9] = cube[19]

    tmpCube[16] = cube[10]
    tmpCube[14] = cube[9]

    tmpCube[5] = cube[7]
    tmpCube[6] = cube[5]
    tmpCube[7] = cube[8]
    tmpCube[8] = cube[6]

    return checkColor(tmpCube)
}

fun checkBackDownLeft(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[1] = cube[18]
    tmpCube[2] = cube[20]

    tmpCube[15] = cube[1]
    tmpCube[13] = cube[2]

    tmpCube[12] = cube[15]
    tmpCube[11] = cube[13]

    tmpCube[18] = cube[12]
    tmpCube[20] = cube[11]

    tmpCube[21] = cube[23]
    tmpCube[22] = cube[21]
    tmpCube[23] = cube[24]
    tmpCube[24] = cube[22]

    return checkColor(tmpCube)
}

fun checkBackDownRight(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[1] = cube[15]
    tmpCube[2] = cube[13]

    tmpCube[15] = cube[12]
    tmpCube[13] = cube[11]

    tmpCube[12] = cube[18]
    tmpCube[11] = cube[20]

    tmpCube[18] = cube[1]
    tmpCube[20] = cube[2]

    tmpCube[21] = cube[22]
    tmpCube[22] = cube[24]
    tmpCube[23] = cube[21]
    tmpCube[24] = cube[23]

    return checkColor(tmpCube)
}

fun checkTopLeft(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[5] = cube[17]
    tmpCube[6] = cube[18]

    tmpCube[17] = cube[21]
    tmpCube[18] = cube[22]

    tmpCube[21] = cube[13]
    tmpCube[22] = cube[14]

    tmpCube[13] = cube[5]
    tmpCube[14] = cube[6]

    tmpCube[1] = cube[3]
    tmpCube[2] = cube[1]
    tmpCube[3] = cube[4]
    tmpCube[4] = cube[2]

    return checkColor(tmpCube)
}

fun checkTopRight(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[5] = cube[13]
    tmpCube[6] = cube[14]

    tmpCube[17] = cube[5]
    tmpCube[18] = cube[6]

    tmpCube[21] = cube[17]
    tmpCube[22] = cube[18]

    tmpCube[13] = cube[21]
    tmpCube[14] = cube[22]

    tmpCube[1] = cube[2]
    tmpCube[2] = cube[4]
    tmpCube[3] = cube[1]
    tmpCube[4] = cube[3]

    return checkColor(tmpCube)
}

fun checkDownLeft(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[7] = cube[19]
    tmpCube[8] = cube[20]

    tmpCube[19] = cube[23]
    tmpCube[20] = cube[24]

    tmpCube[23] = cube[15]
    tmpCube[24] = cube[16]

    tmpCube[15] = cube[7]
    tmpCube[16] = cube[8]

    tmpCube[9] = cube[10]
    tmpCube[10] = cube[12]
    tmpCube[11] = cube[9]
    tmpCube[12] = cube[11]

    return checkColor(tmpCube)
}

fun checkDownRight(): Boolean{
    val tmpCube = cube.clone()
    tmpCube[7] = cube[15]
    tmpCube[8] = cube[16]

    tmpCube[19] = cube[7]
    tmpCube[20] = cube[8]

    tmpCube[23] = cube[19]
    tmpCube[24] = cube[20]

    tmpCube[15] = cube[23]
    tmpCube[16] = cube[24]

    tmpCube[9] = cube[11]
    tmpCube[10] = cube[9]
    tmpCube[11] = cube[12]
    tmpCube[12] = cube[10]

    return checkColor(tmpCube)
}

fun checkColor(tmpCube: IntArray): Boolean{
    if((tmpCube[1] == tmpCube[2]) && (tmpCube[3] == tmpCube[4]) && (tmpCube[1] == tmpCube[3])) {
        if ((tmpCube[5] == tmpCube[6]) && (tmpCube[7] == tmpCube[8]) && (tmpCube[5] == tmpCube[7])) {
            if ((tmpCube[9] == tmpCube[10]) && (tmpCube[11] == tmpCube[12]) && (tmpCube[9] == tmpCube[11])) {
                if ((tmpCube[13] == tmpCube[14]) && (tmpCube[15] == tmpCube[16]) && (tmpCube[13] == tmpCube[15])) {
                    if ((tmpCube[17] == tmpCube[18]) && (tmpCube[19] == tmpCube[20]) && (tmpCube[17] == tmpCube[19])) {
                        if ((tmpCube[21] == tmpCube[22]) && (tmpCube[23] == tmpCube[24]) && (tmpCube[21] == tmpCube[23])){
                            return true
                        }
                    }
                }
            }
        }
    }
    return false
}
