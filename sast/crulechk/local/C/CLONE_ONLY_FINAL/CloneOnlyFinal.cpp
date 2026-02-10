//@checker  CLONE_ONLY_FINAL

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
using namespace std;

struct move
{
    int piece;
    char direction;
};




class SBP 
{
public:
    vector< vector<int> > state;
    int width; //columns
    int height; //rows

    void load(string filename);
    void display();
    SBP clone();
    SBP (const SBP &p2) {state = p2.state; width = p2.width; height = p2.height;} 
    SBP ( );
    SBP clonethis();
    SBP* clonenewthis();
    virtual SBP* clonenewthisFinal() final;
};

SBP SBP::clonethis() //@violation CLONE_ONLY_FINAL
{
    return *this;
}


SBP* SBP::clonenewthis() //@violation CLONE_ONLY_FINAL
{
    return new SBP(*this);
}


SBP* SBP::clonenewthisFinal()
{
    return new SBP(*this);
}



void SBP::load(string filename)
{
    int rownum = 1;
    char n;
    string str;
    ifstream file(filename.c_str());
    getline(file, str);
    width = str[0]-'0';
    height = str[2]-'0';
    while (getline(file, str))
    {
        vector<int> row;
        for (int i = 0; i < str.size(); ++i)
        {
            n = str[i];
            if (n != ',')
            {
                if (n == '-')
                {
                    row.push_back((str[i + 1] - '0')*(-1));
                    i = i + 1;
                }
                else
                {
                    if (str[i + 1] == ',')
                        row.push_back(n - '0');
                    else
                    {
                        row.push_back((str[i] += str[i + 1]) - '0');
                        i = i + 1;
                    }
                }
            }
        }
        state.push_back(row);
        rownum = rownum + 1;
    }
    printf("File has been loaded.\n\n");
}

void SBP::display()
{
    int num;
    printf("The state of the game is: \n");
    printf("%i,%i,\n", width, height);
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            num = state[r][c];
            printf("%i,", num);
        }
        printf("\n");
    }
    printf("\n");
}

SBP SBP::clone() //@violation CLONE_ONLY_FINAL
{
    SBP clonestate;
    clonestate.width = width;
    clonestate.height = height;
    for (int r = 0; r < height; ++r)
    {
        for (int c = 0; c < width; ++c)
            clonestate.state[r][c] = state[r][c];
    }
    return clonestate;
}

int main(int argc, char **argv)
{
    string filename = argv[1];
    SBP puzzle, clonestate;
    puzzle.load(filename);
    puzzle.display();
    clonestate = puzzle.clone();
    clonestate.display();

    return 0;
}