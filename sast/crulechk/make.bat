del *.o

for /r %%a in (*.c) do gcc -std=c99 -c "%%a"
for /r %%a in (*.cpp) do g++ -fpermissive -c "%%a"

del *.o
