#include <iostream>

inline void moveDisk(int disk, char from, char to)
{
    std::cout << "Move disk <" << disk << "> from <" << from << "> to <" << to << ">\n";
}

void hanoi(int n, char from, char to, char aux);

int main()
{
    constexpr int NUM_DISKS = 3;
    hanoi(NUM_DISKS, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char from, char to, char aux)
{
    // base case; move one disk
    if (n == 1)
    {
        moveDisk(1, from, to);
        return;
    }

    // move (n - 1) disks from (from) to (aux)
    hanoi(n - 1, from, aux, to);
    // now the remaining disk in (from) is biggest one
    // move biggest disk from (form) to (to)
    moveDisk(n, from, to);
    // move (n - 1) disks from (aux) to (to)
    hanoi(n - 1, aux, to, from);
}
