/*FCSFS DISC*/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
       int arr[n];
       for(int i=0;i<n;i++){
        	   scanf("%d",&arr[i]);
       }
       int head;
       printf("enter head");
       scanf("%d",&head);
       int sum=0;
       for(int i=0;i<n;i++){
           sum+=abs(head-arr[i]);
           head=arr[i];
       }
       printf("total head movements");
       printf("%d",sum);
       
}

/*SCAN DISC*/
 #include <stdio.h> 
 #include <stdlib.h> 

  // This function is used in qsort to decide the relative order 
  // of elements at addresses p and q. 
  int comparator(const void *p, const void *q) 
   { 
      return (*(int*)p-*(int*)q);
      } 

  // A utility function to print an array 
  void printArr(int arr[], int n) 
  { 
     int i; 
     for (i = 0; i < n; ++i) 
     printf("%d ", arr[i]); 
  }  

  // Driver program to test above function 
  int main() 
  { 
     int n;
     scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++){
     	scanf("%d",&arr[i]);
     }
     qsort((void*)arr, n, sizeof(arr[0]), comparator); 
     printf("enter disc size is\n"); 
     //printArr(arr, n);  
     int disc;
     scanf("%d",&disc);
     int head;
      printf("head is at\n"); 
     scanf("%d",&head);
     int index=0;
     for(int i=0;i<n;i++){
        if(arr[i]>=head){
                   index=i;
        		break;
        }
     }
      if(arr[index]!=head){
        printf("%d->",head);
     }
     for(int i=index;i<n;i++){
         printf("%d->",arr[i]);
     }
     if((disc-1)!=arr[n-1]){
         printf("%d->",disc-1);
     }
     if(index-1>=0){
   	  for(int i=index-1;i>=0;i--){
       		 printf("%d->",arr[i]);
     	 }
     }
     int sum=((disc-1)-head)+((disc-1)-arr[0]);
     printf("head movements:%d",sum);
     
    return 0; 
   }  

/*CSCAN*/  

 #include <stdio.h> 
 #include <stdlib.h> 
 
  int comparator(const void *p, const void *q) 
   { 
      return (*(int*)p-*(int*)q);
      } 


  int main() 
  { 
     int n;
     scanf("%d",&n);
     int arr[n];
     for(int i=0;i<n;i++){
     	scanf("%d",&arr[i]);
     }
     qsort((void*)arr, n, sizeof(arr[0]), comparator); 
     printf("enter disc size is\n"); 
     
     int disc;
     scanf("%d",&disc);
     int head;
      printf("head is at\n"); 
     scanf("%d",&head);
     int index=0;
     for(int i=0;i<n;i++){
        if(arr[i]>=head){
                  index=i;
        		break;
        }
     }
     if(arr[index]!=head){
        printf("%d->",head);
     }
     for(int i=index;i<n;i++){
         printf("%d->",arr[i]);
     }
     if((disc-1)!=arr[n-1]){
         printf("%d->",disc-1);
     }
     if(arr[0]!=0){
         printf("0->");
     }
     for(int i=0;i<=index-1;i++){
        printf("%d->",arr[i]);
     }
     int sum2=0;
     if(index!=0){
       sum2=arr[index-1];
     }
     int sum=((disc-1)-head)+((disc-1))+sum2;
     printf("head movements%d:",sum);
     
    return 0; 
   }  
   
 /*SSTF*/	
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(){
         int n;
	scanf("%d",&n);
       int arr[n];
       for(int i=0;i<n;i++){
        	   scanf("%d",&arr[i]);
       }
       int head;
       printf("enter head");
       scanf("%d",&head);
       int sum=0;
       int vis[n];
       memset(vis,0,sizeof(vis));
       for(int i=0;i<n;i++){
           int min=INT_MAX;
           int index=0;
          for(int j=0;j<n;j++){
               if((abs(arr[j]-head)<=min)&&vis[j]==0){
                     min=abs(arr[j]-head);
                     index=j;

               }
          }
          printf("min:%d\n",min);
          sum=sum+min;
          head=arr[index];
          vis[index]=1;
       }
       printf("total head movements");
       printf("%d",sum);
       
}
/*FIFO REP*/
#include<stdio.h>
#include<string.h>
int n;
int m;
int pf=0;
int ph=0;
int front=-1;
//int rear=-1;
void check(int arr[],int val){
  int found=0;
   for(int i=0;i<n;i++){     
         if(arr[i]==-1){
            pf++;
            arr[i]=val;
             found=1;
            break;
         }
         else{
           if(arr[i]==val){
             ph++;
             found=1;
             break;
           }  
         }      
   }
   if(found==0){
      front++;
      arr[front]=val;
      pf++;
      if(front==n-1){
        front=-1;
      }
   }
}
int main(){
  scanf("%d",&n);
  int arr[n];
  memset(arr,-1,sizeof(arr));
  scanf("%d",&m);
  int res[m];
  for(int i=0;i<m;i++){
    scanf("%d",&res[i]);
  }
  //int count=0;
  for(int i=0;i<m;i++){
     check(arr,res[i]);
  }
  printf("%d",pf);
return 0;

}

