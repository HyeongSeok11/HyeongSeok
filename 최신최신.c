#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

int count= 0;
int i;
int AccountPasswd= 1016;


struct Information {
	char Name[20][20];
	char Address[20][50];
	char PhoneNumber[20][20];
	int Birthday[20];
	int Year[20];
	int Deposit[20];
	int AccountMoney[20];
	int ID[20];
	char AccountType[20][15];
	int Loan[20];
};

struct Information newacc;

void new_acc() {
	srand(time(NULL));
	
	i = count;

	printf("\n�̸��� 'ȫ�浿'ó�� ��ĭ���� �����ּ���.\n");
	scanf("%s", newacc.Name[i]);
	fflush(stdin);	

	printf("�ּҸ� �����ּ���.\n");
	scanf("%[^\t\n]s", newacc.Address[i]);
	fflush(stdin);
	

	printf("��������� YYYYMMDD�� �����ּ���.\n");
	scanf("%d", &newacc.Birthday[i]);
	fflush(stdin);
	
	printf("�ڵ��� ��ȣ�� �����ּ���.\n");
	scanf("%[^\t\n]s", newacc.PhoneNumber[i]);
	fflush(stdin); 
	
	int Num;

	printf("Saving ���¸� ���Ͻø� 1��, Current ���¸� ���Ͻø� 0�� �Է����ּ���.\n");
	scanf("%d", &Num);
	
	if( Num == 1 ){
		printf("������� �Ͻðڽ��ϱ�?(1��, 2��, 3��)\n");
		scanf("%d", &newacc.Year[i]);
		strcpy(newacc.AccountType[i], "Saving");
		
		printf("��ġ������ ���� �ݾ��� �Է����ּ���.\n");
		scanf("%d", &newacc.Deposit[i]);	
		newacc.AccountMoney[i] = newacc.Deposit[i];	
	}
	else if (Num == 0){
		printf("��ġ������ ���� �ݾ��� �Է����ּ���.\n");
		scanf("%d", &newacc.Deposit[i]);
		strcpy(newacc.AccountType[i], "Current");
		newacc.AccountMoney[i] = newacc.Deposit[i];
	}
	else {
		printf("�����Դϴ�. �ٽ� �õ����ּ���.");
		menu();
	}

	newacc.ID[i] = rand() % 1000000;
    printf("������ ID�� %08d�Դϴ�.\n\n", newacc.ID[i]);	
    
    count++;
    
    
}

