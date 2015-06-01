#!/usr/bin/python

N = input();

res = {0:0,1:2,2:3}

if ( N in res ):
	print res[N]
else:
	N = N+1
	for i in range(3,N):
		res[i] = res[i-1]+res[i-2]

	print res[N-1]
