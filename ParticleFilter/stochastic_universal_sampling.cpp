/*
	Predict each particles position after a timestep based on its previous position/heading/velocity
	
	account for sensor noise

	Yaw rotation is change in direction the thing is pointing
*/

#include <random> // Need this for sampling from distributions
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Particle {
	
	int id;				// Id of matching landmark in the map.
	double x;			// Local (vehicle coordinates) x position of landmark observation [m]
	double y;			// Local (vehicle coordinates) y position of landmark observation [m]
	double weight;
};


vector<Particle> stochastic_sampling(vector<Particle>particles, int num_particles ){
	vector<Particle>result;
	//outer ring is a cumulative distribution function, cdf

	double c[num_particles];
	c[0] = particles[0].weight;

	for( int k = 1; k < num_particles; k++){
		//think of c's as what percentage around the clock have you gone?
		c[k] = c[k-1] + particles[k].weight;
	}

	// make a random number between 0 and 1 / num_particles
	random_device rd;
	default_random_engine generator(rd()); // rd() provides a random seed
	uniform_real_distribution<double> distribution(0.0, 1./num_particles);	
	double u1 = distribution(generator);

	double u[num_particles];
	u[0] = u1;

	int i = 0;
	for( int j = 0; j < num_particles; j++){
		//think of c's as what percentage around the clock have you gone?
		while( u[j] > c[i] ){
			i += 1;
		}
		// The line below is the link that this function based upon, question is, should we re-do particle's weight?
		//https://classroom.udacity.com/courses/ud810/lessons/3353208568/concepts/33538586070923#
		particles[i].weight = 1.0 / num_particles;
		result.push_back( particles[i] );
		u[j + 1] = u[j] + 1.0 / num_particles;
	}

	return result;
} 

int main() {
	
	int num_particles = 4;

	vector<Particle> originals;
	

	for( int i=0; i < num_particles; i++){
		Particle p;
		p.x =i; p.y =i; p.id = i; p.weight = 1. / num_particles;

		originals.push_back(p);
	}


	
	
	vector <Particle> results = stochastic_sampling(originals, num_particles );	

	for ( int i=0; i < num_particles; i++){

		cout << results[i].id << " " << results[i].x << " " << results[i].y << endl;
	}

	return 0;
}




