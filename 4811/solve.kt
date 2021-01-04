// https://www.acmicpc.net/problem/4811
// 알약
// Written in C++ langs
// 2021. 01. 04.
// Wizley

import java.math.BigInteger
import java.util.*

fun getFactorial(input: Int): BigInteger {
    var factorial: BigInteger = BigInteger.valueOf(1)
    for(i in 1..input){
        factorial *= i.toBigInteger()
    }
    return factorial
}

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    while(true){
        val input = nextInt()
        if(input == 0) break

        // 카탈란 수 
        val result = getFactorial(2*input) / (getFactorial(input)*getFactorial(input+1))
        println(result)
    }
}

