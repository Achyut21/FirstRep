#include<iostream>
#include<math.h>
#include<string.h>
#include<sstream>
using namespace std;
//For adding two numbers.
inline int add(int x,int y){
    return x+y;
}
//To get remainder of 2 numbers.
inline int mod(int x,int y){
    return (x%y);
}
//To multiply two numbers.
inline int mult(int x,int y){
    return x*y;
}
//To convert a decimal number to binary number.
inline int decimal_to_Binary(int x){
  long int binary_num=0,expo=0,power;

    while(x!=0){
        int rem=x%2;
        power = pow(10,expo);
        binary_num+=rem*power;
        x=x/2;
        expo++;
    }
  return binary_num;
}
//To convert binary number to decimal number.
inline int binary_to_Decimal(int y){
    int dec_val,base_val=1;
    int temp=y;
    while(temp){
        int last_number = temp%10;
        temp=temp/10;
        dec_val += last_number*base_val;
        base_val*=2;
    }
    return dec_val;
}
//To flip zero with one and vice-versa.
char flip(char c) {return (c == '0')? '1': '0';}

//To get get 2's complement.
inline string two_complement(string x){
    int n = x.length(),i;
    string one_comp, twos_comp;
    one_comp = twos_comp = "";
    for (i = 0; i < n; i++)
        one_comp += flip(x[i]);
    twos_comp = one_comp;
    for (i = n - 1; i >= 0; i--)
    {
        if (one_comp[i] == '1')
            twos_comp[i] = '0';
        else
        {
            twos_comp[i] = '1';
            break;
        }
    }
    if (i == -1)
        twos_comp = '1' + twos_comp;    
    return twos_comp;
}

int main(){

    int n=0,num_1,num_2;
    cout<<":::::::::::::::::::::::Menu::::::::::::::::::::::::";
   do{ 
    cout<<"\n Choose your option from the list given below: \n a.) Press '1' for addition, \n b.) Press '2' for multiplication,  \n c.) Press '3' for modulus,  \n d.) Press '4' To convert decimal number to binary, \n";
    cout<<" e.) Press '5' To convert binary number to decimal , \n f.) Press '6' To get 2's complementry,\n g.) Press '0' to exit. \n Enter your Option: ";
    cin>>n;
    switch (n)
    {
    //for addition.
    case 1:
    cout<<" ->Enter 2 numbers: ";
    cin>>num_1>>num_2; 
        cout<<" =>After adding both numbers we get: "<<add(num_1,num_2)<<endl;
        break;
    //for multiplication.
    case 2:
    cout<<" ->Enter 2 numbers: ";
    cin>>num_1>>num_2; 
        cout<<" =>After multiplying both numebrs we get: "<<mult(num_1,num_2)<<endl;
        break;
    //to get remainder.
    case 3:
    cout<<" ->Enter 2 numbers: ";
    cin>>num_1>>num_2; 
        cout<<" =>The remainder is: "<<mod(num_1,num_2)<<endl;
        break;
    //To take decimal number and print its binary number.
    case 4:
        cout<<" ->Enter a decimal number to convert it to binary number: ";
        cin>>num_1;
        cout<<" =>The binary number is: "<<decimal_to_Binary(num_1)<<endl;
        break; 
    //To take binary number and print its decimal number.
    case 5:
        cout<<" ->Enter a binary number to convert it to decimal number: ";
        cin>>num_2;
        cout<<" =>The decimal number is: "<<binary_to_Decimal(num_2)<<endl;  
        break;
    //To print 2's compliment of binary number as well as decimal number.
    case 6:
        int a;
         cout<<"--> Press 1 to input new binary number, \n--> Press 2 to input decimal number\n";
         cin>>a; 
         //To get 2's compliment of decimal number.  
         if(a==2){
            cout<<" ->Enter a decimal number: ";
            cin>>num_1;
            int num = decimal_to_Binary(num_1);
            string str1 = to_string(num);
             cout<<" ==>The output: "<<two_complement(str1)<<endl;
         } 
         //To get 2's compliment of binary number.
         else if(a==1){
             string bnum;
             cout<<" ->Enter a binary number: ";
             cin>>bnum;
             cout<<" ==>The output: "<<two_complement(bnum)<<endl;    
         }
         else{
             cout<<"***Invalid entry***";
         }
         break;
    //Press 0 to exit from the menu.
    case 0:
        cout<<"\n----------Exited sccussesfully---------";
        break;      
    default:
        cout<<"***Error: You entered any number thats not in the list.***";
        break;
    }
   }while(n!=0); 
    return 0;
}