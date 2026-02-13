void make_step() {/*step*/}

void run_for(int n)
{
    for (int i = 1; i <= n; i++)
    {
        make_step();
    }
}

void run_rec1(int n)
{
    if (n == 0) {return;}
    make_step();
    run_rec1(n - 1);
}

void run_rec2(int n)
{
    if (n == 1)
    {
        make_step();
        return;
    }
    run_rec2(n / 2);
    run_rec2(n - n / 2);
}


int main()
{
    int n = 10;

    run_for(n);
    run_rec1(n);
    run_rec2(n);

    return 0;
}