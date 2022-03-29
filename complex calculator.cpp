# include<bits/stdc++.h>
using namespace std;

float a,b,c,d;
char op;
float real_result;
float complex_result;

void get_inputs();
bool check_validity(float);
void display_result ();
void complex_calculator ();


int main () {

    complex_calculator();
    return 0;
}


void get_inputs()
{
    cout<<"The operation in the program is: (a+bi) operator (c+di)\n";
    cout<<"Please enter number 'a':\n";
    cin>>a;
    check_validity(a);

    cout<<"Please enter number 'b':\n";
    cin>>b;
    check_validity(b);

    cout<<"Please enter number 'c':\n";
    cin>>c;
    check_validity(c);

    cout<<"Please enter number 'd':\n";
    cin>>d;
    check_validity(d);

    cout<<"please enter the operator '+' or '-' or '*' or '/' :\n";
    cin>>op;
    while (op != '+' && op != '-' && op != '*' && op != '/')
    {
        cout<<"please enter the operator :\n";
        cin>>op;
    }
}

bool check_validity (float num)
{
    while (cin.fail()==1)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Please enter a number as integer or float:\n";
        cin>>num;
    }
    cin.clear();
    cin.ignore(256,'\n');
}

void display_result ()
{
    if (real_result == 0 && complex_result == 0)
        cout<<0;
    else if (real_result == 0)
        cout<<"The result = "<<complex_result<<"i";
    else if (complex_result == 0)
        cout<<"The result = "<<real_result;
    else if (complex_result > 0)
        cout<<"The result = "<<real_result<<"+"<<complex_result<<"i";
    else
        cout<<"The result = "<<real_result<<complex_result<<"i";
}

void complex_calculator () {
    get_inputs();
    if (op == '+') {
        real_result = a + c;
        complex_result = b + d;
    } else if (op == '-') {
        real_result = a - c;
        complex_result = b - d;
    } else if (op == '*') {
        real_result = a * c + (-b * d);
        complex_result = a * d + b * c;
    } else if (op == '/') {
        real_result = (a * c + b * d) / (c * c + d * d);
        complex_result = (a * -d + b * c) / (c * c + d * d);
    }
    display_result();
}
