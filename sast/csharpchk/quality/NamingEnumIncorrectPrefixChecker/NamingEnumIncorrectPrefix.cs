using System;

namespace NamingLibrary
{
   public enum DigitalImageMode
   {
      DigitalImageModeBitmap = 0, // @violation
      DigitalImageModeGrayscale = 1,// @violation
      DigitalImageModeIndexed = 2,// @violation
      DigitalImageModeRGB = 3// @violation
   }

   public enum DigitalImageMode2
   {
      Bitmap = 0,
      Grayscale = 1,
      Indexed = 2,
      RGB = 3
   }
}