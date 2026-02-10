/* interval, unsigned -> signed */

void CAV_020_function(unsigned char uch) {
  char sch = 'a';

  if(uch <= 128) {
    sch = uch; //@It's ok.
  }
  else {
    sch = uch; //@violation CAST_ALTERS_VALUE.EXT
  }

}

