func countDownToZero(num: Int) {
    print(num)

        countDownToZero(num: num - 1) //@violation

}



func countDownToZeroSec(num: Int) {
    print(num)
    if num > 0 {
        countDownToZero(num: num - 1)
    }
}
print("Countdown:")
countDownToZero(num:3)

print("Countdown:")
countDownToZeroSec(num:3)