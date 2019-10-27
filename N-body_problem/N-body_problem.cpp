#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Vmath.h"
#include "Model.h"


int main()
{
	std::vector<body> planet(3); 

	planet[1].set_pos(1e7/2, 0, 0);
	planet[1].set_vel(-4e2, -5e2, 0);

	planet[0].set_prop(EARTH_MASS, EARTH_RAD);
	planet[0].set_pos(-1e7/2, 0, 0);
	planet[0].set_vel(2.3e2, 9e2, 0);

	
	std::ofstream data;
	data.open("data_500.txt");

	
	double dt = 5*1e-3;
	double t = 0;
	while (t < 400)
	{  
		std::cout << t << std::endl;
		time_step(planet, dt);

		for (auto& p : planet)
		{
			data << p.pos.x << " " << p.pos.y << " " << p.pos.z << " ";
		}
		data << std::endl;

		t += dt;
	}
	
	data.close();
}

