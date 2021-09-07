//#include "CelestialBody.h" //universe has celestialbody.h in it
#include "Universe.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

//Commandline: ./NBody (total sim time) (delta time) < (celestial bodies).txt
int main(int argc, char* argv[])
{
 int num,index;
 double wx = 800.0 ,wy = 800.0;
 double radius, xpos, ypos,xvel, yvel, mass, seconds, deltaT;
 std::string imagename;
 Universe verse;
 std::cout << "argc: " << argc << std::endl;
if(argc == 5)
{
    wx = std::stoi(argv[3]);
    wy =std::stoi(argv[4]);
}
 verse.setWindowSize(wx,wy);
 seconds = std::stod(argv[1]);
 deltaT = std::stod(argv[2]);

 verse.setTargetTime(seconds, deltaT);
 
 //reads from input file, to get data for the universe!
 std::cin >> verse;


 verse.draw(); //universe now manages the window as well

 return 0;
}
