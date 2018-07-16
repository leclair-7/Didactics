#include <iostream>
#include <algorithm>
#include <vector>

#include "particles.h"

using namespace std;

#define PI 3.14159265
/*
BEWARE OF THE NUMBER OF PAPIRTICLES, NOT WELL DESIGNED HERE
*/

float Gaussian(float mu, float sigma, float x)
{
	float numerator = exp( -1*pow(mu-x,2) / pow(sigma,2) / 2.0 ); 
	float denomenator = sqrt(2.0 * PI * pow(sigma,2));
	return numerator / denomenator;
}

float measurement_prob(Particle p, std::vector<std::vector<float>> landmarks, std::vector<float> measurements)
{

	// measurements = p.sense( landmarks );

	float prob=1.0;
	float dist;
	for (int i=0; i < landmarks.size(); i++)	{
		dist = sqrt( pow(p.x-landmarks[i][0], 2) + pow(p.y-landmarks[i][1], 2));  
		prob *= Gaussian( dist, p.sense_noise, measurements[i] );
	}

	return dist;
}


bool sampleParticle(Particle p)
{
	/*
		Flip a coin biased by the particles weight
		
		probability of picking the particle is the normalized weight
		if normalized weight = .2 then .2 chance of resampling it
	*/

	if (p.normalized_weight > 1.0){
		cout<< "Error, unnormalized weight, run normalization function on particle set"<<endl;
		return false;
	}

	float pick = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	if (pick - p.normalized_weight > 0.0) {
		return false;
	} else {
		return true;
	}
}




void print_a_particle(Particle p)
{
	cout<< p.getPosition()[0]<<"\t"<< p.getPosition()[1]<<"\t"<< p.getPosition()[2]<<endl;
}

int main()
{
	vector<std::vector<float>> objects  {  { 20, 20 },
                                           { 80, 80 },
                                           { 20, 80 },
                                           { 80, 20 }    };

	std::vector<Particle> particle_set;

	Particle myrobot = Particle();
	std::vector<float> Z = myrobot.sense(objects);

	for( int i=0; i<1000; i++){ particle_set.push_back(Particle());	}	
	////////////////////////// End of initialization ///////////////////////

	cout<< "---------- Before the Selection ----------"<<endl;
	for( int i=0; i<5; i++){ 
		print_a_particle(particle_set[i]);
	}
	//particle_set = normalizeParticleWeights(particle_set);

	//////////////////////////////////////////////
	//	beginning of the selection
	//////////////////////////////////////////////


for(int k =0; k < 10;k++)
{	
	std::vector<float> w;
	float thesum = 0.0;
	for (int i=0; i < particle_set.size(); i++){
		w.push_back(measurement_prob(particle_set[i], objects,Z));
		thesum += measurement_prob(particle_set[i], objects, Z);
	}

	float tmw = 0.0;

	for (int i=0; i < particle_set.size(); i++){
		w[i] = w[i] / thesum;
		if (tmw < w[i]) { tmw = w[i]; }
	}
	std::vector<float> weights_normalized = w;
	// THE WEIGHTS ARE NORMALIZED
	float beta = 0.0;
	std::vector<Particle> new_selection;
	unsigned int i;
	int index;
	for ( i = 0 ; i < particle_set.size(); i++)
	{
		//In Python it is:
		//beta = beta + random.uniform(0,2*max(weights_normalized))
		beta = beta + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2*tmw)));
		index = i;
		while( weights_normalized[index % 1000] < beta)
		{
			beta = beta - weights_normalized[index % 1000];
			index += 1;
		}
		new_selection.push_back(particle_set[index%1000]);
	}
	particle_set = new_selection;
}
	//////////////////////////////////////////////
	//	end of the selection
	//////////////////////////////////////////////

	cout<< "---------- After the selection ----------"<<endl;
	for( int i=0; i<5; i++){ 
		print_a_particle(particle_set[i]);
	}

	return 0;
}