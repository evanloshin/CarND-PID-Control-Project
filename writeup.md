# PID Controller Writeup
**Author:** Evan Loshin

**Final Video Submission:** https://youtu.be/3f2AJ73YZe4

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)


#### Describe the effect each of the P, I, D components had in your implementation

**Proportional (P)** - Controls the magnitude of steering correction in proportion to the cross track error (CTE). Larger values of P will exaggerate the steering angle. Small values will take too long to correct, which dulls the vehicle's reaction to turns in the road.

**Integral (I)** - Weights the steering angle with the sum of CTE such that magnitude of steering angle increases over time. This term is useful for compensating a vehicle's steering bias because it's magnitude changes with time, whereas P does not.

**Derivative (D)** - Weights the magnitude of steering proportional to change in CTE. This term prevents overshooting because it's contribution to steering angle decreases as CTE approaches steady state.

In the project, I discovered the vehicle was most sensitive to **P**, followed by the **I** term. I discovered **I** is mostly responsible for the oscillations. The **D** term was very useful for managing the oscillations while retaining the **I** term's ability to quickly correct.

#### Describe how the final hyperparameters were chosen

I chose my hyperparameters by manually tuning them. While Twiddle was effective in lab, it requires many iterations to converge it's not conducive to the real-time Unity simulator. Stochastic gradient decent (SGD) is probably a good choice, however I'm not adequately prepared to implement it in the timeframe for this project.

I tuned my parameters methodically by beginning with **P** and setting the other two equal to zero. Once I settled on a value for **P**, I introduced **I**. From research and intuition, I gathered that **I** should take on a very small value in comparison to **P** so I didn't spend too much time tuning it. Last, I introduced **D** and witnessed the simulation improve dramatically as I increased this final term. I kept making **D** larger, and therefore more important, than I initially thought would be required.

Here are the final values I settled on for throttle of 0.4 (appx. 40MPH):

**P** = 0.12, **I** = 0.00005, **D** = 0.9

Overall, the vehicle makes it around the track with minimal oscillation. However, it's probably still enough to make me sick if I were a passenger.
