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

struct LandmarkObs {
	
	int id;				// Id of matching landmark in the map.
	double x;			// Local (vehicle coordinates) x position of landmark observation [m]
	double y;			// Local (vehicle coordinates) y position of landmark observation [m]
};

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
/**
 * dataAssociation Finds which observations correspond to which landmarks (likely by using
 *   a nearest-neighbors data association).
 * @param predicted Vector of predicted landmark observations
 * @param observations Vector of landmark observations
 */
void dataAssociation(std::vector<LandmarkObs> predicted, std::vector<LandmarkObs>& observations) {
	// TODO: Find the predicted measurement that is closest to each observed measurement and assign the 
	//   observed measurement to this particular landmark.
	// NOTE: this method will NOT be called by the grading code. But you will probably find it useful to 
	//   implement this method and use it as a helper during the updateWeights phase.

	/*
		Still don't know what exactly this association does, however, 
			it does associate what the particle thinks it sees with what it observes
	*/

	double currdist;
	int id_pred;
	
	for ( int i = 0; i < predicted.size(); i++){
		double mindist = 999.0;
		
		for ( int j=0; j < observations.size(); j++){
			currdist = dist(observations[j].x, observations[j].y, predicted[i].x, predicted[i].y);
			if ( currdist < mindist){
				mindist = currdist;
				id_pred = i;
			}
		}

		/*
		//Notice the association made in the printline, may put that in some sort of map soon

		cout<< "The closest to: " << predicted[i].id << " " << predicted[i].x << " " << predicted[i].y  << " is "
								  << observations[id_pred].id << " " << observations[id_pred].x << " " << observations[id_pred].y << endl; 
		*/

	}
}


int main() {
	
	vector<LandmarkObs> the_predicted;
	vector<LandmarkObs> observations;
	
	for (int i=1; i < 4; i++)
	{
		LandmarkObs single_land;
		single_land.id = i;
		single_land.x    = i*2;
		single_land.y    = i*2;

		the_predicted.push_back(single_land);
		
		LandmarkObs p;
		p.id = i;
		p.x  = i * 2;
		p.y  = i * 2 + 1;
		
		observations.push_back(p);
		
	}


	for (int i=15; i < 20; i++)
	{
		LandmarkObs single_land2;
		single_land2.id = i;
		single_land2.x    = i*2;
		single_land2.y    = i*2;

		observations.push_back(single_land2);
	}
	dataAssociation( the_predicted, observations);

	return 0;
}




