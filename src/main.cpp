#include "..\include\neville.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  
  int sz=5;
  double *x = new double[sz];
  x[0]=-.5; x[1]=-.3; x[2]=-.1; x[3]=.1; x[4]=.2;
  double *f = new double[sz];
  f[0]=0.0; f[1]=.42; f[2]=.67; f[3]=.67; f[4]=.57;
  
  cout<<"x=0"<<endl<<neville(0,x,f,sz)<<endl;
  cout<<endl;
  cout<<"x=0.5"<<endl<<neville(.5,x,f,sz)<<endl;
  
  return 0;
}
