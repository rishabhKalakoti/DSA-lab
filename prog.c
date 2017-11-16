#include<stdio.h>
#include<stdlib.h>
int main()
{
    int V;
    printf("num of vertices\n");
    scanf("%d", &V);
    
    int i=0;
    printf("no of edges\n");
    int e;
    scanf("%d", &e);
    
    int ed[V][V];
    int j=0;
    
    int p,q;  
    for(p=0;p<V;p++)
            for(q=0;q<V;q++)
                ed[p][q]=0;
    
    for(i=0; i<e;i++)
    {
        
        scanf("%d %d", &p, &q);
        ed[p][q]=1;
        ed[q][p]=1;
    }
    for(p=0;p<V;p++)
    {
        for(q=0;q<V;q++)
        {
            printf("%d ",ed[p][q]);
        }
        printf("\n");
    }
    int count;
    int flag=0;
    for(i=0; i<V;i++)
    {
        int edgeX[V][V];
        for(p=0;p<V;p++)
            for(q=0;q<V;q++)
                edgeX[p][q]=0;
        for(p=0;p<V;p++)
        {
            for(q=0;q<V;q++)
            {
                if(q!=i && p!=i)
                {
                    edgeX[p][q]=ed[p][q];
                }
           }
        }           
        count=0;
        int start;
        if(i==0 && V>=2)
            start=1;
        else
            start=0;
        int visited[V];
        for(q=0;q<V;q++)
                visited[q]=0;
        int Q[V];
        int qPtr=-1;
        for(q=0;q<V;q++)
            Q[q]=-1;
            
        //printf("X");
        visited[start]=1;
        Q[++qPtr]=start;
        while(qPtr>-1)
        {
            count++;
            start=Q[0];
            for(q=0;q<qPtr;q++)
                Q[q]=Q[q+1];
            qPtr--;
            for(q=0;q<V;q++)
            {
                if(edgeX[start][q]==1)
                {
                    if(visited[q]==0)
                    {
                        Q[++qPtr]=q;
                        visited[q]=1;
                    }
                }
            }
        }
        for(p=0;p<V;p++)
        {
            for(q=0;q<V;q++)
            {
                printf("%d ",edgeX[p][q]);
            }
            printf("\n");
        }
        printf("\t%d %d\n", i,count);
        if(count<V-1)
            flag=1;
    }
    if(flag==0)
        printf("Yes\n");
    else
        printf("No\n");
        
    return 0;
}
