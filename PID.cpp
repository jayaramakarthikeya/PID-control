#include "PID.h"
#include <cmath>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

  

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double err = -Kp * p_error - Kd * d_error - Ki * i_error;
  if(err > 1)
    err = 1;
  if(err < -1)
    err = -1;
  return err;  // TODO: Add your total error calc here!
}