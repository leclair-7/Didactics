/*
 * print_samples.cpp
 *

	Given gps_x, gps_y, and heading:
			This makes 3 normal distributions and generates 3 x,y,theta points based on that


 * Print out to the terminal 3 samples from a normal distribution with
 * mean equal to the GPS position and IMU heading measurements and
 * standard deviation of 2 m for the x and y position and 0.05 radians
 * for the heading of the car. 
 *
 * Author: Tiffany Huang
 */

#include <random> // Need this for sampling from distributions
#include <iostream>

using namespace std;

// @param gps_x 	GPS provided x position
// @param gps_y 	GPS provided y position
// @param theta		GPS provided yaw
void printSamples(double gps_x, double gps_y, double theta) {
	
	int num_particles = 3

	// random number generator
	default_random_engine gen;
	double std_x, std_y, std_theta;
    double sample_x, sample_y, sample_theta;
	
	std_x = 2.0;
	std_y = 2.0;
	std_theta = .05;
	
	// Creates a normal (Gaussian) distribution for x, y, and theta.
	normal_distribution<double> dist_x(gps_x, std_x);	
	normal_distribution<double> dist_y(gps_y, std_y);
	normal_distribution<double> dist_theta(theta, std_theta);

	for (int i = 0; i < num_particles; ++i) {

		double sample_x, sample_y, sample_theta;

		sample_x     = dist_x(gen);
		sample_y     = dist_y(gen);
		sample_theta = dist_theta(gen);	
		
		cout << "Sample " << i + 1 << " " << sample_x << " " << sample_y << " " << sample_theta << endl;

		cin >> frog;
	}
}

int main() {
	
	// Set GPS provided state of the car.
	double gps_x = 4983;
	double gps_y = 5029;
	double theta = 1.201;
	
	// Sample from the GPS provided position.
	printSamples(gps_x, gps_y, theta);
	
	return 0;
}




