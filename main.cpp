#include <bits/stdc++.h>
using namespace std;

void input(void);
class TimeStamp{

    public:

    string datetime;

    void put(string datetime1)
    {
        datetime=datetime1;
    }

    string getdatetime()
    {
        return datetime;
    }

};

struct Data{

 string name,address,mobile,phone,password,algo;
 float value;
};

struct node{

  TimeStamp Datetime;
  struct Data* data;
  unsigned int NodeNumber;
  unsigned int NodeId;
  struct node *ref;
  vector<struct node*> child;
};

map<int,struct node*> all;

static int number=0;
string datetime()
{
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);

    return asctime(ti);
}

unsigned int unique()
{
    return rand();
}

string encrypt(string value){
    char key ='#';
    string output = value;

    for (int i = 0; i < value.size(); i++)
        output[i] = value[i] ^ key;

    return output;
}

void input(int head,vector<struct node*> headnodes)
{
    cout<<"Taking inputs : ";
    int size = headnodes.size();
    string name,address,mobile,phone,password,algo="AnkitKumar";
    float value;
    cout<<endl<<"Enter your name : ";
    cin>>name;
    cout<<endl<<"Enter your Address : ";
    cin>>address;
    cout<<endl<<"Enter your Mobile : ";
    cin>>mobile;
    cout<<endl<<"Enter your Phone : ";
    cin>>phone;
    cout<<endl<<"Enter Value : ";
    cin>>value;
    cout<<endl<<"Enter password : ";
    cin>>password;
    struct node *node1 = new node();
    struct Data *data1=new Data();
    string date = datetime();
    TimeStamp time;
    time.put(date);
    node1->Datetime=time;
    data1->name=encrypt(name);
    data1->address=encrypt(address);
    data1->mobile=encrypt(mobile);
    data1->phone=encrypt(phone);
    data1->password=encrypt(password);
    data1->algo=encrypt(algo);
    data1->value=value;
    node1->data=data1;
    node1->NodeNumber=++number;
    node1->NodeId=unique();

    if(head==-1)
    {
        node1->ref=NULL;
        headnodes.push_back(node1);
    }
    else
    {
        all[head]->child.push_back(node1);
        node1->ref=all[head];
    }

    all[number]=node1;
    return;
}

bool printverify(string password,string algo)
{
        string password1=encrypt(password);
        string algo1=encrypt("AnkitKumar");

        map<int,struct node*>::iterator it=all.begin();
        int flag=0;

        for(;it!=all.end(); it++)
        {
            if(it->second->data->password==password1 && it->second->data->algo==algo1)
            {
                flag=1;

                cout<<encrypt(it->second->data->address)<<endl;
                cout<<encrypt(it->second->data->phone)<<endl;
                cout<<encrypt(it->second->data->mobile)<<endl;
                cout<<encrypt(it->second->data->name)<<endl;

                break;
            }
        }

        if(flag==1)
        return true;

        return false;
}

int c=0;

void longest(struct node* root,int &ma)
{
        if(root==NULL)cout<<endl<<"Enter your input : ";
            return;

           c++;

            for(int i=0; i<root->child.size(); i++)
            {
                longest(root->child[i],ma);
            }

        if(c>ma)
            ma=c;
}

void levels(struct node* root,int c,int &ma)
{
        if(root==NULL)
            return;

            for(int i=0; i<root->child.size(); i++)
            {
                levels(root->child[i],c+1,ma);
            }

        if(c>ma)
            ma=c;
}

void merge(struct node* first,struct node * second,vector<struct node*> headnodes)
{cout<<endl<<"Enter your input : ";

}

int main()
{
    vector<struct node *> headnodes;
    cout<<"1 : Option to create first node\n";
    cout<<"2 : Option to create multi set of first node\n";
    cout<<"3 : Option to create new node to any set of node\n";
    cout<<"4 : create an algo to encrypt data\n";
    cout<<"5 : verify owner with key\n";
    cout<<"6 : break any node\n";
    cout<<"7 : change owner of node\n";
    cout<<"8 : longest chain of main node\n";
    cout<<"9 : longest chain of sub node among set of node\n";
    cout<<"10 : merge two sets\n";
    cout<<"11 : finish then all data is cleared";

    while(1)
    {
        cout<<endl<<"Enter your input :---- ";
        int num;
        cin>>num;


        if(num==11)
        break;



        else if(num==1)
        {
            cout<<"Hello"<<endl;
            input(-1,headnodes);
        }

        else if(num==2)
        {
            cout<<"Enter the number of sets : ";
            int sets;
            cin>>sets;

            while(sets--)
            {
                input(-1,headnodes);
            }
        }

        else if(num==3)
        {
            int nodenum;
            cout<<"Enter the Node Number : ";
            cin>>nodenum;
            input(nodenum,headnodes);
        }

        else if(num==4)
        {
            string password,algo;
            cout<<"Enter the Password and the Algo key : ";
            bool k=printverify(password,algo);
        }

        else if(num==5)
        {
            string password,algo;
            cout<<"Enter the Password and Algo key : ";

            bool k=printverify(password,algo);

            if(k)
            cout<<"Verified"<<endl;
            else
            cout<<"Not Verified"<<endl;

            cout<<endl;
        }

        else if(num==6)
        {
            int nodenum;
            cout<<"Enter Node Number : ";
            cin>>nodenum;
            all.erase(nodenum);
            cout<<"Erased"<<endl;
        }

        else if(num==7)
        {
            int nodenum1,nodenum2;
            cout<<"enter node number of first node and new owner";
            cin>>nodenum1>>nodenum2;

            struct node* first=all[nodenum1];
            struct node* newowner=all[nodenum2];

            first->ref->child.erase(first->child.begin()+nodenum1);
            newowner->child.push_back(first);
            first->ref=newowner;
        }

        else if(num==8)
        {
            int ma=0;
            c=0;

            for(int i=0; i<headnodes.size(); i++)
                longest(headnodes[i],ma);

            cout<<ma<<endl;
        }

        else if(num==9)
        {
            int ma=0;

            for(int i=0; i<headnodes.size(); i++)
                levels(headnodes[i],0,ma);

            cout<<ma<<endl;
        }

        else if(num==10)
        {
            cout<<"This function Not Working"<<endl;
            /*int nodenum1,nodenum2;
            cout<<"enter nodenumbers of 1 & 2";
            cin>>nodenum1>>nodenum2;

            struct node* first=all[nodenum1];
            struct node* second=all[nodenum2];

            merge(first,second,headnodes);*/
        }

    }

   return 0;
}
