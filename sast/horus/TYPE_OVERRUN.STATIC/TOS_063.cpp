
/* TOS_063 - type casting & different offset size */
namespace TOS_063_Namespace {

typedef unsigned char Byte;

struct TOS_063_Rgb {
  Byte a;
  Byte b;
  Byte c;
  Byte d;
};

struct TOS_063_BitmapHeader {
  const char name[16];
  int size;
};

struct TOS_063_BitmapInfo {
  TOS_063_BitmapHeader header;
  TOS_063_Rgb color[1];
};

struct TOS_063_ByteBuffer {
  Byte arr[sizeof(TOS_063_BitmapHeader) + sizeof(TOS_063_Rgb) * 256];
};

int TOS_063_function1(int flag) {
  TOS_063_ByteBuffer buffer;
  
  TOS_063_BitmapInfo* bmi = (TOS_063_BitmapInfo* )buffer.arr;
  
  TOS_063_Rgb* palette = 0;
  if(flag > 10) {
    palette = (TOS_063_Rgb*)(((Byte*)bmi) + sizeof(TOS_063_BitmapHeader));
    
    palette[253].a = 0x01; //It's ok.
    palette[254].b = 0x05; //It's ok.   
    palette[255].c = 0x10; //It's ok.
    palette[256].d = 0xfa; //@violation TYPE_OVERRUN.STATIC
  }  
  
  return 0;
}

}
