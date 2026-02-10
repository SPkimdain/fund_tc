import GameplayKit

// get random Int
var k: Int = random() % 10; //@violation

let randomInt = GKRandomSource.sharedRandom().nextInt(upperBound: 26)
