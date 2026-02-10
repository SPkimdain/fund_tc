//@checker BAD_DB_TRANSACTION
extern void pfmDbioCommit();

void BDBTRS_001_transaction() {
  pfmDbioCommit();
} //@violation BAD_DB_TRANSACTION
