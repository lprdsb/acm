@echo off
:asd
Data.exe > in.txt
F.exe < in.txt > out1.txt
F1.exe < in.txt > out2.txt

fc out1.txt out2.txt
if not errorlevel 1 goto asd
pause