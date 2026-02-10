Option Explicit
 
Dim asc, enc, bytes, instr, outstr, pos
 
instr = "test string"
 
'Borrow some objects from .NET (supported from 1.1 onwards)
Set asc = CreateObject("System.Text.UTF8Encoding")
Set enc = CreateObject("System.Security.Cryptography.SHA1CryptoServiceProvider") '@violation
 
'Convert the string to a byte array and hash it
bytes = asc.GetBytes_4(instr)
bytes = enc.ComputeHash_2((bytes))
 
outstr = ""
 
'Convert the byte array to a hex string
For pos = 1 To Lenb(bytes)
 outstr = outstr & LCase(Right("0" & Hex(Ascb(Midb(bytes, pos, 1))), 2))
Next
 
WScript.Echo outstr