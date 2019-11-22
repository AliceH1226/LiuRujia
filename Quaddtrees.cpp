//2 1
//3 4
//p median node  e empty node  f black node
//quadtrees
//calculate the number of black pixels it is one pixel if the one node is black
//the whole 2 1 3 4 represents the root note




#include<cstdio>
#include<cstring>

const int len=32;
const int maxn=1024+10;
char s[maxn];
int buf[len][len],cnt;

//s[p..]  length of side is w   (r,c) represents the cordinate of the top left square(one node)
void draw(const char* s, int& p,int r, int c, int w)
{
    char ch=s[p++];
    if(ch=='p')
    {
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }else if(ch=='f'){
        for(int i=r;i<r+w;i++)
            for(int j=c;j<c+w;j++)
        if(buf[i][j]==0){buf[i][j]=1;cnt++;}
    }
}

int main()
{
    freopen("C:\\Users\\lenovo\\Desktop\\tmp.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        memset(buf,0,sizeof(buf));
        cnt=0;
        for(int i=0;i<2;i++)
        {
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    fclose(stdin);
}


input
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe

output
There are 640 black pixels.
There are 512 black pixels.
There are 384 black pixels.
