// Number to Word Convertor.
// Copyright(c)-2006 by Abhishek Kumar. All rights reserved.

#include<fstream.h>
#include<stdlib.h>
#include<string.h>

char num_str[200];
class N2W
{
  int stack[9];
  int nested_flag;
  int top;
 public:
  int push(int);
  void print(int);
  void print_pair(int);
  void translate(int);
  int Num_in_Word();
};

int N2W::push(int item)
{
	int status=1;

	if(top==9-1)
	{
	    strncpy(num_str,"NUMBER IS TOO BIG. STACK OVERFLOW.", 35);
	    num_str[35] = '\0';
	    status=0;
	}
	else
	    stack[++top] = item;

	return status;
}

void N2W::print(int num)
{
	switch(num)
	{
		case 1: strcat(num_str,"ONE ");	break;
		case 2: strcat(num_str,"TWO "); break;
		case 3:	strcat(num_str,"THREE "); break;
		case 4:	strcat(num_str,"FOUR "); break;
		case 5:	strcat(num_str,"FIVE "); break;
		case 6:	strcat(num_str,"SIX "); break;
		case 7:	strcat(num_str,"SEVEN "); break;
		case 8:	strcat(num_str,"EIGHT "); break;
		case 9: strcat(num_str,"NINE "); break;
	}
}

void N2W::print_pair(int num)
{
	switch(num)
	{
	 case 1: switch(stack[top])
		 {
		  case 1: strcat(num_str,"ELEVEN "); break;
		  case 2: strcat(num_str,"TWELVE "); break;
		  case 3: strcat(num_str,"THIRTEEN "); break;
		  case 4: strcat(num_str,"FOURTEEN "); break;
		  case 5: strcat(num_str,"FIFTEEN "); break;
		  case 6: strcat(num_str,"SIXTEEN "); break;
		  case 7: strcat(num_str,"SEVENTEEN "); break;
		  case 8: strcat(num_str,"EIGHTEEN "); break;
		  case 9: strcat(num_str,"NINETEEN "); break;
		  case 0: strcat(num_str,"TEN "); nested_flag = 0;
		 }
		 break;
	 case 2: strcat(num_str,"TWENTY "); break;
	 case 3: strcat(num_str,"THIRTY "); break;
	 case 4: strcat(num_str,"FORTY "); break;
	 case 5: strcat(num_str,"FIFTY "); break;
	 case 6: strcat(num_str,"SIXTY "); break;
	 case 7: strcat(num_str,"SEVENTY "); break;
	 case 8: strcat(num_str,"EIGHTY "); break;
	 case 9: strcat(num_str,"NINETY "); break;
	}
}

void N2W::translate(int length)
{
	if(length==9)
	{
		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
		  print(stack[top--]);
		else
		  top--;

		strcat(num_str,"CRORES ");
	}

	if(length>=7)
	{
		if(length==8)
		{
			print(stack[top--]);
			strcat(num_str,"CRORES ");
		}

		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
		  print(stack[top--]);
		else
		  top--;

		if(stack[6]!=0||stack[5]!=0)
		  strcat(num_str,"LAKHS ");

		if(nested_flag==0)
		  nested_flag = 1;
	}

	if(length>=5)
	{
		if(length==6)
		{
		  print(stack[top--]);
		  strcat(num_str,"LAKHS ");
		}

		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
		  print(stack[top--]);
		else
		  top--;

		if(stack[4]!=0||stack[3]!=0)
		  strcat(num_str,"THOUSAND ");

		if(nested_flag==0)
		  nested_flag = 1;

	}

	if(length>=3)
	{
		if(length==4)
		{
		  print(stack[top--]);
		  strcat(num_str,"THOUSAND ");
		}

		print(stack[top--]);

		if(stack[2]!=0)
		  strcat(num_str,"HUNDERED ");

		if(stack[1]==0&&stack[0]!=0)
		{
		  strcat(num_str,"AND ");
		  print(stack[0]);
		}

		else if(stack[1]!=0)
		{
		  strcat(num_str,"AND ");
		  print_pair(stack[top--]);

		  if(stack[top+1]!=1 && nested_flag)
		    print(stack[top--]);
		}
	}

	if(length==2)
	{
		print_pair(stack[top--]);

		if(stack[top+1]!=1 && nested_flag)
		  print(stack[top--]);

		if(nested_flag==0)
		  nested_flag = 1;
	}

	if(length==1)
	  print(stack[top--]);

}

int N2W::Num_in_Word()
{
	ifstream in;
	ofstream out;

	int status;
	long number;
	top=-1;
	nested_flag=1;

	char temp[50];
	
	in.open("input.txt");
	if(!in) { strcpy(num_str,"File does not exist!"); goto END; }
	in.getline(temp,50);
	number=atol(temp);
	in.close();

	while(number>0)
	{
	  status=push(number%10);

	  if(status==0) goto END;

	  number = number/10;
	}

	translate(top+1);

    END:
	out.open("output.txt");
	if(!out) strcpy(num_str,"Can not write in file!");
	out<<num_str;
	out.close();

	num_str[0] = '\0';
	//free(temp);
	return 0;
}

void main()
{
 N2W NumberToWords;
 NumberToWords.Num_in_Word();
}