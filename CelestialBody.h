#include <iostream>
#include <string>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <cmath>
class CelestialBody : public sf::Drawable
{
 public:
  CelestialBody(double , double , double, double, double , std::string );
  //accessor
  double getX(){return x;}
  double getY(){return y;}
  double getYV(){return yv;}
  double getXV(){return xv;}
  double getMass(){return Mass;}
  std::string getBodyName(){return bodyname;}
  //mutators  
  void setX(double initx){ x = initx;}
  void setY(double inity){ y = inity;}
  void setVel(double newxv, double newyv){ setXV(newxv); setYV(newyv);}
  void setXV(double newxv){ xv = newxv;}
  void setYV(double newyv){yv = newyv;}
  void setScaleX(double initx){ scaleX = initx;}
  void setScaleY(double inity){scaleY = inity;}
  void UpdatePos(std::vector<std::shared_ptr<CelestialBody>> bodies, double deltaT);  
  private:
  //
  double scaleX, scaleY;
  double x, y, xv, yv, Mass;
  std::string bodyname;
  sf::Image image;
  sf::Texture texture;
  mutable sf::Sprite sprite;  
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
};
