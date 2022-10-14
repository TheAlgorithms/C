#include<stdio.h>
#include<conio.h>
int acc[100],Q[100],M[100],Mcomp[100],q=0,n1,n2,temp,count,i,j,c=0,temp1,ans[100];
void rightshift()
{
    q=Q[count-1];
    for(i=count-1; i>=1; i--)
    {
        Q[i]=Q[i-1];
    }
    Q[0]=acc[count-1];
    for(i=count-1; i>=1; i--)
    {
        acc[i]=acc[i-1];
    }
}
void addcomplement()
{
    c=0;
    for(i=count-1; i>=0; i--)
    {
        acc[i]=acc[i]+Mcomp[i]+c;
        if(acc[i]>1) c=1;
        else
        {
            c=0;
        }
        acc[i]=acc[i]%2;
    }
}
void add()
{
    c=0;
    for(i=count-1; i>=0; i--)
    {
        acc[i]=acc[i]+M[i]+c;
        if(acc[i]>1) c=1;
        else
        {
            c=0;
        }
        acc[i]=acc[i]%2;
    }
}
void display()
{
    printf("\n----------------------------------------------------------------------\n");
    for(i=0; i<=count-1; i++)
    {
        printf("%d",acc[i]);
    }
    printf("\t");
    for(i=0; i<=count-1; i++)
    {
        printf("%d",Q[i]);
    }
    printf("\t%d\t\t",q);
    for(i=0; i<=count-1; i++)
    {
        printf("%d",M[i]);
    }
    printf("\t%d\t",temp);
}
void initialize()
{
    i=count-1;
    temp=count;
    while(temp!=0)
    {
        acc[i]=0;

        Q[i]=n1%2;
        n1=n1/2;

        M[i]=n2%2;
        n2=n2/2;

        i--;
        temp--;
    }
    i=count-1;
    while(M[i]!=1&&i>=0)
    {
        Mcomp[i]=M[i];
        i--;
    }
    Mcomp[i]=1;
    i--;
    for(; i>=0; i--)
    {
        if(M[i]==1) Mcomp[i]=0;
        else Mcomp[i]=1;
    }
}
void main()
{
    printf("Enter 2 numbers between -128 to 127: ");
    scanf("%d %d",&n1,&n2);
	printf("\n\n");
    count=8;
    if(n1<0&&n2<0)
    {
        n1=-n1;
        n2=-n2;
        initialize();
        for(i=0;i<=count-1;i++)
        {
            temp=Mcomp[i];
            Mcomp[i]=M[i];
            M[i]=temp;
        }
        i=count-1;
        while(Q[i]!=1&&i>=0)
        {
            i--;
        }
        Q[i]=1;
        i--;
        for(; i>=0; i--)
        {
            if(Q[i]==1) Q[i]=0;
            else Q[i]=1;
        }
    }
    else if(n1<0)
    {
        n1=-n1;
        initialize();
        i=count-1;
        while(Q[i]!=1&&i>=0)
        {
            i--;
        }
        Q[i]=1;
        i--;
        for(; i>=0; i--)
        {
            if(Q[i]==1) Q[i]=0;
            else Q[i]=1;
        }
    }
    else if(n2<0)
    {
        n2=-n2;
        initialize();
        for(i=0;i<=count-1;i++)
        {
            temp=Mcomp[i];
            Mcomp[i]=M[i];
            M[i]=temp;
        }
    }
    else initialize();
    temp=count;
    printf("A\t\tQ\t\tQ(-1)\t\tM\t\tCount");
    display();
    temp--;
    while(temp!=-1)
    {
        if((q==0&&Q[count-1]==0)||(q==1&&Q[count-1]==1))
        {
            rightshift();
        }
        else if(q==0&&Q[count-1]==1)
        {
            addcomplement();
            rightshift();
        }
        else if(q==1&&Q[count-1]==0)
        {
            add();
            rightshift();
        }
        display();
        temp--;
    }
    printf("\n\n");
    j=0;
    for(i=0;i<=7;i++,j++)
    {
        ans[j]=acc[i];
    }
    for(i=0;i<=7;i++,j++)
    {
        ans[j]=Q[i];
    }
    if(ans[0]==1)
    {
        i=15;
        while(ans[i]!=1&&i>=0)
        {
            i--;
        }
        ans[i]=1;
        i--;
        for(; i>=0; i--)
        {
            if(ans[i]==1) ans[i]=0;
            else ans[i]=1;
        }
        printf("\nFinal Answer in binary is: -(");
        for(i=0;i<=15;i++)
        {
            printf("%d",ans[i]);
        }
         printf(")");
    }
    else
    {
        printf("\n\nFinal answer/ Quotient in binary is: (");
        for(i=0;i<=15;i++)
        {
            printf("%d",ans[i]);
        }
        printf(")");
    }
    getch();
}
