#include "particles.h"
#include <math.h>
#include <cstdlib>
#include <random>

#define PI 3.14159265

Particle::Particle()
{
	//random 0..99 (for a small map)
	float square_map_size = 100.0;

	x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/square_map_size));
	y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/square_map_size)); 
	heading = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360.));
	
	normalized_weight = 0.0;
	weight = 1.0;	

	forward_noise = .05;
	turn_noise = .05;
	sense_noise = 5.;

	measurement = -1;

}

float Particle::distToLandmark(std::vector<float> landmark)
{
	float distance;

	std::default_random_engine generator;
	std::normal_distribution<float> distribution(0.0,sense_noise);
	distance = sqrt( pow(x-landmark[0], 2) + pow(y-landmark[1], 2));
	distance += distribution(generator);

	return distance;
}

std::vector<float> Particle::sense(std::vector<std::vector<float>> landmarks){

	std::vector<float> Z;

	std::default_random_engine generator;
	std::normal_distribution<float> distribution(0.0,sense_noise);
	float dist = 0;
	for ( int i=0; i < landmarks.size(); i ++ )
	{
		dist = sqrt( pow(x-landmarks[i][0], 2) + pow(y-landmarks[i][1], 2));
		dist += distribution(generator);
		Z.push_back(dist);
	}

	return Z;
}


std::vector<float> Particle::getPosition()
{
	float arr[] = {x, y, heading};
	std::vector<float> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	return v;
}

void Particle::move(float turn, float forward_move)
{
	/*
		Changes the particle's heading then moves it "forward" 
	*/
	heading += turn;
	
	if (heading > 360.0) {
		heading -=360.0;
	}

	x += forward_move * cos(heading);
	y += forward_move * sin(heading);
}