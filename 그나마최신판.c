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
};

struct Information newacc;

void new_acc() {
	srand(time(NULL));
	
	i = count;

	printf("\n이름을 '홍길동'처럼 빈칸없이 적어주세요.\n");
	scanf("%s", newacc.Name[i]);
	fflush(stdin);	

	printf("주소를 적어주세요.\n");
	scanf("%[^\t\n]", newacc.Address[i]);
	fflush(stdin);
	

	printf("생년월일을 YYYYMMDD로 적어주세요.\n");
	scanf("%d", &newacc.Birthday[i]);
	fflush(stdin);
	
	printf("핸드폰 번호를 적어주세요.\n");
	scanf("%[^\t\n]", newacc.PhoneNumber[i]);
	fflush(stdin); 
	
	int Num;

	printf("Saving 계좌를 원하시면 1을, Current 계좌를 원하시면 0을 입력해주세요.\n");
	scanf("%d", &Num);
	
	if( Num == 1 ){
		printf("몇년으로 하시겠습니까?(1년, 2년, 3년)\n");
		scanf("%d", &newacc.Year[i]);
		strcpy(newacc.AccountType[i], "Saving");
		
		printf("예치금으로 넣을 금액을 입력해주세요.\n");
		scanf("%d", &newacc.Deposit[i]);	
		newacc.AccountMoney[i] = newacc.Deposit[i];	
	}
	else {
		printf("예치금으로 넣을 금액을 입력해주세요.\n");
		scanf("%d", &newacc.Deposit[i]);
		strcpy(newacc.AccountType[i], "Current");
		newacc.AccountMoney[i] = newacc.Deposit[i];
	}
	

	newacc.ID[i] = rand() % 1000000;
    printf("고객님의 ID는 %08d입니다.\n\n", newacc.ID[i]);	
    
    count++;
    
    
}

void view_list() {
	int IDnumber;
	int j=0;

	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	printf("\n고객님의 계좌정보\n\n");
	printf("이름: %s\n", newacc.Name[j]);
	printf("주소: %s\n", newacc.Address[j]);
	printf("생년월일: %d\n", newacc.Birthday[j]);
	printf("핸드폰 번호: %s\n", newacc.PhoneNumber[j]);
	printf("계좌 종류: %s\n", newacc.AccountType[j]);
	printf("예치금: %d\n", newacc.Deposit[j]);
	printf("계좌 잔액: %d\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
}


void see() {
	
	int Passwd;
	
	printf("\n관리자 비밀번호를 입력하세요.\n");
	scanf("%d", &Passwd);
	
	if (Passwd == AccountPasswd){
				
	    int k;
	    int num = 0;
	    for (k=0; k < count; k++) {
	    	
	    	if(newacc.ID[k] != -1) {
	    		printf("\n%d 번 회원 정보\n", ++num );
	            printf("이름: %s\n", newacc.Name[k]);
	            printf("주소: %s\n", newacc.Address[k]);
	            printf("생년월일: %d\n", newacc.Birthday[k]);
	            printf("핸드폰 번호: %s\n", newacc.PhoneNumber[k]);
	            printf("계좌 종류: %s\n", newacc.AccountType[k]);
	            printf("예치금: %d\n", newacc.Deposit[k]);
	            printf("계좌 잔액: %d\n", newacc.AccountMoney[k]);
	            printf("ID: %08d\n\n", newacc.ID[k]);
				}
			}
		    
			}
	
	else {
		printf("\n비밀번호가 틀렸습니다.\n\n");
		menu();
	}
	
}

void edit(){
	int IDnumber;
	int j=0;

	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	int EditNumber; 
	printf("핸드폰 번호를 변경하고 싶으시면 1을, 주소를 변경하고 싶으시면 2를, 둘 다 변경하고 싶으시면 3을 입력해주세요.\n");
	scanf("%d", &EditNumber); 
	fflush(stdin);	
	
	
	switch(EditNumber) {
		case 1:
			printf("\n변경하실 핸드폰 번호를 입력해주세요.\n");
			scanf("%[^\t\n]", newacc.PhoneNumber[j]);
			printf("\n변경된 핸드폰 번호는 %s 입니다.\n\n", newacc.PhoneNumber[j]);
			break;
			
		case 2:
			printf("변경하실 주소를 입력해주세요.\n");
			scanf("%[^\t\n]", newacc.Address[j]);
			printf("\n변경된 주소는 %s 입니다.\n\n", newacc.Address[j]);
			break;
			
		case 3:
			printf("변경하실 핸드폰 번호를 입력해주세요.\n");
			scanf("%[^\t\n]", newacc.PhoneNumber[j]);
			fflush(stdin);
			printf("변경하실 주소를 입력해주세요.\n");
			scanf("%[^\t\n]", newacc.Address[j]);
			fflush(stdin);
			printf("\n변경된 핸드폰 번호는 %s 입니다.\n", newacc.PhoneNumber[j]);
			printf("\n변경된 주소는 %s 입니다.\n\n", newacc.Address[j]);
			break;
			
		default:
			menu();
			break;
	}
	
}

void erase(){
	
	int IDnumber;
	int j=0;
	
	printf("\n삭제하실 고객님의 ID를 입력해주세요.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			menu();
		}
		else{
			j++;
		}	
	}
	
	printf("\n이름: %s\n", newacc.Name[j]);
    printf("주소: %s\n", newacc.Address[j]);
	printf("생년월일: %d\n", newacc.Birthday[j]);
	printf("핸드폰 번호: %s\n", newacc.PhoneNumber[j]);
	printf("계좌 종류: %s\n", newacc.AccountType[j]);
	printf("예치금: %d\n", newacc.Deposit[j]);
	printf("계좌 잔액: %d\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
	int erasernum;
	
	printf("\n삭제를 원하시면 1을, 그렇지 않으면 0을 입력하세요.\n");
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
		printf("\n고객님의 ID가 정상적으로 삭제되었습니다.\n\n");
		
		}
	else if (erasernum == 0) {
		menu();
	}
	else {
		printf("오류입니다.\n");
		menu();
	}
	
}

