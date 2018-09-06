/*
	Predict each particles position after a timestep based on its previous position/heading/velocity
	
	account for sensor noise

	Yaw rotation is change in direction the thing is pointing
*/

#include <random> // Need this for sampling from distributions
#include <iostream>
#include <cmath>
using namespace std;

struct position {
	double x;
	double y;
	double heading;

};

void updatePosition(position & pos, double yaw_rate, double velocity, double delta_t ){
	
	double vel_over_yawd = velocity / yaw_rate;

	pos.x = pos.x + vel_over_yawd * (sin(pos.heading + yaw_rate * delta_t) - sin(pos.heading));
	pos.y = pos.y + vel_over_yawd * (cos(pos.heading) - cos(pos.heading + yaw_rate * delta_t) );
	pos.heading = pos.heading + yaw_rate * delta_t;

}

int main() {
	
	// Set GPS provided state of the car.
	double gps_x = 102.;
	double gps_y = 65.;
	
	// in radians
	double heading = (5. * M_PI) / 8. ; 
	
	// pi/8 rad/s over the past .1 seconds
	double dt = .1;
	double yaw_rate = M_PI / 8; 

	// m/2
	double velocity = 110;
	
	//double position_and_heading[] = {gps_x, gps_y, headin};
	position p;
	p.x = gps_x;
	p.y = gps_y;
	p.heading = heading;

	double vel_over_yawd = (velocity/yaw_rate);
	p.x = p.x + vel_over_yawd * (sin(p.heading + yaw_rate * dt) - sin(p.heading));
	p.y = p.y + vel_over_yawd * (cos(p.heading) - cos(p.heading + yaw_rate * dt) );
	p.heading = p.heading + yaw_rate * dt;

	// Sample from the GPS provided position.
	cout << "x pos   new: " << p.x <<  endl;
	cout << "y pos   new: " << p.y <<  endl;
	cout << "heading new: " << p.heading <<  endl;

	position frog;
	frog.x = gps_x;
	frog.y = gps_y;
	frog.heading = heading;

	updatePosition( frog, yaw_rate, velocity, dt);
	cout << "x pos   frog: " << frog.x <<  endl;
	cout << "y pos   frog: " << frog.y <<  endl;
	cout << "heading frog: " << frog.heading <<  endl;


	return 0;
}




