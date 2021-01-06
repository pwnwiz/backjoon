import java.lang.Integer.min
import java.util.*
import kotlin.collections.ArrayList

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val arr = Array<Int>(10){0}
    val result = ArrayList<Int>()

    val no = nextInt()
    var minPrice:Int = Int.MAX_VALUE
    var minNo:Int = 0

    for (i in 0 until no){
        arr[i] = nextInt()
        if(i != 0)minPrice = min(minPrice, arr[i])
    }

    for(i in no-1 downTo 1){
        if(arr[i] == minPrice){
            minNo = i
            break
        }
    }

    var money = nextInt()

    // 숫자 0만 사용할 수 있는 경우
    if(minPrice == Int.MAX_VALUE || minPrice > money){
        println("0")
        return
    }

    // 0 카드의 값이 더 싼 경우
    if(minPrice >= arr[0]){
        result.add(minNo)
        money -= arr[minNo]
        minNo = 0
    } else {
        result.add(minNo)
        money -= arr[minNo]
    }

    // 일단 자릿수를 다 채움
    while(money - arr[minNo] >= 0){
        result.add(minNo)
        money -= arr[minNo]
    }

    if(result.size == 1){
        println(result[0])
        return
    }

    // 앞에서부터 돌면서 큰 수 채워넣기
    for(i in result.indices){
        for(j in no-1 downTo 0){
            val diff = arr[j] - arr[result[i]]
            if(diff > money || result[i]>j) continue

            result[i] = j
            money -= diff
            break
        }
    }

    for(i in result){
        print(i)
    }
    print('\n')

}
