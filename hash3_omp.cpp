#include <Kokkos_Core.hpp>
#include <Kokkos_Atomic.hpp>
#include <omp.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
typedef long long ll;
int main(int argc, char* argv[]) {
    std::ifstream fin(argv[1]);
    int f=argv[2][0]-'0';
    std::ofstream fout("tmp.txt");
    Kokkos::Timer timer;
    int ord[256];
    std::string data;
    fin>>data;
    ll size=data.size();
    int len=(data.size()>10000?1000:data.size()/10);
    len=(len<3?3:len);
    ord['A']=0;
    ord['C']=1;
    ord['G']=2;
    ord['T']=3;
    std::vector<int>freq(size,0);
    timer.reset();
    double st=timer.seconds();
#pragma omp parallel for shared(freq)
    for(int i=0;i<=size-len;++i){
        int res=0;
        int sh1;
        std::vector<int>shift(64,len-2);
        ll hash=0;
        for(int j=2;j<=len-1;++j){
            int ind=ord[data[i+j-2]]*16+ord[data[i+j-1]]*4+ord[data[i+j]];
            if (j==len-1) sh1=shift[ind];
            shift[ind]=len-1-j;
        }
        
        if (!sh1) sh1=1;
        int j=len-1;
        for(;;){
            int sh=1;
            while (sh && j<size) {
                int ind=ord[data[j-2]]*16+ord[data[j-1]]*4+ord[data[j]];
                sh=shift[ind];
                j+=sh;
            }
            if (j<size){
                int is_eq=1;
                for(int k=0;k<len;++k){
                    if (data[i+k]!=data[j-len+1+k]){
                        is_eq=0;
                        break;
                    }
                }
                res+=is_eq;
                j+=sh1;
            }else{
                break;
            }
        }
        freq[i]=res;
    }
    if (f==1) fout<<timer.seconds()-st<<" ";
    if(f==2){
        for(int i=0;i<=size-len;++i){
            fout<<freq[i];
        }
    }
    return 0;
}
