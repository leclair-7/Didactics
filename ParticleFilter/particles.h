#include <vector>


class Particle {
   
  public:

  	//may change heading to orientation
  	// weight is the importance weight
  	float x, y, heading, weight, normalized_weight;
    
    float sense_noise, forward_noise, turn_noise;

    float measurement;
    Particle();

  	std::vector<float> getPosition();
  	void move(float turn, float forward_move);
	std::vector<float> sense(std::vector<std::vector<float>> landmarks);
	float distToLandmark(std::vector<float> landmark);
};