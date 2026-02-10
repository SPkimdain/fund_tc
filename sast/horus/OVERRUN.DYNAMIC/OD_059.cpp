
/* OD_059 - type casting & different offset size */
namespace OD_059_Namespace {

typedef unsigned char Byte;

struct OD_059_Rgb {
  Byte a;
  Byte b;
  Byte c;
  Byte d;
};

struct OD_059_BitmapHeader {
  const char name[16];
  int size;
};

struct OD_059_BitmapInfo {
  OD_059_BitmapHeader header;
  OD_059_Rgb color[1];
};

int OD_059_function1(int flag) {
  OD_059_BitmapInfo* bmi = (OD_059_BitmapInfo*)new Byte[sizeof(OD_059_BitmapHeader) + sizeof(OD_059_Rgb) * 256];
  if(bmi == 0) {
    return 0;
  }
  
  OD_059_Rgb* palette = 0;
  if(flag > 10) {
    palette = (OD_059_Rgb*)(((Byte*)bmi) + sizeof(OD_059_BitmapHeader));
    
    palette[253].a = 0x01; //It's ok.
    palette[254].b = 0x05; //It's ok.   
    palette[255].c = 0x10; //It's ok.
    palette[256].d = 0xfa; //@violation OVERRUN.DYNAMIC
  }
  
  delete[] bmi;
  
  return 0;
}

}
