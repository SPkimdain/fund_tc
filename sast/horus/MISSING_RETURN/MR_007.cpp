/* MR_007 - simple case with lambda */

int MR_007_function(int flag) {
  auto&& MR_007_lambda = [](int flag) -> int {
    if(flag > 10) {
      return 10;
    }
  }; //@violation MISSING_RETURN


  return 0;
} 

