#include <stdio.h>
#include <stdlib.h>
#define h 1.0
#define g 9.81
static float Az, Vz, Pz; /* vertical accn (m/s^2), vel (m/s), position (m) */
static float Ax, Vx, Px; /* horizontal accn (m/s^2), vel (m/s), position (m) */
static float t; /* time (secs) */
void Integrate(float *y, float x);
void Integrate(float y, float x) / simple 1st order Euler */
{
*y = *y + x * h;
}
int main(int argc, char *argv[])
{
Az = -g; /* initial vertical accn */
Vz = 0.0; /* initial vertical vel */
Pz = 100.0; /* initial height */
Ax = 0.0; /* initial horizontal accn */
Vx = 500.0; /* initial horizontal vel */
Px = 0.0; /* initial horizontal distance */
t = 0.0; /* start from time t=0 */
do
{
printf("%2d %8.2f %8.2f %8.2f %8.2f\n",
(unsigned int) t, Vz, Pz, Vx, Px);
t = t + h;
Integrate(&Vz, Az);
Integrate(&Pz, Vz);
Integrate(&Vx, Ax);
Integrate(&Px, Vx);
} while (Pz >= 0.0);
}