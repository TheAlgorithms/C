/**
 * PID Controller
 *
 * The PID controller is a linear control algorithm that has three terms:
 *  - Proportional: A simple scaling of the error value by a gain kP
 *  - Integral: Integration of the error value over time, then multipled by gain
 * kI
 *  - Derivative: Rate of change of the error value over time, multiplied by
 * gain kD
 *
 * Terms of the controller can be removed by setting their gain to 0, creating a
 * PI (kD = 0) or PD (kI = 0) controller. Depending on the control problem at
 * hand, some terms may not increase the performance of the system, or may have
 * a negative effect.
 *
 * For a more mathematical expanation of the PID Controller, see
 * https://en.wikipedia.org/wiki/PID_controller
 *
 * Limitations of this implementation:
 *  - Since this implementation is just for demonstration, the pid_step function
 * takes the dt as a parameter, and it can be provided by the user in main().
 * This allows deterministic experimentation with the algorithm, rather than
 * using time(NULL) which would make the function non-deterministic.
 *
 * Inputs: e(t) - Current error at time t. For example, how far a servo is off
 * the desired angle Output: u(t) - Controller output at time t.
 */
#include <stdio.h>

struct pid
{
    // Controller gains
    float kP;
    float kI;
    float kD;

    // State variables
    float lastError;
    float integral;
};

float pid_step(struct pid *controller, float dt, float error)
{
    // Calculate p term
    float p = error * controller->kP;

    // Calculate i term
    controller->integral += error * dt * controller->kI;

    // Calculate d term, taking care to not divide by zero
    float d =
        dt == 0 ? 0 : ((error - controller->lastError) / dt) * controller->kD;
    controller->lastError = error;

    return p + controller->integral + d;
}

int main()
{
    printf("PID Controller Example\n");

    struct pid controller = {.lastError = 0, .integral = 0};

    // Take the controller gains from the user
    printf(
        "Please enter controller gains in format kP, kI, KD. For example, "
        "\"1.2 2.1 3.2\"\n> ");
    scanf("%f %f %f", &controller.kP, &controller.kI, &controller.kD);
    printf("Using kP: %f, kI: %f, kD: %f\n", controller.kP, controller.kI,
           controller.kD);

    // How often the pid_step algorithm expects to be called. In a real life
    // scenario this would be provided by calling time(NULL) - last_time, or by
    // calling the function reliably at X Hz (using a timer or RTOS etc) For
    // demonstration of this algorithm though, it is defined below as 1 second,
    // allowing easy testing of integral and derivative terms.
    float time_step = 1;

    float error_value;
    while (1)
    {
        printf("Enter error value\n>");
        scanf("%f", &error_value);

        float output = pid_step(&controller, time_step, error_value);
        printf("Output: %f\n", output);
    }
}
