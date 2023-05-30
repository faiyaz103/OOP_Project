#include<bits/stdc++.h>
using namespace std;

class DOC{

    private:
    int dcode;
    float fee;
    string dfname, dlname, dept, hour;

    public:
    void menu();
    void admin();
    void patient();
    void add();
    void edit();
    void rem();
    void list();
    void finddoc();
};



/*-------------------------Menu-----------------------------*/
void DOC::menu(){
    A:
    int choice;
    string mail,pass;

    cout<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"|      DOC on the GO        |"<<endl;
    cout<<"|___________________________|"<<endl;

    cout<<"1. Use as Admin."<<endl;
    cout<<"2. Use as a Patient."<<endl;
    cout<<"3. Exit."<<endl;
    cout<<"Please select one:"<<endl;
    cin>>choice;

    switch(choice){

        case 1:

            cout<<endl;
            cout<<"_______Please Login______"<<endl;
            cout<<"Enter Email:"<<endl;
            cin>>mail;
            cout<<"Enter password:"<<endl;
            cin>>pass;

            if(mail=="doctor@email.com" && pass=="doctor"){
                admin();
            }
            else{
                cout<<"WRONG EMAIL/PASSWORD !!!"<<endl;
            }

        break;

        case 2:
            patient();
        break;

        case 3:
            exit(0);
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;

}
/*----------------------------------------------------------*/



/*-------------------------Admin---------------------------*/
void DOC::admin(){
    A:
    int choice;

    cout<<endl;
    cout<<"---------Admin Panel-------"<<endl;
    cout<<"1. Visit Database."<<endl;
    cout<<"2. Add Doctor to Database."<<endl;
    cout<<"3. Modify Database."<<endl;
    cout<<"4. Remove Doctor from Database."<<endl;
    cout<<"5. Back to Menu."<<endl;
    cout<<"Please select one:"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            list();
        break;

        case 2:
            add();
        break;

        case 3:
            edit();
        break;

        case 4:
            rem();
        break;

        case 5:
            menu();
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;
}
/*----------------------------------------------------------*/



/*-------------------------Patient---------------------------*/
void DOC::patient(){
    A:
    int choice;

    cout<<endl;
    cout<<"---------Welcome-------"<<endl;
    cout<<"1. Make an Appointment."<<endl;
    cout<<"2. Back to Main Menu."<<endl;
    cout<<"3. Exit."<<endl;
    cout<<"Please select one:"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            finddoc();
        break;

        case 2:
            menu();
        break;

        case 3:
            exit(0);
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;
}
/*----------------------------------------------------------*/



/*-------------------------Add Doctor---------------------------*/
void DOC::add(){
    A:
    int code,flag=0;
    float f;
    string fname, lname, dep, hr;

    cout<<endl;
    cout<<"---------Add Doctor to Database-------"<<endl;
    cout<<"Enter doctor's code:"<<endl;
    cin>>dcode;
    cout<<"Enter first name:"<<endl;
    cin>>dfname;
    cout<<"Enter last name:"<<endl;
    cin>>dlname;
    cout<<"Enter department (Gynaecology, Cardiology etc.):"<<endl;
    cin>>dept;
    cout<<"Enter fees per visit:"<<endl;
    cin>>fee;
    cout<<"Enter visiting hour(Example: 6.00pm-9.00pm):"<<endl;
    cin>>hour;

    fstream data;

    data.open("docinfo.txt", ios::in);

    if(!data){

        data.open("docinfo.txt", ios::out|ios::app);

        data<<" "<<dcode<<" "<<dfname<<" "<<dlname<<" "<<dept<<" "<<fee<<" "<<hour<<"\n";

        data.close();
    }
    else{

        data>>code>>fname>>lname>>dep>>f>>hr;

        while(!data.eof()){

            if(code==dcode){
                flag++;
            }
            data>>code>>fname>>lname>>dep>>f>>hr;
        }
        data.close();

        if(flag==1){
            cout<<"Duplicate Doctor Code Detected !!!"<<endl;
            goto A;
        }
        else{
            data.open("docinfo.txt", ios::out|ios::app);

            data<<" "<<dcode<<" "<<dfname<<" "<<dlname<<" "<<dept<<" "<<fee<<" "<<hour<<"\n";

            data.close();
        }
    }

    cout<<"Database Updated Successfully."<<endl;
}
/*----------------------------------------------------------*/



/*-------------------------Modify Database---------------------------*/
void DOC::edit(){

    int key,code,flag=0;
    float f;
    string fname, lname, dep, hr;

    fstream data,newdata;

    data.open("docinfo.txt", ios::in);

    if(!data){

        cout<<"Database doesn't exist !!!"<<endl;
    }
    else{

        cout<<endl;
        cout<<"---------Modify Database-------"<<endl;
        list();
        cout<<"Enter doctor code:"<<endl;
        cin>>key;

        newdata.open("docinfo2.txt", ios::out|ios::app);

        data>>dcode>>dfname>>dlname>>dept>>fee>>hour;

        while(!data.eof()){

            if(key==dcode){

                cout<<endl;
                cout<<"Enter new doctor code:"<<endl;
                cin>>code;
                cout<<"Enter first name:"<<endl;
                cin>>fname;
                cout<<"Enter last name:"<<endl;
                cin>>lname;
                cout<<"Enter department:"<<endl;
                cin>>dep;
                cout<<"Enter fees per visit:"<<endl;
                cin>>f;
                cout<<"Enter visiting hour(Example: 6.00pm-9.00pm):"<<endl;
                cin>>hr;

                newdata<<" "<<code<<" "<<fname<<" "<<lname<<" "<<dep<<" "<<f<<" "<<hr<<"\n";

                cout<<"Database Edited"<<endl;

                flag++;
            }
            else{
                newdata<<" "<<dcode<<" "<<dfname<<" "<<dlname<<" "<<dept<<" "<<fee<<" "<<hour<<"\n";
            }

            data>>dcode>>dfname>>dlname>>dept>>fee>>hour;
        }
        data.close();
        newdata.close();

        remove("docinfo.txt");
        rename("docinfo2.txt","docinfo.txt");

        if(flag==0){
            cout<<"Record not found !!!"<<endl;
        }
    }
}
/*----------------------------------------------------------*/



/*-------------------------Remove Doctor---------------------------*/
void DOC::rem(){

    int key,flag=0;
    fstream data,newdata;

    data.open("docinfo.txt", ios::in);

    if(!data){

        cout<<"Database doesn't exist !!!"<<endl;
    }
    else{

        cout<<endl;
        cout<<"---------Remove Record from Database-------"<<endl;
        list();
        cout<<"Enter doctor code:"<<endl;
        cin>>key;

        newdata.open("docinfo2.txt", ios::out|ios::app);

        data>>dcode>>dfname>>dlname>>dept>>fee>>hour;

        while(!data.eof()){

            if(key==dcode){

                cout<<"Removed Successfully!!!"<<endl;

                flag++;
            }
            else{
                newdata<<" "<<dcode<<" "<<dfname<<" "<<dlname<<" "<<dept<<" "<<fee<<" "<<hour<<"\n";
            }

            data>>dcode>>dfname>>dlname>>dept>>fee>>hour;
        }
        data.close();
        newdata.close();

        remove("docinfo.txt");
        rename("docinfo2.txt","docinfo.txt");

        if(flag==0){
            cout<<"Record not found !!!"<<endl;
        }
    }
}
/*----------------------------------------------------------*/



/*-----------------------Doctor List------------------------*/
void DOC::list(){

    fstream data;

    data.open("docinfo.txt", ios::in);

    if(!data){

        cout<<"Database doesn't exist !!!"<<endl;
    }
    else{
        data>>dcode>>dfname>>dlname>>dept>>fee>>hour;
        while(!data.eof()){

            cout<<"Code: "<<dcode<<"\t\t"<<"Name: "<<dfname<<" "<<dlname<<"\t\t"<<"Department: "<<dept<<"\t\t"<<"Fees: "<<fee<<"\t\t"<<"Visiting Hour: "<<hour<<endl;
            data>>dcode>>dfname>>dlname>>dept>>fee>>hour;

        }

        data.close();
    }

}
/*----------------------------------------------------------*/



/*-----------------------Make Appointment------------------------*/
void DOC::finddoc(){
    A:
    int key;

    string fname,lname,phone;
    int flag=0;

    fstream data,pdata;
    data.open("docinfo.txt",ios::in);

    if(!data){
        cout<<"Database is empty."<<endl;
    }
    else{

        cout<<endl;
        cout<<"---------Make Appointment----------"<<endl;
        list();
        cout<<"Enter doctor code:"<<endl;
        cin>>key;

        data>>dcode>>dfname>>dlname>>dept>>fee>>hour;
        while(!data.eof()){
            if(key==dcode){

                cout<<endl;
                cout<<"Enter your first name: "<<endl;
                cin>>fname;
                cout<<"Enter your last name:"<<endl;
                cin>>lname;
                cout<<"Enter Phone number:"<<endl;
                cin>>phone;

                cout<<endl;
                cout<<"Name: "<<fname<<" "<<lname<<endl;
                cout<<"Phone: "<<phone<<endl;
                cout<<"Code: "<<dcode<<endl;
                cout<<"Name of Doctor: "<<dfname<<" "<<dlname<<endl;
                cout<<"Visiting hour: "<<hour<<endl;
                cout<<"Fees: "<<fee<<endl;

                pdata.open("receipt.txt",ios::out);

                pdata<<"Name: "<<fname<<" "<<lname<<"\nPhone: "<<phone<<"\nCode: "<<dcode<<"\nTime: "<<hour<<"\nFees: "<<fee<<"\n";

                cout<<"Appointment Done"<<endl;

                flag=1;

                break;
            }
            data>>dcode>>dfname>>dlname>>dept>>fee>>hour;
        }

        int choice;
        if(flag==0){
            cout<<"Try to enter correct doctor code"<<endl;
            cout<<"Press 1 to continue"<<endl;
            cout<<"Press 2 to return to main menu"<<endl;
            cin>>choice;

            if(choice==1){
                goto A;
            }
            else{
                menu();
            }
        }

        pdata.close();
    }

}
/*----------------------------------------------------------*/


int main(){

    DOC obj;

    obj.menu();

    return 0;
}
