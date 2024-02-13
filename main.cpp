#include <iostream>
#include <string>
using namespace std;
string a[5][21] ;
string statearr[5][21];
void fellarr(){
    for(int i=0;i<5;i++){
        for(int k=0;k<21;k++){
            a[i][k]="0";
        }
    }
    for(int i=0;i<5;i++){
        for(int k=0;k<21;k++){
            statearr[i][k]="0";
        }
    }
}


void addpatient(){
    cout<<"Enter specialization,name,states(0/1)";
    int spec;
    cin>>spec;
    string name;
    cin>>name;
    int state;
    cin>>state;
    int flag_tocheck_empt=1;

        if(a[4][spec]!="0")
            flag_tocheck_empt=0;

    if(flag_tocheck_empt==0)
        cout<<"sorry we don't have places in this specialization\n";
    else {
        if(state==0){
            for(int w=0;w<5;w++){
                if(a[w][spec]=="0"){
                    a[w][spec]=name;
                    statearr[w][spec]="regular";
                    break;}
            }

        }
        else  {
            string h=statearr[0][spec];
            statearr[0][spec]="urgent";
            string m = a[0][spec];
            a[0][spec] = name;
            for (int j = 1; j < 5; j++) {
                string switst =statearr[j][spec];
                statearr[j][spec]=h;
                h=switst;
                string swit = a[j][spec];
                a[j][spec] = m;
                m = swit;
            }
        }

    }

}

void printpatient(){
    for(int j=0;j<21;j++){
        int cnt=0;


        for(int i=0;i<5;i++){
            if(a[i][j]!="0"){
                cnt++;
            }

        }
        if(cnt!=0){
        cout<<"There is "<<cnt<<" in specializtion "<<j<<endl;
        for(int i=0;i<5;i++){
            if(a[i][j]!="0"){
                cout<<"there is "<<a[i][j]<<" "<<statearr[i][j]<<endl;
            }

        }}
    }
}

void getpatient(){
    cout<<"Enter the  specialization\n";
    int sp;
    cin>>sp;
    for(int s=0;s<5;s++){
        if(a[s][sp]!="0"){
            cout<<"plese "<<a[s][sp]<<" go to the doctor\n";
            for(int i=1;i<5;i++){
                a[i-1][sp]=a[i][sp];
                statearr[i-1][sp]=statearr[i][sp];

            }
            a[4][sp]="0";
            statearr[4][sp]="0";

            break;
        }
        else {
            cout<<"there is no patients ,u can take a rist\n";
            break;
        }
    }

}

void hospial(){
    int n;
    cout<<"Enter your choice\n"<<
        "1)ADD new patient\n"<<
        "2)print all patients\n"<<
        "3)Get next patient\n"<<
        "4)Exit\n";
    cin>>n;
    if(n==4)
        return;
    if(n==1){
        addpatient();
        return hospial();
    }
    if(n==2) {
        printpatient();
        return hospial();
    }if(n==3) {
        getpatient();
        return hospial();
    }
    if(n<1 || n>4){
        cout<<"plz enter valid choice\n";
        return hospial();}
}

int main(){
    fellarr();
    hospial();

    return 0;
}
