import subprocess
from random import randint
from timeit import default_timer as timer
import time
import os
import sys
num= list(map(int, sys.argv[1:]))
inf=num[0]
num=num[1:]
names=["hash3","hash3_omp","rabin_karp","rabin_karp_vect","hash3_seq","naive"]
os.environ["OMP_PLACES"]="threads"
os.environ["OMP_PROC_BIND"]="spread"
i=50;
out={};
for j in num:
    out[j]=open("time_results/"+names[j]+".txt","w+")
    out[j].write("size/pattern lenght ")
    tmp=4;
    while(tmp<2048):
        out[j].write(str(tmp)+" ")
        tmp*=2
    out[j].write("\n")
while(i<inf):
    file="genome_samples/s"+str(i)+".txt"
    for j in num:
        out[j].write(str(i)+" ")
        tmp=4;
        while(tmp<2048):
            if tmp>i:
                out[j].write(" ");
                tmp*=2
                continue
            subprocess.call(["build/"+names[j],file,"1",str(tmp)])
            tm=open("tmp.txt").read()
            out[j].write(tm[:-1]+" ")
            tmp*=2
        out[j].write("\n")
    i+=i//10
