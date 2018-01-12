
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>


using namespace std;

// let's find the Yeald to maturity

void YealdToMaturity(){

    //input variables
    double C,d,FV,PV;
    int N;

    //working variables
    double c,delta,YTMdiscount,YTMpremium,YTM,i,YTM100;

    //examples
    //C = 5, d = 1, FV = 100, PV = 95, N = 1;
    //C = 2.5, d = 1, FV = 100, PV = 100, N = 10;
   // C = 1.0, d = 0.96, FV = 100, PV = 99.06, N = 7;
    //C = 2.625, d = 0.42, FV = 100, PV = 105.5, N = 2;


     //input new data
    cout<< "what is the coupon value?  ";
    cin>>C;
    cout<< "year fraction until next coupon payment? ";
    cin>>d;
    //same as
    //cout<< "How many days have passed since last coupon payment? ";
    //cin>>d;
    //d=(365-d)/365;
    //or equivalent to
    //cout<< "How many days remain to the next coupon payment? ";
    //cin>>d;
    //d=d/365;
    cout<< "what is the face (future) value of the bond ?  ";
    cin>>FV;
    cout<< "what is the present value (the price) of the bond ?  ";
    cin>>PV;
    cout<< "How many FULL years remain until maturity?? ";
    cin>>N;


//find the coupon rate
    c=C/FV;

//define delta as the step size
    delta=0.00001;

//initialize YTMdiscount and YTMpremium
    YTMdiscount=C/c*pow(1+c,1-d)*(1-1/pow(1+c,N+1))+FV/pow(1+c,N+d);
    YTMpremium =C/c*pow(1+c,1-d)*(1-1/pow(1+c,N+1))+FV/pow(1+c,N+d);
    YTM=c;

//bond at PAR
    if (PV==FV){
        YTM=c;
    }
    else {

//initialize the iteration to the coupon rate
        i=c;

//bond at DISCOUNT
        if(PV<FV)
        {
            while (PV-YTMdiscount<0)
            {
                i=i+delta;
                YTMdiscount=C/i*pow(1+i,1-d)*(1-1/pow(1+i,N+1))+FV/pow(1+i,N+d);

                if (PV-YTMdiscount>0){
                    //approximate YTM to the midpoint of the last iterations
                    YTM=i-delta*.5;
                    break;
                }
            }
        }

//bond at PREMIUM
        else
            {
                int n;
                n=1;
                while (PV-YTMpremium>0)
                {
                    i=i-delta;
                    YTMpremium=C/i*pow(1+i,1-d)*(1-1/pow(1+i,N+1))+FV/pow(1+i,N+d);

                    if (PV-YTMpremium<0){
                         //approximate YTM to the midpoint of the last iterations
                         YTM=i+delta*.5;
                         break;
                        }
                     n++;
                 }
            }

    }
    //round YTM
    YTM100=round(YTM*10000)/100;
    cout << "The Yield To Maturity is: "<< YTM <<  endl;
    cout<< "in percentage corresponds to: "<< YTM100 <<"%"<<  endl;


}
#endif //UNTITLED6_YTM_H
