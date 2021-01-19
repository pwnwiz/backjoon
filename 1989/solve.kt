// https://www.acmicpc.net/problem/1989
// 부분배열 고르기 2
// Written Kotlin
// 2021. 01. 19.
// Wizley


import java.util.*

var result: Long = 0L

var start: Long = 1L
var end: Long = 1L

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val n = nextInt()
    val stack = Stack<StackValue>()

    for(idx in 0 until n){
        val input = nextInt()
        var length = 0L

        var from = 0L
        while(stack.isNotEmpty() && stack.peek().maxv > input){
            length += stack.peek().length
            from = stack.peek().idx

            val sum = length*stack.peek().maxv
            if (result < sum){
                result = sum

                start = from
                end = idx.toLong()
            }
            stack.pop()
        }

        length += input
        stack.push(StackValue(length, input.toLong(), if(length==input.toLong()) (idx+1).toLong() else from))
    }

    var length = 0L
    val to = stack.peek().idx
    while(stack.isNotEmpty()){
        length += stack.peek().length
        val sum = length*stack.peek().maxv
        if(result < sum){
            result = sum

            start = stack.peek().idx.toLong()
            end = to
        }
        stack.pop()
    }
    println(result)
    println("$start $end")
}

data class StackValue(val length: Long, val maxv: Long, val idx: Long)

