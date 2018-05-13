#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class fluid {
private:
  int c;
  float g;
  float surf_tension;
  int pressure;
  float density, velocity, length, dyn_visc;
  float reynolds;
  float mach;
  float froude;
  float weber;
  float euler;

public:
  fluid (float d, float v, float l, float dy, float st, float p)
  {
    density = d;
    velocity = v;
    length = l;
    dyn_visc = dy;
    surf_tension = st;
    pressure = p;
    c = 340;
    g = 9.8;

    reynolds = ((density*velocity*length)/dyn_visc);

    mach = (velocity/c);

    froude = (velocity/sqrt(length*g));

    weber = (density*length*velocity*velocity)/surf_tension;

    euler = (pressure)/(density*velocity*velocity);

    std::cout << "Following are the values :- " << '\n';
    std::cout << "Mach No. is = " << mach << '\n';
    std::cout << "Froude No. is = " << froude << '\n';
    std::cout << "Weber No. is = " << weber << '\n';
    std::cout << "Euler No. is = " << euler << '\n';

    std::cout << "For Reynolds Number" << '\n';
    std::cout << "We have value = " << reynolds << '\n';
    std::cout << "According to value we categorize the liquid as having : " << '\n';

    if (reynolds < 2000) { std::cout << "Laminar Flow" << '\n';
    }
    else if (reynolds <= 4000 && reynolds >= 2000) { std::cout << "Transition State" << '\n';
    }
    else if (reynolds > 4000){ std::cout << "Turbulent Flow" << '\n';
    }
    else{
       std::cout << "Critical Condition" << '\n' ;
    }
  }
};

int main() {

  float surf_tension;
  int pressure;
  float density, velocity, length, dyn_visc;

  char n = 'y';

  std::cout << "           ###... Welcome to Fluid Calculator System ...###" << '\n' << '\n';


  do{
    std::cout << "Enter Density in kg/m^3 = " << '\n';
    std::cin >> density;
    std::cout << "Enter Velocity in m/s = " << '\n';
    std::cin >> velocity;
    std::cout << "Enter Length in m = " << '\n';
    std::cin >> length;
    std::cout << "Enter Dynamic Viscosity in Ns/m^2 = " << '\n';
    std::cin >> dyn_visc;
    std::cout << "Enter Surface Tension in N/m^2  = " << '\n';
    std::cin >> surf_tension;
    std::cout << "Enter Pressure in Pascal = " << '\n';
    std::cin >> pressure;

    fluid test(density, velocity, length, dyn_visc, surf_tension, pressure);

    std::cout << "Do you want to calculate for another liquid ? y/n" << '\n';
    std::cin >> n;
  }while(n == 'y');

  std::cout << "Thank You for Using Fluid Calculator, have a nice day." << '\n';
}
