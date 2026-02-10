REPORT ZX_DD.

" non-compliant codes
TABLES flight.
DATA itab TYPE STANDARD TABLE OF flight.

flight-name = 'John'.
flight-airline = 'Lufthansa'.

REFRESH itab FROM TABLE t100. "@violation

" compliant codes
DATA itab TYPE STANDARD TABLE OF flight.

                                       SELECT *
                                              FROM flight
                                              INTO TABLE itab
                                              WHERE name = 'John' AND
                                                    airline LIKE 'Lufthansa%'.