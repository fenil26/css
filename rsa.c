#include <stdio.h>

int inverse(int a, int m)
{
	a = a%m;
	int x;
	for(x=1;x<m;x++)
	{
		if((a*x)%m == 1)
			return x;
	}
}

int exponent(int x, int y, int n)
{
	int temp = 1;
	while(y)
	{
		if(y & 1)
		{
			temp = (temp * x) % n;
			y--;
		}
		else
		{
			x = (x*x) % n;
			y = y >> 1;
		}
	}
	return temp;
}

int encrpytDecrypt(int msg, int k, int n)
{
	int exp;
	exp = exponent(msg,k,n);
	return (exp % n);
}

void main()
{
	int p,q,n;
	int phi;
	int d;
	int e=13; 
	int val = 0;
	int msg,cipher,plain;
	printf("Enter p and q: ");
	scanf("%d",&p);
	scanf("%d",&q);
	n = p*q;
	phi = (p-1)*(q-1);
	printf("\ne: %d\n",e);
	d = inverse(e,phi);
	printf("\nd: %d\n",d);
	printf("\nEnter message: ");
	scanf("%d",&msg);
	cipher = encrpytDecrypt(msg,e,n);
	printf("\ncipher text: %d",cipher);	
	plain = encrpytDecrypt(cipher,d,n);
	printf("\nplain text: %d\n",plain);
}