void transact() {
	int sendid; //sendid는 보내는 사람 id 
	int sender=0, getter=0;  // h는 보내는 사람 배열숫자? k는 받는 사람 배열 숫자? 
	int GetMoney, OutMoney; // getmoney는 입금액, outmoney는 출금액과 송금액 
	
	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%d", &sendid);

	while( sendid != newacc.ID[sender]) {
		
		if ( sender >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			menu();
		}
		else{
			sender++;
		}
		
	}
	
	printf("\nID: %08d\n", newacc.ID[sender]);
	printf("계좌 잔액: %d\n", newacc.AccountMoney[sender]);
	
	int SelectMoney;
	printf("\n입금을 원하시면 1번을, 출금을 원하시면 2번을, 송금을 원하시면 3번, 취소는 4번을 입력해주세요.\n");
	scanf("%d", &SelectMoney);
	
	char GetName[20]; // 받는 사람 이름 
	int GetBirthday; // 받는 사람 생일 
	 
	switch (SelectMoney) {
		
		case 1:
			printf("\n입금하실 금액을 입력해주세요.\n");
			scanf("%d", &GetMoney);
			newacc.AccountMoney[sender] = newacc.AccountMoney[sender] + GetMoney;
			printf("\n계좌 잔액: %d\n", newacc.AccountMoney[sender]);
			break;
			
		case 2:
			if (newacc.AccountType[sender] != "Current") {
				printf("\nSaving 계좌는 출금하실 수 없습니다.\n");
				menu();
			}
			else if (newacc.AccountType[sender] == "Current") {
				printf("\n출금하실 금액을 입력해주세요.\n");
				scanf("%d", &OutMoney);
				newacc.AccountMoney[sender] = newacc.AccountMoney[sender] - OutMoney;
				printf("\n계좌 잔액: %d\n", newacc.AccountMoney[sender]);				
			}
			break;
			
		case 3:
			if (newacc.AccountMoney[sender] != "Current") {
				printf("\nSaving 계좌는 송금하실 수 없습니다.\n");
				menu();
			}
			else if (newacc.AccountType[sender] == "Current") {
				printf("\n받는 사람의 이름을 적어주세요.\n");
				scanf("%s", GetName);
				printf("\n받는 사람의 생년월일을 적어주세요.\n");
				scanf("%d", &GetBirthday);
				
				while ((GetName == newacc.Name[getter]) && (GetBirthday == newacc.Birthday[getter]) ) {
					if (getter >= count) {
			            printf("일치하는 사람이 없습니다.\n\n");
			            menu();
		                       }
		            else{
			            getter++;
		                     }
				}
				
				int num;
				printf("\n받는 사람을 찾았습니다.\n %s %d가 맞습니까?\n 맞으면 1을, 아니면 2를 입력해주세요.\n", newacc.Name[getter], newacc.Birthday[getter]);
				scanf("%d", &num);
				
				switch (num) {
					case 1:
						printf("\n보내실 금액을 입력해주세요.\n");
						scanf("%d", &OutMoney);
						newacc.AccountMoney[sender]= newacc.AccountMoney[sender] - OutMoney;
						newacc.AccountMoney[getter]= newacc.AccountMoney[getter] + OutMoney;
						printf("\n계좌 잔액: %d", &newacc.AccountMoney[sender]);
						break;
						
					case 2:
						printf("\n다시 시도해주세요.\n");
						menu();
						break;
					
					default:
						menu();
						break;
				}
			}
			break;
		
		case 4:
			menu();
			break;
					
		default:
			printf("\n오류입니다.\n");
			menu();
			break;
			
	}
	
}

void menu() {
	
	int exitnum = 1;
	while( exitnum == 1 ){
		
		int t;	    
		for ( t=0; t<25; t++){
			printf("ㅡ");}
			
		int Number;
	    printf("\n1. 계정생성\n");
	    printf("2. 핸드폰 번호, 주소 변경\n");
	    printf("3. 입출금, 송금\n");
	    printf("4. 계좌상세정보\n");
	    printf("5. 계좌 삭제\n");
	    printf("6. 대출금 확인\n");
	    printf("7. 나가기\n");
	    printf("\n들어가고 싶은 번호를 입력해주세요.\n");
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
			    view_list();
			    break;	}
			
			case 7:
				break;
			
			default:
				break;
		
		if (Number == 7) {
			break;
		}
	
	} 

}

int main(void) {
	
	menu();
	printf("\n은행관리시스템이 종료되었습니다.\n"); 

	return 0;
}

