@echo off
:asd
data.exe > in.txt
L2.exe < in.txt > out1.txt
L1.exe < in.txt > out2.txt

fc out1.txt out2.txt
if not errorlevel 1 goto asd
pause