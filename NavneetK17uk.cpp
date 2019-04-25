#include<iostream>
#include<algorithm>
#include<map>
#include<array>//Make pair
#include<queue>
#include<set>
#include<stack>
#include<tuple>
using namespace std;
 
int main()
{
    int Burst_Time[20],Process_no[20],WaitinG_TimE[20],Turn_Around_Time[20];
	int Arrival_time[20],PrioritY[20],i,j,Number_of_Process,total=0,pos,temp,Average_Waiting_Time,Average_Turn_Around_time;
    cout<<"Enter Total Number of Process:";
    cin>>Number_of_Process;//Number of process
 
   // cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<Number_of_Process;i++)
    {
        cout<<"\nProcess "<<i+1<<" \n";
        cout<<"Enter Burst Time for Process:"<<i+1<<endl;//Burst time for each Process
        cin>>Burst_Time[i];
        cout<<"Enter Arrival Time for Process:"<<i+1<<endl;
        cin>>Arrival_time[i];//Arrival time for each process
        cout<<"Enter Priority for Process:"<<i+1<<endl;
        cin>>PrioritY[i];
        Process_no[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<Number_of_Process;i++)
    {
        pos=i;
        for(j=i+1;j<Number_of_Process;j++)
        {
            if(PrioritY[j]<PrioritY[pos])
                pos=j;
        }
 		swap(PrioritY[i],PrioritY[pos]);
 		
 		swap(Burst_Time[i],Burst_Time[pos]);
        
        swap(Process_no[i],Process_no[pos]);
 
        
    }
 
    WaitinG_TimE[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<Number_of_Process;i++)
    {
        WaitinG_TimE[i]=0;
        for(j=0;j<i;j++)
            WaitinG_TimE[i]+=Burst_Time[j];
 
        total+=WaitinG_TimE[i];
    }
 
    Average_Waiting_Time=total/Number_of_Process;      //average waiting time
    total=0;
 	cout<<"__________________________________________________________";
    cout<<"\nProcess\t       Burst Time    Waiting Time  Turnaround Time";
    for(i=0;i<Number_of_Process;i++)
    {
        Turn_Around_Time[i]=Burst_Time[i]+WaitinG_TimE[i];     //calculate turnaround time
        total+=Turn_Around_Time[i];
        cout<<"\nProcess "<<Process_no[i]<<" \t "<<Burst_Time[i]<<"\t \t   "<<WaitinG_TimE[i]<<"\t\t"<<Turn_Around_Time[i];
    }
    	cout<<"\n";
    Average_Turn_Around_time=total/Number_of_Process;     //average turnaround time
    cout<<"\n\nAvg Waiting Time ="<<Average_Waiting_Time;
    cout<<"\nAvg Turnaround Time="<<Average_Turn_Around_time;
 
    return 0;
}



