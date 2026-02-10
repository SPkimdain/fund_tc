// @checker SIZEOF_DO_NOT_CONTAIN_SIDE_EFFECTS

/* SDNCSE_002 - decltype */

void SDNCSE_002_function(int x, int y) {
  int val = 0;


  decltype(x++) dtTest = 12; //@violation SIZEOF_DO_NOT_CONTAIN_SIDE_EFFECTS

  decltype(x) dtTest2 = 200; //It's ok.
}

