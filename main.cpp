#include <iostream>
#include <cstdlib> 
#include <vector>
#include <string>
#include <map>
#include <unistd.h>
#include<time.h> 


#include <iostream>

using namespace std;

int gen_chislo();
void push_in_vector(vector<int> & vec, int num);
void summ_number_in_vector(vector<int> & vec, int & num);
void game_player(int num_player);
void game_comp();
void check_game();
void compare_numbers(string num1, string num2);
void check_num(int & summ, int num_player);
pair<bool, char> check_num_comp(int & summ);
pair<bool,string> check_vybor(char vybor);
vector<int> number_player1;
vector<int> number_player2;
vector<int> number_comp;
int summ_player1;
int summ_player2;
int summ_comp;


int main()
{
    srand((unsigned) time(NULL));
    game_player(1);
    return 0;
}

void game_player(int num_player)
{  
    int gen_num = 0;
    char vybor;
    bool start_stop_game = true;
    pair<bool,string> check;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        if(num_player == 1)
        {
            push_in_vector(number_player1,gen_num);
            cout << "P1 number is " << gen_num << endl;
        }
        else if(num_player == 2)
        {
            push_in_vector(number_player2,gen_num);
            cout << "P2 number is " << gen_num << endl;
        }
        
        if(num_player == 1)
        {
            summ_number_in_vector(number_player1,summ_player1);
            cout << "P1 summ is " << summ_player1 << endl;
        }
        else if(num_player == 2)
        {
            summ_number_in_vector(number_player2,summ_player2);
            cout << "P2 summ is " << summ_player2 << endl;
        }
        
        do
        {
            cout << "Enter 'y' for new number or 'n' for stop game!" << endl;
            cin >> vybor;
            check = check_vybor(vybor);
            start_stop_game = check.first;
        }while(check.second == "error");
    }
    if(num_player == 1)
    {
        check_num(summ_player1, num_player);
    }
    else if(num_player == 2)
    {
        check_num(summ_player2, num_player);
    }
    
}

void game_comp()
{
    int gen_num;
    bool start_stop_game = true;
    pair<bool, char> choose;
    while(start_stop_game)
    {
        gen_num = gen_chislo();
        push_in_vector(number_comp,gen_num);
        cout << "comp number is " << gen_num << endl;
        summ_number_in_vector(number_comp,summ_comp);
        cout << "comp summ is " << summ_comp << endl;
        choose = check_num_comp(summ_comp);
        start_stop_game = choose.first;
        if(choose.second)
        {
            cout<<"next step"<<endl;
        }
        usleep(1000 * 1000);
    }
    if(choose.second == 'w')
    {
        cout<<"Comp win..."<<endl;
    }
    else if(choose.second == 'l')
    {
        cout<<"COMP BE LOSER!"<<endl;
    }
    else if(choose.second == 's')
    {
        compare_numbers("player1", "computer");
    }
}

int gen_chislo()
{
    int rand_chislo = 0;
    rand_chislo = 2 + rand()%13;
    return rand_chislo;    
}

void push_in_vector(vector<int> & vec, int num)
{
    vec.push_back(num);
}

void summ_number_in_vector(vector<int> & vec, int & num)
{
    num = 0;
    for(int i : vec)
    {
        num +=i;
    }
}

pair<bool,string> check_vybor(char vybor)
{
    if(vybor == 'y')
    {
        return make_pair(true,"yes");
    }
    else if(vybor == 'n')
    {
        return make_pair(false,"no");
    }
    else
    {
        return make_pair(true,"error");
    }
}

void check_num(int & summ, int num_player)
{
    if(summ == 21)
    {
        cout << "Player " + to_string(num_player) + " win!" << endl;
    }
    else if(summ > 21)
    {
        cout << "Player " + to_string(num_player) + " lose!" << endl;
    }
    else if(summ < 21 && num_player == 1)
    {
        check_game();
    }
    else if(summ < 21 && num_player == 2)
    {
        compare_numbers("player1", "player2");
    }
}

pair<bool, char> check_num_comp(int & summ)
{
    if(summ == 21)
    {
        return make_pair(false, 'w');
    }
    else if(summ > 21)
    {
        return make_pair(false, 'l');
    }
    else if(summ == 18 || summ == 19 || summ == 20)
    {
        return make_pair(false, 's');//stop game
    }
    else
    {
        return make_pair(true, 'n');//next
    }
}

void check_game()
{
    char check;
    do
    {
        cout<<"Would you like to play with player 2 or computer?"<<endl;
        cout<<"'p' for player 2 or 'c' for computer"<<endl;
        cin>>check;
    }
    while(check != 'p' || check != 'c');
    if(check == 'c')
    {
        game_comp();
    }
    else if(check == 'c')
    {
        game_player(2);
    }
    else
    {
        cout<<"STOP THIS GAME!!!"<<endl;
    }
}

void compare_numbers(string num1, string num2)
{
    if(num1 == "player1" && num2 == "player2")
    {
        if(summ_player2 > summ_player2)
        {
            cout<<"Player 1 WIN!"<<endl;
        }
        else
        {
            cout<<"Player 2 WIN!"<<endl;
        }
    }
    else if(num1 == "player1" && num2 == "computer")
    {
        if(summ_player2 > summ_comp)
        {
            cout<<"Player 1 WIN!"<<endl;
        }
        else
        {
            cout<<"Computer WIN!"<<endl;
        }
    }
}


