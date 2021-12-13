# CMPS-3240-Lab12

I started with the BLOCKSIZE as 32. Like the textbook stated, this meant each matrix would be 32 x 32 = 1024 elements. So the matrices would occupy 24 KiB
which would easily fit into the 32 KiB data cache of an Intel Core i7. Out of curiousity, I used 64 as the BLOCKSIZE but after 4 minutes I gave up and
realized that was too big of a BLOCKSIZE. After running a few tests, it seems a BLOCKSIZE between 32 and 40 would be the best to use for the program to run
as efficiently as possible. A smaller BLOCKSIZE runs faster but does less work, while a larger BLOCKSIZE would take many clock cycles to complete due to the 
amount of work/matrices. 

Benchmark for BLOCKSIZE = 32
```shell
$ for i in {1..3}; do time ./dgemm.out; done;
Running DGEMM operation of size 1024 x 1

real	0m4.669s
user	0m4.661s
sys	0m0.008s
Running DGEMM operation of size 1024 x 1

real	0m4.633s
user	0m4.625s
sys	0m0.008s
Running DGEMM operation of size 1024 x 1

real	0m4.601s
user	0m4.601s
sys	0m0.000s
```

Benchmark for BLOCKSIZE = 40
```shell
$ for i in {1..3}; do time ./dgemm.out; done;
Running DGEMM operation of size 1600 x 1

real	0m13.836s
user	0m13.836s
sys	0m0.000s
Running DGEMM operation of size 1600 x 1

real	0m13.837s
user	0m13.833s
sys	0m0.004s
Running DGEMM operation of size 1600 x 1

real	0m13.669s
user	0m13.669s
sys	0m0.000s
```

Benchmark for BLOCKSIZE = 30
```shell
$ for i in {1..3}; do time ./dgemm.out; done;
Running DGEMM operation of size 900 x 1

real	0m2.339s
user	0m2.331s
sys	0m0.008s
Running DGEMM operation of size 900 x 1

real	0m2.299s
user	0m2.295s
sys	0m0.004s
Running DGEMM operation of size 900 x 1

real	0m2.323s
user	0m2.323s
sys	0m0.000s
```

Benchmark for BLOCKSIZE = 25
```shell
$ for i in {1..3}; do time ./dgemm.out; done;
Running DGEMM operation of size 625 x 1

real	0m0.793s
user	0m0.792s
sys	0m0.000s
Running DGEMM operation of size 625 x 1

real	0m0.792s
user	0m0.792s
sys	0m0.000s
Running DGEMM operation of size 625 x 1

real	0m0.791s
user	0m0.791s
sys	0m0.000s
```
