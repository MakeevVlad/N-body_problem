#include "Vmath.h"
#include "Model.h"

body::body()
{
	set_prop(EARTH_MASS, EARTH_RAD);
	pos.set(0, 0, 0);
	vel.set(0, 0, 0);
	ax.set(0, 0, 0);
}

void body::set_prop(double m, double R)
{
	mass = m;
	rad = R;
}

void body::set_pos(double X, double Y, double Z)
{
	pos.set(X, Y, Z);
}
void body::set_pos(vec3 other)
{
	pos.set(other);
}

void body::set_vel(double X, double Y, double Z)
{
	vel.set(X, Y, Z);
}
void body::set_vel(vec3 other)
{
	vel.set(other);
}

void body::set_ax(double X, double Y, double Z)
{
	ax.set(X, Y, Z);
}
void body::set_ax(vec3 other)
{
	ax.set(other);
}


void time_step(std::vector<body>& planet, double dt)
{
	vec3 F(0, 0, 0);
	for (size_t i = 0; i < planet.size(); ++i)
	{
		//Computing total force
		for (size_t j = 0; j < planet.size(); ++j)
			if (i != j) F = F + Force(planet[i], planet[j]);

		planet[i].ax = F / planet[i].mass;
		planet[i].vel = planet[i].vel + planet[i].ax * dt;
		planet[i].pos = planet[i].pos + planet[i].vel * dt;

		F.set(0, 0, 0);
	}
}


vec3 Force(body& p1, body& p2)
{
	vec3 R = p2.pos - p1.pos;
	return R * G * p1.mass * p2.mass / pow(abs(R), 3);
}




vec3 Force_try(body& planet)
{
	return planet.pos * G * 1e6 * EARTH_MASS * planet.mass * (-1) / (abs(planet.pos) * abs(planet.pos) * abs(planet.pos));
}
void time_try(body& planet, double dt)
{
	vec3 F = Force_try(planet);
	planet.ax = F / EARTH_MASS;
	planet.vel = planet.vel + planet.ax * dt;
	planet.pos = planet.pos + planet.vel * dt;
}
