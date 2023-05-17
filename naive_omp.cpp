#include <omp.h>
#include <iostream>
#include <string>
#include <fstream>
#include <Kokkos_Core.hpp>
typedef long long ll;
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
    std::vector<int>freq(size,0);
    timer.reset();
    double st=timer.seconds();
    #pragma omp parallel for shared(freq,data)
    for(int i=0;i<=size-len;++i){
    for(int j=0;j<size-len+1;++j){
        int is_eq=1;
        for(int k=0;k<len && is_eq;++k){
           if (data[i+k]!=data[j+k]) is_eq=0;
         }
         freq[i]+=is_eq;
     }
     }
     double fint=timer.seconds()-st;
     if (f==1){
        fout<<fint<<" ";
     }
     if (f==2){
        std::ofstream fout(argv[3]);
        for(int i=0;i<size-len+1;++i){
            fout<<freq[i];
         }
     }
     return 0;
}
