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
	double heading;
	double weight;

	std::vector<int> associations;
	std::vector<double> sense_x;
	std::vector<double> sense_y;
};

struct LandmarkObs {
	
	int id;				// Id of matching landmark in the map.
	double x;			// Local (vehicle coordinates) x position of landmark observation [m]
	double y;			// Local (vehicle coordinates) y position of landmark observation [m]

};

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
/*
void updateWeights(double sensor_range, double std_landmark[], 
		const std::vector<LandmarkObs> &observations, const Map &map_landmarks) {
*/

/*
	1 transform car sensor observations (car coords to map coords)
	2 associate transformed observations with the nearest landmark on the map
	3 udpate weights based on gaussian probab
	4 combine probabilities of all for posteriot probability
*/

void updateWeights(vector<Particle>particles){

}

int main() {
	
	LandmarkObs l5;
	l5.x=4;l5.y=7;l5.id=5;
	LandmarkObs l1;
	l1.x=5;l1.y=3;l1.id=1;
	LandmarkObs l2;
	l2.x=2;l2.y=1;l2.id=2;
	LandmarkObs l3;
	l3.x=6;l3.y=1;l3.id=3;
	LandmarkObs l4;
	l4.x=7;l4.y=4;l4.id=4;

	vector<LandmarkObs>landmarks;
	landmarks.push_back(l1);
	landmarks.push_back(l2);
	landmarks.push_back(l3);
	landmarks.push_back(l4);
	landmarks.push_back(l5);

	Particle p;
	p.x = 4;
	p.y = 5;
	p.heading = -1 * M_PI / 2.0;

	//observations 1..3
	p.sense_x.push_back(2);
	p.sense_y.push_back(2);

	p.sense_x.push_back(3);
	p.sense_y.push_back(-2);

	p.sense_x.push_back(0);
	p.sense_y.push_back(-4);
	// end of observations
	
	// say we saw something at ( 2 , 2 )
	// look throu
	double x_observe_c = 0;
	double y_observe_x = -4;
	double xm = p.x + cos(p.heading) * x_observe_c  + -1 * sin ( p.heading) * y_observe_x; 
	double ym = p.y + sin(p.heading) * x_observe_c + cos(p.heading) * y_observe_x;
	double one = 1.0;

	//maybe make a landmarkObs and get the distance from it to real ones
	cout << "xm  " << xm << endl;
	cout << "ym  " << ym << endl;
	cout << "one " << one << endl; 

	for ( int i=0; i < p.sense_x.size(); i++){

		double x_observe_c = p.sense_x[i];
		double y_observe_c = p.sense_y[i];

		double xm = p.x + cos(p.heading) * x_observe_c  + -1 * sin ( p.heading) * y_observe_c; 
		double ym = p.y + sin(p.heading) * x_observe_c + cos(p.heading) * y_observe_c;

		double minsize = 9999;
		int id_curr = 99;
		for( int l=0; l < landmarks.size(); l++){
			
			double obs_to_lm = dist(landmarks[l].x, landmarks[l].y, xm, ym);
			if ( minsize < obs_to_lm ){
				minsize = obs_to_lm;
				id_curr = l;
			}			
		}

		cout << "Observation " << i << " " << x_observe_c << "," << y_observe_c << " most likely landmark " << landmarks[id_curr].id  << endl; 
	}

	cout<< landmarks[0].id << endl;
	cout<< landmarks[0].x << endl;
	cout<< landmarks[0].y << endl;

	return 0;
}




