#include <fstream>
#include <cmath>

using namespace std;
void k(double* const y, double* k1, double* k2, double* k3, double* k4, const double a, const double b, const double c, const double dt);
void f(double* const y, const double a, const double b, const double c, double*);

int main(){
 const double dt=0.05;
 const double a=10;
 const double b=28;
 const double c=8.0/3.0;
 const double t0=0;
 const double tf=100;
 const double n=(tf-t0)/dt;
 double y[3],k1[3],k2[3],k3[3],k4[3]; y[0]=1; y[1]=1; y[2]=1; k1[0]=0; k1[1]=0; k1[2]=0;
 ofstream out("Data.txt");

 for(int i=0;i<n;i++){
  out << i*dt << " " << y[0] << " " << y[1] << " " << y[2] << endl;
  k(y,k1,k2,k3,k4,a,b,c,dt);
  y[0]+= dt/6.0*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
  y[1]+= dt/6.0*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
  y[2]+= dt/6.0*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
 }

 out.close();
 return 0;
}

void k(double* const y, double* k1, double* k2, double* k3, double* k4, const double a, const double b, const double c, const double dt){
  f(y,a,b,c,k1);
  double kk[3]; kk[0]=y[0]+dt*1/2.0*k1[0]; kk[1]=y[1]+dt*1/2.0*k1[1]; kk[2]=y[2]+dt*1/2.0*k1[2];
  f(kk,a,b,c,k2);
  kk[0]=y[0]+1/2.0*dt*k2[0]; kk[1]=y[1]+1/2.0*dt*k2[1]; kk[2]=y[2]+dt*1/2.0*k1[2];
  f(kk,a,b,c,k3);
  kk[0]=y[0]+dt*k3[0]; kk[1]=y[1]+dt*k3[1]; kk[2]=y[2]+dt*k3[2];
  f(kk,a,b,c,k4);
}

void f(double* const y, const double a, const double b, const double c, double* k){
  k[0]=a*y[1]-a*y[0];
  k[1]=b*y[0]-y[0]*y[2]-y[1];
  k[2]=y[0]*y[1]-c*y[2];
}
