

let user : UITextField
let pwd : UITextField

createUser(user.text,pwd.text) //@violation

createUser(user.text,validatePassword(pwd.text))
