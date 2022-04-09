g++ data.cpp -o data -g
g++ std.cpp -o std -g
g++ stupid.cpp -o stupid -g

:loop
  data.exe> data.txt
  std.exe< data.txt >myout.txt
  stupid.exe< data.txt >stdout.txt
  fc stdout.txt myout.txt
if not errorlevel 1 goto loop
pause
goto loop
