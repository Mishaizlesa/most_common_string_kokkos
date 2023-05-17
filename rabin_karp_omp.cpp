#include <Kokkos_Core.hpp>
#include <Kokkos_Atomic.hpp>
#include <omp.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
typedef long long ll;
ll mod=(1LL<<31)-1;
ll p=31;
int main(int argc, char* argv[]){
    std::ifstream fin(argv[1]);
    int f=argv[2][0]-'0';
    std::ofstream fout("tmp.txt");
    Kokkos::Timer timer;
    std::string data;
    fin>>data;
    ll size=data.size();
    int len=std::stoi(argv[3]);
    len=(len<3?3:len);
    std::vector<ll>freq(size);
    std::vector<ll>dp_h(size+1);
    dp_h[0]=0;
    timer.reset();
    double st=timer.seconds();
    ll powmod=1;
    for(int i=0;i<size;++i){
    dp_h[i+1]=(dp_h[i]+powmod*(data[i]-'A'))%mod;
        powmod*=p;
        powmod%=mod;
    }
    #pragma omp parallel for shared(freq, dp_h, data)
    for(int i=0;i<=size-len;++i){
        int res=0;
        ll hash=0;
        powmod=1;
        for(int j=0;j<len;++j){
            hash=(hash+powmod*(data[i+j]-'A'))%mod;
            powmod*=p;
            powmod%=mod;
        }
        powmod=1;
        for(int j=0;j<=size-len;++j){
            ll val_h=(dp_h[j+len]+mod-dp_h[j])%mod;
            if (val_h==(hash*powmod)%mod){
                int is_eq=1;
                for(int k=0;k<len && is_eq;++k){
                    if (data[i+k]!=data[j+k]){
                        is_eq=0;
                    }
                }
                res+=is_eq;
            }
            powmod*=p;
            powmod%=mod;
        }
        freq[i]=res;
    }
    if (f==1) fout<<timer.seconds()-st<<" ";
    if (f==2) for(int i=0;i<=size-len;++i) fout<<freq[i];
    return 0;
}
