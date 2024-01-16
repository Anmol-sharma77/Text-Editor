#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Node
{
	public:
	char data[1000];
	Node* next;
};
class Track
{
	public:
		int history;
		int post;
		Track* next; 
};
Track* Hhead=NULL;
Track* Hhead2=NULL;
Node * head=NULL;
Node* head2=NULL;
Node* head3=NULL;
Node*head4=NULL;
char savestr[100];
void insertdata(char *s)
{
	Hhead2=NULL;
   	Node* temp;
   	Track* node1=new Track();
   	node1->history=1;
   	node1->post=1;
   	node1->next=Hhead;
   	Hhead=node1;
   	Node* node=new Node();
   	strcpy(node->data,s);
   	if(head==NULL)
   	{
   	    node->next=NULL;
   	   	head=node;
	}
    else
    {
     	temp=head;
		while(temp->next!=NULL)
	    {
	     	temp=temp->next;
		}
		node->next=temp->next;
		temp->next=node;
	}
	cout<<">>>>>Task performed<<<<<";
	getch();
	return ;
}
void show()
{
	if(head==NULL)
	{
		cout<<">>>>>Your document is empty<<<<<";
		return;
	}
	Node* temp;
	temp=head;
	while(temp!=NULL)
    {
     	cout<<temp->data<<endl;
     	temp=temp->next;
	}
}
void update(int n,char *s)
{
	Hhead2=NULL;
	Node* temp=head;
	Node* node1=new Node();
	Track* node=new Track();
	int count=1;
	Node* temp2;
	node->history=2;
	node->post=n;
	while(temp!=NULL)
	{
		if(count==n)
		{
			strcpy(node1->data,temp->data);
			strcpy(temp->data,s);
			node1->next=head4;
			head4=node1;
			node->next=Hhead;
			Hhead=node;
			cout<<">>>>>Task performed<<<<<";
			getch();
			return;
		}
		temp=temp->next;
		count++;
	}
	cout<<">>>>>There is nothing to update<<<<<";
	getch();
}
void append_data(int n,char *s)
{
	Hhead2=NULL;
    Node* temp=head;
	int count=1;
	Node* node1=new Node();
	Track* node=new Track();
	node->history=3;
	node->post=n;
	while(temp!=NULL)
	{
		if(count==n)
		{
			strcpy(node1->data,temp->data);
			strcat(temp->data,s);
			node1->next=head4;
			head4=node1;
			node->next=Hhead;
			Hhead=node;
			cout<<">>>>>Task performed<<<<<";
			getch();
			return;
		}
		temp=temp->next;
		count++;
	}	
	cout<<">>>>>There is nothing to Append<<<<<";
	getch();
}
int search(char *s)
{
	char *find;
	int count=1,c=0,len1,len2,pos;
	Node* temp=head;
	while(temp!=NULL)
	{
		if(strstr(temp->data,s)!=NULL)
		{
			len2=strlen(s);
			cout<<"Found in row:"<<count<<endl;
			c++;
		    find=temp->data;
		    len1=strlen(temp->data); 
            while ((strstr(find, s))!=NULL) 
		    {
		    	find=strstr(find, s);
			    pos=len1-strlen(find);
			    cout<<"Found at position:"<<pos+1<<endl;
                find += len2;
            }
	    }
	    count++;
	    temp=temp->next;    
	}
	if(c==0)
	   cout<<">>>>>Text not found<<<<<";
}
void delete_data(int pos)
{
    int count=1;
    Node* temp=head;
    Node*temp2=head2;
    Node*t;
    Track* node=new Track();
    node->history=5;
    node->post=pos;
	if(pos==1)
	{
		node->next=Hhead;
		Hhead=node;	
		t=head;
		head=head->next;
		t->next=head2;
		head2=t;
		cout<<">>>>>Task performed<<<<<";
		getch();
		return;
	}
	else
	{
	    while(temp!=NULL)
	    {
            if(count==pos-1)
            {
            	node->next=Hhead;
	         	Hhead=node;
            	t=temp->next;
	            temp->next=temp->next->next;
	            t->next=head2;
		        head2=t;
		        cout<<">>>>>Task performed<<<<<";
			    getch();
	            return;
            }
            count++;
            temp=temp->next;
        }
    }
    cout<<">>>>>There is nothing to Delete<<<<<";
	getch();
}
void insert_at_pos(int pos)
{
	int count=1;
	Node* temph=head;
	Node*temp;
	if(pos==1||head==NULL)
	{
		temp=head2->next;
		head2->next=head;
		head=head2;
		head2=temp;
		return;
	}
	else
	{
		while(temph!=NULL)
		{
			if(count==pos-1)
			{
			    temp=head2->next;
		        head2->next=temph->next;
		        temph->next=head2;
		        head2=temp;
				return;	
			}
			temph=temph->next;
			count++;
		}
	}
}
void insert_at_pos2(int pos)
{
	int count=1;
	Node* temph=head;
	Node*temp;
	if(head==NULL)
	{
		temp=head3->next;
		head3->next=head;
		head=head3;
		head3=temp;
		return;
	}
		while(temph!=NULL)
		{
			if(temph->next==NULL)
			{
			    temp=head3->next;
		        head3->next=NULL;
		        temph->next=head3;
		        head3=temp;
				return;	
			}
			temph=temph->next;
		}
}
void swap(int pos)
{
	int count=1;
	Node*temp=head;
	Node* temp2;
	char str[100];
	if(pos==1)
	{
		strcpy(str,head->data);
		strcpy(head->data,head4->data);
		strcpy(head4->data,str);
		temp2=head3;
		head3=head4;
		head4=head4->next;
		head3->next=temp2;
		return;
		
	}
	while(temp!=NULL)
	{
		if(count==pos)
		{
			strcpy(str,temp->data);
			strcpy(temp->data,head4->data);
			strcpy(head4->data,str);
			temp2=head3;
		    head3=head4;
	     	head4=head4->next;
		    head3->next=temp2;
			return;
		}
		count++;
		temp=temp->next;
	}
	cout<<"Nothing to undo";
}
void swap2(int pos)
{
	int count=1;
	Node*temp=head;
	Node* temp2;
	char str[100];
	if(pos==1)
	{
		strcpy(str,head->data);
		strcpy(head->data,head3->data);
		strcpy(head3->data,str);
		temp2=head4;
		head4=head3;
		head3=head3->next;
		head4->next=temp2;
		return;
		
	}
	while(temp!=NULL)
	{
		if(count==pos)
		{
			strcpy(str,temp->data);
			strcpy(temp->data,head3->data);
			strcpy(head3->data,str);
			temp2=head4;
		    head4=head3;
	     	head3=head3->next;
		    head4->next=temp2;
			return;
		}
		count++;
		temp=temp->next;
	}
	cout<<"Nothing to undo";
}
void undo()
{
	if(Hhead==NULL)
	{
		cout<<"--------There is nothing to undo-----------";
		getch();
		return;
	}
	cout<<">>>>>Task performed<<<<<";
	getch();
	int count=1;
	Node* temp=head;
	Node* temp2=head2;
	Track* Ttemp;
	Track* node=new Track();
	Node* t;
	Track* temp3=Hhead;
		while(temp3!=NULL)
		{
			if(Hhead->history==5)
			{
			    Hhead->history=7;
				insert_at_pos(temp3->post);
				Ttemp=Hhead;
				Hhead=Hhead->next;
				Ttemp->next=Hhead2;
				Hhead2=Ttemp;
				return;	
			}
			else if(temp3->history==5&&Hhead!=NULL)
			{
				temp3->history=7;
				insert_at_pos(temp3->post);
				Ttemp=temp3;
				temp3=Hhead->next;
				Ttemp->next=Hhead2;
				Hhead2=Ttemp;
				return;
			}
			else if(Hhead->history==2||Hhead->history==3)
			{
				Hhead->history=12;
				swap(temp3->post);
				Ttemp=Hhead;
				Hhead=Hhead->next;
				Ttemp->next=Hhead2;
				Hhead2=Ttemp;
				return;	
			}
			else if(temp3->next!=NULL&&temp3->history==2||temp3->next!=NULL&&temp3->history==3)
			{
				temp3->history=12;
				swap(temp3->post);
				Ttemp=temp3;
				temp3=Hhead->next;
				Ttemp->next=Hhead2;
				Hhead2=Ttemp;
				return;	
			}
            if(Hhead->history==1)
            {
            	temp=head;
		        Hhead->history=10;
		        if(head->next==NULL)
		        {
			        temp3->post=1;
			        t=head;
			        head=head->next;
			        t->next=head3;
			        head3=t;
			        Ttemp=Hhead;
			    	Hhead=Hhead->next;
				    Ttemp->next=Hhead2;
				    Hhead2=Ttemp;
			        return;
		        }
		        while(temp->next!=NULL)
		        {
			        if(temp->next->next==NULL)
			        {
				        Hhead->post=count+1;
				        t=temp->next;
				        temp->next=NULL;
				        t->next=head3;
				        head3=t;
				        Ttemp=Hhead;
				        Hhead=Hhead->next;
				        Ttemp->next=Hhead2;
				        Hhead2=Ttemp;
				        return;
			        }
			        count++;
			        temp=temp->next;
		        }
		    }
		    temp3=temp3->next;
        }
}
void redo()
{
	if(Hhead2==NULL)
	{
		cout<<"--------There is nothing to redo-----------";
		getch();
		return;
	}
	int count=1,pos;
	Node* temp=head;
	Node* temp2=head2;
	Node* t;
	Track* temp3=Hhead2;
	Track* Ttemp;
	while(temp3!=NULL&&Hhead2!=NULL)
		{
			if(Hhead2->history==7)
			{
				pos=Hhead2->post;
				Hhead2=Hhead2->next;
				delete_data(pos);
				return;	
			}
			else if(temp3!=NULL&&temp3->history==7)
			{
				pos=temp3->post;
				temp3=temp3->next;
				delete_data(pos);
				return;
			}
			cout<<">>>>>Task performed<<<<<";
			getch();
			if(Hhead2->history==10)
			{
			    Hhead2->history=1;
				insert_at_pos2(Hhead2->post);
				Ttemp=Hhead2;
			    Hhead2=Hhead2->next;
				Ttemp->next=Hhead;
				Hhead=Ttemp;
				return;	
			}
			else if(temp3->history==10)
			{
				temp3->history=1;
				insert_at_pos2(temp3->post);
				Ttemp=temp3;
			    temp3=temp3->next;
			    Ttemp->next=Hhead;
		        Hhead=Ttemp;
				return;
			}
	        else if(Hhead2->history==12)
			{
				Hhead2->history=2;
				swap2(temp3->post);
				Ttemp=Hhead2;
			    Hhead2=Hhead2->next;
				Ttemp->next=Hhead;
				Hhead=Ttemp;
				return;
			}
			else if(temp3->next->history==12)
			{
			    temp3->history=2;
				swap2(temp3->next->post);
				Ttemp=temp3;
			    temp3=temp3->next;
			    Ttemp->next=Hhead;
		        Hhead=Ttemp;
				return;	
			}
			temp3=temp3->next;
	    }
}
void save_data(int counter)
{
	int num;
	if(counter==0)
	{
	    printf("Enter the name of the file:");
	    fflush(stdin);
	    cin.getline(savestr,100);
	    strcat(savestr,".txt");
    }
	ofstream obj(savestr);
	Node* temp=head;
	while(temp!=NULL)
	{
		obj<<temp->data;
		obj<<endl;
		temp=temp->next;
	}
	cout<<">>>>>Your document is saved succesfully<<<<<";
	cout<<"\nEnter 1 to see your document \nOtherwise press any key:";
	cin>>num;
	if(num==1)
	{
		cout<<"**********Your Document**********\n";
	    char str[1000];
        ifstream myfile (savestr);
        while (! myfile.eof() )
        {
            myfile.getline (str,100);
            cout << str << endl;
        }
    }
    else
    {
    	cout<<"Your document save at C:\\Users\\hp\\Documents\\Dev C++\\"<<savestr<<"\nYou can check it later";
	}
}
int searching(char *s)
{
	int count=1,c=0,i,pos=0,arr[100];
	Node* temp=head;
	while(temp!=NULL)
	{
		if(strstr(temp->data,s)!=NULL)
		{
	        arr[c]=count;
	        c++;
		}
		count++;
		temp=temp->next;    
	}
	if(c==0)
	{
	    cout<<"Text not found";
	    getch();
	    return 0;
    }
	else 
    {
    	for(i=0;i<c;i++)
    	    cout<<"Your text found in line:"<<arr[i]<<endl;
        cout<<"Enter where you want to perform operation:";
	    cin>>pos;
	    for(i=0;i<c;i++)
	    {
	    	if(arr[i]==pos)
	    	     return pos;
		}
	    cout<<"\nWrong input";
    }
    return 0;
}
int main()
{
	int choice,pos,n,counter=0;
	char ch,str[1000];
	while(1)
	{
	   system("cls");
	   cout<<"********TEXT EDITOR********\n";
	   cout<<"*                         *\n";
	   cout<<"*                         *\n";
	   cout<<"*  *********************  *\n";
	   cout<<"T  *********************  T\n";
	   cout<<"E  **1.Insertion      **  E\n";
	   cout<<"X  **2.Update         **  X\n";
	   cout<<"T  **3.Append         **  T\n";
	   cout<<"   **4.searching      **   \n";
	   cout<<"E  **5.deletion       **  E\n";
	   cout<<"D  **6.display        **  D\n";
	   cout<<"I  **7.Undo           **  I\n";
	   cout<<"T  **8.Redo           **  T\n";
	   cout<<"O  **9.Save ducument  **  O\n";
	   cout<<"R  **0.exit           **  R\n";
	   cout<<"*  *********************  *\n";
	   cout<<"*  *********************  *\n";
	   cout<<"*                         *\n";
	   cout<<"*                         *\n";
	   cout<<"********TEXT EDITOR********\n";
	   cout<<"Enter your choice:";
	   cin>>choice;
	   switch(choice)
	   {
	   	    case 1:
	   	   	    {
	   	   	   	    cout<<"Enter a Text:";
	   	   	   	    fflush(stdin);
	   	   	   	    cin.getline(str,1000);
	   	   	   	    strcat(str," ");
	   	   	   	    insertdata(str);
	   	   	   	    break;
			    }
			case 2:
				{
					if(head==NULL)
					{
						cout<<">>>>>Your document is empty<<<<<";
						getch();
						break;
					}
					cout<<"Deletion option:"<<endl;
					cout<<"Press 1 to update with row no:"<<endl;
					cout<<"Press 2 to update with string:"<<endl;
					cout<<"Enter your choice:";
					cin>>n;
					if(n==1)
				    {
				    	cout<<"Enter the position where you want to update:";
					    cin>>pos;
					    cout<<"Enter the updated Text:";
					    fflush(stdin);
					    cin.getline(str,1000);
					    strcat(str," ");
					    update(pos,str);
				    }
				    else if(n==2)
				    {
				    	cout<<"Enter the searching string:";
				    	fflush(stdin);
				    	cin.getline(str,1000);
					    strcat(str," ");
					    pos=searching(str);
					    if(pos!=0)
					    {
					        cout<<"Enter the updated Text:";
					        fflush(stdin);
					        cin.getline(str,1000);
					        strcat(str," ");
				    	    update(pos,str);
				        }
					}
					else
					{
					    cout<<">>>>>Invalid choice<<<<<";	
					}
				    break;
				}
			case 3:
				{
				    if(head==NULL)
					{
						cout<<">>>>>Your document is empty<<<<<";
						getch();
						break;
					}
					cout<<"Append option:"<<endl;
					cout<<"Press 1 to Append with row no:"<<endl;
					cout<<"Press 2 to Append with string:"<<endl;
					cout<<"Enter your choice:";
					cin>>n;
					if(n==1)
				    {
				    	cout<<"Enter the position where you want to Append:";
					    cin>>pos;
					    cout<<"Enter the Appending Text:";
					    fflush(stdin);
					    cin.getline(str,1000);
					    strcat(str," ");
					    append_data(pos,str);
				    }
				    else if(n==2)
				    {
				    	cout<<"Enter the searching string:";
				    	fflush(stdin);
				    	cin.getline(str,1000);
					    strcat(str," ");
					    pos=searching(str);
					    if(pos!=0)
					    {
					        cout<<"Enter the Appending Text:";
					        fflush(stdin);
					        cin.getline(str,1000);
					        strcat(str," ");
				    	    append_data(pos,str);
				        }
					}
					else
					{
					    cout<<">>>>>Invalid choice<<<<<";	
					}
				    break;
				}
			case 4:
				{
					if(head==NULL)
					{
						cout<<">>>>>Your document is empty<<<<<";
						getch();
						break;
					}
					cout<<"Enter the  you want to search:";
					fflush(stdin);
					cin.getline(str,1000);
					search(str);
					getch();
					break;
				}
			case 5:
				{
				    if(head==NULL)
					{
						cout<<">>>>>Your document is empty<<<<<";
						getch();
						break;
					}
					cout<<"Deletion option:"<<endl;
					cout<<"Press 1 to delete with row no:"<<endl;
					cout<<"Press 2 to delete with string:"<<endl;
					cout<<"Enter your choice:";
					cin>>n;
					if(n==1)
				    {
				    	cout<<"Enter the position where you want to delete:";
					    cin>>pos;
					    delete_data(pos);
				    }
				    else if(n==2)
				    {
				    	cout<<"Enter the searching string:";
				    	fflush(stdin);
				    	cin.getline(str,1000);
					    strcat(str," ");
					    pos=searching(str);
					    if(pos!=0)
					    {
				    	    delete_data(pos);
				        }
					}
					else
					{
					    cout<<">>>>>Invalid choice<<<<<";	
					    getch();
					}
				    break;
				}
			case 6:
				{
					show();
					getch();
					break;
				}
			case 7:
				{
					undo();
					break;
				}
			case 8:
				{
					redo();
					break;
				}
			case 9:
				{
					if(head==NULL)
					{
						cout<<">>>>>Your document is empty<<<<<";
						getch();
						break;
					}
					save_data(counter);
					counter++;
					getch();
					break;
				}
			case 0:
				{
					exit(1);
				}
			default:
				{
					cout<<">>>>>Enter valid choice<<<<<";
					getch();
				}
	   }
    }
    return 0;
}
