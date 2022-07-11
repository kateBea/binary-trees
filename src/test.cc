#include <iostream>
#include <bintree.h>

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

// postorder traverse
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