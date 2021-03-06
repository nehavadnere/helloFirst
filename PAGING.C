/***************************************************************
ASSIGNMENT NO: 
TITLE                    : To implement Page Replacement Algorithms
NAME                    :  Neha Vadnere
START DATE        :
END DATE             :
**************************************************************/

#include<stdio.h>
#include<conio.h>
struct page
{
	int size;

}page1[20];

struct frame
{
	int id;
}frame1[10];

void main()
{
	int ch,i,j,p,f,k,l,l1,l1_fin,max,isempty,page_fault[20],number;
	int val[20][10],count[20][20],m,k1,cnt[20],done;
	int use[20][20],counter,ptr;
	char ans;

	printf("\n\n -------------------------------------------------\n\n");
	printf("\n                 PAGING ASSIGNMENT");

	do
	{
		clrscr();
		printf("\n\n MENU:\n\n");
		printf("\n 1.Create");
		printf("\n 2.FIFO");
		printf("\n 3.LRU");
		printf("\n 4.LFV");
		printf("\n 5.OPTIMAL");
		printf("\n 6.CHECK");
		printf("\n 7.EXIT");
		printf("\n\n\n Enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1://create:
			printf("\n\n INPUT:\n\n");
			printf("\n Enter no of pages : ");
			scanf("%d",&p);
			printf("\n Enter no of frames: ");
			scanf("%d",&f);
			printf("\n Enter page size for each page:\n");
			for(i=0;i<p;i++)
			{
				scanf("%d",&page1[i].size);
				//page1[i].count=0;
			}
			for(i=0;i<f;i++)
			{
				frame1[i].id=i+1;


			}
			break;

			case 2://FIFO

			for(i=0;i<p;i++)
			{
				page_fault[i]=1;
			}
			for(i=0;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					val[i][j]=-99;
					count[i][j]=0;
				}
			}
			val[0][0]=page1[0].size;
			for(i=1;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					/*if(val[i][j]==-99)
					{
						val[i][j]=page1[i].size;
						page1[i].count++;
						break;
					}*/
					val[i][j]=val[i-1][j];
					count[i][j]=count[i-1][j];
				}
				k=i;
				l=0;
				while(val[k][l]!=-99 && l<f)
				{
					count[k][l]++;
					l++;
				}
				k=i;
				l=0;
				for(l=0;l<f;l++)
				{
					if(val[k][l]==-99)
					{
						isempty=1;
						//break;
					}
					else
						isempty=0;
				}
				k=i;
				l=0;
				while(val[k][l]!=page1[i].size  && val[k][l]!=-99 && l<f)
				{
					l++;
				}
				if(l<f)
				{
					val[k][l]=page1[k].size;
					if(isempty==1)
						count[k][l]=0;
					else
						page_fault[k]=0;
						//count[k][l]++;
				}
				else
				{
					l1=0;
					max=count[k][l1];
					while(l1<f)
					{
						if(count[k][l1]>=max)
						{
							max=count[k][l1];
							l1_fin=l1;
						}
						l1++;
					}
					val[k][l1_fin]=page1[k].size;
					count[k][l1_fin]=0;
				}
			}
			printf("\n\n\nDISPLAY:\n\n");
			for(i=0;i<p;i++)
			{
				printf("%d   ",page1[i].size);
			}
			printf("\n -------------------------------------\n");
			for(i=0;i<f;i++)
			{
				for(j=0;j<p;j++)
				{
					if(val[j][i]!=-99)
						printf("%d   ",val[j][i]);
					else
						printf("    ");
				}
				printf("\n");
			}

			printf("\n");
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					printf("+   ");
				else
					printf("-   ");
			}
			number=0;
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					number++;
			}

			printf("\n\n\n\n NUMBER OF PAGE FAULTS:  %d ",number);
			break;

			case 3://LRU
			for(i=0;i<p;i++)
			{
				page_fault[i]=1;
			}
			for(i=0;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					val[i][j]=-99;
					//count[i][j]=0;
				}
			}
			val[0][0]=page1[0].size;
			for(i=1;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					/*if(val[i][j]==-99)
					{
						val[i][j]=page1[i].size;
						page1[i].count++;
						break;
					}*/
					val[i][j]=val[i-1][j];
					//count[i][j]=count[i-1][j];
				}
				k=i;
				l=0;
				while(val[k][l]!=-99 && l<f)
				{
					//count[k][l]++;
					l++;
				}
				k=i;
				l=0;
				for(l=0;l<f;l++)
				{
					if(val[k][l]==-99)
					{
						isempty=1;
						//break;
					}
					else
						isempty=0;
				}
				k=i;
				l=0;
				while(val[k][l]!=page1[i].size  && val[k][l]!=-99 && l<f)
				{
					l++;
				}
				if(l<f)
				{
					val[k][l]=page1[k].size;
					if(isempty==0)
						page_fault[k]=0;

				}
				else
				{
					/*l1=0;
					max=count[k][l1];
					while(l1<f)
					{
						if(count[k][l1]>=max)
						{
							max=count[k][l1];
							l1_fin=l1;
						}
						l1++;
					} */
					l1=k-f;
					for(m=0;m<f;m++)
					{
						if(val[k][m]==page1[l1].size)
						{
							l1_fin=m;
						}
					}
					val[k][l1_fin]=page1[k].size;
					count[k][l1_fin]=0;
				}
			}
			printf("\n\n\nDISPLAY:\n\n");
			for(i=0;i<p;i++)
			{
				printf("%d   ",page1[i].size);
			}
			printf("\n -------------------------------------\n");
			for(i=0;i<f;i++)
			{
				for(j=0;j<p;j++)
				{
					if(val[j][i]!=-99)
						printf("%d   ",val[j][i]);
					else
						printf("    ");
				}
				printf("\n");
			}

			printf("\n");
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					printf("+   ");
				else
					printf("-   ");
			}
			number=0;
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					number++;
			}

			printf("\n\n\n\n NUMBER OF PAGE FAULTS:  %d ",number);
			break;

			case 4://LFV
			break;

			case 5://Optimal

			for(i=0;i<p;i++)
			{
				page_fault[i]=1;
			}
			for(i=0;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					val[i][j]=-99;
					count[i][j]=0;
				}
			}
			val[0][0]=page1[0].size;
			for(i=1;i<p;i++)
			{
				for(j=0;j<f;j++)
				{

					val[i][j]=val[i-1][j];
					count[i][j]=count[i-1][j];
				}

				k=i;
				l=0;
				for(l=0;l<f;l++)
				{
					if(val[k][l]==-99)
					{
						isempty=1;
						//break;
					}
					else
						isempty=0;
				}
				k=i;
				l=0;
				while(val[k][l]!=page1[i].size  && val[k][l]!=-99 && l<f)
				{
					l++;
				}
				if(l<f)
				{
					val[k][l]=page1[k].size;
					if(isempty==1)
						count[k][l]=0;
					else
						page_fault[k]=0;
						//count[k][l]++;
				}
				else
				{
					for(l1=0;l1<f;l1++)
					{
						done=0;
						for(k1=k+1;k1<p;k1++)
						{
							if(val[k][l1]==page1[k1].size)
							{
								cnt[l1]=k1;
								done=1;
								break;
							}
						}
						if(done!=1)
							cnt[l1]=99;
					}
					max=cnt[0];
					l1=0;
					while(l1<f)
					{
						if(cnt[l1]>=max)
						{
							max=cnt[l1];
							l1_fin=l1;
						}
						l1++;
					}

					val[k][l1_fin]=page1[k].size;
					//count[k][l1_fin]=0;
				}
			}
			printf("\n\n\nDISPLAY:\n\n");
			for(i=0;i<p;i++)
			{
				printf("%d   ",page1[i].size);
			}
			printf("\n -------------------------------------\n");
			for(i=0;i<f;i++)
			{
				for(j=0;j<p;j++)
				{
					if(val[j][i]!=-99)
						printf("%d   ",val[j][i]);
					else
						printf("    ");
				}
				printf("\n");
			}

			printf("\n");
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					printf("+   ");
				else
					printf("-   ");
			}
			number=0;
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					number++;
			}

			printf("\n\n\n\n NUMBER OF PAGE FAULTS:  %d ",number);
			break;



			case 6://clock
			for(i=0;i<p;i++)
			{
				page_fault[i]=1;
			}
			for(i=0;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					val[i][j]=-99;
					use[i][j]=0;
				}
			}
			val[0][0]=page1[0].size;
			use[0][0]=1;
			ptr=1;
			for(i=1;i<p;i++)
			{
				for(j=0;j<f;j++)
				{
					val[i][j]=val[i-1][j];
					use[i][j]=use[i-1][j];
				}
				k=i;
				l=0;
				for(l=0;l<f;l++)
				{
					if(val[k][l]==-99)
					{
						isempty=1;
						//break;
					}
					else
						isempty=0;
				}

				k=i;
				l=0;
				while(val[k][l]!=page1[i].size  && val[k][l]!=-99 && l<f)
				{
					l++;
				}
				if(l<f)
				{
					if(val[i][l]==-99)
					{
						ptr++;
						if(ptr==f)
							ptr=0;

					}
					if(isempty==0 || val[i][l]==page1[i].size)
						page_fault[k]=0;

					val[i][l]=page1[i].size;
					use[i][l]=1;
					//break;
				}
				else
				{
					done=0;
					counter=0;
					do
					{
					if(use[i][ptr]==0)
					{
						val[i][ptr]=page1[i].size;
						use[i][ptr]=1;
						ptr++;
						if(ptr==f)
							ptr=0;
						//break;
						done=1;
					}
					else
					{
						use[i][ptr]=0;
						counter++;
						ptr++;
						if(ptr==f)
							ptr=0;



					}
					}while(counter<=f && done!=1);
				}
			}
			printf("\n\n\nDISPLAY:\n\n");
			for(i=0;i<p;i++)
			{
				printf("%d   ",page1[i].size);
			}
			printf("\n -------------------------------\n");
			for(i=0;i<f;i++)
			{
				for(j=0;j<p;j++)
				{
					if(val[j][i]!=-99)
						printf("%d   ",val[j][i]);
					else
						printf("    ");
				}
				printf("\n");
			}
			printf("\n");
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					printf("+   ");
				else
					printf("-   ");
			}
			number=0;
			for(i=0;i<p;i++)
			{
				if(page_fault[i]==1)
					number++;
			}

			printf("\n\n\n\n NUMBER OF PAGE FAULTS:  %d ",number);

			break;




			case 7://exit
			exit(0);

			default:
			printf("\n\n\nINVALID CHOICE");
		}
		printf("\n\n\n CONTINUE WITH MAIN MENU?(Y/N):  ");
		scanf("%s",&ans);
	}while(ans=='y');
	getch();
}