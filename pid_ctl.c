// pid_ctl.c
#ifndef PID_CTL_C_
#define PID_CTL_C_

#if __cplusplus
extern "C" {
#endif

// Includes
#include <string.h>
#include "pid_ctl.h"

void init_pid(pid_ctl* pid){
    memset(pid, 0, sizeof(pid_ctl));
}

void step_pid(pid_ctl* pid, pid_input* input){

    /* P */
    pid->proportional =(input->target - input->measurement);

    /* I */
    pid->integral = (pid->integral * ((input->target - input->measurement) - pid->prev_err) * pid->time_sec);

    /* I Anti-Wind-Up */
    // TODO

    /* D */
    pid->derivative = ((input->measurement - pid->prev_measure) / pid->time_sec);

    /* Comput output */
    pid->output = ((pid->Kp * pid->proportional) + (pid->Ki * pid->integral) + (pid->Kd * pid->derivative));

    /* Add rate rate limiting option? */
    // TODO

    /* Set new previous values */
    pid->prev_err = (input->target - input->measurement);
    pid->prev_measure = input->measurement;
}

#ifdef __cplusplus
}
#endif
#endif

int main(){
    return 0;
}