SELECT byte_str,
       TO_HEX(byte_str) AS hex_str --@violation
FROM TB_BYTE_INFO;