/*lRU*/

#include<stdio.h>
#include<string.h>
int n;
int m;
int pf=0;
int ph=0;
int front=-1;
//int rear=-1;
void check(int arr[],int val,int index,int res[]){
  int found=0;
   for(int i=0;i<n;i++){
     
         if(arr[i]==-1){
            pf++;
            arr[i]=val;
             found=1;
            break;
         }
         else{
           if(arr[i]==val){
             ph++;
             found=1;
             break;
           }  
         }      
   }
   if(found==0){
       int temp[n];
       for(int i=0;i<n;i++){
          temp[i]=arr[i];
       }
       int count=0;
    //   while(found2){
          for(int i=index-1;i>=0;i--){
             for(int j=0;j<n;j++){
                if(res[i]==temp[j]){
                   temp[j]=-1;
                   count++;
                   if(count==n-1){
                        break;
                   }
                 
                }
            }
             if(count==n-1){
                        break;
                   }
                 
         } 
         /* if(count==n-1){
                        break;
                   }*/
                 
   //  }
      for(int i=0;i<n;i++){
         if(temp[i]!=-1){
            arr[i]=val;
            break;
         }
      }
      pf++;
    
   }
  // printf("%d pfnum %d",res[i],pf);
}
int main(){
  scanf("%d",&n);
  int arr[n];
  memset(arr,-1,sizeof(arr));
  int front=-1;
  int rear=-1;
  scanf("%d",&m);
  int res[m];
  for(int i=0;i<m;i++){
    scanf("%d",&res[i]);
  }
  int count=0;
  for(int i=0;i<m;i++){
     check(arr,res[i],i,res);
  }
  printf("%d",pf);
return 0;
}


//CPU SCHEDULING 
//fcfs
#include<stdio.h>
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int n;
int main(){
   scanf("%d",&n);
   int p[n];
   int at[n];
   int bt[n];
   int ct[n];
   int tat[n];
   int wt[n];
   for(int i=0;i<n;i++){
      scanf("%d%d%d",&p[i],&at[i],&bt[i]);
     // printf("inloop");
   }
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
          if(at[j]>at[j+1]){
              swap(&at[j],&at[j+1]);
              swap(&p[j],&p[j+1]); 
              swap(&bt[j],&bt[j+1]);
           
          }
      }
   }
   int arrival=0;
   for(int i=0;i<n;i++){
       if(at[i]<=arrival){
            ct[i]=arrival+bt[i];
            printf("p%d (%d %d)->",p[i],arrival,ct[i]);
            arrival=ct[i];
       }
       else{
           int x=arrival;
           printf("IDLE (%d %d)->",arrival,at[i]);
           arrival=at[i];
           ct[i]=arrival+bt[i];
           printf("p%d (%d %d)->",p[i],arrival,ct[i]);
           arrival=ct[i];   
       }
   }
return 0;
}
//sjf

#include<stdio.h>
#include<string.h>
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int n;
int findminburst(int bt[],int at[],int arrival,int v[]){
    int min=99999;
    int index=-1;
    for(int i=0;i<n;i++){
       if(at[i]<=arrival&&bt[i]<min&&v[i]==0){
            min=bt[i];
            index=i;
       }
    }
    return index;
}
int findnext(int at[],int arrival){
    for(int i=0;i<n;i++){
      if(at[i]>arrival){
         return i;
      }
    }
}
int main(){
   scanf("%d",&n);
   int p[n];
   int at[n];
   int bt[n];
   int ct[n];
   int tat[n];
   int wt[n];
   for(int i=0;i<n;i++){
      scanf("%d%d%d",&p[i],&at[i],&bt[i]);
     // printf("inloop");
   }
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
          if(at[j]>at[j+1]){
              swap(&at[j],&at[j+1]);
              swap(&p[j],&p[j+1]); 
              swap(&bt[j],&bt[j+1]);
           
          }
      }
   }
   int arrival=0;
   int v[n];
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
      int z=findminburst(bt,at,arrival,v);
      if(z!=-1){
            int x=arrival;
            ct[z]=arrival+bt[z];
            arrival+=bt[z];
            v[z]=1;
            printf("p%d %d %d->",p[z],x,arrival);
      }
      else{
          int k=findnext(at,arrival);
          printf("IDLE (%d %d )->",arrival,at[k]);
          arrival=at[k];
          ct[k]=arrival+bt[k];
          printf("p%d %d %d->",p[z],arrival,arrival+ct[k]);
          arrival=ct[k];         
       }
   }
