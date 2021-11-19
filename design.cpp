#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
#define pi 3.142857
int main()
{
    float Tor,V=24, f=50, rating=200, ns=1000, Ar=0.6, sr=0.5, ktrv=19100, Bg=0.7, Nc=2, cd=5, eff=0.9,Bsy=1.5, Bry=1.5, Bst=1.8, kst=0.9;
    Tor = (60*rating)/(2*pi*ns);
    float L = cbrt((4*Tor*Ar)/(pi*ktrv*sr*sr));
    float Dso, Dro, ac, poles=4, ph=3, slots=24, iph, zph, as, tph;
    float L = 0.091;
    //MAIN DIMENSIONS
    Dso = L/Ar;
    Dro = sr*Dso;
    ac = ktrv/(2*Bg);
    ac = 29778;
    iph = rating/(eff*V);
    zph = (ac*pi*Dro)/(2*iph);
    tph = zph/2;
    as = iph/cd;
    cout<<"*********** Main Dimensions ***********"<<endl;
    cout<<"Axial length= "<<L<<"\n"<<"Dso= "<<Dso<<endl<<"Dro= "<<Dro<<endl<<"Elec. loading= "<<ac<<endl<<"phase current= "<<iph<<endl<<"turns per phase= "<<tph<<endl<<"Stator cond. area= "<<as<<endl<<endl;
    
    //STATOR DESIGN
    float As, Zs, Zss, Cu_area, sf=0.5, d3, wsb=5, lg=0.5, agapflux, wbi, wbt, Nsm;
    cout<<"*********** Stator Design ***********"<<endl;
    Nsm = slots/poles;
    cout<<"slots per pole= "<<Nsm<<endl;
    As = as*slots/sf;
    cout<<"Slot area= "<<As<<endl;
    Zs = 3*zph;
    cout<<"Total conductors= "<<Zs<<endl;
    Zss = Zs/slots;
    cout<<"Cond. per slot= "<<Zss<<endl;
    cout<<"Slot width= "<<wsb<<endl;
    d3 = As/wsb;
    d3 = 0.01;
    cout<<"Slot depth="<<d3<<endl;
    cout<<"length of air gap= "<<lg<<endl;
    agapflux = Bg*pi*L*Dro/poles;
    cout<<"Air gap flux= "<<agapflux<<endl;
    wbi = 1000*agapflux/(2*Bsy*kst*L);
    wbi = 0.005;
    cout<<"Stat. back iron width= "<<wbi<<endl;
    wbt = 1000*agapflux/(Nsm*Bst*kst*L);
    cout<<"Stat. teeth width= "<<wbt<<endl<<endl;

    //ROTOR DESIGN
    cout<<"*********** Rotor Design ***********"<<endl;
    float lm=5, wry, Dri;
    wry = 1000*agapflux/(2*Bry*kst*L);
    cout<<"Rot. back iron width= "<<wry<<endl;
    Dri = 2*((Dro*1000/2)-wry-lg)/1000;
    cout<<"Rot. inner radius= "<<Dri<<endl<<endl;

    //PERFROMANCE ESTIMATION
    cout<<"*********** Performance Estimation ***********"<<endl;
    float Pl, Pcu, Pi, Rs, Re, Rph, coilpitch, turperslot = 12, kcp=0.2, Pfw=2;
    Rs = (0.0172*turperslot*turperslot*L)/(kcp*As);
    cout<<"Rs= "<<Rs<<endl;
    coilpitch = pi*Dso/poles;
    Re = (0.0172*turperslot*turperslot*pi*coilpitch)/(2*kcp*As);
    cout<<"Re= "<<Re<<endl;
    Rph = 6*(Rs+Re);    
    cout<<"Phase resistance= "<<Rph<<endl;
    Pcu = 3*iph*iph*Rph;
    cout<<"Copper loss= "<<Pcu<<endl;
    float Rsi = 0.0425;
    float Dsi = 2*Rsi;
    cout<<"Stator inner dia.= "<<Dsi<<endl;
    float Rso = Dso/2;
    Pi = 7870*((pi*(Rso*Rso)-(Rsi*Rsi))-(turperslot*As*0.000001))*L*kst*1.53;
    cout<<"Iron loss= "<<Pi<<endl;
    Pl = Pcu+Pi+Pfw;
    cout<<"Total loss= "<<Pl<<endl;
    float calc_eff= ((rating-Pl)/rating)*100;
    cout<<"Calculated efficiency= "<<calc_eff<<endl;
    float pd, bav=0.89, kw=0.95;
    pd = (4.44*poles*poles*bav*ac*kw*Dsi*L*ns)/(pi*(Dsi+2*(wbi+d3)*(Dsi+2*(wbi+d3)))*L);
    cout<<"Power density= "<<pd<<endl;
    Tor = ktrv*(pi/4)*Dro*Dro*L;
    cout<<"Avg. Torque= "<<Tor<<endl;
    return 0;
}