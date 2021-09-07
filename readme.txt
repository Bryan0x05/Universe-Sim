A universe sim using C++ and SFML(https://www.sfml-dev.org) written by Bryan Tait
Note: Made for Ubuntu but SFML is mutli-platform

How to use:
Run "make all" to make the executable. 
The program is makes an executable called Nbody.
The program uses commandline inputs to get several parameters and an input file listing infomation about celeistal bodies in specific format.
A window will be open showing the simulation and an output file "output.txt" of the final state of the universe using the same input.txt format

Run "make clean" to remove the files made by make all and the executable 
Commandline: 
./NBody (total sim time) (delta time) < input.txt
./NBody (total sim time) (delta time) (window length) (window height) < input.txt

input.txt format:
N = number of celestial bodies
R = Radius of the universe
 x_position  y_position  x_velocity  y_velocity  mass filename(include file path if file is not local)

example file:
5
2.50e+11
 1.4960e+11  0.0000e+00  0.0000e+00  2.9800e+04  5.9740e+24    earth.gif
 2.2790e+11  0.0000e+00  0.0000e+00  2.4100e+04  6.4190e+23     mars.gif
 5.7900e+10  0.0000e+00  0.0000e+00  4.7900e+04  3.3020e+23  mercury.gif
 0.0000e+00  0.0000e+00  0.0000e+00  0.0000e+00  1.9890e+30      sun.gif
 1.0820e+11  0.0000e+00  0.0000e+00  3.5000e+04  4.8690e+24    venus.gif

 try: 
 ./NBody 2000000000 10000  < example.txt 