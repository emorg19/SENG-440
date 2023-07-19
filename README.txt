SENG 440: Embedded Systems
Matrix Inversion Project

This project is an embedded implementation of matrix inversion by Gaussian Elimination with pivoting created for SENG 440 at the University of Victoria

Multiple versions of the source are given which use different optimizations
The only special cases are the hardware_inverse.c version which won’t compile due to using a fictional assembly instruction, and the vector_inverse.c version which uses neon intrinsics and therefore has special build instructions as described below.


Build:

ssh <netlink>@seng440.ece.uvic.ca
mkdir /tmp/<name>
cd tmp/<name>
git clone https://github.com/nathantutak/seng440.git
cd seng440
arm-linux-gcc inverse.c -std=c99 -o inverse -O3

For neon instructions build:

/opt/arm/4.3.2/bin/arm-linux-gcc -mfloat-abi=softfp -mfpu=neon -static -O3 vector_inverse.c


Running:
The executables are expected to run on the virtual arm machine provided for the course

