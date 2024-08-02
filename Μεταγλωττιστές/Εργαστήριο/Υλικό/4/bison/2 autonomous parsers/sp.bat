@ECHO OFF
echo Setting proper paths...
set PATH=C:\mingw\bin;C:\MinGW\msys\1.0\bin;%PATH%
set LIBRARY_path=C:\MinGW\msys\1.0\lib
echo ...done!
echo ____Reminder for commands____
echo Edit with: notepad ex1.l
echo Flex with: flex -o ex1.c ex1.l
echo GCC with.: gcc -o ex1 ex1.c
echo Run with.: ex1