return 0;
}

//Non premp prior
#include<stdio.h>
#include<string.h>
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int n;
int findminburst(int pt[],int at[],int arrival,int v[]){
    int min=99999;
    int index=-1;
    for(int i=0;i<n;i++){
       if(at[i]<=arrival&&pt[i]<min&&v[i]==0){
            min=pt[i];
            index=i;
       }
    }
    return index;
}
int findnext(int at[],int arrival){
    for(int i=0;i<n;i++){
      if(at[i]>arrival){
         return i;
      }
    }
}
int main(){
   scanf("%d",&n);
   int p[n];
   int at[n];
   int bt[n];
   int ct[n];
   int pt[n];
   int tat[n];
   int wt[n];
   for(int i=0;i<n;i++){
      scanf("%d%d%d%d",&p[i],&pt[i],&at[i],&bt[i]);
     // printf("inloop");
   }
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
          if(at[j]>at[j+1]){
              swap(&at[j],&at[j+1]);
              swap(&p[j],&p[j+1]); 
              swap(&bt[j],&bt[j+1]);
              swap(&pt[j],&pt[j+1]);
           
          }
      }
   }
   int arrival=0;
   int v[n];
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
      int z=findminburst(pt,at,arrival,v);
      if(z!=-1){
            int x=arrival;
            ct[z]=arrival+bt[z];
            arrival+=bt[z];
            v[z]=1;
            printf("p%d %d %d->",p[z],x,arrival);
      }
      else{
          int k=findnext(at,arrival);
          printf("IDLE (%d %d )->",arrival,at[k]);
          arrival=at[k];
          ct[k]=arrival+bt[k];
          printf("p%d %d %d->",p[z],arrival,arrival+ct[k]);
          arrival=ct[k];         
       }
   }
return 0;
}


/*srtf*/
#include<stdio.h>
#include<string.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int findminburst(int at[],int bt[],int n,int arrival){
  int k=-1;
  int min=9999;
  for(int i=0;i<n;i++){
    if(at[i]<=arrival&&bt[i]!=0&&bt[i]<min){
        min=bt[i];
        k=i;
    }
  }
  return k;

}
int findnextarrival(int at[],int n,int arrival){
      //int index;
      for(int i=0;i<n;i++){
         if(at[i]>arrival){
            return i;
         }
      }
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n];
    int bt[n];
    int at[n];
    int count=0;
    for(int i=0;i<n;i++){
            scanf("%d %d %d",&p[i],&at[i],&bt[i]);
            count+=bt[i];

    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]>at[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
               }
           }
    }
    int bt1[n];
      for(int i=0;i<n;i++){
          bt1[i]=bt[i];
    }
    int arrival=0;
    int ct[n];
    memset(ct,0,sizeof(ct));
    printf("\n");
    while(count!=0){
       int z=findminburst(at,bt,n,arrival);
       if(z!=-1){
       
           bt[z]=bt[z]-1;
           int y=arrival;
           arrival+=1;
           ct[z]=arrival;
           printf("p%d(%d %d)--",p[z],y,arrival);
           count--;
       }
       else{
          int l=findnextarrival(at,n,arrival);
          int x=arrival;
          arrival= arrival+at[l]-arrival;
          printf("idle (%d %d)--",x,arrival);
       }
    }
    printf("\nTABLE\n");
    int tat[n];
    int wt[n];
    int tsum=0;
    int wsum=0;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt1[i];
        tsum+=tat[i];
        wsum+=wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
    }
    printf("average tat%f average wat%f",(float)tsum/(float)n,(float)wsum/(float)n);
return 0;
}

/*roundrobin*/

