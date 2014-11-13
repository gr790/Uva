#!/bin/bash

for k in {0..200}
do
	echo $k >> sample.txt
	k=`expr $k+1`
done
