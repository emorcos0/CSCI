// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>

void moveStack(int diskQty, char src, char dst, char spr);
void moveDisk(char src, char dst);

int main(int argc, char const *argv[])
{
	moveStack(50, 'a', 'c', 'b');
	
	return 0;
}

void moveStack(int diskQty, char src, char dst, char spr)
{
    if(diskQty == 1)
        moveDisk(src, dst);
    else
    {
        moveStack(diskQty -1, src, spr, dst);
        moveDisk(src, dst);
        moveStack(diskQty - 1, spr, dst, src);
    }
}

void moveDisk(char src, char dst)
{
    std::cout << "Moved disk from pin " << src << " to pin " << dst << std::endl;
}