void loanmoney() {
	int IDnumber;
	int j=0;

	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	
	
	printf("\n������ ��������\n\n");
	printf("�̸�: %s\n", newacc.Name[j]);
	
	
	printf("���� ����: %s\n", newacc.AccountType[j]);
	if (strcmp(newacc.AccountType[j], "Saving") == 0) {
		
		printf("���� ���: %d\n", newacc.Year[j]);
	}

	printf("���� �ܾ�: %d\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
}


void see() {
	
	int Passwd;
	
	printf("\n������ ��й�ȣ�� �Է��ϼ���.\n");
	scanf("%d", &Passwd);
	
	if (Passwd == AccountPasswd){
				
	    int k;
	    int num = 0;
	    for (k=0; k < count; k++) {
	    	
	    	if(newacc.ID[k] != -1) {
	    		printf("\n%d �� ȸ�� ����\n", ++num );
	            printf("�̸�: %s\n", newacc.Name[k]);
	            printf("�ּ�: %s\n", newacc.Address[k]);
	            printf("�������: %d\n", newacc.Birthday[k]);
	            printf("�ڵ��� ��ȣ: %s\n", newacc.PhoneNumber[k]);
	            printf("���� ����: %s\n", newacc.AccountType[k]);
	            printf("��ġ��: %d\n", newacc.Deposit[k]);
	            printf("���� �ܾ�: %d\n", newacc.AccountMoney[k]);
	            printf("ID: %08d\n\n", newacc.ID[k]);
				}
			}
		    
			}
	
	else {
		printf("\n��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n");
		menu();
	}
	
}

void edit(){
	int IDnumber;
	int j=0;

	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	int EditNumber; 
	printf("�ڵ��� ��ȣ�� �����ϰ� �����ø� 1��, �ּҸ� �����ϰ� �����ø� 2��, �� �� �����ϰ� �����ø� 3�� �Է����ּ���.\n");
	scanf("%d", &EditNumber); 
	fflush(stdin);	
	
	
	switch(EditNumber) {
		case 1:
			printf("\n�����Ͻ� �ڵ��� ��ȣ�� �Է����ּ���.\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]);
			printf("\n����� �ڵ��� ��ȣ�� %s �Դϴ�.\n\n", newacc.PhoneNumber[j]);
			break;
			
		case 2:
			printf("�����Ͻ� �ּҸ� �Է����ּ���.\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			printf("\n����� �ּҴ� %s �Դϴ�.\n\n", newacc.Address[j]);
			break;
			
		case 3:
			printf("�����Ͻ� �ڵ��� ��ȣ�� �Է����ּ���.\n\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]);
			fflush(stdin);
			printf("�����Ͻ� �ּҸ� �Է����ּ���.\n\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			fflush(stdin);
			printf("\n����� �ڵ��� ��ȣ�� %s �Դϴ�.\n", newacc.PhoneNumber[j]);
			printf("\n����� �ּҴ� %s �Դϴ�.\n\n", newacc.Address[j]);
			break;
			
		default:
			menu();
			break;
	}
	
}

void erase(){
	
	int IDnumber;
	int j=0;
	
	printf("\n�����Ͻ� ������ ID�� �Է����ּ���.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			menu();
		}
		else{
			j++;
		}	
	}
	
	printf("\n�̸�: %s\n", newacc.Name[j]);
    printf("�ּ�: %s\n", newacc.Address[j]);
	printf("�������: %d\n", newacc.Birthday[j]);
	printf("�ڵ��� ��ȣ: %s\n", newacc.PhoneNumber[j]);
	printf("���� ����: %s\n", newacc.AccountType[j]);
	printf("��ġ��: %d\n", newacc.Deposit[j]);
	printf("���� �ܾ�: %d\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
	int erasernum;
	
	printf("\n������ ���Ͻø� 1��, �׷��� ������ 0�� �Է��ϼ���.\n");
	scanf("%d", &erasernum);
	
	if (erasernum == 1) {
		strcpy(newacc.Name[j], "0");
		strcpy(newacc.Address[j], "0");
		newacc.Birthday[j] = 0;
		strcpy(newacc.PhoneNumber[j], "0");
		strcpy(newacc.AccountType[j], "0");
		newacc.Deposit[j] = 0;
		newacc.AccountMoney[j] = 0;
		newacc.Year[j] = 0;
		newacc.ID[j] = -1;
		printf("\n������ ID�� ���������� �����Ǿ����ϴ�.\n\n");
		
		}
	else if (erasernum == 0) {
		menu();
	}
	else {
		printf("�����Դϴ�.\n");
		menu();
	}
	
}

void transact() {
	int senderid; //senderid�� ������ ��� id 
	int sender=0, getter=0;  // sender�� ������ ��� �迭����? getter�� �޴� ��� �迭 ����? 
	int GetMoney, OutMoney; // getmoney�� �Աݾ�, outmoney�� ��ݾװ� �۱ݾ� 
	
	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &senderid);

	while( senderid != newacc.ID[sender]) {
		
		if ( sender >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			menu();
		}
		else{
			sender++;
		}
		
	}
	
	printf("\nID: %08d\n", newacc.ID[sender]);
	printf("���� �ܾ�: %d\n", newacc.AccountMoney[sender]);
	printf("���� Ÿ��: %s\n", newacc.AccountType[sender]);
	
	int SelectMoney;
	printf("\n�Ա��� ���Ͻø� 1����, ����� ���Ͻø� 2����, �۱��� ���Ͻø� 3��, ��Ҵ� 4���� �Է����ּ���.\n");
	scanf("%d", &SelectMoney);
	
	int getterid; // �޴� ��� ���� 
	 
	switch (SelectMoney) {
		
		case 1:
			printf("\n�Ա��Ͻ� �ݾ��� �Է����ּ���.\n");
			scanf("%d", &GetMoney);
			newacc.AccountMoney[sender] += GetMoney;
			printf("\n�Ա� �� �ܾ�: %d\n\n", newacc.AccountMoney[sender]);
			break;
			
		case 2:
		
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n����Ͻ� �ݾ��� �Է����ּ���.\n");
				scanf("%d", &OutMoney);
				
				if (newacc.AccountMoney[sender] >= OutMoney) {
					
					newacc.AccountMoney[sender] -=OutMoney;
				    printf("\n��� �� �ܾ�: %d\n\n", newacc.AccountMoney[sender]);	
				}
				
				else {
					
					printf("\n�ܾ��� �����մϴ�.\n");
					menu(); 
				}
			
						
			}
			else {
				printf("\nSaving ���´� ����Ͻ� �� �����ϴ�.\n");
				menu();
			}
			break;
			
		case 3:
			
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n�޴� ����� ID�� �����ּ���.\n");
				scanf("%08d", &getterid);
				
				while ( getterid != newacc.ID[getter]){
					
					if (getter >= count) {
			            printf("��ġ�ϴ� ����� �����ϴ�.\n\n");
			            menu();
		                }
		            
					else{
			            getter++;
		            }
						
				}
				
				int num;
				printf("\n�޴� ����� ã�ҽ��ϴ�.");
				printf("\n %s %d�� �½��ϱ�?", newacc.Name[getter], newacc.Birthday[getter]);
				printf("\n ������ 1��, �ƴϸ� 2�� �Է����ּ���.\n"); 
				scanf("%d", &num);
				
				switch (num) {
					case 1:
						printf("\n������ �ݾ��� �Է����ּ���.\n");
						scanf("%d", &OutMoney);
						
						if (newacc.AccountMoney[sender] >= OutMoney) {
							
							newacc.AccountMoney[sender] -= OutMoney;
						    newacc.AccountMoney[getter] += OutMoney;
						    printf("\n���� �ܾ�: %d\n\n", newacc.AccountMoney[sender]);
						}
						
						else {
							printf("\n�ܾ��� �����մϴ�.\n");
							menu();
						}
					
						break;
						
					case 2:
						printf("\n �����մϴ�.\n");
						menu();
						break;
					
					default:
						printf("\n �����Դϴ�. ó������ �ٽ� �õ����ּ���.\n");
						menu();
						break;
				}
			}
			else {
				printf("\nSaving ���´� �۱��Ͻ� �� �����ϴ�.\n");
				menu();			
			}
			break;
		
		case 4:
			menu();
			break;
					
		default:
			printf("\n�����Դϴ�.\n");
			menu();
			break;
			
	}
	
}

void menu() {
	
	int exitnum = 1;
	while( exitnum == 1 ){
		
		int t;	    
		for ( t=0; t<25; t++){
			printf("��");}
			
		int Number;
	    printf("\n1. ��������\n");
	    printf("2. �ڵ��� ��ȣ, �ּ� ����\n");
	    printf("3. �����, �۱�\n");
	    printf("4. ���»�����\n");
	    printf("5. ���� ����\n");
	    printf("6. ���� �ѵ� ��ȸ\n");
	    printf("7. ������\n");
	    printf("\n���� ���� ��ȣ�� �Է����ּ���.\n");
	    scanf("%d", &Number);
	
	    switch(Number) {
		    case 1:
			    new_acc();
			    break;
			    
			case 2:
				edit();
				break;
				
			case 3:
				transact();
				break;
				
			case 4:
				see();
				break;
				
			case 5:
				erase();
				break;
		
		    case 6:
			    loanmoney();
			    break;	
			
			case 7:
				exitnum++;
				break;
			
			default:
				break;
			}
		
		
	
	} 

}

int main(void) {
	
	int a;
	for (a= 0; a < 40 ; a++) {
		printf("~");
	}
	printf("\n�������ι� ���࿡ ���Ű� ȯ���մϴ�\n");
	
    for (a = 0; a < 40 ; a++) {
	    printf("~");
	}
	
	printf("\n\n������: ������\n��: ������");
	printf("\n\n\n\n"); 
	printf("�츮 �������ι� ������ �ѱ��� ����ϰ�, �ѱ��ε鿡�� ����޴� �� 1������ �����Դϴ�.\n");
	printf("����, �������ι� ������ ������ ����� ������ �����ϰ� �ֽ��ϴ�!\n");
	printf("� �������ι� ���� ���¸� �����Ͽ� ������ ����������~\n");
	
	menu();
	printf("\n��������ý����� ����Ǿ����ϴ�.\n"); 

	return 0;
}

