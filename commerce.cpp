#include<iostream>
#include<string>

using namespace std;

  class product{
  public:
    string name;
    int price,id;
    product(string name_,int price_,int id_){
      name = name_;
      price = price_;
      id = id_;
    }
    product(){}
    void display(){
      cout << "Name : " <<name<< '\n'<<"Price : "<<price<<'\n'<<"ID : "<<id<<'\n';
    }
  };

  class customer {
    string loginID,password,name;
    product cart[20];
    int n = 0,s = 0;

  public:
    customer(){
      loginID = "akash";
      password = "123";
    }
    bool authenticate(string loginID_,string password_){
      if(loginID == loginID_&& password == password_)
        return true;
      return false;
    }

    void addToCart (product p){
      cart[n++] = p;
    }
    void displayCart() {
      s = 0;
      for(int i = 0;i < n;i++){
        cart[i].display();
        s += cart[i].price;
      }
      std::cout << "TOTAL AMOUNT : " <<s<< '\n';
    }
    void removeFromCart(int i){
      for(int j = i;j < n;j++){
        cart[j] = cart[j+1];
      }
      n--;
    }
  };

  int main(){
    product products[20];
    int n = 5,ch = 1;
    customer cu;
    string name,password;

    for(int i = 0;i < n;i++){
      product p("pn",(i+1)*10,i);
      products[i] = p;
    }
    for(int i = 0;i < n;i++){
               products[i].display();
             }
    cout<<"Enter name"<<'\n';
    cin>>name;
    cout<<"Enter password"<<'\n';
    std::cin >> password;
    if(cu.authenticate(name,password)){
      while (ch != 0) {
        cout<<"Enter choice\n";
        cin>>ch;
        if(ch == 1){
          for(int i = 0;i < n;i++){
            products[i].display();
          }
        }
        if(ch == 2){
          int id;
          cout<<"Enter product id\n";
          cin>>id;
          cu.addToCart(products[id]);
        }
        if(ch == 3){
          cu.displayCart();
        }
        if(ch == 4){
          int id;
          cout<<"Enter product id\n";
          cin>>id;
          cu.removeFromCart(id);
        }
        if(ch == 0){
          return 0;
        }
      }
    }
  else{
    cout<<"Error login\n";
  }
  return 0;
}
