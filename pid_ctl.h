// pid.h
#ifndef PID_CTL_H_
#define PID_CTL_H_

#if __cplusplus
extern "C" {
#endif

typedef struct{
    float measurement;
    float target;
} pid_input;

typedef struct{
    /* gains */
    float Kp;
    float Ki;
    float Kd;

    /* Limits */
    float low_int_lim;
    float high_int_lim;

    /* Time */
    float time_sec;

    /* PID Values */
    float proportional;
    float integral;
    float derivative;

    /* Previous Values */
    float prev_err;
    float prev_measure;

    /* Output */
    float output;
} pid_ctl;


/**
 * @brief Set PID controller to 0s
 *
 * @param pid PID Controller
 */
void init_pid_ctl(pid_ctl* pid);

/**
 * @brief Step PID algorithm given controller, input with measure and target
 *
 * @param pid PID controller
 * @param input PID measure and target inputs
 */
void step_pid(pid_ctl* pid, pid_input* const input);

#ifdef __cplusplus
}
#endif
#endif