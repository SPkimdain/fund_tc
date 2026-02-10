//@checker BSSC.NAMING_CONVENTION.VARIABLE
int currentLine;
int previousLine;
int maxNumLines;

int maxRgbLevel;
int maxRGB_Level; //@violation BSSC.NAMING_CONVENTION.VARIABLE
int NonCompliant; //@violation BSSC.NAMING_CONVENTION.VARIABLE

void foo() {
  int currentLine;
  static int previousLine;
  int maxNumLines;

  int maxRgbLevel;
  int maxRGB_Level; //@violation BSSC.NAMING_CONVENTION.VARIABLE
  static int NonCompliant; //@violation BSSC.NAMING_CONVENTION.VARIABLE
}
