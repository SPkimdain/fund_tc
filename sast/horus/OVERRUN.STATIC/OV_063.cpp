
/* OV_063 - type casting & different offset size */
namespace OV_063_Namespace {

typedef unsigned char Byte;

struct OV_063_Rgb {
  Byte a;
  Byte b;
  Byte c;
  Byte d;
};

struct OV_063_BitmapHeader {
  const char name[32];
  int size;
};

struct OV_063_BitmapInfo {
  OV_063_BitmapHeader header;
  OV_063_Rgb color[1];
};

int OV_063_function1(int flag) {
  Byte arr[sizeof(OV_063_BitmapHeader) + sizeof(OV_063_Rgb) * 256];
  OV_063_BitmapInfo* bmi = (OV_063_BitmapInfo*)arr;
  
  OV_063_Rgb* palette = 0;
  if(flag > 10) {
    palette = (OV_063_Rgb*)(((Byte*)bmi) + sizeof(OV_063_BitmapHeader));
    
    palette[253].a = 0x01; //It's ok.
    palette[254].b = 0x05; //It's ok.   
    palette[255].c = 0x10; //It's ok.
    palette[256].d = 0xfa; //@violation OVERRUN.STATIC
  }  
  
  return 0;
}

}
