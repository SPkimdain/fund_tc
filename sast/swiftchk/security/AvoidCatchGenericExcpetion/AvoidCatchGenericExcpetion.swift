

var vendingMachine = VendingMachine()
vendingMachine.coinsDeposited = 8
do {
    try buyFavoriteSnack(person: "Alice", vendingMachine: vendingMachine)
    print("Success! Yum.")
} catch TestError.outOfRange {
     // 오류처리
  } catch TestError.invalidInput(let testNumber) {
     // 오류처리
  }catch { //@violation
    print("Unexpected error: \(error).")
}