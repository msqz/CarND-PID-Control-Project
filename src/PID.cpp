#include "PID.h"
#include <chrono>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
}

void PID::UpdateError(double cte) {
  this->p_error = cte;

  this->sum_cte += cte;
  this->i_error = this->sum_cte;

  long now = this->now();
  long dt = now - this->t_prev;
  this->d_error = (cte - this->cte_prev) / dt;
  this->t_prev = now;
}

double PID::TotalError() {
  return this->Kp * p_error +
         this->Ki * i_error +
         this->Kd * d_error;
}

long PID::now() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::system_clock::now().time_since_epoch())
      .count();
}