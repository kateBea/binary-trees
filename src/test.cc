#include <iostream>
#include <bintree.h>

// g++ -o main.exe test.cc -Wall -Wextra -std=c++17 -I C:\Users\zanet\Desktop\bt\binary-trees\src

void read(bintree<double>& bt)
{
    double input;

    std::cin >> input;

    if (input)
    {
        bintree<double> left;
        bintree<double> right;

        read(left);
        read(right);

        bt = bintree<double> (input, left, right);
    }
}

void write(const bintree<double>& bt)
{
    if (not bt.empty())
    {
        write(bt.left());
        write(bt.right());

        std::cout << bt.value() << std::endl;
    }
}

int main(int, char**)
{
    bintree<double> bt;

    read(bt);
    write(bt);

    

    return EXIT_SUCCESS;
}