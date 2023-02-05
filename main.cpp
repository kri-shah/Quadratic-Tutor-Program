#include <iostream>
#include <cmath>
using namespace std;

//Quadratic Formula Variables
double a, b, c, x1, x2, discriminant, real, imaginary;

int method_choice;

int funcdiscriminant(double a, double b, double c){
    discriminant = b*b - 4*a*c;
    return discriminant;
}

void QuadraticFormula()
{
    funcdiscriminant(a, b, c);

    cout<<"The Quadratic Formula is: (-b +- sqrt(b^2 - 4ac))/(2a)";
    cout<<"\nThe part of the formula underneath the radical is called the discriminant.";
    cout<<"\t-->\tsqrt(b^2 - 4ac)\n";
    cout<<"When you plug in all your variables you'll get this:\n";
    cout<<"\t"<<-b<<" +- "<<"sqrt("<<discriminant<<")/("<<2*a<<")\n";

    if (discriminant == 0)
    {
        cout<<"If the discriminant is 0 then the formula simplifies down to -b/2a\n";
        cout<<"This means that you will get 2 of the same answer\n";
        cout << "Roots: " << "\n";
        x1 = -b/(2*a);
        cout << "x1 = x2 =" << x1 << "\n";
    }
    else{
        cout<<"If the discriminant is above 0 then there will be 2 real answers given;\n";
        cout<<"Use one equation as + the disriminant and the other as - the discriminant:\n";
        cout << "Then divide by 2 *a\n\n";
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots: \n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
}

void CompletingSquare(double A, double B, double C){
    double D = B;
    
    cout << "Here is the original equation:" << A << "x^2+" << B << "x+" << C << endl << endl;
    cout << "The first thing we need to do is check if a equals one." << endl;
    cout << "If it isn't, we'll have to divide each coefficent by a, in order to make a equal to one." << endl;
    
    if (A != 1){
        cout << "Unfortunetly, A equals " << A << ", which means we'll have to divide each coefficent by " << A << "." << endl;
        B = B / A;
        C = C / A;
        A = A / A;
        cout << "Here is the resulting equation:" << A << "x^2+" << B << "x+" << C << endl << endl;
    }
    else{
        cout << "Cool, a = 1, so we don't need to do any extra work!" << endl << endl;
    }
    
    C = -C;
    cout << "Now we need to set the equation equal to the constant. All those fancy words mean is we need to set ax^2 + bx = c" << endl;
    cout << "We can do this by subtracting c over to the other side (if c is positive) or add it to the other side (if c is negative)." << endl;
    cout << "The new equation is:" <<  A << "x^2+" << B << "x=" << C << endl << endl;

    double newc = (B / 2) * (B / 2);
    C = C + newc;
    cout << "Now what we need to do, is add (b/2)^2 (in your equation:" << newc << ") to both sides of the equation." << endl; 
    cout << "Here is the equation:" << A << "x^2+" << B << "x+" << newc << "=" << C << endl << endl;
    
    
    cout << "The quadratic is now a perfect square that we can factor as such." << endl;
    
    newc = sqrt(newc);
    cout << "So now, we can factor the quadratic into (x +/- √c)^2" << endl;
    cout << "In order to find out if the equation is plus or minus, we need to see if B is positve or negative." << endl;
    
    char symbol;
    
    if (D > 0){
        cout << "Because b is positive, here is your equation: (x+" << newc << ")^2" << "=" << C << endl << endl;
        symbol = '+';
    }
    else{
        cout << "Because b is negative, here is your equation: (x-" << newc << ")^2" << "=" << C << endl << endl;
        symbol = '-';
    }
    
    C = sqrt(C);
    cout<<"Now we have to take the square root of both sides." << endl;
    cout << "Here it is:" << "x" << symbol << newc << "= +/-" << C << endl;
    cout << "(In case you're confused about the +/-, remember that when you take the square root of something it has a positive or negative value.)" << endl << endl;
    
    double fac1, fac2;
    if (D > 0){
        cout << "Now all we need to do is subtact " << newc << " from " << "positive " << C << " and negative " << C << endl;
        fac1 = -C - newc;
        fac2 = C - newc;
        cout << "Hence, the x's are:" << fac1 << " and " << fac2;
    }
    else{
        cout << "Now all we need to do is add " << newc << " to " << " positive "<< C <<" negative " << C << endl;
        fac1 = -C + newc;
        fac2 = C + newc;
        cout << "Hence, the x's are:" << fac1 << " and " << fac2;
    }
}

void Factoring(int A, int B, int C)
{
    int gca = A, gcb = B, gcc = C;
    
    //Starting to calculate gcf between coefficents- makes sure all values are positive to avoid sign headache- if they arent, makes the value positive
    if (gca < 0){
        gca = -gca;
    }
    if (gcb < 0){
        gcb = -gcb;
    }
    if (gcc < 0){
        gcc = -gcc;
    }
    
    int AC = A * C;
    
    if (AC < 0){
        AC = -AC;   
    }
    
    int GCF = 1, i = 1;
    
    cout << "Alright, here is your quadratic equation:" << A << "x^2+" << B << "x+" << C << endl << endl;
    cout << "Okay so before we factor, we should check what the GCF of the two coefficents (A and B), as well as the constant C." << endl;
    cout << "In your equation, we need to check between:" << A << " " << B << " " << C << endl;
    
    //calculates gcf between A, B, C
    while((i <= gca) && (i <= gcb) && (i <= gcc)){
        if((gca % i == 0) && (gcb % i== 0) && (gcc % i == 0)){
            GCF = i;
        }
        i++;
    }
    
    //divides everything by GCF to get the smallest numbers before calculation
    A = A / GCF; B = B / GCF; C = C / GCF;
    
    cout << "Your GCF is:" << GCF << endl;
    cout << "So in regular algebra, you could just divide the entire equation by the GCf, and it would just cancel out and be fine." << endl; 
    cout << "But in a quadratic, what have to do is pull out that gcf, and represent that by multiplying the rest of the equation by that number." << endl;
    cout << "For example, GCF(ax^2 + bx + c)" << endl;
    cout << "Here is your equation:" << GCF << "(" << A << "x^2" << "+" << B << "x" << "+" << C << ")" << endl << endl;
    cout << "Alright, so now what we need to do, is multiply A and C (in your equation:" << A << ", " << C << ") and find factors which add up to B (in your equation:" << B << ")" << endl;
    cout << "Here are all the factors:";
    
    //couts all factors of A * C
    for(int x = -AC; x <= AC; ++x){
        if (x == 0){
            x = x + 1;
        }
        if (A * C % x == 0){
            cout << x << " ";
        }
    }
    
    int factor, factor2;
    double subfact, subfact2;
    
    //splits the B term into the factors which add up to A * C
    for(int x = -AC; x <= AC; ++x){
        if (x == 0){
            x = x + 1;
        }
        factor = A * C / x;
        if ((A * C % x == 0) && (factor + x == B)){
            factor2 = x;
            break;
        }
    }
    
    cout << endl << "Here are the factors that add up to b (" << B << "): " << factor << " & " << factor2 << endl; 
    cout << endl << "Let's now rewrite the equation:" << GCF << "(" << A << "x^2 + " << factor << "x + " << factor2 << "x + " << C << ")" << endl;
    cout << "Let's now factor by grouping on each half of the equation." << endl;
    
    //does factor * A- and makes it positive- so we can use that as varible limits in the for loop
    int factprod = factor * A;
    if (factprod < 0){
        factprod = -factprod;
    }
    
    //group factors right half of equation
    for (int y = -factprod; y <= factprod; ++y){
        if (y == 0){
            y = y + 1;
        }
        if ((A % y == 0) && (factor % y == 0)){
            subfact = y;
        }
    }
    
    //same as before, but for the left half- so this does factor2 * C
    int factprod2 = factor * C;
    
    if (factprod2 < 0){
        factprod2 = -factprod2;
    }
    
    //group factors left half of equation
    for (int y = -factprod2; y <= factprod2; ++y){
        if (y == 0){
            y = y + 1;
        }
        if ((C % y == 0) && (factor2 % y == 0)){
            subfact2 = y;
        }
    }
    A = A/subfact; factor = factor/subfact; C = C/subfact2; factor2 = factor2/subfact2;
    
    //fixes any potential sign errors
    if ((A != factor2) && (C != factor)){
        C = -C;
        factor2 = -factor2;
        subfact2 = -subfact2;
    }
    
    cout << GCF << "(" << subfact << "x(" << A << "x+" << factor << ")" << " + " << subfact2 << "(" << factor2 << "x+" << C << ")" << ")" << endl;
    
    cout << "Okay, so the overlapping part is one factor, and the coefficents of the overlapping part is the other factor." << endl;
    cout << endl << "Here is the end result:" << endl;
    cout << GCF << "(" << subfact << "x+" << subfact2 << ")" << "(" << A << "x+" << C << ")" << endl; //couts factored equation
    cout << "So to find the zeros/x-intercepts of the equation, we have to find out what value makes the equation = 0" << endl;
    cout << "As such, we can half of the expression to 0." << endl;
    cout << "(" << subfact << "x+" << subfact2 << ")" << "= 0" << endl;
    cout << "(" << A << "x+" << C << ")" << "= 0" << endl;
    
    //couts zeros
    cout << endl << "Hence, the zeros are:" << -subfact2 << "/" << subfact <<", " << -C << "/" << A;
    
}

bool verification(double A, double B, double C, int method){
    funcdiscriminant(a, b, c);
    
    if (method != 2){
        if (discriminant >= 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        double check = sqrt(discriminant);
        int check2 = sqrt(discriminant);
        if (check == check2){
            return true;
        }
        else if (discriminant >= 0){
            cout << "Sorry this equation cannot be factored, let's try to use quadratic formula instead!";
            QuadraticFormula();            
        }
        else{
            return false;
        }
    }
}

void Vertex()
{
    cout<<"The vertex of the function is the turning point of the quadratic.\n";
    cout<<"This can be found using -b/2a\n";
    double vertex = (-b)/(2*a);
        cout<<"\tThe x value of vertex is: "<<vertex << endl;
        cout << "\tTo find the y value, all we need to do is subsitute the x-value into the equation." << endl;
        cout<<"\tThe y value of vertex is: "<<a*(vertex*vertex)+b*vertex+c << endl << endl;
}

int main() 
{
    cout<<"This is the Quadratic Tutor! \n";
    cout<<"Enter coefficients A,B,C and separate them by spaces:";
    cin>>a>>b>>c;
    cout<<endl;
    
    cout << "Lets first check what the vertex is:" << endl;
    Vertex();
    
    cout << "Let's now try to solve the equation" << endl;
    cout<<"Which method would you like use? \n";
    cout<<"Option 1: Completing the Square \n";
    cout<<"Option 2: Factoring \n";
    cout<<"Option 3: Quadratic Formula \n";
    cout<<endl;        
    cout<<"Choice: ";
    cin>>method_choice;
    cout << endl << endl;
    
    if (verification(a, b, c, method_choice)){
        if(method_choice == 3)
        {
            cout<<"You have chosen QUADRATIC FORMULA \n";
            QuadraticFormula();
        }
        
        else if(method_choice == 2)
        {
            cout<<"You have chosen FACTORING \n";
            Factoring(a, b, c);
        }
        
        else
        {
            cout<<"You have chosen COMPLETING THE SQUARE \n";
            CompletingSquare(a, b, c);
        }
    }
    else{
        cout << "The discriminant is less that 0, which means that unfortunetly, there are no real solutions!";
    }
    return 0;
}
