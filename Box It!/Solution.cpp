#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
class Box{  
    //l,b,h are integers representing the dimensions of the box
    private:
        int l,b,h;
    // The class should have the following functions : 
    public:

    // Constructors: 
    // Box();
    Box(){
        l = 0;
        b = 0;
        h = 0;
    }
    // Box(int,int,int);
    Box(int l, int b, int h){
        this->l = l;
        this->b = b;
        this->h = h;
    }
    // Box(Box);
    Box(Box & box){
        this->l = box.l;
        this->b = box.b;
        this->h = box.h;
    }


    // int getLength(); // Return box's length
    int getLength(){
        return this->l;
    }
    // int getBreadth (); // Return box's breadth

    int getBreath(){
        return this->b;
    }
    // int getHeight ();  //Return box's height
    int getHeight(){
        return this->h;
    }
    // long long CalculateVolume(); // Return the volume of the box
    long CalculateVolume(){
        return (long)l * (long)h * (long)b;
    }

    //Overload operator < as specified
    //bool operator<(Box& b)
    bool operator<(Box& b){
        if(this->l < b.l){
            return true;
        }
        if(this->b < b.b && this->l == b.l){
            return true;
        }
        if(this->h < b.h && this->l == b.l && this->b == b.b){
            return true;
        }
        return false;
    }

    //Overload operator << as specified
    friend ostream& operator<<(ostream& out, Box& B){
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
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
}