#include<stdio.h>
#include<string.h>
int arr[10000];
int front=-1;
int rear=-1;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void enqueue(int element){
     if(rear==9999){
        printf("queue full");
     }
     else{
        rear++;
        arr[rear]=element;
     }
}
int dequeue(){
    front++;
    int element=arr[front];
    return element;
}
int isempty(){
      if(front==rear){
         return 1;
      }
      else{
         return 0;
      }
}
int check(int n){
 int found=1;
  for(int i=front+1;i<=rear;i++){
     if(arr[i]==n){
        found=0;
        break;
     }
  }
  return found;
}
int main(){
      
          int n;
   scanf("%d",&n);
    int pn[n];
   int at[n];
   int bt[n];
   int ct[n];
   int visited[n];
   int count=0;
   memset(visited,0,sizeof(visited));
    memset(ct,0,sizeof(ct));
   for(int i=0;i<n;i++){
      scanf("%d",&pn[i]);
      scanf("%d",&at[i]);
      scanf("%d",&bt[i]);
      count+=bt[i];
   } 
   printf("before sorting\n");  
    for(int i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   } 
   for(int i=0;i<n-1;i++){
      for(int j=0;j<n-i-1;j++){
           if(at[j]>at[j+1]){
                  swap(&at[j+1],&at[j]);
                  swap(&bt[j+1],&bt[j]);
                  swap(&pn[j+1],&pn[j]);
           }
      }
   }
      int bt1[n];
   for(int i=0;i<n;i++){
      bt1[i]=bt[i];
   }
   int arrival=0;
  // printf("%d\n",count);
   int qt=2;
   printf("\n");
   printf("after sorting \n"); 
    for(int i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   }
   printf("\n");
   int c=n;
   
   enqueue(0);
   int index;
   int flag=0;
   int prev;
    if(at[0]>arrival&&flag==0){
                 prev=arrival;
                  arrival=arrival+at[index];
                     printf("IDLE(%d %d)",prev,arrival);
                  flag=1;
    }
 while(c!=0){
         index=dequeue();
         // printf("index =%d\t",index);
         if(at[index]<=arrival){
           
             if(bt[index]>=qt){
                 //ct[index]=ct[index]+qt;
                  ct[index]=arrival+qt;
                  bt[index]-=qt;
                  prev=arrival;
                  arrival+=qt;
                // printf("arrival%d\t",arrival);
                  printf("p%d (%d-%d)\t",pn[index],prev,arrival);
                  if(bt[index]==0){
                     c--;
                  }
                    if(c==0){
                     break;
                 }
             }
             else{
                 ct[index]=arrival+bt[index];
                 c--;
                   prev=arrival;
                  arrival+=bt[index];
                    printf("p%d (%d-%d)\t",pn[index],prev,arrival);
                 bt[index]=0;
                 if(c==0){
                     break;
                 }
                
                 
             }
             for(int i=0;i<n;i++){
                 if(i!=index&&at[i]<=arrival&&bt[i]!=0&&check(i)){
                     enqueue(i);
                    // printf("yes");            
                 }
             }
            if(isempty()){
              
              int y;
             for(int i=0;i<n;i++){
                   	if(bt[i]!=0){
                       	
                       	y=i;
                      		break;
                  	}
             }
             if(y!=index){
               printf("IDLE");
               arrival=arrival+(at[y]-arrival);
             }
             enqueue(y);
            
            }
             else {
                 if(bt[index]!=0){
                  enqueue(index);
                 }
             }
       }   
      /*  else{
             printf("IDLE\t");
             for(int i=0;i<n;i++){
                   if(at[i]<=arrival&&bt[i]!=0){
                       arrival=arrival+at[i];
                       index=i;
                       break;
                   }
             }
             enqueue(index);
         }  */ 
   }
       
      
        /**/
 //}
  
  
    int tat[n];
    int wt[n];
      int avgtat=0;
    int avgwt=0;
    printf("\n");
    printf("PN\tAT\tBT\tCT\tTAT\tWT \n");
    for(int i=0;i<n;i++){
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt1[i];
        avgtat+=tat[i];
       avgwt+=wt[i];
      printf("%d	%d	%d	%d	%d	%d \n",pn[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
   } 
        //printf("queue:");
        //display(&q);
  // }*//
return  0;
}

/*premptive priority*/

 #include<stdio.h>
#include<string.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int findminburst(int at[],int pt[],int bt[],int n,int arrival){
  int k=-1;
  int min=9999;
  int minprior=100;
  for(int i=0;i<n;i++){
    if(at[i]<=arrival&&bt[i]!=0&&pt[i]<minprior){
       // min=bt[i];
        k=i;
        minprior=pt[i];
    }
  }
  return k;

}
int findnextarrival(int at[],int n,int arrival){
      //int index;
      for(int i=0;i<n;i++){
         if(at[i]>arrival){
            return i;
         }
      }
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n];
    int pt[n];
    int bt[n];
    int at[n];
    int count=0;
    for(int i=0;i<n;i++){
            scanf("%d %d %d %d",&p[i],&pt[i],&at[i],&bt[i]);
            count+=bt[i];

    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]>at[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&pt[j],&pt[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
               }
           }
    }
    for(int i=0;i<n-1;i++){
           for(int j=0;j<n-i-1;j++){
               if(at[j]==at[j+1]){
                 if(bt[j]>bt[j+1]){
                  swap(&at[j],&at[j+1]);
                  swap(&pt[j],&pt[j+1]);
                  swap(&p[j],&p[j+1]);
                  swap(&bt[j],&bt[j+1]);
                  }
               }
           }
    }
    int bt1[n];
      for(int i=0;i<n;i++){
          bt1[i]=bt[i];
    }
    int arrival=0;
    int ct[n];
    memset(ct,0,sizeof(ct));
    printf("\n");
    while(count!=0){
       int z=findminburst(at,pt,bt,n,arrival);
       if(z!=-1){
       
           bt[z]=bt[z]-1;
           int y=arrival;
           arrival+=1;
           ct[z]=arrival;
           printf("p%d(%d %d)--",p[z],y,arrival);
           count--;
       }
       else{
          int l=findnextarrival(at,n,arrival);
          int x=arrival;
          arrival= arrival+at[l]-arrival;
          printf("idle (%d %d)--",x,arrival);
       }
    }
      printf("\nTABLE\n");
    int tat[n];
    int wt[n];
    int tsum=0;
    int wsum=0;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt1[i];
        tsum+=tat[i];
        wsum+=wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt1[i],ct[i],tat[i],wt[i]);
    }
    printf("average tat%f average wat%f",(float)tsum/(float)n,(float)wsum/(float)n);
   
