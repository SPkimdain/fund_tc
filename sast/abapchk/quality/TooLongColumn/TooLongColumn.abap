REPORT ZX_DD.

" non-compliant codes
CALL METHOD mif_document_proxy->get_spreadsheet_interface->aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa      "@violation
      IMPORTING
        error           = mif_error
        sheet_interface = mif_spreadsheet
      .

" compliant codes
CALL METHOD mif_document_proxy->
       get_spreadsheet_interface
      IMPORTING
        error           = mif_error
        sheet_interface = mif_spreadsheet
      .