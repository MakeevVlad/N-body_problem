#pragma once
#include "Vmath.h"

const double EARTH_MASS = 5.97e24;
const double EARTH_RAD = 6.4e6;
const double G = 6.7e-11;


class body
{
private:
	double mass, rad; //Mass and radius

	friend vec3 Force_try(body&);
	friend vec3 Force(body&, body&);
	friend void time_step(std::vector<body>&, double);
public:

	body();

	vec3 pos; //Position radius-vector
	vec3 vel; //Velosity vector
	vec3 ax; //Axeleration vector

	void set_prop(double, double);
	
	void set_pos(double, double, double);
	void set_pos(vec3);

	void set_vel(double, double, double);
	void set_vel(vec3);

	void set_ax(double, double, double);
	void set_ax(vec3);
};


void time_try(body&, double);
vec3 Force_try(body&);
