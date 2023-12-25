@echo off
: asd
tem.exe > in.txt
"A.exe" < in.txt > out1.txt
"A1.exe" < in.txt > out2.txt
fc out1.txt out2.txt
if not errorlevel 1 goto asd
pause