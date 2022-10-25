int main(int argc, char const *argv[])
{
    int left{0};
    int right{1};

    ((right > left) ? right : left) = 5; // choosing which variable to assign 5 to
    return 0;
}
