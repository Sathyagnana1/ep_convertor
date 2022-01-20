#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
    char keyword[200];
    struct node * llink;
    struct node * rlink;
};
typedef struct node * NODE;
struct op
{
    char out[100];
};
typedef struct op output;
struct python
{
    char pyth[100];
};
typedef struct python py;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if (x==NULL)
    {
        printf("memory not present\n");
        return NULL;
    }
    return x;
}
NODE insert(NODE list,char ele)
{
    NODE temp=getnode();
    NODE cur=NULL;
    cur=list;
    strcpy(temp->keyword,ele);
    temp->llink=NULL;
    temp->rlink=NULL;
    if (list->rlink==NULL)
    {
        return temp;
    }
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=list;
    list->llink=cur;
    return list;
}
void acceptinput(char psuedocode[100])
{
    scanf("%[^.]s",psuedocode);
    int len;
    len=strlen(psuedocode);
    psuedocode[len]='.';
    psuedocode[len+1]='\0';
}
void display(NODE first)
{
    NODE cur;
    cur=first;
    if(first==NULL)
    {
        printf("SLL is empty\n");
    }
    else
    {
        printf("SLL elements are:\n");
        while(cur!=NULL)
        {
            printf("sathya");
            printf("%d\t",first->keyword);
        }
    }
}
//process(char word[100])
//{
    //if(strcmp(word,"print")==0)
    //{
      //  printf("print(");



    //}
//}
int main()
{
    NODE oplist=NULL;
    char opt[100];
    output * op;
    int max=10;
    op=(output *)malloc(sizeof(struct op)*max);
    //py=(struct python*)malloc(sizeof(struct python)*max);
    char code[128];
    printf("Enter the psuedo code( press . to stop)\n");
    acceptinput(code);
    int i,j,n=0,k=0,l=0,m=0,o=0;
    int * lines;
    lines=(int *)malloc(sizeof(int)*max);
    char processed[100],rev[100];
    for (i=0;i<strlen(code)+1;i++)
    {
        if(code[i]==' '||code[i]=='.'||code[i]=='\n')
        {
            for (j=i-1;j>=k;j--)
            {
                processed[l]=code[j];
                l++;
            }
            k=i+1;
            strrev(processed);
            if (m==max)
            {
                max=max*2;
                op=(output *)realloc(op,sizeof(struct op)*max);
            }
            strcpy(op[m].out,processed);
            m++;
            if (code[i]=='.'||code[i]=='\n')
            {
                    lines[o]=m-1;
                    o++;
            }

            strcpy(processed,"");
            l=0;

        }
        }
        printf("\n");
        printf("\n");
        printf("HERE IS YOUR PYTHON CODE\n");
        printf("\n");
        for (i=0,j=0,o=0;i<m;m++,i++)
        {
            if(strcmp(op[i].out,"print")==0)
            {
                //j=strlen("printf")+3;
                printf("print(\"");
                //strcat(opt,"printf");
                //strcat(opt,"(\"");
                for(k=i+1;k<=lines[o];k++)
                {
                   // strcat(opt,op[k].out);
                   printf("%s",op[k].out);
                    //j=j+strlen(op[k].out);
                    if(k!=l)
                    {
                        printf(" ");
                        //opt[j]=" ";
                        //j++;
                    }
                }
                printf("\")");
                printf("\n");
                //strcat(opt,"\");");
                //j=j+2;
                //opt[j+1]="\0";
                o++;
            }

        }
        //printf("%d",strlen(opt));
     }



