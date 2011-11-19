main(int b,char**d){
    int a,n,k=atoi(d[b-1]);
    for(n=1;n<b-1;n++){a*=k;a+=atoi(d[n]);}
    printf("%d\n",a);
}