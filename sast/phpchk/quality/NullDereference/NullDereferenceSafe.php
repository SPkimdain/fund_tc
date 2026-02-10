<?php
  function fontWithPath($filePath, $embeddingOptions = 0)
  {
    /* Create a file parser data source object for this file. File path and
     * access permission checks are handled here.
     */
    require_once 'Zend/Pdf/FileParserDataSource/File.php';
    $dataSource = new Zend_Pdf_FileParserDataSource_File($filePath);

    /* Attempt to determine the type of font. We can't always trust file
     * extensions, but try that first since it's fastest.
     */

    /* If it turns out that the file is named improperly and we guess the
     * wrong type, we'll get null instead of a font object.
     */
    if($x === 'a') {
      $font = $unknown;
    } else {
      $font = null;
    }

    if ($k !== 'b') {
    }

    /* Done with the data source object.
     */
    $dataSource = null;

    if ($font !== null) {
        /* Parsing was successful. Add this font instance to the cache arrays
         * and return it for use.
         */
        $fontName = $font->getFontName(Zend_Pdf_Font::NAME_POSTSCRIPT, '', '');
        Zend_Pdf_Font::$_fontNames[$fontName] = $font;
        $filePathKey = md5($filePath);
        Zend_Pdf_Font::$_fontFilePaths[$filePathKey] = $font;
        return $font;

    } else {
        /* The type of font could not be determined. Give up.
         */
        require_once 'Zend/Pdf/Exception.php';
        throw new Zend_Pdf_Exception("Cannot determine font type: $filePath",
                                     Zend_Pdf_Exception::CANT_DETERMINE_FONT_TYPE);
     }
  }
