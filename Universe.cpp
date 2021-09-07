#include "Universe.h"

Universe::Universe()
{
}

Universe::Universe(std::vector<std::shared_ptr<CelestialBody>> vec)
{
   int size,index;
   size = vec.size();
   for(index = 0; index < size; index++)
   {
     bodies.push_back(vec[index]);
   }
}
Universe::Universe(double xpos, double ypos, double xvel, double yvel, double mass, std::string imagename)
{
 std::shared_ptr<CelestialBody> temp(new CelestialBody(xpos, ypos, xvel, yvel, mass, imagename));

  bodies.push_back(temp);
}

void Universe::setWindowSize(double inx, double iny)
{
 wx = inx;
 wy = iny;
}

std::ostream& operator <<(std:: ostream &out, Universe& uniobj)
{
  out << uniobj.num << "\n" << uniobj.radius << "\n";
  
  for(auto body : uniobj.bodies)
  {
    out << std::setprecision(6) << std::scientific << body->getX() << " "  << body->getY() << " "
    <<  body->getXV() << " "  << body->getYV() << " "  << body->getMass() << " " << body->getBodyName()  << "\n";
  }
  out << "\n";
 return out; 
}
 std::istream& operator >>(std::istream &in, Universe& uniobj)
{
 int index;
 double x,y,xv,yv,mass;
 std::string imagename;
 
 in >> uniobj.num >> uniobj.radius;
 
 for(index = 0; index < uniobj.num; index++)
 {
   in >> x >> y >> xv >> yv >> mass >> imagename;
   std::shared_ptr<CelestialBody> temp ( new CelestialBody(x, y, xv, yv, mass, imagename));
   uniobj.bodies.push_back(temp);
 }
 return in;
}

void Universe::scale()
{
 double mapx, mapy;
 double scalex =( radius*2)/wx;
 double scaley = (radius*2)/wy;
 double x,y;
 for(int index = 0; index < bodies.size(); index++)
 {
   x = (bodies[index])->getX();
   y = (bodies[index])->getY();
    if( x > 0)
    {
     mapx = (x/scalex) + wx/2;
    }
    else if( x < 0)
    {
     mapx = (x/ scalex) + wx/2;
    }
    else if( x == 0)
    {
 
     mapx = wx/2;
    }
    if(y > 0)
    {
 
     mapy= (y/ scaley) + wy/2;
    }
    else if(y < 0)
    {
 
     mapy= (y/scalex) + wy/2;
    }
    else if(y== 0)
    {
      mapy = wy/2;
    }
  (bodies[index])->setScaleX( mapx);
  (bodies[index])->setScaleY( mapy);
  
  x = (bodies[index])->getX();
 }
}

void  Universe::draw()
{
 int index;
 std::string input;
 simTime = 0;
 
 sf::RenderWindow window(sf::VideoMode(wx, wy), "The Universe!");
  std::ofstream myfile;
    while (window.isOpen())
{
 sf::Event event;
 // smooths the movement of the celestial bodies
 window.setFramerateLimit(60);
 while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
    }

    if(simTime < targetSeconds)
    {
      window.clear();
      for(index = 0; index < num; index++)
      {
        // maps universe celestial body to the window
        this->scale();
        // draws the celestialbody
        window.draw(*(bodies[index]));
      }
    //does the next delta T step calucation
    this->step();
    window.display();
    }
  }
 //outputs final universe state to output.txt
 myfile.open("output.txt");
 myfile << *this;
 myfile.close();
}
void Universe::step()
{
   for(int index = 0; index < this->bodies.size(); index++)
   {
    this->bodies[index]->UpdatePos(bodies,deltaT);
   }
    simTime += deltaT;
}

void Universe::setTargetTime(double seconds, double dT)
{
 deltaT = dT;
 targetSeconds = seconds;
}
