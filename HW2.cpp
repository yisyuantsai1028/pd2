#include <iostream>
#include <vector>
using namespace std;

class Product {
    public:
        string name;
        int price;
        int count;
        Product(string n,int p,int c): name(n), price(p),count(c) {}
    
       
};

class Record {
    public:
        string date;
        vector<Product> products;
        Record(string d,vector<Product> p):date(d),products(p){}

        int total() const {
            int sum = 0;
            for (auto &p : products)
            {
                sum += p.price * p.count;
            }
            return sum;
        } 
};
    

class User {
    public:
        string name;
        string birthday;
        vector<Record> records;
        User(string n, string b): name(n), birthday(b) {}
    
 
};
vector<User> users;//動態陣列名字叫users，裡面存放許多User物件


int main() {


    string operation;

    while(cin>>operation){

        
        if(operation=="register")
        {
            string a;
            string b;
            cin >> a;
            cin >> b;
            User newuser(a,b);//建立User物件
            users.push_back(newuser);//將它移入動態陣列
        }
        else if(operation=="update")
        {
            string a;
            string b;
            cin >> a;
            cin >> b;
            for(auto &u : users){
            if(u.name == a)
            {
               u.birthday=b;
               break;
            }
            }
           
        }
        else if(operation=="search")
        {
            int ans=0;
            string a;
            cin >> a;
            for(auto &u : users){
                if(u.name == a)
                {
                   cout<<u.name<<" "<<u.birthday<<endl; 
                   ans=1;
                   break;
                }
            }

            if(ans==0){

                cout<<"USER NOT FOUND"<<endl;
            }

        }

        else if(operation=="buy")
        {
            string a;
            string b;
            int c;
            cin>>a;
            cin>>b;
            cin>>c;
            vector<Product> products;
            for(int i=0;i<c;i++)
            {
                string name;
                int price;
                int count;
                cin>>name;
                cin>>price;
                cin>>count;
                Product newproduct(name,price,count);
                products.push_back(newproduct);
            }
            for(auto &u : users)
            {
                if(u.name == b)
                {
                    Record newrecord(a, products);
                    u.records.push_back(newrecord);
                    break;
                }
            }
        }
        else if(operation=="detail")
        {
            string a;
            int b;
            cin>>a;
            cin>>b;
            for(auto &u : users)
            {
                if(u.name == a)
                {
                    Record r = u.records[b];
                    cout << r.date << " " << r.total() << endl;
                    for(auto &p : r.products)
                    {
                        cout << p.name << " " << p.price << " " << p.count << " " << p.price * p.count << endl;
                    }
                    break;
                }
                

            }
           
        }
        else
        {

            string a;
            cin>>a;
            for(auto &u :users)
            {
                if(u.name==a)
                {
                    int sum=0;
                    for(auto &r:u.records)
                    {
                        sum+=r.total();
                    }
                    cout << u.records.size() << " " << sum << endl;
                    break;
                }
            }
        }

    
    }   

    return 0;
} 
    
    
    
    