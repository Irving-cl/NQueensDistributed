# NQueensDistributed
In this project, I'm going to solve `N-Queens` problem on a distributed system.
Since I have never developed a distributed application and
recently I learned something about `boost.asio`,
I think this would be a good practice for me.  

As we know, the `N-Queens` problem is a **NP-Complete** problem,
and there are some good solutions like **Monte-Carol** algorithm.
But this project is not meant for algorithm at this level, I'm going to use the
most basic algorithm which will bring us huge amount of calculation.
And this project tries to distribute the calculation to different threads and different machines
to accelerate the solving process.  

This project contains the following things:
*    Solving `N-Queens` on one machine with single thread
*    Solving `N-Queens` on one machine with multiple threads
*    Solving `N-Queens` on some machines with multiple threads, the machines are all the same
*    Solving `N-Queens` on some machines with multiple threads, the machines may be different, 
we should do the scheduling
*    Comparing the performances of the above things

