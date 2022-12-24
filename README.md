#  videoparticles

This application demonstrates using a PNG image comprised of a gradient white circle as the source of a stream of particles.  The image is colorized by pixels grabed from a webcam.  Performance on my system is currently at 25fps when the number of particles is around 25000-35000.  We can get near to 40fp at 10000.   
The cleaning process causes considerable slow downs.. It seems the addition of mutex in this process may help, or using off screen graphics swaps. 
