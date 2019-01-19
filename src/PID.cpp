#include "PID.h"
#include <chrono>
#include <vector>

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
}

void PID::UpdateError(double cte) {
  double cte_prev = this->p_error;
  this->p_error = cte;
  this->i_error += cte;
  this->d_error = cte - cte_prev;
}

double PID::TotalError() {
  return this->Kp * p_error +
         this->Ki * i_error +
         this->Kd * d_error;
}