return 0;
}
/*	Bankers*/

#include<stdio.h>

int main(){
   int m;
   scanf("%d",&m);
      int n;
   scanf("%d",&n);
   int all[m][n];
   int max[m][n];
   for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
           scanf("%d",&all[i][j]);
      }
   }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
           printf("%d",all[i][j]);
      }
      printf("\n");
   }
   printf("max\n");
   for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
           scanf("%d",&max[i][j]);
      }
   }
   int need[m][n];
   for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
           need[i][j]=max[i][j]-all[i][j];
      }
   }
    int avail[1][3];
     avail[0][0]=3;
     avail[0][1]=3;
     avail[0][2]=2;
    int visited[m];
    for(int i=0;i<m;i++){
       visited[i]=0;
    }
    for(int k=0;;k++){
         int found=0;
  	  for(int i=0;i<m;i++){
    		  int count=0;
     		 for(int j=0;j<n;j++){
          		if(need[i][j]<=avail[0][j]){
             		count++;
          	}      
     	 }
       if(count==n&&visited[i]==0){
          visited[i]=1; 
          avail[0][0]+=all[i][0];
          avail[0][1]+=all[i][1];
          avail[0][2]+=all[i][2];
          printf("p%d\n",i);
          found=1;    
        }
      }
      if(found!=1){
       break;
      }
   }
return 0;
}


//partitoining
//fcfs
#include<stdio.h>
#include<string.h>
int main(){
  int n;
  scanf("%d",&n);
  int p[n];
   int m;
  scanf("%d",&m);
  int b[m];
  for(int i=0;i<n;i++){
     scanf("%d",&p[i]);
  }
  for(int i=0;i<m;i++){
     scanf("%d",&b[i]);
  }
  int v[m];
  int pv[n];
  memset(v,0,sizeof(v));
  memset(pv,0,sizeof(pv));
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
               if(p[i]<=b[j]&&v[j]==0){
                   b[j]-=p[i];
                   printf("p%d->b%d\n",i+1,j+1);
                   v[j]=1;
                   pv[i]=1;
                   break;
               }
 	 }
  }
  int sum=0;
  printf("internal fragmentations\n");
  for(int i=0;i<m;i++){
     if(v[i]==1){
         printf("block %d %d\n",i+1,b[i]);
     }else{
         sum+=b[i];
     }
  }
  int  found=0;
  for(int i=0;i<n;i++){
    if(pv[i]==0&&p[i]<=sum){
       found=1;
    }
  }
  if(found==1){
     printf("external fragmentation%d",sum);
  }
