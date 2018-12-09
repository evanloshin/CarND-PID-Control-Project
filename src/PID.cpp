#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
  
  Kp = Kp_in;
  Ki = Ki_in;
  Kd = Kd_in;
  prev_cte = 0;
  cum_cte = 0;
    
}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

