#include "CelestialBody.h"

CelestialBody::CelestialBody(double  xpos, double  ypos, double xvel, double yvel, double  mass, std::string imagename)
{
  x = xpos;
  y = ypos;
  xv = xvel;
  yv = yvel;
  Mass = mass; 
  bodyname = imagename;   
 
 if(!image.loadFromFile(imagename))
  {
   std::cout << "couldn't load file abort!" << std::endl;
   exit(1);
  }
  
  texture.loadFromImage(image);
  sprite.setTexture(texture);
}
 void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states)const 
{
   this->sprite.setPosition(scaleX,scaleY);
   target.draw(this->sprite, states);
}

void CelestialBody::UpdatePos(std::vector<std::shared_ptr<CelestialBody>> bodies, double deltaT)
{
 double Fx = 0, Fy = 0;
 //constant G
 double G = 6.67E-11;
 //for each Celestial body
 for(auto body : bodies)
 {
   //skip over if they are the same body
   if(x == body->x && body->y == y) continue;

   double deltaX, deltaY, F, range;

   deltaX = body->x - x;
   deltaY = body->y - y;

   range = std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
   F = G * body->Mass * Mass / (range * range);
   Fx += F * deltaX / range;
   Fy += F * deltaY / range;
 }
 double ax, ay;
 ax = Fx/ Mass;
 ay = Fy / Mass;
  
 xv += ax * deltaT;
 yv -= ay * deltaT;

 x += xv * deltaT;
 y -= yv * deltaT;
}  
