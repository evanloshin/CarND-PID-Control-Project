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
  cum_cte += cte;
  p_error = Kp * cte;
  d_error = Kd * (cte - prev_cte);
  i_error = Ki * cum_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  return (-p_error - d_error - i_error);
}

