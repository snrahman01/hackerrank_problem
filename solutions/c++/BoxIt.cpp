#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box&
class Box{
public:
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }

    Box(int l, int b, int h){
        this->l = l;
        this->b = b;
        this->h = h;
    }

    Box(const Box &b1){
        l = b1.l;
        b = b1.b;
        h = b1.h;
    }

    bool operator < (Box const &obj){
        return (l < obj.l || (b<obj.b && l == obj.l) || (h < obj.h && b == obj.b && l == obj.l));
    }

    friend ostream& operator<< (ostream& os, const Box& obj){
        os<< obj.l<<" " << obj.b<< " " << obj.h;
        return os;
    }

    int getLength(){
        return l;
    }

    int getBreadth(){
        return b;
    }

    int getHeight(){
        return h;
    }

    long long CalculateVolume(){

        long long a = l*b;
        long long a1 = a*h;
        return a1;

    }
private:
    int l, b, h;
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
	return 0;
}
