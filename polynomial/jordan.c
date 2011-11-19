int main(int argc, char** argv){
    int a;
    int n;
    int k = atoi(argv[argc-1]);
    for (n = 1; n < argc - 1; n++) {
        a *= k;
        a += atoi(argv[n]); 
    }
    printf("%d\n", a);
}