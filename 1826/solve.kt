// https://www.acmicpc.net/problem/1826
// 연료 채우기
// Written in Kotlin
// 2021. 01. 10.
// Wizley

import java.util.*
import kotlin.math.max


fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val n = nextInt()

    val gasStations = PriorityQueue<GasStation>(compareBy<GasStation>{it.pos})

    for(i in 0 until n){
        gasStations.add(GasStation(nextInt(), nextInt()))
    }

    // l : 마을 까지의 거리, p : 초기 가스 연료량
    val l = nextInt()
    val p = nextInt()

    var currentGas = p
    var result = 0

     val candidates = PriorityQueue<GasStation>(compareByDescending<GasStation>{it.gas})

    // 도착지점에 도착할 수 있을때까지 순회
    while(currentGas < l){

        // 현재 연료를 가지고 이동할 수 있는 거리인지를 계산
        while(gasStations.isNotEmpty() && gasStations.peek().pos <= currentGas){
            // 이 경우에 만약 maxGas 값만을 가지게 되면 추가로 연료가 필요한 경우에 과거의 특정 주유소의 값을 가질 수 없음
            candidates.add(gasStations.peek())
            gasStations.poll()
        }

        // 도착하지 못하는 경우
        if(candidates.size == 0) {
            result = -1
            break
        }

        // 연료로 갈 수 있는 최대 길이를 최신화시킴
        currentGas += candidates.peek().gas
        candidates.poll()

        result++
    }

    println(result)
}

data class GasStation(val pos: Int, val gas: Int)