return 0;
}
//bestfit

#include<stdio.h>
#include<string.h>
#include<limits.h>
int main(){
  int n;
  scanf("%d",&n);
  int p[n];
   int m;
  scanf("%d",&m);
  int b[m];
  printf("enter the process sizes\n");
  for(int i=0;i<n;i++){
     scanf("%d",&p[i]);
  }
  printf("enter the block sizes\n");
  for(int i=0;i<m;i++){
     scanf("%d",&b[i]);
  }
  int v[m];
  int pv[n];
  memset(v,0,sizeof(v));
  memset(pv,0,sizeof(pv));
  for(int i=0;i<n;i++){
        int min=INT_MAX;
        int flag=0;
        int index;
  	for(int j=0;j<m;j++){
               if(p[i]<=b[j]&&v[j]==0){
                  flag=1;
                  if(b[j]-p[i]<min){
                     min=b[j]-p[i];
                     index=j;
                  }
               }
 	 }
 	 if(flag==1){
 	   b[index]-=p[i];
                   printf("p%d->b%d\n",i+1,index+1);
                   v[index]=1;
                   pv[i]=1;
                  // break;
        }           
  }
  int sum=0;
  printf("internal fragmentations\n");
  for(int i=0;i<m;i++){
     if(v[i]==1){
         printf("block %d %d\n",i+1,b[i]);
     }else{
         sum+=b[i];
     }
  }
  int  found=0;
  for(int i=0;i<n;i++){
    if(pv[i]==0&&p[i]<=sum){
       found=1;
    }
  }
  if(found==1){
     printf("external fragmentation%d",sum);
  }
return 0;
}

//worst




//variable fcfs
#include<stdio.h>
#include<string.h>
int main(){
   int n;
   printf("enter number of processes");
   scanf("%d",&n);
    int m;
   printf("enter number of blocks");
   scanf("%d",&m);
   int p[n];
   int b[m];
   printf("enter the processes");
   for(int i=0;i<n;i++){
       scanf("%d",&p[i]);
   }
   printf("enter the block sizes");
   for(int i=0;i<m;i++){
         scanf("%d",&b[i]);
   }
   int found=0;
   int i=0;//block
   int j=0;//process
   int v[n];
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
          if(p[i]<=b[j]){
              printf("p%d->b%d ",i+1,j+1);
              b[j]=b[j]-p[i];
              v[i]=1;
              break;
          }
          
   }
   } 
return 0;
}

//variable bestfit

#include<stdio.h>
#include<string.h>
int main(){
   int n;
   printf("enter number of processes");
   scanf("%d",&n);
    int m;
   printf("enter number of blocks");
   scanf("%d",&m);
   int p[n];
   int b[m];
   printf("enter the processes");
   for(int i=0;i<n;i++){
       scanf("%d",&p[i]);
   }
   printf("enter the block sizes");
   for(int i=0;i<m;i++){
         scanf("%d",&b[i]);
   }
   int found=0;
   int i=0;//block
   int j=0;//process
   int v[n];
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
          if(p[i]<=b[j]){
              printf("p%d->b%d ",i+1,j+1);
              b[j]=b[j]-p[i];
              v[i]=1;
              break;
          }
          
   }
   } 
return 0;
}

//worstvariable
#include<stdio.h>
#include<string.h>
int main(){
   int n;
   printf("enter number of processes");
   scanf("%d",&n);
    int m;
   printf("enter number of blocks");
   scanf("%d",&m);
   int p[n];
   int b[m];
   printf("enter the processes");
   for(int i=0;i<n;i++){
       scanf("%d",&p[i]);
   }
   printf("enter the block sizes");
   for(int i=0;i<m;i++){
         scanf("%d",&b[i]);
   }
   int found=0;
   int i=0;//block
   int j=0;//process
   int v[n];
   memset(v,0,sizeof(v));
   for(int i=0;i<n;i++){
      int found=0;
      int min=-1;
      int index;
      int flag=0;
       for(int j=0;j<m;j++){
          if(p[i]<=b[j]){
             if(b[j]-p[i]>min){
               min=b[j]-p[i];
               index=j;
               flag=1;
             }
          }
          
   }
   if(flag==1){
     printf("p%d->b%d ",i+1,index+1);
              b[index]=b[index]-p[i];
              v[index]=1;
   }
   } 
return 0;
}
