#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>
#include "CelestialBody.h"
class Universe 
{
 public:
   //just a defaullt constructor that does nothing, >> is meant to give it all the body values
   Universe(); 
   Universe(std::vector<std::shared_ptr<CelestialBody>> vec);
   Universe(double xpos, double ypos, double xvel, double yvel, double mass, std::string imagename);
   //sets the length and width of the window
   void setWindowSize( double wx, double wy);
   //gets the seconds for the step function and saves it as a member variable
   void setTargetTime(double, double);
  
   //maps the universe celestial body coordinates to the window coordinates and scales it
   void scale();
   //simulates universe for + delta T seconds 
   void step();
   //Draws the window with the celestialbodies
   void draw();
   
   friend std::istream& operator >>(std::istream &in, Universe& uniobj); 
   friend std::ostream& operator <<(std::ostream &out, Universe& uniobj);
 private:
   int num;
   /* 
   targetSeconds = sim stopping point, when simTime >= targetSeconds
   deltaT = time moved in one step
   simTime = elasped sim time
   */
   double targetSeconds, deltaT, simTime;
   /*
   radius = universe radius
   wx = window length
   wy = window height
   */
   double radius, wx, wy;
   std::vector<std::shared_ptr<CelestialBody>> bodies;
};
