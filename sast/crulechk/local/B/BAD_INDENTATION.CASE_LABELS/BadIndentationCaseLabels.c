// @checker BAD_INDENTATION.CASE_LABELS

void nh_switch_2_4_2_9_7()
{
    int a;
    int b;
    int c;

    switch (1) {
        a = 1;
        case 1:
            switch (1) {
                case 1:
                case 2:  // @violation BAD_INDENTATION.CASE_LABELS
                    break;
            }

        case 2:
            break;
    }


    switch (1) {
      a = 1;   // @violation BAD_INDENTATION.CASE_LABELS
        a = 1;
        case 1:
            switch (1) {
              case 1:        // @violation BAD_INDENTATION.CASE_LABELS
                    a = 2;
                case 2:
                    a = 3;
                  a = 1;      // @violation BAD_INDENTATION.CASE_LABELS
            }

        case 2:
        a = 1;   // @violation BAD_INDENTATION.CASE_LABELS

      default:    // @violation BAD_INDENTATION.CASE_LABELS
      a = 1;   // @violation BAD_INDENTATION.CASE_LABELS
    }

}
